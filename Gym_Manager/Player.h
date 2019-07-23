#ifndef PLAYER_H
#define PLAYER_H


class Player
{
private:
    int cursorX;
    int cursorY;
    bool rightbuttonstate;
    bool leftbuttonstate;
    bool active;
    static Player p;

public:
    static Player getInstance();
};

#endif // PLAYER_H
