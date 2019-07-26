#include "PauseMenu.h"
#include "Word.h"

PauseMenu::PauseMenu()
{

}

PauseMenu::PauseMenu(LTexture* image, float x, float y, LTexture* gSpriteSheetTexturew)
{
    spriteSheetTexture = image;


    //Frame 0
    spriteClips[ 0 ].x = 8;
    spriteClips[ 0 ].y = 507;
    spriteClips[ 0 ].w = 1240;
    spriteClips[ 0 ].h = 690;

    resume = Word("Resume", gSpriteSheetTexturew, 455, 200);
    exit = Word("Exit", gSpriteSheetTexturew, 455, 500);
    save = Word("Save", gSpriteSheetTexturew, 455, 300);

}


PauseMenu::~PauseMenu()
{
    spriteSheetTexture = NULL;
}


void PauseMenu::Render(long int& frame, SDL_Renderer* gRenderer, bool debug, SDL_Event& e, LTexture& gSpriteSheetTexturew, int& state)
{
    spriteSheetTexture->Render( x - width/2, y - height/2, &spriteClips[ 0 ], 0.0, NULL, SDL_FLIP_NONE, gRenderer );
    if(debug == true)
    {
        SDL_Rect rect = { x - width/2, y - height/2, width, height };
        SDL_SetRenderDrawColor( gRenderer, 0xFF, 0x00, 0x00, 0xFF );
        SDL_RenderDrawRect( gRenderer, &rect );
    }

    resume.Render(gRenderer, debug);
    exit.Render(gRenderer, debug);
    save.Render(gRenderer, debug);

    int r = resume.mouseEvents(e, gSpriteSheetTexturew, state);
    int ex = exit.mouseEvents(e, gSpriteSheetTexturew, state);
    int s = save.mouseEvents(e, gSpriteSheetTexturew, state);

    if (r == 1)
    {
        state = 1;
//        std::cout<<"IN"<<std::endl;

    }
    else if (ex == 1)
    {
        state = 0;
    }
//    else if (l3 == 1)
//    {
//        state = 3;
//        exit(1);
//    }
//    cout<<state<<endl;
}

int PauseMenu::GetWidth()
{
    return width;
}

int PauseMenu::GetHeight()
{
    return height;
}

float PauseMenu::GetX()
{
    return x;
}
float PauseMenu::GetY()
{
    return y;
}





