#include "Clock.h"
#include <string>
#include <sstream>

using namespace std;

Clock::Clock()
{

}

Clock::Clock(int& killed)
{

}


void Clock::Render(SDL_Renderer* gRenderer, LTexture* image)
{

   count--;
   ostringstream str1;
   this->seconds = count / 60;
   str1 << (this->seconds);
   string seconds = (str1.str());
   clock = Word(seconds, image, 500, 50);
   clock.Render(gRenderer, false);
}

int Clock::getSeconds()
{
    return this->seconds;
}

