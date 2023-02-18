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
	 clrWhite = C2D_Color32(0xFF, 0xFF, 0xFF, 0xFF),
	 clrGreen = C2D_Color32(0x00, 0xFF, 0x00, 0xFF),
	 clrRed   = C2D_Color32(0xFF, 0x00, 0x00, 0xFF),
	 clrBlue  = C2D_Color32(0x00, 0x00, 0xFF, 0xFF),

	 clrCircle1 = C2D_Color32(0xFF, 0x00, 0xFF, 0xFF),
	 clrCircle2 = C2D_Color32(0xFF, 0xFF, 0x00, 0xFF),
	 clrCircle3 = C2D_Color32(0x00, 0xFF, 0xFF, 0xFF),

	 clrSolidCircle = C2D_Color32(0x68, 0xB0, 0xD8, 0xFF),

	 clrTri1 = C2D_Color32(0xFF, 0x15, 0x00, 0xFF),
	 clrTri2 = C2D_Color32(0x27, 0x69, 0xE5, 0xFF),

	 clrRec1 = C2D_Color32(0x9A, 0x6C, 0xB9, 0xFF),
	 clrRec2 = C2D_Color32(0xFF, 0xFF, 0x2C, 0xFF),
	 clrRec3 = C2D_Color32(0xD8, 0xF6, 0x0F, 0xFF),
	 clrRec4 = C2D_Color32(0x40, 0xEA, 0x87, 0xFF),

	 clrClear = C2D_Color32(0xFF, 0xD8, 0xB0, 0x68)

};

static C2D_SpriteSheet spriteSheet;
static Sprite sprites[MAX_SPRITES];

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
	C3D_RenderTarget* top = C2D_CreateScreenTarget(GFX_TOP, GFX_LEFT);

    Player localplayer(10, 0.0f, 0.0f, 16.0f, 16.0f, 0);



	spriteSheet = C2D_SpriteSheetLoad("romfs:/gfx/sprites.t3x");

	if(!spriteSheet){
		printf("Failed to load spritesheet\n");
		svcBreak(USERBREAK_PANIC);
	}

	initSprites();

	C2D_Sprite spaceship = sprites[4].sprite;

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

		// Print a string to the console
		printf("Localplayer X: %f\n", localplayer.getX());
		printf("CPU:    %f\n", C3D_GetProcessingTime()*6.0f);
		printf("GPU:     %f\n", C3D_GetDrawingTime()*6.0f);
		printf("HCmdBuf:  %f\n", C3D_GetCmdBufUsage()*100.0f);
	

		C3D_FrameBegin(C3D_FRAME_SYNCDRAW);
		C2D_TargetClear(top, static_cast<u32>(Color::clrClear));
		C2D_SceneBegin(top);
		C2D_DrawRectangle(SCREEN_WIDTH - 50, 0, 0, 50, 50, static_cast<u32>(Color::clrRec1), static_cast<u32>(Color::clrRec2), static_cast<u32>(Color::clrRec3), static_cast<u32>(Color::clrRec4));
		//C2D_DrawSprite(&sprites[localplayer.getSprite()].sprite);
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
