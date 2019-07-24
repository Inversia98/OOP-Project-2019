#ifndef MAIN_SCREEN_H
#define MAIN_SCREEN_H


#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <iostream>
#include "LTexture.h"
#include "Buttons.h"

using namespace std;



class Main_Screen
{
    protected:
        float x;
        float y;
        int width;
        int height;
        Button start;
        Button load;
        Button quit;

        SDL_Rect spriteClips[FLYING_FRAMES];
        LTexture* spriteSheetTexture;

    public:
        Main_Screen(LTexture* image, float x, float y, LTexture*);
        Main_Screen();
        virtual ~Main_Screen();
        int GetWidth();
        int GetHeight();
        float GetX();
        float GetY();
        virtual void Render(long int& frame, SDL_Renderer* gRenderer, bool debug, SDL_Event& e, LTexture& gSpriteSheetTextureWorld, int& state);


#endif // MAIN_SCREEN_H
