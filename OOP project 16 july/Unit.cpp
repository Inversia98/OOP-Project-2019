#include "Unit.h"

Unit::Unit()
{

}

Unit::Unit(LTexture* image, float x, float y)
{
    spriteSheetTexture = image;


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

    for (int i = 0; i<6; i++)
        {
            spriteClips[i].x = i*60;
            spriteClips[i].y = 90;
            spriteClips[i].w = 60;
            spriteClips[i].h = 90;
        }

    for (int i = 0; i<6; i++)
    {
        spriteClips1[i].x = i*55;
        spriteClips1[i].y = 0;
        spriteClips1[i].w = 55;
        spriteClips1[i].h = 88;
    }

    for (int i = 0; i<6; i++)
        {
            spriteClips2[i].x = i*55;
            spriteClips2[i].y = 0;
            spriteClips2[i].w = 55;
            spriteClips2[i].h = 88;
        }
    for (int i = 0; i<6; i++)
        {
            spriteClips3[i].x = i*60;
            spriteClips3[i].y = 90;
            spriteClips3[i].w = 60;
            spriteClips3[i].h = 90;
        }

// for (int i = 0; i<6; i++)
//    {
//        spriteClips1[i].x = i*60;
//        spriteClips1[i].y = 90;
//        spriteClips1[i].w = 105;
//        spriteClips1[i].h = 100;
//    }




    this->x = x;
    this->y = y;

    this->width = spriteClips[ 0 ].w;
    this->height = spriteClips[ 0 ].h;

    friction = 0.85f;
    speedx = 0;
    speedy = 0;
    alive  = true;

    ID = 1;
}


Unit::~Unit()
{
    spriteSheetTexture = NULL;
}



//void Unit::Move(int direction)
//{
//
//    if(direction==LEFT)
//    {
//        speedx = -3;
//        x+=speedx;
//
//    }
//
//    if(direction==RIGHT)
//    {
//        speedx = 3;
//        x+=speedx;
//    }
//
//    if(direction==UP)
//    {
//        speedy = -8;
//        y+=speedy;
//
//    }
//
//    if(direction==DOWN)
//    {
//        speedy = 17;
//        y+=speedy;
//    }
//
//}
//
////void Unit::
//
//void Unit::Move()
//{
//    //if (x > 100&& x < 1024)
//    //{
//    speedx = speedx * friction;
//     speedy = speedy * friction;
//
//     x = x + speedx;
//     y = y + speedy;
////     cout<<"Unit Move"<<endl;
//    //}
//
//
//
//
//}

void Unit::Render(long int& frame, SDL_Renderer* gRenderer, bool debug)
{
//    p++;
    if (frame % 3 == 0){
        p = frame % 5;
        //cout << "WAD" << endl;
    }

    spriteSheetTexture->Render( x - width/2, y - height/2, &spriteClips[p], 0.0, NULL, SDL_FLIP_NONE, gRenderer );
    if(debug == true)
    {
        SDL_Rect rect = { x - width/2, y - height/2, width, height };
        SDL_SetRenderDrawColor( gRenderer, 0xFF, 0x00, 0x00, 0xFF );
        SDL_RenderDrawRect( gRenderer, &rect );
    }
//    cout<<"Space Render"<<endl;
}

void Unit::Render1(long int& frame, SDL_Renderer* gRenderer, bool debug)
{
//    p++;
    if (frame % 3 == 0){
        q = frame % 5;
        //cout << "WAD" << endl;
    }
    //cout << this->speedx << endl;
    spriteSheetTexture->Render( x - width/2, y - height/2, &spriteClips1[q], 0.0, NULL, SDL_FLIP_NONE, gRenderer );
    if(debug == true)
    {
        SDL_Rect rect = { x - width/2, y - height/2, width, height };
        SDL_SetRenderDrawColor( gRenderer, 0xFF, 0x00, 0x00, 0xFF );
        SDL_RenderDrawRect( gRenderer, &rect );
    }
    cout<<"Right Render"<<endl;
}

void Unit::Render2(long int& frame, SDL_Renderer* gRenderer, bool debug)
{
//    p++;
    if (frame % 3 == 0){
        q = frame % 5;
        //cout << "WAD" << endl;
    }
   // cout << this->speedx << endl;
    spriteSheetTexture->Render( x - width/2, y - height/2, &spriteClips1[q], 0.0, NULL, SDL_FLIP_HORIZONTAL, gRenderer );
    if(debug == true)
    {
        SDL_Rect rect = { x - width/2, y - height/2, width, height };
        SDL_SetRenderDrawColor( gRenderer, 0xFF, 0x00, 0x00, 0xFF );
        SDL_RenderDrawRect( gRenderer, &rect );
    }
    cout<<"Left Render"<<endl;
}

void Unit::Render3(long int& frame, SDL_Renderer* gRenderer, bool debug)
{
//    p++;
    if (frame % 3 == 0){
        s = frame % 5;
        //cout << "WAD" << endl;
    }
   // cout << this->speedx << endl;
    spriteSheetTexture->Render( x - width/2, y - height/2, &spriteClips2[s], 0.0, NULL, SDL_FLIP_HORIZONTAL, gRenderer );
    if(debug == true)
    {
        SDL_Rect rect = { x - width/2, y - height/2, width, height };
        SDL_SetRenderDrawColor( gRenderer, 0xFF, 0x00, 0x00, 0xFF );
        SDL_RenderDrawRect( gRenderer, &rect );
    }
    //cout<<"Idle Render"<<endl;
}

void Unit::Render4(long int& frame, SDL_Renderer* gRenderer, bool debug)
{
//    p++;
    if (frame % 3 == 0){
        b = frame % 5;
        //cout << "WAD" << endl;
    }
   // cout << this->speedx << endl;
    spriteSheetTexture->Render( x - width/2, y - height/2, &spriteClips3[b], 0.0, NULL, SDL_FLIP_HORIZONTAL, gRenderer );
    if(debug == true)
    {
        SDL_Rect rect = { x - width/2, y - height/2, width, height };
        SDL_SetRenderDrawColor( gRenderer, 0xFF, 0x00, 0x00, 0xFF );
        SDL_RenderDrawRect( gRenderer, &rect );
    }
    //cout<<"Idle Render"<<endl;
}

void Unit::jump()
{
    int i=0;
    this->Move(UP);
    //this->Render(frame,R,false);

    while(i<100){i=i+1;}
    this->Move(DOWN);

    //this->Move(DOWN);

    //this->Render(frame,R,false);
}
void Unit::reset()
{
    x = (float)52; y = (float)545;
}






