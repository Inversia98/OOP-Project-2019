#ifndef LIST_H
#define LIST_H

#include "Node.h"

class List
{
private:
    Node* head;
    Node* tail;
    int length;

public:
    List(LTexture*);
    ~List();
    void insertFirst(int element);
    void insertLast(int element);
    void insertAfter(int old, int element);
    void deleteFirst();
    void deleteLast();
    void deleteItem(int element);
    Node* searchItem(int element);
    void printList();
};

#endif // LIST_H
