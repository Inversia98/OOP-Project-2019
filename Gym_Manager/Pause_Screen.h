#ifndef PAUSE_SCREEN_H_INCLUDED
#define PAUSE_SCREEN_H_INCLUDED

#include "LTexture.h"
#include <SDL2/SDL.h>
#include "Buttons.h"

class Pause_Screen
{
protected:
    float x;
    float y;
    int width;
    int height;
    Button resume;
    Button save;
    Button exit;

    SDL_Rect spriteClips[FLYING_FRAMES];
    LTexture* spriteSheetTexture;

public:
    Pause_Screen();
    Pause_Screen(LTexture* image, float x, float y, LTexture*);
    virtual ~Pause_Screen();
    int GetWidth();
    int GetHeight();
    float GetX();
    float GetY();
    virtual void Render(long int& frame, SDL_Renderer* gRenderer, bool debug, SDL_Event& e, LTexture& gSpriteSheetTextureWorld, int& state);
};

#endif
