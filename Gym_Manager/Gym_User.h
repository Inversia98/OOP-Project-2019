#ifndef GYM_USER_H
#define GYM_USER_H

#include "LTexture.h"
#ifdef __APPLE__
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#else
#include <SDL.h>
#include <SDL_image.h>
#endif

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
