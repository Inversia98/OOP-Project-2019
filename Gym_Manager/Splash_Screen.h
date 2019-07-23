#ifndef SPLASH_SCREEN_H
#define SPLASH_SCREEN_H

#include "Ltexture.h"
#include <SDL2/SDL.h>
#include "Buttons.h"

class Splash_Screen
{
protected:
    float x;
    float y;
    int width;
    int height;
    Button title;

    SDL_Rect spriteClips[FLYING_FRAMES];
    LTexture* spriteSheetTexture;

public:
    Splash_Screen();
    Splash_Screen(LTexture* image, float x, float y, Ltexture*);
    virtual ~Splash_Screen();
    int GetWidth();
    int GetHeight();
    float GetX();
    float GetY();
    virtual void Render(long int& frame, SDL_Renderer* gRenderer, bool debug, SDL_Event& e, LTexture& gSpriteSheetTextureWorld, int& state);

};
