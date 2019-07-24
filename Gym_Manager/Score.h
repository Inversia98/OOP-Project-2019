#ifndef SCORE_H
#define SCORE_H

#include "Ltexture.h"
#ifdef __APPLE__
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#else
#include <SDL.h>
#include <SDL_image.h>
#endif
#include "Buttons.h"

class Score
{
private:
    int points;
    Button score;

public:
    Score();
    void scoreIncrease();
    void render(SDL_Renderer* gRenderer);
    void setPoint();
};

#endif // SCORE_H
