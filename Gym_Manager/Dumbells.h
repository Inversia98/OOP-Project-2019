#ifndef DUMBELLS_H
#define DUMBELLS_H

#include "LTexture.h"
#include "Weights.h"
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>

class Dumbells: public Weights
{
public:
//    Weights();
//    ~Weights();
    void render(SDL_Renderer* gRenderer);
    void reduceWeight();
    void addWeight();

};

#endif // DUMBELLS_H
