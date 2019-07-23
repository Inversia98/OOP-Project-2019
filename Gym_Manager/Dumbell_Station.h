#ifndef DUMBELL_STATION_H
#define DUMBELL_STATION_H

#include "Ltexture.h"
#include <SDL2/SDL.h>

class Dumbell_Station
{
    public:
        Dumbell_Station();
        ~Dumbell_Station();
        void Draw(Ltexture* gRenderer);
        int getNumberWeights();
        void receiveWeight(Weights);

    protected:

    private:
};

#endif // DUMBELL_STATION_H
