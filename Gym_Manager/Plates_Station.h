#ifndef PLATES_STATION_H
#define PLATES_STATION_H


class Plates_Station
{
    public:
        Plates_Station();
        ~Plates_Station();
        void Draw(Ltexture* gRenderer);
        int getNumberWeights();
        void receiveWeight(Weights);

    protected:

    private:
};

#endif // PLATES_STATION_H
