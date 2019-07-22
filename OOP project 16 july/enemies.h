#pragma once

#include"gameobject.h"
#include "Unit.h"

class enemies:public gameobject
{
public:
    enemies(LTexture* image, float x, float y);
    enemies();
    virtual ~enemies();
    virtual void Move();
    virtual void Render(long int& frame, SDL_Renderer* gRenderer, bool debug);
    void Chase();


    private:

    bool inScreen=false;

    protected:
        int a = 0;

};

