#ifndef WEIGHT_STATION_H
#define WEIGHT_STATION_H

#include "LTexture.h"
#include <SDL2/SDL.h>

class Weight_Station
{
    public:
        Weight_Station();
        ~Weight_Station();
        virtual void Draw(LTexture* gRenderer);
        virtual int getNumberWeights();
        virtual void receiveWeight(Weights);

    protected:

    private:
        Weights weight;
        int currentWeight;
        int posX;
        int posY;
        int length;
        int width;
        SDL_Rect spriteclips;
        LTexture spritesheetTexture;
};

#endif // WEIGHT_STATION_H
