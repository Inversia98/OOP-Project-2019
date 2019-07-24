#ifndef SCORE_H
#define SCORE_H

<<<<<<< HEAD
#include "Ltexture.h"
#ifdef __APPLE__
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#else
#include <SDL.h>
#include <SDL_image.h>
#endif
=======
#include "LTexture.h"
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
>>>>>>> 09473ad891135b7388b5cc6f47b2b9e300a60d4f
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
