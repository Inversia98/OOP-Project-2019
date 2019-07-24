#ifndef CHARACTER_H
#define CHARACTER_H

#include "Ltexture.h"
#include "Buttons.h"
#include "Point.h"
#ifdef __APPLE__
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#else
#include <SDL.h>
#include <SDL_image.h>
#endif

class Button;

using namespace std;

class Character
{
 private:
    Point position;
    int character_value;
    int width;
    int height;
    SDL_Rect spriteClips;
    LTexture* spritesheetTexture;

 public:

     Character();
     Character(LTexture* image, float x, float y, char Char);
     virtual ~Character();
     virtual void Render(SDL_Renderer* gRenderer, bool debug);
     void SetPosition(Point&);
     void SetPosition(int, int);
     int GetFrameWidth();
     int GetFrameHeight();
     void valueChecker();


};

#endif // CHARACTER_H
