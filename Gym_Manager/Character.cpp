#include"Character.h"
#include<iostream>

Character::Character()              //Constructor
{
    width = 44;                     //Deafault values
    height = 48;
    character_value = 0;
}

Character::Character(LTexture* image, float x, float y, char Char)  //Overloaded constructor which has the position and char to
{                                                                   //be displayed
    spriteSheetTexture = image;                     //Setting sprite sheet texture
    character_value = int (Char);                   //updating the ascii value by using the char

    //Frame 0
    spriteClips.x = 228;                              //Setting up default sprite clips
    spriteClips.y = 400;
    spriteClips.w = 20;
    spriteClips.h = 48;

    valueChecker();                             //This will check the ascii value and set the respective sprite clips

    position.x = x;                             //Loading position for rendering
    position.y = y;

    this->width = spriteClips.w;
    this->height = spriteClips.h;
}

Character::~Character()                         //Destructor
{
    char n = character_value;
    std::cout<<"\nCharacter "<<n<<" Destroyed";
}

void Character::Render(SDL_Renderer* gRenderer, bool debug)     //Render function for character type
{

    spriteSheetTexture->Render( position.x - width / 2, position.y - height / 2, &spriteClips, 0.0, NULL, SDL_FLIP_NONE, gRenderer );
    if(debug == true)       //the positions are set for where to render and the sprites are already set
    {
        SDL_Rect rect = { position.x - width / 2, position.y - height / 2, width, height };
        SDL_SetRenderDrawColor( gRenderer, 0xFF, 0x00, 0x00, 0xFF );
        SDL_RenderDrawRect( gRenderer, &rect );
    }
}

void Character::SetPosition(Point& position)        //Setting position using position arguments
{
    this->position.x = position.x - width / 2;
    this->position.y = position.y - height / 2;
}

void Character::SetPosition(int x, int y)           //Setting position using int arguments
{
    this->position.x = x - width / 2;
    this->position.y = y - height / 2;
}

int Character::GetFrameWidth()
{
    return width;
}
int Character::GetFrameHeight()
{
    return height;
}

