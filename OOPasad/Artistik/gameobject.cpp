#include "gameobject.h"

gameobject::gameobject()
{

}

gameobject::~gameobject()
{
    spriteSheetTexture = NULL;
}


void gameobject::Move(int direction)
{

     if(direction==LEFT)
    {
        speedx = -3;
        x+=speedx;

    }

    if(direction==RIGHT)
    {
        speedx = 3;
        x+=speedx;
    }

    if(direction==UP)
    {
        speedy = -8;
        y+=speedy;

    }

    if(direction==DOWN)
    {
        speedy = 17;
        y+=speedy;
    }

}



void gameobject::Move()
{

    speedx = speedx * friction;
    speedy = speedy * friction;


     x = x + speedx;
     y = y + speedy;
     cout<<"GameObject Move"<<endl;





}




void gameobject::Render(long int& frame, SDL_Renderer* gRenderer, bool debug)
{

    spriteSheetTexture->Render( x - width/2, y - height/2, &spriteClips[0], 0.0, NULL, SDL_FLIP_NONE, gRenderer );
    if(debug == true)
    {
        SDL_Rect rect = { x - width/2, y - height/2, width, height };
        SDL_SetRenderDrawColor( gRenderer, 0xFF, 0x00, 0x00, 0xFF );
        SDL_RenderDrawRect( gRenderer, &rect );
    }
}


int gameobject::GetWidth()
{
    return width;
}

int gameobject::GetHeight()
{
    return height;
}

float gameobject::GetX()
{
    return x;
}
float gameobject::GetY()
{
    return y;
}

int gameobject::GetID()
{
    return ID;
}

void gameobject::SetAlive(bool alive)
{
    this->alive = alive;
}

bool gameobject::GetAlive()
{
    return alive;
}



