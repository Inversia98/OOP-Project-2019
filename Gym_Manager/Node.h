#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED

#include "Game_Objects.h"

class Node
{
public:
    Game_objects* data;
    Node* next;
    Node* prev;

public:
    ~Node();
};


#endif // NODE_H_INCLUDED
