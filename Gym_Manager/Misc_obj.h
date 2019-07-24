#ifndef MISC_OBJ_H
#define MISC_OBJ_H

#include "Weights.h"
#include "LTexture.h"
#include <SDL2/SDL.h>

class Misc_obj: public Weights, protected Weights
{
public:
    Misc_obj();
    ~Misc_obj();
    virtual void render(SDL_Renderer* gRenderer);
    virtual void reduceWeight();
    virtual void addWegihtl();
};

#endif // MISC_OBJ_H
