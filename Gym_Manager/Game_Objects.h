#ifndef GAME_OBJECTS_H
#define GAME_OBJECTS_H

#include "LTexture.h"
#ifdef __APPLE__
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#else
#include <SDL.h>
#include <SDL_image.h>
#endif

class Game_objects
{
private:
    int posX;
    int posY;
    int length;
    int width;
    SDL_Rect spriteclips;
    LTexture* spritesheetTexture;

public:
    Game_objects();
    Game_objects(LTexture* image, int x, int y);
    ~Game_objects();
    void update();
    void render(SDL_Renderer* gRenderer);
};



#endif
