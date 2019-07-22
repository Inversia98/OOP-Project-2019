#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <iostream>
#include"LTexture.h"
#include"Point.h"

class Character
{
public:
    Character();                                                //Constructor
    Character(LTexture* image, float x, float y, char Char);    //Overloaded constructor with coords and the char we want to display
    virtual ~Character();                                               //Destructor
    virtual void Render(SDL_Renderer* gRenderer, bool debug);   //Render function for Character type
    void SetPosition(Point&);                                   //Position setter with position type argument
    void SetPosition(int, int);                                 //Position setter with int type arguments
    int GetFrameWidth();                                        //Returns frame width
    int GetFrameHeight();                                       //Returns frame height
    void valueChecker();                                        //This checks the ascii value of a char and sets the sprite clips
private:
    Point position;                                 //position of rendering
    int character_value;                            //Ascii value
    int width;
    int height;
    SDL_Rect spriteClips;                           //Sprite clips to renders
    LTexture* spriteSheetTexture;
};

