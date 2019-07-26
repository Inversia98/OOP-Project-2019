#include <iostream>
#include "Word.h"
#include"LTexture.h"

Word::Word()
{

}

Word::Word(std::string String, LTexture* image, float x, float y)       //Word class overloaded constructor which contains the
{                                                                       //string being displayed, image, and the x y coordinates
    this->x = x;
    this->y = y;
    word = String;                                                      //string is stored in word attribute
    characterArray = new Character[word.length()];                      //a dynamic array is declared of size of the word
    for (int i = 0;(unsigned) i < word.length(); i++)                   //a loop is set to load all char as character types
    {                                                                   //within the array
        characterArray[i] = Character(image,(x + (i * 30)), y, word[i]);        //we also create spacing so that letters dont
    }                                                                           //coincide

}

Word::~Word()       //Destructor
{
    delete characterArray;              //deallocating memory
}

void Word::Render(SDL_Renderer* gRenderer, bool debug)              //Render function for word type
{
    for (int i = 0; (unsigned) i < word.length(); i++)              //at each itteration 1 character is rendered
    {
        characterArray[i].Render(gRenderer, debug);
    }
}

int Word::mouseEvents(SDL_Event& e, LTexture& gSpriteSheetTexturew, int &state)
{
    //Event handler that takes care of all events

    bool mouseClicked = false;
//    SDL_Rect fillRect;
    int oldx = 0;
    int oldy = 0;


        if( e.type == SDL_MOUSEMOTION || e.type == SDL_MOUSEBUTTONDOWN || e.type == SDL_MOUSEBUTTONUP )
        {
            //Get mouse position

            int xc, yc;
            SDL_GetMouseState( &xc, &yc );



            if(e.type ==  SDL_MOUSEMOTION)
            {
                if ((((oldx > (this->getX()) - 28) && (oldx < (this->getLength()) * 22 + (this->getX())) + 28) || ((xc > (this->getX()) - 28) && (xc < (this->getLength()) * 22 + (this->getX()) + 28))) && (((oldy > (this->getY()) - 28) && (oldy < (this->getY()) + 24)) || ((yc > (this->getY()) - 28) && (yc < (this->getY()) + 24))))
                {
                    gSpriteSheetTexturew.SetColor( 0xFF, 0, 0 );
                    //std::cout<<"HELLO"<<std::endl;
                }
                else if (!((((oldx > (this->getX()) - 28) && (oldx < (this->getLength()) * 22 + (this->getX())) + 28) || ((xc > (this->getX()) - 28) && (xc < (this->getLength()) * 22 + (this->getX()) + 28))) && (((oldy > (this->getY()) - 28) && (oldy < (this->getY()) + 24)) || ((yc > (this->getY()) - 28) && (yc < (this->getY()) + 24)))))
                {
                    gSpriteSheetTexturew.SetColor( 0xFF, 0xFF, 0xFF );

                }

            }
            if(e.type == SDL_MOUSEBUTTONDOWN)
            {

                if (e.button.button == SDL_BUTTON_LEFT)
                {
                    if(mouseClicked == false)
                    {




                        mouseClicked = true;
                        oldx = xc;
                        oldy = yc;
                        //std::cout<<oldx << " " << oldy<<std::endl;
                        //std::cout<<xc << " " << yc<<std::endl;
                        return false;

                    }
                }
            }
            if(e.type == SDL_MOUSEBUTTONUP)
            {
                if (e.button.button == SDL_BUTTON_LEFT)
                {
                    if ((((oldx > (this->getX()) - 28) && (oldx < (this->getLength()) * 22 + (this->getX())) + 28) || ((xc > (this->getX()) - 28) && (xc < (this->getLength()) * 22 + (this->getX()) + 28))) && (((oldy > (this->getY()) - 28) && (oldy < (this->getY()) + 24)) || ((yc > (this->getY()) - 28) && (yc < (this->getY()) + 24))))
                    {

                        //std::cout<<"HI"<<std::endl;
                        return 1;



                    }
                }
            }
        }
    }
//}

int Word::getLength()                           //Get length of string word
{
    return word.length();
}


Character* Word::getArray()                     //to access character outside class
{
    return characterArray;
}

int Word::getX()
{
    return x;
}

int Word::getY()
{
    return y;
}


