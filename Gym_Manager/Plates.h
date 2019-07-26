#ifndef PLATES_H
#define PLATES_H

#include "LTexture.h"
#ifdef __APPLE__
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#else
#include <SDL.h>
#include <SDL_image.h>
#endif
#include "Weights.h"

class Plates: public Weights
{
public:
   Plates();
   ~Plates();
   virtual void render(SDL_Renderer* gRenderer);
   virtual void reduceWeight();
   virtual void addWegihtl();
};

#endif // PLATES_H
