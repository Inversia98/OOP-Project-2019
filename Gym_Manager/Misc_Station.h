#ifndef MISC_STATION_H
#define MISC_STATION_H

#include "LTexture.h"
#include "Weights.h"
#ifdef __APPLE__
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#else
#include <SDL.h>
#include <SDL_image.h>
#endif

class Misc_Station
{
    public:
        Misc_Station();
        ~Misc_Station();
        void Draw(LTexture* gRenderer);
        int getNumberWeights();
        void receiveWeight(Weights);


    protected:

    private:
};

#endif // MISC_STATION_H
