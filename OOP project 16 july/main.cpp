#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "windows.h"
#include "LTexture.h"
#include "Queue.h"
#include "Unit.h"
#include "Background.h"
#include "gameobject.h"
#include "Word.h"
#include "Character.h"
#include "MainMenu.h"
#include "LoadScreen.h"
#include "PauseMenu.h"
#include "SplashScreen.h"
#include "enemies.h"
#include "Health.h"
#include "Score.h"
#include "DeathScreen.h"

using namespace std;

//Pre defined screen width and height
const int SCREEN_WIDTH = 1024;
const int SCREEN_HEIGHT = 600;

bool init();

bool loadMedia();

void close();

SDL_Window* gWindow = NULL;

SDL_Renderer* gRenderer = NULL;

LTexture gSpriteSheetTexture;
LTexture gSpriteSheetTexture1;
LTexture gSpriteSheetTexturew;
LTexture gSpriteSheetTexturem;
LTexture gSpriteSheetTextureSplash;
LTexture gSpriteSheetTexture2;
LTexture gSpriteSheetTextureDeath;

bool init();
bool loadMedia();
void close();
bool spaceBar=false;
int spacebarDetected=0;

int main( int argc, char* args[] )
{

    int s = -1;
    int& state = s;
    int k = 0;
    int& kills = k;
    //Start up SDL and create window
    if( !init() )
    {

        printf( "Failed to initialize!\n" );
    }
    else
    {
        //Load media
        if( !loadMedia() )
        {
            printf( "Failed to load media!\n" );
        }
        else
        {

            bool quit = false;                      //Main loop flag

            SDL_Event e;                            //Event handler

            long int frame = 0;                     //Current animation frame
//            int bulletDelay = 0;

            cout<<"before"<<endl;
            MainMenu* background = new MainMenu(&gSpriteSheetTexturem, (float)SCREEN_WIDTH/2, (float)SCREEN_HEIGHT/2, &gSpriteSheetTexturew);
            LoadScreen* loadscreen = new LoadScreen(&gSpriteSheetTexturem, (float)SCREEN_WIDTH/2, (float)SCREEN_HEIGHT/2, &gSpriteSheetTexturew);
            PauseMenu* pauseMenu = new PauseMenu(&gSpriteSheetTexturem, (float)SCREEN_WIDTH/2, (float)SCREEN_HEIGHT/2, &gSpriteSheetTexturew);
            SplashScreen* splash = new SplashScreen(&gSpriteSheetTextureSplash, (float)SCREEN_WIDTH/2, (float)SCREEN_HEIGHT/2, &gSpriteSheetTexturew);
            DeathScreen* death = new DeathScreen(&gSpriteSheetTextureDeath, (float)SCREEN_WIDTH/2, (float)SCREEN_HEIGHT/2, &gSpriteSheetTexturew, kills);
            Health health;
            Score score(kills);
            cout<<"after"<<endl;
            /* initialize random seed: */
            srand (time(NULL));

            /* generate secret number between 1 and 10: */
            int random = 0;

            Queue objectList(&gSpriteSheetTexturew);
//            gameobject* ptr = NULL;
            Unit* hero = new Unit(&gSpriteSheetTexture, (float)52, (float)545);
            Background* ptr2 = new Background(&gSpriteSheetTexture1, 0, 0);
            enemies* enemy = NULL;

            //objectList.Enqueue(hero);

            int leftright = 0;
            int tmp = 0;
            int noenemies = tmp;
            bool phasingright=true;

            while( !quit )                          //While application is running
            {
                if(frame%60 == 0)
                {
                    if(noenemies<3)
                    {
                        random = 1 + rand() % 4;//SCREEN_WIDTH;
                        enemy = new enemies(&gSpriteSheetTexture2, 1200/*50 + (rand() % 900)*/,510);
                        objectList.Enqueue(enemy);
                        noenemies=noenemies+1;
                        objectList.Render(frame, gRenderer, false);
                    }
                }
                while( SDL_PollEvent( &e ) != 0 )   //Handle events on queue
                {



                    //User requests quit
                    if( e.type == SDL_QUIT )
                    {
                        quit = true;
                    }


                }
                frame++;

                if (state == -2)
                {
                    SDL_RenderClear( gRenderer );
                    score.Render(gRenderer, &gSpriteSheetTexturew);
                    death->Render(frame, gRenderer, false, e, gSpriteSheetTexturew, kills);
                    SDL_RenderPresent(gRenderer);
                    //score.Render(gRenderer, &gSpriteSheetTexturew);
                    SDL_Delay(3000);
                    objectList.QueueDelete();
                    health.setHealth();
                    noenemies = 0;
                    score.setKills();
                    state = 0;

                }

                if (state == -1)
                {
                    SDL_RenderClear( gRenderer );
                    splash->Render(frame, gRenderer, false, e, gSpriteSheetTexturew, state);
                    SDL_RenderPresent(gRenderer);
                    SDL_Delay(3000);
                    state = 0;

                }

                if (state == 0)
                {
                    SDL_RenderClear( gRenderer );
                    background->Render(frame, gRenderer, false, e, gSpriteSheetTexturew, state, kills);
                    cout<< "kill:"<<kills<<endl;
                }

                if (state == 3)
                {
                    SDL_RenderClear( gRenderer );
                    loadscreen->Render(frame, gRenderer, false, e, gSpriteSheetTexturew, state);
                }

                if (state == 4)
                {
                    //SDL_RenderClear( gRenderer );
                    pauseMenu->Render(frame, gRenderer, false, e, gSpriteSheetTexturew, state);
                    if (state == 0)
                    {
                        objectList.QueueDelete();
                        score.setKills();
                        kills = 0;
                        noenemies = 0;
                    }
                }

                if (state == 1)
                {
                    ptr2->Render(frame,gRenderer,false);
                    const Uint8* currentKeyStates = SDL_GetKeyboardState( NULL );
                    health.Render(gRenderer);
                    score.Render(gRenderer, &gSpriteSheetTexturew);

                    if (health.getHealth() == 0)
                    {
                        state = -2;
                    }

                    if(currentKeyStates[ SDL_SCANCODE_RIGHT ] && hero->GetY()>=545)
                    {


                        if(hero->GetX() < SCREEN_WIDTH-20)
                        {

                            hero->Move(RIGHT);
                            phasingright=true;
                            //objectList.Render(frame, gRenderer, false);
                            leftright = 0;
                            //cout<<"moving right"<<endl;
                            //cout<<"x:"<<hero->GetX()<<endl;
                            //cout<<"MOVE"<<endl;
                        }

                    }

                    else if(currentKeyStates[ SDL_SCANCODE_LEFT ] && hero->GetY()>=545)
                    {
                        //std::cout << hero->GetX()<<std::endl;
                        if(hero->GetX()>20)
                        {
                            hero->Move(LEFT);
                            leftright = 1;
                            phasingright=false;
                        }
                    }

                    else if((currentKeyStates[ SDL_SCANCODE_SPACE  ] && spacebarDetected<=18 ))
                    {
                        spacebarDetected++;
                        hero->Move(UP);




                        //cout<<"Space Bar is pressed"<<endl;


                    }





                    else
                    {
//
                        if(hero->GetY()<545)
                        {

                            hero->Move(DOWN);

                        }

                        if(hero->GetY()>=545)
                        {

                            spacebarDetected=0;


                        }


                        leftright= 3;
                    }

                    Word pause("PAUSE", &gSpriteSheetTexturew, 50, 50);
                    int p = pause.mouseEvents(e, gSpriteSheetTexturew, state);
                    pause.Render(gRenderer, false);
                    if (p == 1)
                    {
                        state = 4;
                    }


                    if (leftright == 0)
                        hero->Render1(frame, gRenderer, false);
                    if (leftright == 1)
                        hero->Render2(frame, gRenderer, false);
                    if (leftright == 3 && phasingright)
                    {
                        hero->Render(frame,gRenderer,false);
                    }
                    if (leftright == 3 && !phasingright)
                    {
                        hero->Render4(frame,gRenderer,false);
                    }



                if (objectList.getHead() != NULL)
                {
                    objectList.personAttack(hero, currentKeyStates, score, e, noenemies);
                    objectList.enemyAttack(hero, health);
                    objectList.Collision(hero);
                    objectList.Render(frame, gRenderer, false);
                    //objectList.Move();
                }
                }

                //SDL_RenderClear( gRenderer );
                //objectList.Clean();
                SDL_RenderPresent( gRenderer );     //Update screen
                //SDL_RenderClear( gRenderer );
                ++frame;                            //Go to next frame
                //SDL_RenderClear( gRenderer );
                //++bulletDelay;


            }
            //delete hero;
            delete enemy;
            delete hero;
        }
    }

    //Free resources and close SDL
    close();

    return 0;
}

