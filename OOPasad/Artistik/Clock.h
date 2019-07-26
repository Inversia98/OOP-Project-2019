#pragma once
#include "Word.h"
#include "string.h"
#include"LTexture.h"
#include <cstdlib>
#include <cstdio>
#include <ctime>

using namespace std;

class Clock
{
public:
    Clock();
    Clock(int&);
    int getSeconds();
    void virtual Render(SDL_Renderer* gRenderer, LTexture*);

private:
    int count = 300000;
    int seconds;
    Word clock;
};

