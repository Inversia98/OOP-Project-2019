#pragma once

#include"Unit.h"

class Explosion :public Unit
{
public:
    Explosion(LTexture* image, float x, float y);
    Explosion();
    virtual ~Explosion();
    virtual void Render(long int& frame, SDL_Renderer* gRenderer, bool debug);
};

