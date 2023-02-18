#include <3ds.h>
#include <citro2d.h>
#include <stdlib.h>
#include <iostream>
#include <assert.h>
#include <time.h>
#include <cstdio>
#include "player.hpp"

#define SCREEN_WIDTH  400
#define SCREEN_HEIGHT 240


#define MAX_SPRITES 8


typedef struct {
	C2D_Sprite sprite;
} Sprite;

enum class Color : u32 {
  Red = C2D_Color32(0xFF, 0x00, 0x00, 0xFF),
  Green = C2D_Color32(0x00, 0xFF, 0x00, 0xFF),
  Blue = C2D_Color32(0x00, 0x00, 0xFF, 0xFF),
  Clear = C2D_Color32(0x00, 0x00, 0x00, 0x00)
};

static C2D_SpriteSheet spriteSheet;
static Sprite sprites[MAX_SPRITES];
static bool isShooting = false;

// Declaring the prototype for initSprites, the function that will initialize the sprites
static void initSprites();


int main(int argc, char** argv)
{
	romfsInit();
	gfxInitDefault();
	consoleInit(GFX_BOTTOM, NULL);

	C3D_Init(C3D_DEFAULT_CMDBUF_SIZE);
	//Initialize citro2d and sets max objects
	C2D_Init(C2D_DEFAULT_MAX_OBJECTS);
	//Prepares the GPU for rendering 2D content
	C2D_Prepare();
	C3D_RenderTarget* top = C2D_CreateScreenTarget(GFX_TOP, GFX_RIGHT);

    Player localplayer(10, 0.0f, 0.0f, 16.0f, 16.0f, 4);



	spriteSheet = C2D_SpriteSheetLoad("romfs:/gfx/sprites.t3x");

	if(!spriteSheet){
		printf("Failed to load spritesheet\n");
		svcBreak(USERBREAK_PANIC);
	}

	initSprites();

	C2D_Sprite &spaceship = sprites[localplayer.getSprite()].sprite;
	C2D_SpriteSetScale(&spaceship, 1.0f, 1.0f);
	localplayer.gotoY(SCREEN_HEIGHT-50);

	// Main loop
	while (aptMainLoop())
	{
		//Scan all the inputs. This should be done once for each frame
		hidScanInput();
		
		u32 kDown = hidKeysDown();
		if (kDown & KEY_START) break; // break in order to return to hbmenu

		u32 kHeld = hidKeysHeld();
        if (kHeld & KEY_LEFT) {
            localplayer.moveLeft();
        }
        if (kHeld & KEY_RIGHT) {
            localplayer.moveRight();
        }

		if(kDown & KEY_A){
			if(!isShooting){
			isShooting=true;
			localplayer.setProjectile(localplayer.getX(), localplayer.getY());
			}
		}

		if(isShooting){
			localplayer.shoot(isShooting, top);

		}

		// Print a string to the console
		printf("Localplayer X: %f\n", localplayer.getX());
		printf("CPU:    %f\n", C3D_GetProcessingTime()*6.0f);
		printf("GPU:     %f\n", C3D_GetDrawingTime()*6.0f);
		printf("HCmdBuf:  %f\n", C3D_GetCmdBufUsage()*100.0f);
	

		C3D_FrameBegin(C3D_FRAME_SYNCDRAW);
		C2D_TargetClear(top, static_cast<u32>(Color::Clear));
		C2D_SceneBegin(top);
		//C2D_DrawRectangle(localplayer.getX(), SCREEN_HEIGHT-50, 0, 50, 50, static_cast<u32>(Color::Red), static_cast<u32>(Color::Red), static_cast<u32>(Color::Green), static_cast<u32>(Color::Green));
		C2D_SpriteSetPos(&spaceship, localplayer.getX(), localplayer.getY());

		C2D_DrawSprite(&spaceship);

		C3D_FrameEnd(0);

		// Flush and swap framebuffers
	/*	gfxFlushBuffers();
		gfxSwapBuffers();

		Wait for VBlank
		gspWaitForVBlank();*/
	}

	C2D_SpriteSheetFree(spriteSheet);

		// Deinitialize libraries
		C2D_Fini();
		C3D_Fini();
	gfxExit();
	romfsExit();
	return 0;
}

static void initSprites(){
	for(size_t i = 0; i<MAX_SPRITES; i++){
		Sprite* sprite = &sprites[i];

		
		C2D_SpriteFromSheet(&sprite->sprite, spriteSheet,i);
		C2D_SpriteSetCenter(&sprite->sprite, 0.5f, 0.5f);
		C2D_SpriteSetPos(&sprite->sprite, rand() % SCREEN_WIDTH, rand() % SCREEN_HEIGHT);
	}



}
