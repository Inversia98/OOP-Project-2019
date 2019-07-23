#ifndef WEIGHTS_H
#define WEIGHTS_H

#include "Ltexture.h"
#include <SDL2/SDL.h>

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
