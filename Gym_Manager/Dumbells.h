#ifndef DUMBELLS_H
#define DUMBELLS_H

#include "LTexture.h"
#include "Weights.h"
<<<<<<< HEAD
#ifdef __APPLE__
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#else
#include <SDL.h>
#include <SDL_image.h>
#endif
=======
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
>>>>>>> 09473ad891135b7388b5cc6f47b2b9e300a60d4f

class Dumbells: public Weights
{
public:
<<<<<<< HEAD
    Dumbells();
    ~Dumbells();
=======
//    Weights();
//    ~Weights();
    Dumbells();
    ~Dumbells();

>>>>>>> 09473ad891135b7388b5cc6f47b2b9e300a60d4f
    void render(SDL_Renderer* gRenderer);
    void reduceWeight();
    void addWeight();

};

#endif // DUMBELLS_H
