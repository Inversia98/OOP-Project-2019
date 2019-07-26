#include"Queue.h"
#include<iostream>
#include <windows.h>
#include <mmsystem.h>

using namespace std;


Queue::Queue(LTexture* gSpriteSheetTexturew)
{
    head = NULL;
    tail = NULL;
}

Queue::~Queue()
{
    while(head != NULL)
    {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

void Queue::Enqueue(gameobject* gameobject)
{
    if(head == NULL)
    {
        head = new Node;
        head->gameobject = gameobject;
        head->next = NULL;
        head->prev = NULL;
        tail = head;
    }
    else
    {
        tail->next = new Node;
        tail->next->gameobject = gameobject;
        tail->next->next = NULL;
        tail->next->prev = tail;
        tail = tail->next;
    }
}

void Queue::Clean()
{
    Node* temp = head;
    while(temp != NULL)

    {
        if(temp->prev == NULL)
        {
            head=head->next;
            if(head!=NULL)
            {
                head->prev = NULL;
            }
            delete temp;
            temp = head;
        }
        else if(temp ->next == NULL)
        {
            tail = tail->prev;
            tail->next = NULL;
            delete temp;
            break;
        }
        else
        {
            Node* carry = temp->next;
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            delete temp;
            temp = carry;
        }



        temp = temp->next;
    }
}

void Queue::Render(long int& frame, SDL_Renderer* gRenderer, bool debug)
{
    Node* temp = head;
    while(temp != NULL)
    {
        temp->gameobject->Render(frame, gRenderer, debug);
        temp = temp->next;
    }
}

void Queue::Collision(Unit * hero)
{
    int cnt = 0;
    Node* temp = head;
    while(temp != NULL)
    {
        float xEnemy = temp->gameobject->GetX();
        float yEnemy = temp->gameobject->GetY();
        float xPerson = hero->GetX();
        float yPerson = hero->GetY();

        if(xEnemy < (xPerson - 50) - (80 * cnt))
        {
            temp->gameobject->Move(RIGHT);
        }
        else if(xEnemy > (xPerson + 30) + (80 * cnt))
        {
            temp->gameobject->Move(LEFT);
        }

        else
        {

            //Set Sprite Sheet.

        }
        temp = temp->next;
        cnt++;
    }
}


void Queue::enemyAttack(Unit * hero, Health& health)
{
    int cnt = 0;
    Node* temp = head;
    while(temp != NULL)
    {
        float xEnemy = temp->gameobject->GetX();
        float yEnemy = temp->gameobject->GetY();
        float xPerson = hero->GetX();
        float yPerson = hero->GetY();

        if((xEnemy < (xPerson + 30)) && (xEnemy > (xPerson - 30)))
        {
            cout<<"DIED"<<endl;
            health.decreaseHealth();
            hero->reset();
            cout<<"DDe"<<endl;

        }

        temp=temp->next;
        cnt++;
    }
}

void Queue::personAttack(Unit* hero,const Uint8* currentKeyStates, Score& kills, SDL_Event &e, int& noenemies)
{
    bool check = true;
    int cnt = 0;
    Node* temp = head;
    bool music = true;
    static int AttackFrame = -1;

    while(temp!=NULL)
    {
        float xEnemy = temp->gameobject->GetX();
        float yEnemy = temp->gameobject->GetY();
        float xPerson = hero->GetX();
        float yPerson = hero->GetY();
        while( SDL_PollEvent( &e ) != 0 )

        {
            if (currentKeyStates[SDL_SCANCODE_A] && e.type == SDL_KEYDOWN && check == true)
            {
                hero->AttackCount=-1;

                if (music)
                {
                    // PlaySound(TEXT("C:\\Users\\Sanie Hamid Hanfi\\Desktop\\OOP project 16 july up\\sound\\2.wav"),NULL, SND_ASYNC|SND_FILENAME);
                }
                music = false;
                cout<<"A is pressed"<<endl;
                check = false;

                if((xEnemy < (xPerson + 180)) && (xEnemy > (xPerson - 180)))
                {

                    cout<<"Enemy killed"<<endl;
                    kills.scoreIncrease();
                    Dequeue();
                    noenemies--;
                }
                if (e.type == SDL_KEYUP)
                {
                    check = true;
                }
            }
        }

        temp = temp->next;
        cnt++;
    }
}

void Queue::QueueDelete()
{
    Node*temp = NULL;
    Node*temp2 = head;


    while(temp2 != NULL)
    {
        temp = temp2;
        temp2 = temp2->next;
        delete temp;

    }

    head = NULL;
}

void Queue::Move()
{
    Node* temp = head;
    while(temp != NULL)
    {
        temp->gameobject->Move();
        temp=temp->next;

    }

}

Node* Queue::getHead()
{
    return head;
}

void Queue::Dequeue()
{
   // gameobject* deq = 0;
    if(head != NULL)
    {
        Node* temp = head;
        head = head->next;
       // deq = temp->gameobject;
        delete temp;
    }
}
