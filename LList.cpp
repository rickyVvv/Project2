#include <iostream>
#include "LList.h"
using namespace std;

LList::LList() //default
{
    head = nullptr;
}
LList::LList(Node *val) //overloaded
{

    while (val) //while this is true this will run and tie everything together
    {
        Node *temp = new Node(val);
        if (head == nullptr)
        {
            head = temp;
        }
        else
        {
            Node *temp1 = head;
            while (temp1->getNext() != nullptr)
            {
                temp1 = temp1->getNext();
            }
            temp1->setNext(temp);
        }
        val = val->getNext();
    }
}
void LList::sort() //our sort
{
    //declaring variables
    Node* temp1= head;
    Node* temp2 = head;
    Node* Current = head;
    Node* LeftNode = head;
    Node* RightNode = head->getNext();
    Node* LastInstance = head;
    bool done = false;
    int counter = 0;
    int checker = 0;
    while (temp1) //checking integers
    {
        temp1= temp1->getNext();
        counter++;
    }
    temp1 = head;//starting sort!
    while(checker < counter) { //while this condition is true

        if (checker == 0) { //setting nodes
            temp2 = temp1;
            temp1 = temp1->getNext();
        }
        else if (checker == 1){ //setting nodes and flipping them
            Current = temp1;
            temp1 = temp1->getNext();
            Current->setNext(NULL);
            if(Current->getExp() > temp2->getExp()){
                Node* temp = Current->getNext();
                Current->setNext(temp2);
                temp2->setNext(temp);
                temp2 = Current;



            }
            else{ //else lets get the next instance
                temp2->setNext(Current);
            }

        }
        else
        {
            Current = temp1; //not for the first or second time
            temp1 = temp1->getNext();
            Current->setNext(NULL);
            LastInstance = temp2;
            for(int i = 0; i < checker-1; i++){
                LastInstance = LastInstance->getNext(); //getting next of last instance
            }
            if(Current->getExp() <= LastInstance->getExp()){
                LastInstance->setNext(Current); //checking to see which exp is bigger

            }
            else if(Current->getExp() >= temp2->getExp())
            {
                Current->setNext(temp2);//setting next if condition is true!
                temp2 =Current; //setting it to current
            }
            else //now we will use left and right nodes to complete this linear search
            {
                LeftNode = temp2;
                RightNode = temp2->getNext();
                while(done == false){ //whike condition is true
                    if(LeftNode->getExp() >= Current->getExp() && Current->getExp() >= RightNode->getExp()){
                        LeftNode->setNext(Current); //setting nodes to replace
                        Current->setNext(RightNode);
                        done = true;
                    }
                    else
                    {
                        LeftNode= RightNode; //move over so we can add more nodes
                        RightNode = RightNode->getNext();
                    }
                }

            }

        }
        checker++;
    }
    head = temp2;


}

const Node *LList::operator[](int index) //this function gets the index and prints it out
{
    Node *temp = head; //temp = head
    for (int i = 0; i < index; i++) //get next while i < index
    {
        temp = temp->getNext();
    }
    return temp;
}
ostream &operator<<(ostream &os, LList &List) //overloaded operator that calles a Node operator
{
    int counter = 0;//declaring variables
    const Node *temp = List[counter];
    while ((List)[counter]) { //while overloaded operator [] is true
        temp = List[counter];
        if(counter != 0 && temp->getTrigID() == "na" && temp->getOuter() != 0){ //NEEDED CANNOT DO THIS IN NODE
            if(temp->getOuter() < 0){ //we are adding our signs manually
                os << " - ";
            }
            else
            {
                os << " + ";
            }
        }
        else if(counter != 0 && temp->getTrigID() != "na" && temp->getInner() != 0)
        {
            if(temp->getInner() < 0){//we are adding our signs manually
                os << " - ";
            }
            else
            {
                os << " + ";
            }
        }
        else if(counter == 0 && temp->getTrigID() == "na" && temp->getOuter() != 0 ){
            if(temp->getOuter() < 0){//we are adding our signs manually
                os << "-";
            }
        }
        else if(counter == 0 && temp->getTrigID() != "na" && temp->getInner() != 0 )
        {
            if(temp->getInner() < 0)//we are adding our signs manually
            {
                os << "-";
            }

        }
        os << temp; //get node
        counter++; //counter increments
    }
    os << endl; //print endl at end of file
    return os; //return os
}
void LList::operator>>(Node *val) //overloaded operator that makes the head set to a certain node
{
    val->setNext(head); //finds head and replaces it
    head = val;
}

LList::~LList() //deconstructor
{
    Node *x = head->getNext();
    while (head) //while head is true
    {
        head->setNext(nullptr); //delete everything
        delete head;
        head = x;
        if (head)
        {
            x = head->getNext();
        }
    }
}











