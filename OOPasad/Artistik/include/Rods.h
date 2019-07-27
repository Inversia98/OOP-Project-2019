#ifndef RODS_H
#define RODS_H

#include <Weights.h>


class Rods : public Weights
{
    public:
        Rods();
        virtual ~Rods();
        void render(*SDL_Renderer gRenderer);
    protected:

    private:
};

#endif // RODS_H
