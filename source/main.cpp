#include <3ds.h>
#include <citro2d.h>
#include <stdlib.h>
#include <iostream>
#include <assert.h>
#include <time.h>
#include <cstdio>
#include "player.hpp"

#define SCREEN_WIDTH  320
#define SCREEN_HEIGHT 240


#define MAX_SPRITES 8


typedef struct {
	C2D_Sprite sprite;
} Sprite;

static C2D_SpriteSheet spriteSheet;
static Sprite sprites[MAX_SPRITES];

// Declaring the prototype for initSprites, the function that will initialize the sprites
static void initSprites();

int main(int argc, char** argv)
{
	gfxInitDefault();
	consoleInit(GFX_TOP, NULL);

	C3D_Init(C3D_DEFAULT_CMDBUF_SIZE);
	//Initialize citro2d and sets max objects
	C2D_Init(C2D_DEFAULT_MAX_OBJECTS);
	//Prepares the GPU for rendering 2D content
	C2D_Prepare();
	C3D_RenderTarget* top = C2D_CreateScreenTarget(GFX_BOTTOM, GFX_LEFT);

	Player localplayer(1,1,1,1,1);

	localplayer.setX(2);



	spriteSheet = C2D_SpriteSheetLoad("romfs:/gfx/sprites.t3x");

	if(!spriteSheet){
		printf("Failed to load spritesheet\n");
		svcBreak(USERBREAK_PANIC);
	}

	initSprites();

	C2D_Sprite spaceship = sprites[4].sprite;
	float x = 100.0f;
    float y = 100.0f;
    int width = 64;
    int height = 64;


	// Main loop
	while (aptMainLoop())
	{
		//Scan all the inputs. This should be done once for each frame
		hidScanInput();
		
		u32 kDown = hidKeysDown();
		if (kDown & KEY_START) break; // break in order to return to hbmenu

		if (kDown & KEY_B){
			localplayer.setX(4);
		}

		// Print a string to the console
		printf("Localplayer X: %f\n", localplayer.getX());


		//START RENDERING
		C3D_FrameBegin(C3D_FRAME_SYNCDRAW);
		C2D_TargetClear(top, C2D_Color32(0, 0, 0, 0));
		C2D_DrawSprite(&spaceship);

		C3D_FrameEnd(0);
		// Flush and swap framebuffers
		gfxFlushBuffers();
		gfxSwapBuffers();

		//Wait for VBlank
		gspWaitForVBlank();
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

	}



}
