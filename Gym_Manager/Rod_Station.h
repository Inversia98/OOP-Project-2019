#ifndef ROD_STATION_H
#define ROD_STATION_H

#include "LTexture.h"
#include "Weights.h"
#ifdef __APPLE__
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#else
#include <SDL.h>
#include <SDL_image.h>
#endif

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
