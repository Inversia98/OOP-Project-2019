#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <iostream>
#include"LTexture.h"
#include "gameobject.h"
using namespace std;


//enum MOTION {RIGHT, LEFT, UP, DOWN};

class Unit:public gameobject
{
    protected:
        bool alive;
        //float x;
        //float y;
        float speedx = 2;
        float speedy = 2 ;
        int width;
        int height;
        int ID;
        int clip;
        float friction; //lower speed means more friction
        int p = 0;
        int q = 0;
        int s =0;
        int b=0;
        float gravity = 0.0006;

        enum ANIMATION_FRAMES {FLYING_FRAMES = 7};
        SDL_Rect spriteClips[ 7 ];
        SDL_Rect spriteClips1[ 6 ];
        SDL_Rect spriteClips2[ 6 ];
        SDL_Rect spriteClips3[ 6 ];
        LTexture* spriteSheetTexture;

    public:
        Unit(LTexture* image, float x, float y);
        Unit();
        void reset();
        virtual ~Unit();
        //void SetAlive(bool);
        //bool GetAlive();
        //int GetWidth();
        //int GetHeight();
        //float GetX();
        //float GetY();
        int GetID();
         //void Move(int direction);
         //void Move();
        virtual void Render(long int& frame, SDL_Renderer* gRenderer, bool debug);
        virtual void Render1(long int& frame, SDL_Renderer* gRenderer, bool debug);
        virtual void Render2(long int& frame, SDL_Renderer* gRenderer, bool debug);
        virtual void Render3(long int& frame, SDL_Renderer* gRenderer, bool debug);
        virtual void Render4(long int& frame, SDL_Renderer* gRenderer, bool debug);
        void jump();
};



