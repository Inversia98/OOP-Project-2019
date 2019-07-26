#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <iostream>
#include"LTexture.h"
#include "gameobject.h"
using namespace std;




class Unit:public gameobject
{
    protected:
        bool alive;
        float speedx = 2;
        float speedy = 2 ;
        int width;
        int height;
        int ID;
        int clip;
        float friction;
        int frameCheck1 = 0;
        int frameCheck2 = 0;
        int frameCheck3 = 0;
        int frameCheck4 = 0;
        int frameCheck5 = 0;
        float gravity = 0.0006;



        enum ANIMATION_FRAMES {FLYING_FRAMES = 7};
        SDL_Rect spriteClips[ 7 ];
        SDL_Rect spriteClips1[ 6 ];
        SDL_Rect spriteClips2[ 6 ];
        SDL_Rect spriteClips3[ 6 ];
        SDL_Rect spriteClips4[ 6 ];
        LTexture* spriteSheetTexture;

    public:
        int AttackCount;
        Unit(LTexture* image, float x, float y);
        Unit();
        void reset();
        ~Unit();
        int GetID();
        void Render(long int& frame, SDL_Renderer* gRenderer, bool debug);
        void Render1(long int& frame, SDL_Renderer* gRenderer, bool debug);
        void Render2(long int& frame, SDL_Renderer* gRenderer, bool debug);
        void Render3(long int& frame, SDL_Renderer* gRenderer, bool debug);
        void Render4(long int& frame, SDL_Renderer* gRenderer, bool debug);
        void Render5(long int& frame, SDL_Renderer* gRenderer, bool debug);
        void jump();
};



