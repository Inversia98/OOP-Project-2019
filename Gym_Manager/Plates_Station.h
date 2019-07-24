#ifndef PLATES_STATION_H
#define PLATES_STATION_H

#include "LTexture.h"
#include <SDL2/SDL.h>

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
