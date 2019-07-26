#include "Score.h"
#include <string>
#include <sstream>

using namespace std;

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
   ostringstream str1;
   str1 << kills;
   string numKills = (str1.str());
   score = Word(numKills, image, 300, 50);
   cout<<"numKills "<<numKills <<endl;
   score.Render(gRenderer, false);
}

void Score::setKills()
{
    kills = 0;
}
