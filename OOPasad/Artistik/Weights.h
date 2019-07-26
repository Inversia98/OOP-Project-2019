#ifndef WEIGHTS_H
#define WEIGHTS_H

#include "LTexture.h"
#include <SDL.h>
#include <SDL_image.h>

class Weights
{
    public:
        Weights();
        virtual ~Weights();

    protected:
        int posX;
        int posY;
        int length;
        int width;
        SDL_Rect spriteclips;
        LTexture* spritesheetTexture;


    private:
};

#endif // WEIGHTS_H
