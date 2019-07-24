#ifndef LOAD_SCREEN_H
#define LOAD_SCREEN_H

#include "LTexture.h"
#ifdef __APPLE__
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#else
#include <SDL.h>
#include <SDL_image.h>
#endif
#include "Buttons.h"

class Load_Screen
{
protected:
    float x;
    float y;
    int width;
    int height;
    Button Load1;
    Button Load2;
    Button Load3;
    Button Back;

    SDL_Rect spriteClips[7];
    LTexture* spriteSheetTexture;

public:
    Load_Screen();
    Load_Screen(LTexture* image, float x, float y, LTexture*);
    virtual ~Load_Screen();
    int GetWidth();
    int GetHeight();
    float GetX();
    float GetY();
    virtual void Render(long int& frame, SDL_Renderer* gRenderer, bool debug, SDL_Event& e, LTexture& gSpriteSheetTextureWorld, int& state);
};

#endif // LOAD_SCREEN_H
