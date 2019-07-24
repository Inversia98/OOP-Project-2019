#include "Load_Screen.h"
#ifdef __APPLE__
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#else
#include <SDL.h>
#include <SDL_image.h>
#endif
#include"LTexture.h"

Load_Screen::Load_Screen()
{
    //ctor
}

Load_Screen::~Load_Screen()
{
    spriteSheetTexture = NULL;
}

Load_Screen:: Load_Screen(LTexture* image, float x, float y, LTexture*)
{
    spriteSheetTexture = image;

    spriteClips[0].x = 8;
    spriteClips[0].y = 507;
    spriteClips[0].w = 1240;
    spriteClips[0].h = 690;

    Load1 = Button("Load 1", spriteSheetTexture, 455,200);
    Load2 = Button("Load 2", spriteSheetTexture, 455,200);
    Load3 = Button("Load 3", spriteSheetTexture, 455,200);
    Back = Button("Back", spriteSheetTexture, 0,550);



}

int Load_Screen::GetHeight()
{
    return height;
}

int Load_Screen::GetWidth()
{
    return width;
}

float Load_Screen::GetX()
{
    return x;
}

float Load_Screen::GetY()
{
    return y;
}

void Load_Screen::Render(long int& frame, SDL_Renderer* gRenderer, bool debug, SDL_Event& e, LTexture& gSpriteSheetTextureWorld, int& state)
{
    spriteSheetTexture -> Render(x - width/2, y - height/2, &spriteClips[0],0.0,NULL,SDL_FLIP_NONE, gRenderer);
    if(debug == true)
    {
        SDL_Rect rect = {x - width/2, y - height/2, width, height};
        SDL_SetRenderDrawColor(gRenderer, 0xFF, 0x00, 0x00, 0xFF);
        SDL_RenderDrawRect(gRenderer, &rect);
    }

    Load1.Render(gRenderer, debug);
    Load2.Render(gRenderer, debug);
    Load3.Render(gRenderer, debug);
    Back.Render(gRenderer, debug);

    int l1 = Load1.mouseEvents(e, gSpriteSheetTextureWorld, state);
    int l2 = Load2.mouseEvents(e, gSpriteSheetTextureWorld, state);
    int l3 = Load3.mouseEvents(e, gSpriteSheetTextureWorld, state);
    int b = Back.mouseEvents(e, gSpriteSheetTextureWorld, state);

    if (b == 1)
    {
        state = 0;
    }
}