void Character::valueChecker()      //All the ascii value if conditions are loaded here, this will check the ascii code and
{                                   //assign the respective sprite clips
    if (character_value == 65)
    {
        spriteClips.x = 0;
        spriteClips.y = 0;
        spriteClips.w = 44;
        spriteClips.h = 48;
    }
    if (character_value == 66)
    {
        spriteClips.x = 44;
        spriteClips.y = 0;
        spriteClips.w = 44;
        spriteClips.h = 48;
    }
    if (character_value == 67)
    {
        spriteClips.x = 88;
        spriteClips.y = 0;
        spriteClips.w = 44;
        spriteClips.h = 48;
    }
    if (character_value == 68)
    {
        spriteClips.x = 132;
        spriteClips.y = 0;
        spriteClips.w = 44;
        spriteClips.h = 48;
    }
    if (character_value == 69)
    {
        spriteClips.x = 176;
        spriteClips.y = 0;
        spriteClips.w = 44;
        spriteClips.h = 48;
    }
    if (character_value == 70)
    {
        spriteClips.x = 220;
        spriteClips.y = 0;
        spriteClips.w = 44;
        spriteClips.h = 48;
    }
    if (character_value == 71)
    {
        spriteClips.x = 264;
        spriteClips.y = 0;
        spriteClips.w = 44;
        spriteClips.h = 48;
    }
    if (character_value == 72)
    {
        spriteClips.x = 308;
        spriteClips.y = 0;
        spriteClips.w = 44;
        spriteClips.h = 48;
    }
    if (character_value == 73)
    {
        spriteClips.x = 352;
        spriteClips.y = 0;
        spriteClips.w = 44;
        spriteClips.h = 48;
    }
    if (character_value == 74)
    {
        spriteClips.x = 396;
        spriteClips.y = 0;
        spriteClips.w = 44;
        spriteClips.h = 48;
    }
    if (character_value == 75)
    {
        spriteClips.x = 440;
        spriteClips.y = 0;
        spriteClips.w = 44;
        spriteClips.h = 48;
    }
    if (character_value == 76)
    {
        spriteClips.x = 0;
        spriteClips.y = 48;
        spriteClips.w = 44;
        spriteClips.h = 48;
    }
    if (character_value == 77)
    {
        spriteClips.x = 44;
        spriteClips.y = 48;
        spriteClips.w = 44;
        spriteClips.h = 48;
    }
    if (character_value == 78)
    {
        spriteClips.x = 88;
        spriteClips.y = 48;
        spriteClips.w = 44;
        spriteClips.h = 48;
    }
    if (character_value == 79)
    {
        spriteClips.x = 132;
        spriteClips.y = 48;
        spriteClips.w = 44;
        spriteClips.h = 48;
    }
    if (character_value == 80)
    {
        spriteClips.x = 176;
        spriteClips.y = 48;
        spriteClips.w = 44;
        spriteClips.h = 48;
    }
    if (character_value == 81)
    {
        spriteClips.x = 220;
        spriteClips.y = 48;
        spriteClips.w = 44;
        spriteClips.h = 48;
    }
    if (character_value == 82)
    {
        spriteClips.x = 264;
        spriteClips.y = 48;
        spriteClips.w = 44;
        spriteClips.h = 48;
    }
    if (character_value == 83)
    {
        spriteClips.x = 308;
        spriteClips.y = 48;
        spriteClips.w = 44;
        spriteClips.h = 48;
    }
    if (character_value == 84)
    {
        spriteClips.x = 352;
        spriteClips.y = 48;
        spriteClips.w = 44;
        spriteClips.h = 48;
    }
    if (character_value == 85)
    {
        spriteClips.x = 396;
        spriteClips.y = 48;
        spriteClips.w = 44;
        spriteClips.h = 48;
    }
    if (character_value == 86)
    {
        spriteClips.x = 440;
        spriteClips.y = 48;
        spriteClips.w = 44;
        spriteClips.h = 48;
    }
    if (character_value == 87)
    {
        spriteClips.x = 0;
        spriteClips.y = 96;
        spriteClips.w = 44;
        spriteClips.h = 48;
    }
    if (character_value == 88)
    {
        spriteClips.x = 44;
        spriteClips.y = 96;
        spriteClips.w = 44;
        spriteClips.h = 48;
    }
    if (character_value == 89)
    {
        spriteClips.x = 88;
        spriteClips.y = 96;
        spriteClips.w = 44;
        spriteClips.h = 48;
    }
    if (character_value == 90)
    {
        spriteClips.x = 132;
        spriteClips.y = 96;
        spriteClips.w = 44;
        spriteClips.h = 48;
    }
    if (character_value == 97)
    {
        spriteClips.x = 176;
        spriteClips.y = 96;
        spriteClips.w = 44;
        spriteClips.h = 48;
    }
    if (character_value == 98)
    {
        spriteClips.x = 220;
        spriteClips.y = 96;
        spriteClips.w = 44;
        spriteClips.h = 48;
    }
    if (character_value == 99)
    {
        spriteClips.x = 264;
        spriteClips.y = 96;
        spriteClips.w = 44;
        spriteClips.h = 48;
    }
    if (character_value == 100)
    {
        spriteClips.x = 308;
        spriteClips.y = 96;
        spriteClips.w = 44;
        spriteClips.h = 48;
    }
    if (character_value == 101)
    {
        spriteClips.x = 352;
        spriteClips.y = 96;
        spriteClips.w = 44;
        spriteClips.h = 48;
    }
    if (character_value == 102)
    {
        spriteClips.x = 396;
        spriteClips.y = 96;
        spriteClips.w = 44;
        spriteClips.h = 48;
    }
    if (character_value == 103)
    {
        spriteClips.x = 440;
        spriteClips.y = 96;
        spriteClips.w = 44;
        spriteClips.h = 48;
    }
    if (character_value == 104)
    {
        spriteClips.x = 0;
        spriteClips.y = 144;
        spriteClips.w = 44;
        spriteClips.h = 48;
    }
    if (character_value == 105)
    {
        spriteClips.x = 44;
        spriteClips.y = 144;
        spriteClips.w = 44;
        spriteClips.h = 48;
    }
    if (character_value == 106)
    {
        spriteClips.x = 88;
        spriteClips.y = 144;
        spriteClips.w = 44;
        spriteClips.h = 48;
    }
    if (character_value == 107)
    {
        spriteClips.x = 132;
        spriteClips.y = 144;
        spriteClips.w = 44;
        spriteClips.h = 48;
    }
    if (character_value == 108)
    {
        spriteClips.x = 176;
        spriteClips.y = 144;
        spriteClips.w = 44;
        spriteClips.h = 48;
    }
    if (character_value == 109)
    {
        spriteClips.x = 220;
        spriteClips.y = 144;
        spriteClips.w = 44;
        spriteClips.h = 48;
    }
    if (character_value == 110)
    {
        spriteClips.x = 264;
        spriteClips.y = 144;
        spriteClips.w = 44;
        spriteClips.h = 48;
    }
    if (character_value == 111)
    {
        spriteClips.x = 308;
        spriteClips.y = 144;
        spriteClips.w = 44;
        spriteClips.h = 48;
    }
    if (character_value == 112)
    {
        spriteClips.x = 352;
        spriteClips.y = 144;
        spriteClips.w = 44;
        spriteClips.h = 48;
    }
    if (character_value == 113)
    {
        spriteClips.x = 396;
        spriteClips.y = 144;
        spriteClips.w = 44;
        spriteClips.h = 48;
    }
    if (character_value == 114)
    {
        spriteClips.x = 440;
        spriteClips.y = 144;
        spriteClips.w = 44;
        spriteClips.h = 48;
    }
    if (character_value == 115)
    {
        spriteClips.x = 0;
        spriteClips.y = 192;
        spriteClips.w = 44;
        spriteClips.h = 48;
    }
    if (character_value == 116)
    {
        spriteClips.x = 44;
        spriteClips.y = 192;
        spriteClips.w = 44;
        spriteClips.h = 48;
    }
    if (character_value == 117)
    {
        spriteClips.x = 88;
        spriteClips.y = 192;
        spriteClips.w = 44;
        spriteClips.h = 48;
    }
    if (character_value == 118)
    {
        spriteClips.x = 132;
        spriteClips.y = 192;
        spriteClips.w = 44;
        spriteClips.h = 48;
    }
    if (character_value == 119)
    {
        spriteClips.x = 176;
        spriteClips.y = 192;
        spriteClips.w = 44;
        spriteClips.h = 48;
    }
    if (character_value == 120)
    {
        spriteClips.x = 220;
        spriteClips.y = 192;
        spriteClips.w = 44;
        spriteClips.h = 48;
    }
    if (character_value == 121)
    {
        spriteClips.x = 264;
        spriteClips.y = 192;
        spriteClips.w = 44;
        spriteClips.h = 48;
    }
    if (character_value == 122)
    {
        spriteClips.x = 308;
        spriteClips.y = 192;
        spriteClips.w = 44;
        spriteClips.h = 48;
    }
    if (character_value == 48)
    {
        spriteClips.x = 352;
        spriteClips.y = 192;
        spriteClips.w = 44;
        spriteClips.h = 48;
    }
    if (character_value == 49)
    {
        spriteClips.x = 396;
        spriteClips.y = 192;
        spriteClips.w = 44;
        spriteClips.h = 48;
    }
    if (character_value == 50)
    {
        spriteClips.x = 440;
        spriteClips.y = 192;
        spriteClips.w = 44;
        spriteClips.h = 48;
    }
    if (character_value == 51)
    {
        spriteClips.x = 0;
        spriteClips.y = 240;
        spriteClips.w = 44;
        spriteClips.h = 48;
    }
    if (character_value == 52)
    {
        spriteClips.x = 44;
        spriteClips.y = 240;
        spriteClips.w = 44;
        spriteClips.h = 48;
    }
    if (character_value == 53)
    {
        spriteClips.x = 88;
        spriteClips.y = 240;
        spriteClips.w = 44;
        spriteClips.h = 48;
    }
    if (character_value == 54)
    {
        spriteClips.x = 132;
        spriteClips.y = 240;
        spriteClips.w = 44;
        spriteClips.h = 48;
    }
    if (character_value == 55)
    {
        spriteClips.x = 176;
        spriteClips.y = 240;
        spriteClips.w = 44;
        spriteClips.h = 48;
    }
    if (character_value == 56)
    {
        spriteClips.x = 220;
        spriteClips.y = 240;
        spriteClips.w = 44;
        spriteClips.h = 48;
    }
    if (character_value == 57)
    {
        spriteClips.x = 264;
        spriteClips.y = 240;
        spriteClips.w = 44;
        spriteClips.h = 48;
    }
    if (character_value == 46)
    {
        spriteClips.x = 308;
        spriteClips.y = 240;
        spriteClips.w = 44;
        spriteClips.h = 48;
    }
    if (character_value == 44)
    {
        spriteClips.x = 352;
        spriteClips.y = 240;
        spriteClips.w = 44;
        spriteClips.h = 48;
    }
    if (character_value == 59)
    {
        spriteClips.x = 396;
        spriteClips.y = 240;
        spriteClips.w = 44;
        spriteClips.h = 48;
    }
    if (character_value == 58)
    {
        spriteClips.x = 440;
        spriteClips.y = 240;
        spriteClips.w = 44;
        spriteClips.h = 48;
    }
    if (character_value == 63)
    {
        spriteClips.x = 0;
        spriteClips.y = 288;
        spriteClips.w = 44;
        spriteClips.h = 48;
    }
    if (character_value == 33)
    {
        spriteClips.x = 44;
        spriteClips.y = 288;
        spriteClips.w = 44;
        spriteClips.h = 48;
    }
    if (character_value == 45)
    {
        spriteClips.x = 88;
        spriteClips.y = 288;
        spriteClips.w = 44;
        spriteClips.h = 48;
    }
    if (character_value == 95)
    {
        spriteClips.x = 132;
        spriteClips.y = 288;
        spriteClips.w = 44;
        spriteClips.h = 48;
    }
    if (character_value == 126)
    {
        spriteClips.x = 176;
        spriteClips.y = 288;
        spriteClips.w = 44;
        spriteClips.h = 48;
    }
    if (character_value == 35)
    {
        spriteClips.x = 220;
        spriteClips.y = 288;
        spriteClips.w = 44;
        spriteClips.h = 48;
    }
    if (character_value == 34)
    {
        spriteClips.x = 264;
        spriteClips.y = 288;
        spriteClips.w = 44;
        spriteClips.h = 48;
    }
    if (character_value == 39)
    {
        spriteClips.x = 308;
        spriteClips.y = 288;
        spriteClips.w = 44;
        spriteClips.h = 48;
    }
    if (character_value == 38)
    {
        spriteClips.x = 352;
        spriteClips.y = 288;
        spriteClips.w = 44;
        spriteClips.h = 48;
    }
    if (character_value == 40)
    {
        spriteClips.x = 396;
        spriteClips.y = 288;
        spriteClips.w = 44;
        spriteClips.h = 48;
    }
    if (character_value == 41)
    {
        spriteClips.x = 440;
        spriteClips.y = 288;
        spriteClips.w = 44;
        spriteClips.h = 48;
    }
    if (character_value == 91)
    {
        spriteClips.x = 0;
        spriteClips.y = 336;
        spriteClips.w = 44;
        spriteClips.h = 48;
    }
    if (character_value == 93)
    {
        spriteClips.x = 44;
        spriteClips.y = 336;
        spriteClips.w = 44;
        spriteClips.h = 48;
    }
    if (character_value == 124)
    {
        spriteClips.x = 88;
        spriteClips.y = 336;
        spriteClips.w = 44;
        spriteClips.h = 48;
    }
    if (character_value == 96)
    {
        spriteClips.x = 132;
        spriteClips.y = 336;
        spriteClips.w = 44;
        spriteClips.h = 48;
    }
    if (character_value == 92)
    {
        spriteClips.x = 176;
        spriteClips.y = 336;
        spriteClips.w = 44;
        spriteClips.h = 48;
    }
    if (character_value == 47)
    {
        spriteClips.x = 220;
        spriteClips.y = 336;
        spriteClips.w = 44;
        spriteClips.h = 48;
    }
    if (character_value == 64)
    {
        spriteClips.x = 264;
        spriteClips.y = 336;
        spriteClips.w = 44;
        spriteClips.h = 48;
    }
    if (character_value == 248)
    {
        spriteClips.x = 308;
        spriteClips.y = 336;
        spriteClips.w = 44;
        spriteClips.h = 48;
    }
    if (character_value == 43)
    {
        spriteClips.x = 352;
        spriteClips.y = 336;
        spriteClips.w = 44;
        spriteClips.h = 48;
    }
    if (character_value == 61)
    {
        spriteClips.x = 396;
        spriteClips.y = 336;
        spriteClips.w = 44;
        spriteClips.h = 48;
    }
    if (character_value == 42)
    {
        spriteClips.x = 440;
        spriteClips.y = 336;
        spriteClips.w = 44;
        spriteClips.h = 48;
    }
    if (character_value == 36)
    {
        spriteClips.x = 0;
        spriteClips.y = 384;
        spriteClips.w = 44;
        spriteClips.h = 48;
    }
    if (character_value == 156)
    {
        spriteClips.x = 44;
        spriteClips.y = 384;
        spriteClips.w = 44;
        spriteClips.h = 48;
    }
    if (character_value == 128)
    {
        spriteClips.x = 88;
        spriteClips.y = 384;
        spriteClips.w = 44;
        spriteClips.h = 48;
    }
    if (character_value == 60)
    {
        spriteClips.x = 132;
        spriteClips.y = 384;
        spriteClips.w = 44;
        spriteClips.h = 48;
    }
    if (character_value == 62)
    {
        spriteClips.x = 176;
        spriteClips.y = 384;
        spriteClips.w = 44;
        spriteClips.h = 48;
    }
    if (character_value == 78)
    {
        spriteClips.x = 88;
        spriteClips.y = 48;
        spriteClips.w = 44;
        spriteClips.h = 48;
    }
}

