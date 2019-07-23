#ifndef SONGS_H
#define SONGS_H


class Songs
{
private:
    Mix_Chunk* songs0;

public:
    Songs();
    Songs(string);
    ~Songs();
    void Play();
};

#endif // SONGS_H
