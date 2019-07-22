#include "gameobject.h"

gameobject::gameobject()
{

}

//Unit::Unit(LTexture* image, float x, float y)
//{
  //  spriteSheetTexture = image;


    //Frame 0
//    spriteClips[ 0 ].x =   0;
//    spriteClips[ 0 ].y =   0;
//    spriteClips[ 0 ].w = 55;
//    spriteClips[ 0 ].h = 88;
//
//    spriteClips[ 1 ].x =   55;
//    spriteClips[ 1 ].y =   0;
//    spriteClips[ 1 ].w = 55;
//    spriteClips[ 1 ].h = 88;

//    for (int i = 0; i<6; i++)
//        {
//            spriteClips[i].x = i*60;
//            spriteClips[i].y = 90;
//            spriteClips[i].w = 60;
//            spriteClips[i].h = 90;
//        }
//
//    for (int i = 0; i<6; i++)
//    {
//        spriteClips1[i].x = i*55;
//        spriteClips1[i].y = 0;
//        spriteClips1[i].w = 55;
//        spriteClips1[i].h = 88;
//    }


// for (int i = 0; i<6; i++)
//    {
//        spriteClips1[i].x = i*60;
//        spriteClips1[i].y = 90;
//        spriteClips1[i].w = 105;
//        spriteClips1[i].h = 100;
//    }




//    this->x = x;
//    this->y = y;
//
//    this->width = spriteClips[ 0 ].w;
//    this->height = spriteClips[ 0 ].h;
//
//    friction = 0.85f;
//    speedx = 0;
//    speedy = 0;
//    alive  = true;
//
//    ID = 1;
//}


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

//void Unit::

void gameobject::Move()
{
    //if (x > 100&& x < 1024)
    //{
    speedx = speedx * friction;
    speedy = speedy * friction;


     x = x + speedx;
     y = y + speedy;
     cout<<"GameObject Move"<<endl;
    //}




}




void gameobject::Render(long int& frame, SDL_Renderer* gRenderer, bool debug)
{
//    p++;
    spriteSheetTexture->Render( x - width/2, y - height/2, &spriteClips[p], 0.0, NULL, SDL_FLIP_NONE, gRenderer );
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



