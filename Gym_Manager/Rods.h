#ifndef RODS_H
#define RODS_H

#include "Weights.h"
#include "LTexture.h"
#include <SDL2/SDL.h>

class Rods: public Weights, protected Weights
{
   public:
   Weights();
   ~Weights();
   virtual void render(SDL_Renderer* gRenderer);
   virtual void reduceWeight();
   virtual void addWegihtl();
};

#endif // RODS_H
