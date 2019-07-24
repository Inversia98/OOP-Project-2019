#ifndef GYM_USER_H
#define GYM_USER_H

#include "LTexture.h"
#include <SDL2/SDL.h>

class Gym_User
{
private:
    bool isActive;
    int currentWeights;
    int length;
    int width;
    SDL_Rect spriteclips;
    LTexture* spritesheetTexture;

public:
    Gym_User();
    ~Gym_User();
    void render(LTexture* gRenderer);
    void pickWeights();
    void dropWeights();
};

#endif // GYM_USER_H