bool init()
{
    //Initialization flag
    bool success = true;

    //Initialize SDL
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
        success = false;
    }
    else
    {
        //Set texture filtering to linear
        if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
        {
            printf( "Warning: Linear texture filtering not enabled!" );
        }

        //Create window
        gWindow = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
        if( gWindow == NULL )
        {
            printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
            success = false;
        }
        else
        {
            //Create renderer for window
            gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );
            if( gRenderer == NULL )
            {
                printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
                success = false;
            }
            else
            {
                //Initialize renderer color
                SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );

                //Initialize PNG loading
                int imgFlags = IMG_INIT_PNG;
                if( !( IMG_Init( imgFlags ) & imgFlags ) )
                {
                    printf( "SDL_image could not initialize! SDL_mage Error: %s\n", IMG_GetError() );
                    success = false;
                }
            }
        }
    }

    return success;
}

bool loadMedia()
{
    //Loading success flag
    bool success = true;

    //Load sprite sheet texture
    if( !gSpriteSheetTexture.LoadFromFile( "Images/pic46.png", gRenderer  ) )
    {
        printf( "Failed to load sprite sheet texture!\n" );
        success = false;
    }

    if( !gSpriteSheetTexture1.LoadFromFile( "Images/king.png", gRenderer  ) )
    {
        printf( "Failed to load sprite sheet texture!\n" );
        success = false;
    }
    if( !gSpriteSheetTexturew.LoadFromFile( "Images/fontSprite.png", gRenderer  ) )
    {
        printf( "Failed to load sprite sheet texture!\n" );
        success = false;
    }
    if( !gSpriteSheetTexturem.LoadFromFile( "Images/1948.png", gRenderer  ) )
    {
        printf( "Failed to load sprite sheet texture!\n" );
        success = false;
    }
    if( !gSpriteSheetTextureSplash.LoadFromFile( "Images/Splash.png", gRenderer  ) )
    {
        printf( "Failed to load sprite sheet texture!\n" );
        success = false;
    }
    if( !gSpriteSheetTexture2.LoadFromFile( "Images/enemy.png", gRenderer  ) )
    {
        printf( "Failed to load sprite sheet texture!\n" );
        success = false;
    }
    if( !gSpriteSheetTextureDeath.LoadFromFile( "Images/DeathScreen.png", gRenderer  ) )
    {
        printf( "Failed to load sprite sheet texture!\n" );
        success = false;
    }
    return success;
}

void close()
{
    //Free loaded images
    gSpriteSheetTexture.Free();
    gSpriteSheetTexture1.Free();
    gSpriteSheetTexturem.Free();
    gSpriteSheetTexturew.Free();

    //Destroy window
    SDL_DestroyRenderer( gRenderer );
    SDL_DestroyWindow( gWindow );
    gWindow = NULL;
    gRenderer = NULL;

    //Quit SDL subsystems
    IMG_Quit();
    SDL_Quit();
}
