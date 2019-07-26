#pragma once
#include "Node.h"
#include "Character.h"
#include "Health.h"
#include "Score.h"

class Queue
{
private:
    Node* head;
    Node* tail;
    int length;
public:
    Queue(LTexture*);
    ~Queue();
    void Enqueue(gameobject*);
    void Dequeue();
    void Clean();
    void Render(long int& frame, SDL_Renderer* gRenderer, bool debug);
    void Move();
    void Collision(Unit*);
    void enemyAttack(Unit*, Health&);
    void QueueDelete();
    void personAttack(Unit*,const Uint8*, Score&, SDL_Event&, int&);
    Node* getHead();

};
