#ifndef SCORE_H
#define SCORE_H

#include "Ltexture.h"
#include <SDL2/SDL.h>
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
