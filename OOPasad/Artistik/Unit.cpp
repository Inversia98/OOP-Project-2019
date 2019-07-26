#include "Unit.h"

Unit::Unit()
{

}

Unit::Unit(LTexture* image, float x, float y)
{
    spriteSheetTexture = image;

    for (int i = 0; i<6; i++)
    {
        spriteClips[i].x = i*60;
        spriteClips[i].y = 90;
        spriteClips[i].w = 60;
        spriteClips[i].h = 90;
    }

    for (int i = 0; i<6; i++)
    {
        spriteClips1[i].x = i*55;
        spriteClips1[i].y = 0;
        spriteClips1[i].w = 55;
        spriteClips1[i].h = 88;
    }

    for (int i = 0; i<6; i++)
    {
        spriteClips2[i].x = i*55;
        spriteClips2[i].y = 0;
        spriteClips2[i].w = 55;
        spriteClips2[i].h = 88;
    }
    for (int i = 0; i<6; i++)
    {
        spriteClips3[i].x = i*60;
        spriteClips3[i].y = 90;
        spriteClips3[i].w = 60;
        spriteClips3[i].h = 90;
    }
    for (int i = 0; i<6; i++)
    {
        spriteClips4[i].x = i*60;
        spriteClips4[i].y = 178;
        spriteClips4[i].w = 60;
        spriteClips4[i].h = 101;
    }


    this->x = x;
    this->y = y;

    this->width = spriteClips[ 0 ].w;
    this->height = spriteClips[ 0 ].h;

    friction = 0.85f;
    speedx = 0;
    speedy = 0;
    alive  = true;
    AttackCount = -1;
    ID = 1;
}


Unit::~Unit()
{
    spriteSheetTexture = NULL;
}

void Unit::Render(long int& frame, SDL_Renderer* gRenderer, bool debug)
{

    if (frame % 3 == 0)
    {
        frameCheck1 = frame % 5;

    }

    spriteSheetTexture->Render( x - width/2, y - height/2, &spriteClips[frameCheck1], 0.0, NULL, SDL_FLIP_NONE, gRenderer );
    if(debug == true)
    {
        SDL_Rect rect = { x - width/2, y - height/2, width, height };
        SDL_SetRenderDrawColor( gRenderer, 0xFF, 0x00, 0x00, 0xFF );
        SDL_RenderDrawRect( gRenderer, &rect );
    }

}

void Unit::Render1(long int& frame, SDL_Renderer* gRenderer, bool debug)
{

    if (frame % 3 == 0)
    {
        frameCheck2 = frame % 5;

    }
    spriteSheetTexture->Render( x - width/2, y - height/2, &spriteClips1[frameCheck2], 0.0, NULL, SDL_FLIP_NONE, gRenderer );
    if(debug == true)
    {
        SDL_Rect rect = { x - width/2, y - height/2, width, height };
        SDL_SetRenderDrawColor( gRenderer, 0xFF, 0x00, 0x00, 0xFF );
        SDL_RenderDrawRect( gRenderer, &rect );
    }
    cout<<"Right Render"<<endl;
}

void Unit::Render2(long int& frame, SDL_Renderer* gRenderer, bool debug)
{

    if (frame % 3 == 0)
    {
        frameCheck3 = frame % 5;

    }
    spriteSheetTexture->Render( x - width/2, y - height/2, &spriteClips1[frameCheck3], 0.0, NULL, SDL_FLIP_HORIZONTAL, gRenderer );
    if(debug == true)
    {
        SDL_Rect rect = { x - width/2, y - height/2, width, height };
        SDL_SetRenderDrawColor( gRenderer, 0xFF, 0x00, 0x00, 0xFF );
        SDL_RenderDrawRect( gRenderer, &rect );
    }
    cout<<"Left Render"<<endl;
}

void Unit::Render3(long int& frame, SDL_Renderer* gRenderer, bool debug)
{

    if (frame % 3 == 0)
    {
        frameCheck4 = frame % 5;

    }
    spriteSheetTexture->Render( x - width/2, y - height/2, &spriteClips2[frameCheck4], 0.0, NULL, SDL_FLIP_HORIZONTAL, gRenderer );
    if(debug == true)
    {
        SDL_Rect rect = { x - width/2, y - height/2, width, height };
        SDL_SetRenderDrawColor( gRenderer, 0xFF, 0x00, 0x00, 0xFF );
        SDL_RenderDrawRect( gRenderer, &rect );
    }

}

void Unit::Render4(long int& frame, SDL_Renderer* gRenderer, bool debug)
{

    if (frame % 3 == 0)
    {
        frameCheck5 = frame % 5;

    }

    spriteSheetTexture->Render( x - width/2, y - height/2, &spriteClips3[frameCheck5], 0.0, NULL, SDL_FLIP_HORIZONTAL, gRenderer );
    if(debug == true)
    {
        SDL_Rect rect = { x - width/2, y - height/2, width, height };
        SDL_SetRenderDrawColor( gRenderer, 0xFF, 0x00, 0x00, 0xFF );
        SDL_RenderDrawRect( gRenderer, &rect );
    }

}

void Unit::Render5(long int& frame, SDL_Renderer* gRenderer, bool debug)
{

    AttackCount++;
    if(AttackCount < 15 && AttackCount > 0)
    {
        if (frame % 3 == 0)
        {
            frameCheck5 = frame % 5;

        }

        spriteSheetTexture->Render( x - width/2, y - height/2, &spriteClips4[frameCheck5], 0.0, NULL, SDL_FLIP_NONE, gRenderer );
        if(debug == true)
        {
            SDL_Rect rect = { x - width/2, y - height/2, width, height };
            SDL_SetRenderDrawColor( gRenderer, 0xFF, 0x00, 0x00, 0xFF );
            SDL_RenderDrawRect( gRenderer, &rect );
        }
    }

}


void Unit::reset()
{
    x = (float)52;
    y = (float)545;
}






