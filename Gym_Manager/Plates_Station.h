#ifndef PLATES_STATION_H
#define PLATES_STATION_H

#include "LTexture.h"
#include "Weights.h"
#ifdef __APPLE__
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#else
#include <SDL.h>
#include <SDL_image.h>
#endif

class Plates_Station
{
    public:
        Plates_Station();
        ~Plates_Station();
        void Draw(LTexture* gRenderer);
        int getNumberWeights();
        void receiveWeight(Weights);

    protected:

    private:
};

#endif // PLATES_STATION_H
