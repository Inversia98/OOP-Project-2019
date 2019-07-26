#ifndef MISC_OBJ_H
#define MISC_OBJ_H

#include "Weights.h"
#include "LTexture.h"
#ifdef __APPLE__
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#else
#include <SDL.h>
#include <SDL_image.h>
#endif


class Misc_obj: public Weights
{
public:
    Misc_obj();
    ~Misc_obj();
    virtual void render(SDL_Renderer* gRenderer);
    virtual void reduceWeight();
    virtual void addWegihtl();
};

#endif // MISC_OBJ_H
