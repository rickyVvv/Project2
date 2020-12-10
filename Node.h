#ifndef NODE_H
#define NODE_H
#include <string>
class Node
{
public: //setting = void geting = type
    Node();
    int getOuter() const { return outer; }
    int getInner() const { return inner; }
    int getExp()const  { return exp; }
    std::string getTrigID() const { return trig; }
    Node *getNext() const { return next; }
    void setOuter(int val) { outer = val; }
    void setInner(int val) { inner = val; }
    void setExp(int val) { exp = val; }
    void setTrigID(std::string val) { trig = val; }
    void setNext(Node *val) { next = val; }
    Node(Node *);
    friend std::ostream& operator<<(std::ostream&, const Node*);

private: // declaring the variables we will use
    Node *next;
    int outer;
    int inner;
    int exp;
    std::string trig;
};






#endif
