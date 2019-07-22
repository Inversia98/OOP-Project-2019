#include "LoadScreen.h"
#include "Word.h"

LoadScreen::LoadScreen()
{

}

LoadScreen::LoadScreen(LTexture* image, float x, float y, LTexture* gSpriteSheetTexturew)
{
    spriteSheetTexture = image;


    //Frame 0
    spriteClips[ 0 ].x = 8;
    spriteClips[ 0 ].y = 507;
    spriteClips[ 0 ].w = 1240;
    spriteClips[ 0 ].h = 690;

    load1 = Word("load 1", gSpriteSheetTexturew, 455, 200);
    load2 = Word("load 2", gSpriteSheetTexturew, 455, 300);
    load3 = Word("load 3", gSpriteSheetTexturew, 455, 400);
    Back = Word("Back", gSpriteSheetTexturew, 0, 550);

}


LoadScreen::~LoadScreen()
{
    spriteSheetTexture = NULL;
}


void LoadScreen::Render(long int& frame, SDL_Renderer* gRenderer, bool debug, SDL_Event& e, LTexture& gSpriteSheetTexturew, int& state)
{
    spriteSheetTexture->Render( x - width/2, y - height/2, &spriteClips[ 0 ], 0.0, NULL, SDL_FLIP_NONE, gRenderer );
    if(debug == true)
    {
        SDL_Rect rect = { x - width/2, y - height/2, width, height };
        SDL_SetRenderDrawColor( gRenderer, 0xFF, 0x00, 0x00, 0xFF );
        SDL_RenderDrawRect( gRenderer, &rect );
    }

    load1.Render(gRenderer, debug);
    load2.Render(gRenderer, debug);
    load3.Render(gRenderer, debug);
    Back.Render(gRenderer, debug);
    int l1 = load1.mouseEvents(e, gSpriteSheetTexturew, state);
    int l2 = load2.mouseEvents(e, gSpriteSheetTexturew, state);
    int l3 = load3.mouseEvents(e, gSpriteSheetTexturew, state);
    int b = Back.mouseEvents(e, gSpriteSheetTexturew, state);

    if (b == 1)
    {
        state = 0;
//        std::cout<<"IN"<<std::endl;

    }
//    else if (l2 == 1)
//    {
//        state = 2;
//        exit(1);
//    }
//    else if (l3 == 1)
//    {
//        state = 3;
//        exit(1);
//    }
//    cout<<state<<endl;
}

int LoadScreen::GetWidth()
{
    return width;
}

int LoadScreen::GetHeight()
{
    return height;
}

float LoadScreen::GetX()
{
    return x;
}
float LoadScreen::GetY()
{
    return y;
}




