#ifndef PLATES_H
#define PLATES_H

#include "Ltexture.h"
#include <SDL2/SDL.h>
#include "Weights.h"

class Plates: public Weights, protected Weights
{
public:
   Weights();
   ~Weights();
   virtual void render(SDL_Renderer* gRenderer);
   virtual void reduceWeight();
   virtual void addWegihtl();
};

#endif // PLATES_H
