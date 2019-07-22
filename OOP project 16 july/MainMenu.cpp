#include "MainMenu.h"
#include "Word.h"

MainMenu::MainMenu()
{

}

MainMenu::MainMenu(LTexture* image, float x, float y, LTexture* gSpriteSheetTexturew)
{
    spriteSheetTexture = image;


    //Frame 0
    spriteClips[ 0 ].x = 8;
    spriteClips[ 0 ].y = 507;
    spriteClips[ 0 ].w = 1240;
    spriteClips[ 0 ].h = 690;

    start = Word("Start Game", gSpriteSheetTexturew, 385, 200);
    quit = Word("Quit", gSpriteSheetTexturew, 455, 400);
    load = Word("Load", gSpriteSheetTexturew, 455, 300);

}


MainMenu::~MainMenu()
{
    spriteSheetTexture = NULL;
}


void MainMenu::Render(long int& frame, SDL_Renderer* gRenderer, bool debug, SDL_Event& e, LTexture& gSpriteSheetTexturew, int& state, int& kills)
{
    spriteSheetTexture->Render( x - width/2, y - height/2, &spriteClips[ 0 ], 0.0, NULL, SDL_FLIP_NONE, gRenderer );
    if(debug == true)
    {
        SDL_Rect rect = { x - width/2, y - height/2, width, height };
        SDL_SetRenderDrawColor( gRenderer, 0xFF, 0x00, 0x00, 0xFF );
        SDL_RenderDrawRect( gRenderer, &rect );
    }

    start.Render(gRenderer, debug);
    quit.Render(gRenderer, debug);
    load.Render(gRenderer, debug);
    int s = start.mouseEvents(e, gSpriteSheetTexturew, state);
    int q = quit.mouseEvents(e, gSpriteSheetTexturew, state);
    int l = load.mouseEvents(e, gSpriteSheetTexturew, state);

    if (s == 1)
    {
        state = 1;
        kills = 0;
    }
    else if (q == 1)
    {
        state = 2;
        exit(1);
    }
    else if (l == 1)
    {
        state = 3;
    }
}

int MainMenu::GetWidth()
{
    return width;
}

int MainMenu::GetHeight()
{
    return height;
}

float MainMenu::GetX()
{
    return x;
}
float MainMenu::GetY()
{
    return y;
}



