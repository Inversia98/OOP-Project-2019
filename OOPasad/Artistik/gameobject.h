#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <iostream>
#include"LTexture.h"

using namespace std;


enum MOTION {RIGHT, LEFT, UP, DOWN};

class gameobject
{
    protected:
        bool alive;
        float x;
        float y;
        float speedx;
        float speedy;
        int width;
        int height;
        int ID;
        int clip;
        float friction; //lower speed means more friction

        enum ANIMATION_FRAMES {FLYING_FRAMES = 7};
        SDL_Rect spriteClips[ 7 ];
        SDL_Rect spriteClips1[ 6 ];
        LTexture* spriteSheetTexture;

    public:
       // Unit(LTexture* image, float x, float y);
        gameobject();
        virtual ~gameobject();
        void SetAlive(bool);
        bool GetAlive();
        int GetWidth();
        int GetHeight();
        float GetX();
        float GetY();
        int GetID();
        virtual void Move(int direction);
        virtual void Move();
        virtual void Render(long int& frame, SDL_Renderer* gRenderer, bool debug);
       // virtual void Render1(long int& frame, SDL_Renderer* gRenderer, bool debug);
};

