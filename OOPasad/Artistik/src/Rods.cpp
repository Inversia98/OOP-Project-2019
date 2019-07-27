#include "Rods.h"

Rods::Rods()
{
    //ctor
}

Rods::~Rods()
{
    //dtor
}

void Rods::render(SDL_Renderer* gRenderer)
{
    spritesheetTexture->Render(posX,posY,&spriteclips);
}
