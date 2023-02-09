#include <3ds.h>
#include <citro2d.h>
#include <stdlib.h>
#include <iostream>
#include <assert.h>
#include <time.h>


#define SCREEN_WIDTH  320
#define SCREEN_HEIGHT 240

consoleInit(GFX_TOP, NULL);
int main(int argc, char** argv)
{
	romfsInit();
	gfxInitDefault();

	// Main loop
	while (aptMainLoop())
	{
		//Scan all the inputs. This should be done once for each frame
		hidScanInput();
		consoleClear();
	

		if (kDown & KEY_START) break; // break in order to return to hbmenu

		// Print a string to the console
		printf("Hello, world!\n");

		// Flush and swap framebuffers
		gfxFlushBuffers();
		gfxSwapBuffers();

		//Wait for VBlank
		gspWaitForVBlank();
	}

	onClose();

	gfxExit();
	romfsExit();
	return 0;
}