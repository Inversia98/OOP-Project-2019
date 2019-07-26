#pragma once
#include "Word.h"
#include "string.h"
#include"LTexture.h"
#include <cstdlib>

using namespace std;

class Score
{
public:
    Score();
    Score(int&);
    void scoreIncrease();
    void virtual Render(SDL_Renderer* gRenderer, LTexture*);
    void setKills();

private:
    int kills;
    Word score;
};

