#include "Buttons.h"

#include <iostream>
#include "Buttons.h"
#include"LTexture.h"

Button::Button()
{

}

Button::Button(std::string String, LTexture* image, float x, float y)       //Button class overloaded constructor which contains the
{                                                                       //string being displayed, image, and the x y coordinates
    this->x = x;
    this->y = y;
    button = String;                                                      //string is stored in Button attribute
    characterArray = new Character[button.length()];                      //a dynamic array is declared of size of the Button
    for (int i = 0;(unsigned) i < button.length(); i++)                   //a loop is set to load all char as character types
    {                                                                   //within the array
        characterArray[i] = Character(image,(x + (i * 30)), y, button[i]);        //we also create spacing so that letters dont
    }                                                                           //coincide

}

Button::~Button()       //Destructor
{
    delete characterArray;              //deallocating memory
}

void Button::Render(SDL_Renderer* gRenderer, bool debug)              //Render function for Button type
{
    for (int i = 0; (unsigned) i < button.length(); i++)              //at each itteration 1 character is rendered
    {
        characterArray[i].Render(gRenderer, debug);
    }
}

int Button::mouseEvents(SDL_Event& e, LTexture& gSpriteSheetTexturew, int &state)
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

int Button::getLength()                           //Get length of string Button
{
    return button.length();
}


Character* Button::getArray()                     //to access character outside class
{
    return characterArray;
}

int Button::getX()
{
    return x;
}

int Button::getY()
{
    return y;
}



