#include <iostream>
#include <stdlib.h>
#include <strings.h>
#include <time.h>
#include <SDL2/SDL.h>
#include "LTexture.h"
#include "Load_Screen.h"
#include "Buttons.h"
#include "End_Screen.h"


using namespace std;

// Predefined Screen width and Height.
const int SCREEN_WIDTH = 1024;
const int SCREEN_HEIGHT = 600;

int main()
{
  Load_Screen* loadscreen = new Load_Screen(&gSpriteSheetTexturem, (float)SCREEN_WIDTH/2, (float)SCREEN_HEIGHT/2, &gSpriteSheetTexturew);
}
