#include"Background.h"

Background::Background()
{

}

Background::~Background()
{
    cout<<"Enemy Deallocated"<<endl;
}

Background::Background(LTexture* image, float x, float y)
{
    spriteSheetTexture = image;


    //Frame 0
    spriteClips[ 0 ].x = 0;
    spriteClips[ 0 ].y = 0;
    spriteClips[ 0 ].w = 1400;
    spriteClips[ 0 ].h = 800;

    this->width = spriteClips[ 0 ].w;
    this->height = spriteClips[ 0 ].h;

    ID = 3;
}




void Background::Render(long int& frame, SDL_Renderer* gRenderer, bool debug)
{
    spriteSheetTexture->Render( x- width/5 , y - height/5, &spriteClips[0], 0.0, NULL, SDL_FLIP_NONE, gRenderer );
    if(debug == true)
    {
        SDL_Rect rect = { x - width/2, y - height/2, width, height };
        SDL_SetRenderDrawColor( gRenderer, 0xFF, 0x00, 0x00, 0xFF );
        SDL_RenderDrawRect( gRenderer, &rect );
    }
}
