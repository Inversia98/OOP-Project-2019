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

    for (int i = 0; i<6; i++)
    {
        spriteClips[i].x = i*55;
        spriteClips[i].y = 0;
        spriteClips[i].w = 55;
        spriteClips[i].h = 88;
    }

    this->x=x;
    this->y=y;


    ID = 3;
}


void enemies::Render(long int& frame, SDL_Renderer* gRenderer, bool debug)
{
    if (frame % 3 == 0){
        frameCheck = frame % 5;

    }
    spriteSheetTexture->Render(x, y, &spriteClips[frameCheck], 0.0, NULL, SDL_FLIP_HORIZONTAL, gRenderer );
    if(debug == true)
    {
        SDL_Rect rect = { x - width/2, y - height/2, width, height };
        SDL_SetRenderDrawColor( gRenderer, 0xFF, 0x00, 0x00, 0xFF );
        SDL_RenderDrawRect( gRenderer, &rect );
    }
}


