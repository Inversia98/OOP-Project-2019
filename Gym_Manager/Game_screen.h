#ifndef GAME_SCREEN_H
#define GAME_SCREEN_H

#include "LTexture.h"
#ifdef __APPLE__
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#else
#include <SDL.h>
#include <SDL_image.h>
#endif

class Game_screen
{
protected:
    float x;
    float y;
    int width;
    int height;

    SDL_Rect spriteClips[7];
    LTexture* spriteSheetTexture;

public:
    Game_screen();
    Game_screen(LTexture* image, float x, float y, LTexture*);
    virtual ~Game_screen();
    int GetWidth();
    int GetHeight();
    float GetX();
    float GetY();
    virtual void Render(long int& frame, SDL_Renderer* gRenderer, bool debug, SDL_Event& e, LTexture& gSpriteSheetTextureWorld, int& state);
};


#endif // GAME_SCREEN_H
