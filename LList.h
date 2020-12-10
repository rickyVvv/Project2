#ifndef LLIST_H
#define LLIST_H
#include "Node.h"
#include <iostream>
class LList
{
private:
    Node *head = NULL; //HEADPOINTER

public:
    //setting = void geting = type
    void sort(); //declaring function types
    Node *getHead() const {return head;}
    void setHead(Node *val) { head = val; }
    LList(Node *);
    const Node* operator[](int);
    friend std::ostream& operator<<(std::ostream&, LList&);
    void operator>>(Node*);

    LList();
    ~LList();
};

#endif

