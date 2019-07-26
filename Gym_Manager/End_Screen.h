#ifndef END_SCREEN_H
#define END_SCREEN_H

#include "LTexture.h"
#include "Buttons.h"
#include "Score.h"

#ifdef __APPLE__
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#else
#include <SDL.h>
#include <SDL_image.h>
#endif

#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>


class End_Screen
{
protected:

    float x;
    float y;
    int width;
    int height;
    Button score;
    Score points;

<<<<<<< HEAD
    SDL_Rect spriteClips[FLYING_FRAMES];
=======
>>>>>>> b8fe3a2ef6a92e29328b0b8c83a591b933e9cda7
    LTexture* spriteSheetTexture;

public:
    End_Screen();
    End_Screen(LTexture* image, float x, float y, LTexture*);
    virtual ~End_Screen();
    int GetWidth();
    int GetHeight();
    float GetX();
    float GetY();
    virtual void Render(long int& frame, SDL_Renderer* gRenderer, bool debug, SDL_Event& e, LTexture& gSpriteSheetTextureWorld, int& state);

};

#endif // END_SCREEN_H
