#ifndef MISC_STATION_H
#define MISC_STATION_H


class Misc_Station
{
    public:
        Misc_Station();
        ~Misc_Station();
        void Draw(Ltexture* gRenderer);
        int getNumberWeights();
        void receiveWeight(Weights);


    protected:

    private:
};

#endif // MISC_STATION_H
