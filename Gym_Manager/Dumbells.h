#ifndef DUMBELLS_H
#define DUMBELLS_H

#include "LTexture.h"
#include "Weights.h"

#ifdef __APPLE__
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#else
#include <SDL.h>
#include <SDL_image.h>
#endif

#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>


class Dumbells: public Weights
{
public:

    Dumbells();
    ~Dumbells();

//    Weights();
//    ~Weights();



    void render(SDL_Renderer* gRenderer);
    void reduceWeight();
    void addWeight();

};

#endif // DUMBELLS_H
