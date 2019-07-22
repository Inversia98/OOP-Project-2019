#ifndef WEIGHT_STATION_H
#define WEIGHT_STATION_H


class Weight_Station
{
    public:
        Weight_Station();
        ~Weight_Station();
        virtual void Draw(Ltexture* gRenderer);
        virtual int getNumberWeights();
        virtual void receiveWeight(Weights);

    protected:

    private:
        Weights weight;
        int currentWeight;
        int posX;
        int posY;
        int length;
        int width;
        SDL_Rect spriteclips;
        Ltexture spritesheetTexture;
};

#endif // WEIGHT_STATION_H
