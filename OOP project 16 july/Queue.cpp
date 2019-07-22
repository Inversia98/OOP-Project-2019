#include"Queue.h"
#include<iostream>

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
    while(temp!=NULL)

    {

//            cout<<"I am in the if block"<<endl;
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
    while(temp!=NULL)
    {
        temp->gameobject->Render(frame, gRenderer, debug);
        temp=temp->next;
    }
}

void Queue::Collision(Unit * hero)
{
    int cnt = 0;
    Node* temp = head;
    while(temp!=NULL)
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
        temp=temp->next;
        cnt++;
    }
}



//void Queue::deleteQueue(){
//
//}



void Queue::enemyAttack(Unit * hero, Health& health)
{
    int cnt = 0;
    Node* temp = head;
    while(temp!=NULL)
    {
        float xEnemy = temp->gameobject->GetX();
        float yEnemy = temp->gameobject->GetY();
        float xPerson =
        hero->GetX();
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
    while(temp!=NULL)
    {
        float xEnemy = temp->gameobject->GetX();
        float yEnemy = temp->gameobject->GetY();
        float xPerson = hero->GetX();
        float yPerson = hero->GetY();
        while( SDL_PollEvent( &e ) != 0 )   //Handle events on queue
        {
            if (currentKeyStates[SDL_SCANCODE_A] && e.type == SDL_KEYDOWN && check == true)
            {
//                if (e.type == SDL_KEYUP)
//                {
//                    check = false;
                   cout<<"A is pressed"<<endl;
                   check=false;

                if((xEnemy < (xPerson + 180)) && (xEnemy > (xPerson - 180)))
                {
                    //delete temp;
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

        temp=temp->next;
        cnt++;
    }
}

void Queue::QueueDelete()
{
    Node*temp=NULL;
    Node*temp2=head;


    while(temp2!=NULL)
    {
         temp=temp2;
         temp2=temp2->next;
         delete temp;

    }

        head=NULL;
}

void Queue::Move()
{
    Node* temp = head;
    while(temp!=NULL)
    {
        temp->gameobject->Move();
        temp=temp->next;
//        cout<<"Queue Move"<<endl;
    }

}

Node* Queue::getHead()
{
    return head;
}

void Queue::Dequeue()
{
    gameobject* deq = 0;
    if(head != NULL)
    {
        Node* temp = head;
        head = head->next;
        deq = temp->gameobject;
        delete temp;
    }
}
/*
void Queue::Collision()
{
    Node* temp = head;
    while(temp != NULL)
    {
        if(temp->gameobject->GetID() == 3)
        {
            Node* temp2 = head;
            while(temp2 != NULL)
            {
                int enemyX = temp->unit->GetX();
                int bulletX = temp2->unit->GetX();
                int enemyY = temp->unit->GetY();
                int bulletY = temp2->unit->GetY();



                if (!((enemyX + 55 > bulletX) && (enemyX - 5 < bulletX)))
                {

                    if (temp2->unit->GetID() == 2)
                    {
                        cout << "LEFT" << endl;
                        temp->unit->Move(RIGHT);
                        temp->unit->Move(RIGHT);
                    }

                }
                if (!((enemyX - 55 < bulletX) && (enemyX + 5 > bulletX)))
                {
                    if (temp2->unit->GetID() == 2)
                    {
                        cout << "RIGHT" << endl;
                        temp->unit->Move(LEFT);
                        temp->unit->Move(LEFT);
                    }
                }
                temp2 = temp2->next;
            }
        }
        temp = temp->next;
    }
}

void Queue::Kill()
{
    Node* temp = head;
    while(temp != NULL)
    {
        if(temp->unit->GetID() == 3)
        {
            Node* temp2 = head;
            while(temp2 != NULL)
            {
                int enemyX = temp->unit->GetX();
                int bulletX = temp2->unit->GetX();
                int enemyY = temp->unit->GetY();
                int bulletY = temp2->unit->GetY();




                if ((!((enemyX + 50 < bulletX) ^ (enemyX - 55 > bulletX))) && (!((enemyY + 55 < bulletY) ^ (enemyY - 55 > bulletY))))
                {
                    if (temp2->unit->GetID() == 2)
                    {
                        temp->unit->SetAlive(false);
                    }
                }

                temp2 = temp2->next;
            }
        }
        temp = temp->next;
    }
}

*/

