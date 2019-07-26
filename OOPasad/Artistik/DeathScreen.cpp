#include "DeathScreen.h"
#include "Word.h"

DeathScreen::DeathScreen()
{

}

DeathScreen::DeathScreen(LTexture* image, float x, float y, LTexture* gSpriteSheetTexturew, int& kills)
{
    spriteSheetTexture = image;

    //Frame 0
    spriteClips[ 0 ].x = 0;
    spriteClips[ 0 ].y = 0;
    spriteClips[ 0 ].w = 1024;
    spriteClips[ 0 ].h = 600;

    textScore = Word("Score", gSpriteSheetTexturew, 455, 200);
    //points = Score(kills);
}


DeathScreen::~DeathScreen()
{
    spriteSheetTexture = NULL;
}


void DeathScreen::Render(long int& frame, SDL_Renderer* gRenderer, bool debug, SDL_Event& e, LTexture& gSpriteSheetTexturew, int& state)
{
    //points = Word("207", gSpriteSheetTexturew, 455, 300);

    spriteSheetTexture->Render( x - width/2, y - height/2, &spriteClips[ 0 ], 0.0, NULL, SDL_FLIP_NONE, gRenderer );
    if(debug == true)
    {
        SDL_Rect rect = { x - width/2, y - height/2, width, height };
        SDL_SetRenderDrawColor( gRenderer, 0xFF, 0x00, 0x00, 0xFF );
        SDL_RenderDrawRect( gRenderer, &rect );
    }

    textScore.Render(gRenderer, debug);
    //points.Render(gRenderer, &gSpriteSheetTexturew);

}

int DeathScreen::GetWidth()
{
    return width;
}

int DeathScreen::GetHeight()
{
    return height;
}

float DeathScreen::GetX()
{
    return x;
}
float DeathScreen::GetY()
{
    return y;
}





