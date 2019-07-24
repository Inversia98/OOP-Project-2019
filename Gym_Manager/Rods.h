#ifndef RODS_H
#define RODS_H

#include "Weights.h"
#include "LTexture.h"
#ifdef __APPLE__
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#else
#include <SDL.h>
#include <SDL_image.h>
#endif

class Rods: public Weights
{
   public:
       Rods();
       ~Rods();
//   Weights();
//   ~Weights();
   virtual void render(SDL_Renderer* gRenderer);
   virtual void reduceWeight();
   virtual void addWegihtl();
};

#endif // RODS_H
