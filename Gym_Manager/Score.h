#ifndef SCORE_H
#define SCORE_H

#include "LTexture.h"
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
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
