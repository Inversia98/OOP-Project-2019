#include"enemies.h"

enemies::enemies()
{

}

enemies::~enemies()
{
    cout<<"Enemy Deallocated"<<endl;
}

enemies::enemies(LTexture* image, float x, float y)
{
    spriteSheetTexture = image;


    //Frame 0
    for (int i = 0; i<6; i++)
    {
        spriteClips[i].x = i*55;
        spriteClips[i].y = 0;
        spriteClips[i].w = 55;
        spriteClips[i].h = 88;
    }
    speedx=-2;
    this->x=x;
    this->y=y;
    this->speedx=-2;
/*
    //Frame 1
    spriteClips[ 1 ].x = 512;
    spriteClips[ 1 ].y =   0;
    spriteClips[ 1 ].w = 128;
    spriteClips[ 1 ].h = 96;

    //Frame 2
    spriteClips[ 2 ].x = 640;
    spriteClips[ 2 ].y = 0;
    spriteClips[ 2 ].w = 128;
    spriteClips[ 2 ].h = 96;

    //Frame 0
    spriteClips[ 3 ].x = 384;
    spriteClips[ 3 ].y =   0;
    spriteClips[ 3 ].w = 128;
    spriteClips[ 3 ].h = 96;

    //Frame 1
    spriteClips[ 4 ].x = 512;
    spriteClips[ 4 ].y =   0;
    spriteClips[ 4 ].w = 128;
    spriteClips[ 4 ].h = 96;

    //Frame 2
    spriteClips[ 5 ].x = 640;
    spriteClips[ 5 ].y = 0;
    spriteClips[ 5 ].w = 128;
    spriteClips[ 5 ].h = 96;

    //Frame 0
    spriteClips[ 6 ].x = 384;
    spriteClips[ 6 ].y =   0;
    spriteClips[ 6 ].w = 128;
    spriteClips[ 6 ].h = 96;

    this->width = spriteClips[ 0 ].w;
    this->height = spriteClips[ 0 ].h;
*/
    ID = 3;
}


void enemies::Move()
{
     //speedx = speedx * friction;
     //speedy = speedy * friction;


     //x = x + 2; //speedy;
     /*if(x > 900)
     {
         SetAlive(false);
     }*/
     cout<<"Move function called"<<endl;


     if(x < 1024-20)
    {

        cout<<"Screen set to true"<<endl;
        inScreen=true;

     }




     if((x<=20))// || (x < )
    {

        speedx=-speedx;
        cout<<"Change direction"<<endl;

     }

     if(x>=(1024-20))
    {
          if(inScreen==true){
          speedx=-speedx;
          cout<<"Change direction"<<endl;
          }


     }



     x = x + speedx;
     cout<<"speedx"<<speedx<<endl;
     cout<<"x:"<<x<<endl;

}

void enemies::Render(long int& frame, SDL_Renderer* gRenderer, bool debug)
{
    if (frame % 3 == 0){
        a = frame % 5;
        //cout << "WAD" << endl;
    }
    spriteSheetTexture->Render( /*x- width/2 , y - height/2*/ x, y, &spriteClips[a], 0.0, NULL, SDL_FLIP_HORIZONTAL, gRenderer );
    if(debug == true)
    {
        SDL_Rect rect = { x - width/2, y - height/2, width, height };
        SDL_SetRenderDrawColor( gRenderer, 0xFF, 0x00, 0x00, 0xFF );
        SDL_RenderDrawRect( gRenderer, &rect );
    }
}

void enemies::Chase()
{

}

