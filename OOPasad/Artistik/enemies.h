#pragma once

#include"gameobject.h"
#include "Unit.h"

class enemies:public gameobject
{
public:
    enemies(LTexture* image, float x, float y);
    enemies();
    virtual ~enemies();
    virtual void Render(long int& frame, SDL_Renderer* gRenderer, bool debug);


    private:

    bool inScreen=false;

    protected:
        int frameCheck = 0;

};

