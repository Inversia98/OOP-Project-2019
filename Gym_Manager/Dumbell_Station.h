#ifndef DUMBELL_STATION_H
#define DUMBELL_STATION_H

#include "LTexture.h"
#include "Weights.h"
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>

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
