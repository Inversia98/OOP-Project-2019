#pragma once
#include <SDL_image.h>
#include <stdio.h>
#include <iostream>
#include"LTexture.h"
#include "gameobject.h"
using namespace std;

//#include"Unit.h"

class Background:public gameobject
{
public:
    Background(LTexture* image, float x, float y);
    Background();
    virtual ~Background();
    //virtual void Move();
    virtual void Render(long int& frame, SDL_Renderer* gRenderer, bool debug);
};

