#include "Rods.h"

Rods::Rods()
{
    //ctor
}

Rods::~Rods()
{
    //dtor
}
<<<<<<< HEAD

void Rods::render(SDL_Renderer* gRenderer)
{
    spritesheetTexture->Render(posX,posY,&spriteclips);
=======
void Rods::render(SDL_Renderer* gRenderer)
{
    spriteSheetTexture->render(posX,posY,&spriteclips);
>>>>>>> 50fc4b29961964eb5ba6515205fbbf927296bee0
}
