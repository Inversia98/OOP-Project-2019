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
    spriteSheetTexture->render(posX,posY,&spriteclips);
}
