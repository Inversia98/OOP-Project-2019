#ifndef WEIGHTS_H
#define WEIGHTS_H

<<<<<<< HEAD
#include "Ltexture.h"
#ifdef __APPLE__
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#else
#include <SDL.h>
#include <SDL_image.h>
#endif
=======
#include "LTexture.h"
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
>>>>>>> 09473ad891135b7388b5cc6f47b2b9e300a60d4f

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
