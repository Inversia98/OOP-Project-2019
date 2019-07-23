#ifndef DUMBELL_STATION_H
#define DUMBELL_STATION_H


class Dumbell_Station
{
    public:
        Dumbell_Station();
        ~Dumbell_Station();
        void Draw(Ltexture* gRenderer);
        int getNumberWeights();
        void receiveWeight(Weights);

    protected:

    private:
};

#endif // DUMBELL_STATION_H
