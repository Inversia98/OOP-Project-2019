#ifndef WEIGHTS_H
#define WEIGHTS_H

#include "LTexture.h"
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>

class Weights
{
protected:
    int posX;
    int posY;
    int length;
    int width;
    SDL_Rect spriteclips;
    LTexture* spritesheetTexture;

public:
    Weights();
    ~Weights();
    virtual void reduceWeight();
    virtual void addWight();
};

#endif // WEIGHTS_H
