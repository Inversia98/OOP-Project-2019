#pragma once
#include "Character.h"
#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <iostream>
#include "LTexture.h"
#include"Point.h"
#include "Character.h"

class Word
{
public:
    Word();                                                         //Constructor
    Word(std::string String, LTexture* image, float, float);        //Overloaded constructor
    ~Word();                                                        //Destructor for dynamic Character Array
    int getLength();                                                //function for getting string length
    Character* getArray();                                          //Function to access array outside class
    void Render(SDL_Renderer* gRenderer, bool debug);
    int mouseEvents(SDL_Event&, LTexture&, int&);
    int getX();
    int getY();
private:
    int x,y;
    std::string word;                                               //String word
    int stringLength;                                               //length of word
    Character* characterArray;                                      //Dynamic character array
};

