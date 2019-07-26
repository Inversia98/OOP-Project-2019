#pragma once
#include"Unit.h"

struct Node
{
    gameobject* gameobject;
    Node* next;
    Node* prev;

    ~Node()
    {
        delete gameobject;
    }
};
