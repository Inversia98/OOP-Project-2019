#ifndef BUTTONS_H
#define BUTTONS_H


#pragma once
#include "Character.h"
#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <iostream>
#include "LTexture.h"
#include "Point.h"

class Character;

class Button
{
public:
    Button();                                                         //Constructor
    Button(std::string String, LTexture* image, float, float);        //Overloaded constructor
    ~Button();                                                        //Destructor for dynamic Character Array
    int getLength();                                                //function for getting string length
    Character* getArray();                                          //Function to access array outside class
    void Render(SDL_Renderer* gRenderer, bool debug);
    int mouseEvents(SDL_Event&, LTexture&, int&);
    int getX();
    int getY();
private:
    int x,y;
    std::string button;                                               //String Button
    int stringLength;                                               //length of Button
    Character* characterArray;                                      //Dynamic character array
};



#endif // BUTTONS_H
