#ifndef ROD_STATION_H
#define ROD_STATION_H

#include "LTexture.h"
#include <SDL2/SDL.h>

class Rod_Station
{
    public:
        Rod_Station();
        ~Rod_Station();
        void Draw(LTexture* gRenderer);
        int getNumberWeights();
        void receiveWeights(Weights);

    protected:

    private:
};

#endif // ROD_STATION_H
