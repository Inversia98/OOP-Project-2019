#ifndef CHARACTER_H
#define CHARACTER_H

<<<<<<< HEAD
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
=======
#include "LTexture.h"
#include "Point.h"
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
>>>>>>> 09473ad891135b7388b5cc6f47b2b9e300a60d4f

class Character
{
 private:
    Point position;
    int character_value;
    int width;
    int height;
    SDL_Rect spriteClips;
<<<<<<< HEAD
    LTexture* spritesheetTexture;
=======
    LTexture* spriteSheetTexture;
>>>>>>> 09473ad891135b7388b5cc6f47b2b9e300a60d4f

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
