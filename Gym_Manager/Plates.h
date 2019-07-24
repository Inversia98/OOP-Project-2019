#ifndef PLATES_H
#define PLATES_H

#include "LTexture.h"
#include <SDL2/SDL.h>
#include "Weights.h"

class Plates: public Weights, protected Weights
{
public:
   Plates();
   ~Plates();
   virtual void render(SDL_Renderer* gRenderer);
   virtual void reduceWeight();
   virtual void addWegihtl();
};

#endif // PLATES_H
