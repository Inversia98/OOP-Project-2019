#ifndef ROD_STATION_H
#define ROD_STATION_H


class Rod_Station
{
    public:
        Rod_Station();
        ~Rod_Station();
        void Draw(Ltexture* gRenderer);
        int getNumberWeights();
        void receiveWeights(Weights);

    protected:

    private:
};

#endif // ROD_STATION_H
