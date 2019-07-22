#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <iostream>
#include"LTexture.h"
#include "Word.h"

using namespace std;



class PauseMenu
{
    protected:
        float x;
        float y;
        int width;
        int height;
        Word resume;
        Word exit;
        Word save;

        enum ANIMATION_FRAMES {FLYING_FRAMES = 7};
        SDL_Rect spriteClips[ FLYING_FRAMES ];
        LTexture* spriteSheetTexture;

    public:
        PauseMenu(LTexture* image, float x, float y, LTexture*);
        PauseMenu();
        virtual ~PauseMenu();
        int GetWidth();
        int GetHeight();
        float GetX();
        float GetY();
        virtual void Render(long int& frame, SDL_Renderer* gRenderer, bool debug, SDL_Event& e, LTexture& gSpriteSheetTexturew, int& state);
};






