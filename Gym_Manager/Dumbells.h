#ifndef DUMBELLS_H
#define DUMBELLS_H

#include "Ltexture.h"
#include "Weights.h"
#inclde <SDL2/SDL.h>

class Dumbells: public Weights, protected Weights
{
public:
    Weghts();
    ~Weights();
    void render(SDL_Renderer* gRenderer);
    void reduceWeight();
    void addWeight();



};

#endif // DUMBELLS_H
