#ifndef DUMBELLS_H
#define DUMBELLS_H

#include "Ltexture.h"
#include "Weights.h"
#ifdef __APPLE__
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#else
#include <SDL.h>
#include <SDL_image.h>
#endif

class Dumbells: public Weights
{
public:
    Dumbells();
    ~Dumbells();
    void render(SDL_Renderer* gRenderer);
    void reduceWeight();
    void addWeight();



};

#endif // DUMBELLS_H
