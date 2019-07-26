#include"Explosion.h"

Explosion::Explosion()
{

}

Explosion::~Explosion()
{
    cout<<"Explosion Deallocated"<<endl;
}

Explosion::Explosion(LTexture* image, float x, float y):Unit(image, x, y)
{
    spriteSheetTexture = image;
/*

    //Frame 0
    spriteClips[ 0 ].x = 2;
    spriteClips[ 0 ].y = 131;
    spriteClips[ 0 ].w = 41;
    spriteClips[ 0 ].h = 41;

    //Frame 1
    spriteClips[ 1 ].x = 39;
    spriteClips[ 1 ].y = 131;
    spriteClips[ 1 ].w = 41;
    spriteClips[ 1 ].h = 41;

    //Frame 2
    spriteClips[ 2 ].x = 76;
    spriteClips[ 2 ].y = 131;
    spriteClips[ 2 ].w = 41;
    spriteClips[ 2 ].h = 41;

    //Frame 3
    spriteClips[ 3 ].x = 116;
    spriteClips[ 3 ].y = 131;
    spriteClips[ 3 ].w = 41;
    spriteClips[ 3 ].h = 41;

    //Frame 4
    spriteClips[ 4 ].x = 157;
    spriteClips[ 4 ].y = 131;
    spriteClips[ 4 ].w = 41;
    spriteClips[ 4 ].h = 41;

    //Frame 5
    spriteClips[ 5 ].x = 196;
    spriteClips[ 5 ].y = 131;
    spriteClips[ 5 ].w = 41;
    spriteClips[ 5 ].h = 41;

    //Frame 6
    spriteClips[ 6 ].x = 236;
    spriteClips[ 6 ].y = 131;
    spriteClips[ 6 ].w = 41;
    spriteClips[ 6 ].h = 41;

    this->width = spriteClips[ 0 ].w;
    this->height = spriteClips[ 0 ].h;
*/
    ID = 4;
}

void Explosion::Render(long int& frame, SDL_Renderer* gRenderer, bool debug)
{
    spriteSheetTexture->Render( x- width/2 , y - height/2, &spriteClips[ frame % FLYING_FRAMES ], 0.0, NULL, SDL_FLIP_VERTICAL, gRenderer );
    if(debug == true)
    {
        SDL_Rect rect = { x - width/2, y - height/2, width, height };
        SDL_SetRenderDrawColor( gRenderer, 0xFF, 0x00, 0x00, 0xFF );
        SDL_RenderDrawRect( gRenderer, &rect );
    }
}


