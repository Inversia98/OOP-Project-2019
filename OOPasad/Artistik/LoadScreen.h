#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <iostream>
#include"LTexture.h"
#include "Word.h"

using namespace std;



class LoadScreen
{
    protected:
        float x;
        float y;
        int width;
        int height;
        Word load1;
        Word load2;
        Word load3;
        Word Back;

        enum ANIMATION_FRAMES {FLYING_FRAMES = 7};
        SDL_Rect spriteClips[ FLYING_FRAMES ];
        LTexture* spriteSheetTexture;

    public:
        LoadScreen(LTexture* image, float x, float y, LTexture*);
        LoadScreen();
        virtual ~LoadScreen();
        int GetWidth();
        int GetHeight();
        float GetX();
        float GetY();
        virtual void Render(long int& frame, SDL_Renderer* gRenderer, bool debug, SDL_Event& e, LTexture& gSpriteSheetTexturew, int& state);
};





