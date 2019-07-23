#ifndef CHARACTER_H
#define CHARACTER_H

#include "Ltexture.h"
#include <SDL2/SDL.h>

class Character
{
 private:
    Point position;
    int character_value;
    int width;
    int height;
    SDL_Rect spriteClips;
    Ltexture* spritesheetTexture;

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