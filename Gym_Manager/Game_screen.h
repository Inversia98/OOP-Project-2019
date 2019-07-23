#ifndef GAME_SCREEN_H
#define GAME_SCREEN_H

#include "Ltexture.h"
#include <SDL2/SDL.h>

class Game_screen
{
protected:
    float x;
    float y;
    int width;
    int height;

    SDL_Rect spriteClips[FLYING_FRAMES];
    LTexture* spriteSheetTexture;

public:
    Game_screen();
    Game_screen(LTexture* image, float x, float y, LTexture*)
    virtual ~Game_screen();
    int GetWidth();
    int GetHeight();
    float GetX();
    float GetY();
    virtual void Render(long int& frame, SDL_Renderer* gRenderer, bool debug, SDL_Event& e, LTexture& gSpriteSheetTextureWorld, int& state);
};


#endif // GAME_SCREEN_H
