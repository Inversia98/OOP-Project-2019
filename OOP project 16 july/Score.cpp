#include "Score.h"

Score::Score()
{

}

Score::Score(int& killed)
{
    kills = killed;
}

void Score::scoreIncrease()
{
    kills++;
}

void Score::Render(SDL_Renderer* gRenderer, LTexture* image)
{
   std::string numKills = to_string (kills);
   score = Word(numKills, image, 300, 50);
   cout<<"numKills "<<numKills <<endl;
   score.Render(gRenderer, false);
}

void Score::setKills()
{
    kills = 0;
}
