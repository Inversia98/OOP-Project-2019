#include "SplashScreen.h"
#include "Word.h"

SplashScreen::SplashScreen()
{

}

SplashScreen::SplashScreen(LTexture* image, float x, float y, LTexture* gSpriteSheetTexturew)
{
    spriteSheetTexture = image;


    //Frame 0
    spriteClips[ 0 ].x = 0;
    spriteClips[ 0 ].y = 0;
    spriteClips[ 0 ].w = 1024;
    spriteClips[ 0 ].h = 600;



}


SplashScreen::~SplashScreen()
{
    spriteSheetTexture = NULL;
}


void SplashScreen::Render(long int& frame, SDL_Renderer* gRenderer, bool debug, SDL_Event& e, LTexture& gSpriteSheetTexturew, int& state)
{
    spriteSheetTexture->Render( x - width/2, y - height/2, &spriteClips[ 0 ], 0.0, NULL, SDL_FLIP_NONE, gRenderer );
    if(debug == true)
    {
        SDL_Rect rect = { x - width/2, y - height/2, width, height };
        SDL_SetRenderDrawColor( gRenderer, 0xFF, 0x00, 0x00, 0xFF );
        SDL_RenderDrawRect( gRenderer, &rect );
    }
}

int SplashScreen::GetWidth()
{
    return width;
}

int SplashScreen::GetHeight()
{
    return height;
}

float SplashScreen::GetX()
{
    return x;
}
float SplashScreen::GetY()
{
    return y;
}






