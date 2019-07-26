#include "Main_Screen.h"
#include "Buttons.h"
#include "LTexture.h"
#ifdef __APPLE__
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#else
#include <SDL.h>
#include <SDL_image.h>
#endif



//Main_Screen::Main_Screen(LTexture* image, float x, float y, LTexture* gSpriteSheetTexturew)
//{
//    spriteSheetTexture = image;
//
//
//    //Frame 0
//    spriteClips[ 0 ].x = 8;
//    spriteClips[ 0 ].y = 507;
//    spriteClips[ 0 ].w = 1240;
//    spriteClips[ 0 ].h = 690;
//
//    start = Word("Start Game", gSpriteSheetTexturew, 385, 200);
//    quit = Word("Quit", gSpriteSheetTexturew, 455, 400);
//    load = Word("Load", gSpriteSheetTexturew, 455, 300);
//
//}
//
//
//Main_Screen::~Main_Screen()
//{
//    spriteSheetTexture = NULL;
//}
//
//
//void Main_Screen::Render(long int& frame, SDL_Renderer* gRenderer, bool debug, SDL_Event& e, LTexture& gSpriteSheetTexturew, int& state, int& kills)
//{
//    spriteSheetTexture->Render( x - width/2, y - height/2, &spriteClips[ 0 ], 0.0, NULL, SDL_FLIP_NONE, gRenderer );
//    if(debug == true)
//    {
//        SDL_Rect rect = { x - width/2, y - height/2, width, height };
//        SDL_SetRenderDrawColor( gRenderer, 0xFF, 0x00, 0x00, 0xFF );
//        SDL_RenderDrawRect( gRenderer, &rect );
//    }
//
//    start.Render(gRenderer, debug);
//    quit.Render(gRenderer, debug);
//    load.Render(gRenderer, debug);
//    int s = start.mouseEvents(e, gSpriteSheetTexturew, state);
//    int q = quit.mouseEvents(e, gSpriteSheetTexturew, state);
//    int l = load.mouseEvents(e, gSpriteSheetTexturew, state);
//
//    if (s == 1)
//    {
//        state = 1;
//        kills = 0;
//    }
//    else if (q == 1)
//    {
//        state = 2;
//        exit(1);
//    }
//    else if (l == 1)
//    {
//        state = 3;
//    }
//}
//
//int Main_Screen::GetWidth()
//{
//    return width;
//}
//
//int Main_Screen::GetHeight()
//{
//    return height;
//}
//
//float Main_Screen::GetX()
//{
//    return x;
//}
//float Main_Screen::GetY()
//{
//    return y;
//}



