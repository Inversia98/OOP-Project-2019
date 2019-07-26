#pragma once
#include"LTexture.h"

using namespace std;

class Health
{
public:
    Health()
    {
        health.x = 800;
        health.y = 10;
        health.w = 200;
        health.h = 32;
    }

    void decreaseHealth()
    {
        if (health.w >= 1)
        {
            this->health.w -= 25;
        }
    }

    void Render(SDL_Renderer* gRenderer)
    {
        SDL_SetRenderDrawColor(gRenderer,255,0,0, 255);
        SDL_RenderFillRect(gRenderer, &health);
    }

    int getHealth()
    {
        return health.w;
    }

    void setHealth()
    {
        health.w = 200;
    }
private:
    SDL_Rect health;
};
