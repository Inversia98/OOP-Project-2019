#ifndef DUMBELL_STATION_H
#define DUMBELL_STATION_H

#include "Ltexture.h"
#include "Weights.h"
#ifdef __APPLE__
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#else
#include <SDL.h>
#include <SDL_image.h>
#endif

class Dumbell_Station
{
    public:
        Dumbell_Station();
        ~Dumbell_Station();
        void Draw(LTexture* gRenderer);
        int getNumberWeights();
        void receiveWeight(Weights);

    protected:

    private:
};

#endif // DUMBELL_STATION_H
