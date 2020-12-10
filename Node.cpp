#include <iostream>
#include "Node.h"
using namespace std;
int counter =0;
Node::Node() //default constructor
{
    next = NULL;
    outer=0;
    inner=0;
    exp=0;
    trig="na";
}
Node::Node(Node *val) //overloaded constructor for NODE
{
    next = NULL;
    outer = val->getOuter();
    inner = val->getInner();
    exp = val->getExp();
    trig = val->getTrigID();
}
ostream& operator<<(ostream& os, const Node* head){ //this finds each and every possible instance and prints it out for us and it returns OS
    const Node* temp = head;

    if(temp->getOuter() < 0 && temp->getExp() >= 2 && counter == 0){ //finding a certain instance so I can throw values in and make this look nice
        os << abs(temp->getOuter()) << "x^" << temp->getExp();
    }
    else if(temp->getOuter() < 0 && temp->getExp() <= 2 && counter == 0 && temp->getTrigID() == "na"){//finding a certain instance so I can throw values in and make this look nice
        os <<abs(temp->getOuter()) << "x^" << temp->getExp();
    }
    else if(temp->getOuter() < 0 && temp->getExp() ==1&& counter == 0 && temp->getTrigID() == "na"){//finding a certain instance so I can throw values in and make this look nice
        os <<temp->getOuter() << "x";
    }
    else if(temp->getOuter() < 0 && temp->getExp() == 0 && counter == 0 && temp->getTrigID() == "na"){//finding a certain instance so I can throw values in and make this look nice
        os << temp->getOuter();
    }
    else if(temp->getOuter() > 0 && temp->getExp() >= 2 && counter == 0 && temp->getTrigID() == "na"){//finding a certain instance so I can throw values in and make this look nice
        os <<  temp->getOuter() << "x^" << temp->getExp();
    }
    else if(temp->getOuter() >  0 && temp->getExp() ==1&& counter == 0 && temp->getTrigID() == "na"){//finding a certain instance so I can throw values in and make this look nice
        os <<temp->getOuter() << "x";
    }
    else if(temp->getOuter() >  0 && temp->getExp() == 0 && counter == 0 && temp->getTrigID() == "na"){//finding a certain instance so I can throw values in and make this look nice
        os << temp->getOuter();
    }
    else if(temp->getOuter() < 0 && temp->getExp() < 0 && counter > 0 && temp->getExp() !=1 && temp->getExp() != 0 && temp->getTrigID() == "na"){//finding a certain instance so I can throw values in and make this look nice
        os << abs(temp->getOuter()) << "x^" << temp->getExp();
    }
    else if(temp->getOuter() < 0 && temp->getExp() ==1&& counter > 0 && temp->getTrigID() == "na"){//finding a certain instance so I can throw values in and make this look nice
        os << abs(temp->getOuter()) << "x";
    }
    else if(temp->getOuter() < 0 && temp->getExp() == 0 && counter > 0 && temp->getTrigID() == "na"){//finding a certain instance so I can throw values in and make this look nice
        os <<  abs(temp->getOuter());
    }
    else if(temp->getOuter() > 0 && temp->getExp() >= 2 && counter > 0){//finding a certain instance so I can throw values in and make this look nice
        os << temp->getOuter() << "x^" << temp->getExp();
    }
    else if(temp->getOuter() > 0 && temp->getExp() <= 2 && counter > 0 && temp->getExp() !=1 && temp->getExp() != 0 && temp->getTrigID() == "na"){//finding a certain instance so I can throw values in and make this look nice
        os << temp->getOuter() << "x^" << temp->getExp();
    }
    else if(temp->getOuter() > 0 && temp->getExp() ==1&& counter > 0 && temp->getTrigID() == "na"){//finding a certain instance so I can throw values in and make this look nice
        os << temp->getOuter() << "x";
    }
    else if(temp->getOuter() > 0 && temp->getExp() == 0 && counter > 0 && temp->getTrigID() == "na"){//finding a certain instance so I can throw values in and make this look nice
        os << temp->getOuter();
    }
    else if(temp->getInner() == 1 && temp->getTrigID() == "sin" && temp->getOuter() > 1 && counter == 0){//finding a certain instance so I can throw values in and make this look nice
        os << temp->getTrigID() << " " << temp->getOuter() << "x";
    }
    else if(temp->getInner() == -1 && temp->getTrigID() == "sin" && temp->getOuter() > 1 && counter == 0){//finding a certain instance so I can throw values in and make this look nice
        os <<temp->getTrigID() << " " << temp->getOuter() << "x";
    }
    else if(temp->getInner() > 1 && temp->getTrigID() == "sin" && temp->getOuter() > 1 && counter == 0){//finding a certain instance so I can throw values in and make this look nice
        os << temp->getInner() << temp->getTrigID() << " " << temp->getOuter() << "x";
    }
    else if(temp->getInner() < -1 && temp->getTrigID() == "sin" && temp->getOuter() > 1 && counter == 0){//finding a certain instance so I can throw values in and make this look nice
        os << temp->getInner() << temp->getTrigID() << " " << temp->getOuter() << "x";
    }
    else if(temp->getInner() > 1 && temp->getTrigID() == "sin" && temp->getOuter() == 1 && counter == 0){//finding a certain instance so I can throw values in and make this look nice
        os << temp->getInner() << temp->getTrigID() << " " << "x";
    }
    else if(temp->getInner() < -1 && temp->getTrigID() == "sin" && temp->getOuter() == 1 && counter == 0){//finding a certain instance so I can throw values in and make this look nice
        os << temp->getInner() << temp->getTrigID() << " " << "x";
    }
    else if(temp->getInner() == 1 && temp->getTrigID() == "sin" && temp->getOuter() > 1 && counter > 0){//finding a certain instance so I can throw values in and make this look nice
        os << temp->getTrigID() << " " << temp->getOuter() << "x";
    }
    else if(temp->getInner() == 1 && temp->getTrigID() == "sin" && temp->getOuter() == 1 && counter > 0){//finding a certain instance so I can throw values in and make this look nice
        os << temp->getTrigID() << " " << "x";
    }
    else if(temp->getInner() > 1 && temp->getTrigID() == "sin" && temp->getOuter() == 1 && counter > 0){//finding a certain instance so I can throw values in and make this look nice
        os << temp->getInner() << temp->getTrigID() << " " << "x";
    }
    else if(temp->getInner() > 1 && temp->getTrigID() == "sin" && temp->getOuter() > 1 && counter > 0){//finding a certain instance so I can throw values in and make this look nice
        os << temp->getInner() << temp->getTrigID() << " " << temp->getOuter() << "x";
    }
        //negatives
    else if(temp->getInner() == -1 && temp->getTrigID() == "sin" && temp->getOuter() > 1 && counter > 0){//finding a certain instance so I can throw values in and make this look nice//finding a certain instance so I can throw values in and make this look nice
        os <<  temp->getTrigID() << " " << temp->getOuter() << "x";
    }
    else if(temp->getInner() == -1 && temp->getTrigID() == "sin" && temp->getOuter() == 1 && counter > 0){//finding a certain instance so I can throw values in and make this look nice
        os <<  temp->getTrigID() << " " << "x";
    }
    else if(temp->getInner() < 1 && temp->getTrigID() == "sin" && temp->getOuter() == 1 && counter > 0){//finding a certain instance so I can throw values in and make this look nice
        os <<  abs(temp->getInner()) << temp->getTrigID() << " " << "x";
    }
    else if(temp->getInner() < 1 && temp->getTrigID() == "sin" && temp->getOuter() > 1 && counter > 0){//finding a certain instance so I can throw values in and make this look nice
        os <<  abs(temp->getInner()) << temp->getTrigID() << " " << temp->getOuter() << "x";
    }
        //cos
    else if(temp->getInner() == 1 && temp->getTrigID() == "cos" && temp->getOuter() > 1 && counter == 0){//finding a certain instance so I can throw values in and make this look nice
        os << temp->getTrigID() << " " << temp->getOuter() << "x";
    }
    else if(temp->getInner() > 1 && temp->getTrigID() == "cos" && temp->getOuter() > 1 && counter == 0){//finding a certain instance so I can throw values in and make this look nice
        os << temp->getInner() << temp->getTrigID() << " " << temp->getOuter() << "x";
    }
    else if(temp->getInner() < 1 && temp->getTrigID() == "cos" && temp->getOuter() > 1 && counter == 0){//finding a certain instance so I can throw values in and make this look nice
        os << temp->getInner() << temp->getTrigID() << " " << temp->getOuter() << "x";
    }
    else if(temp->getInner() > 1 && temp->getTrigID() == "cos" && temp->getOuter() == 1 && counter == 0){//finding a certain instance so I can throw values in and make this look nice
        os << temp->getInner() << temp->getTrigID() << " " << "x";
    }
    else if(temp->getInner() < 1 && temp->getTrigID() == "cos" && temp->getOuter() == 1 && counter == 0){//finding a certain instance so I can throw values in and make this look nice
        os << temp->getInner() << temp->getTrigID() << " " << "x";
    }
    else if(temp->getInner() == 1 && temp->getTrigID() == "cos" && temp->getOuter() > 1 && counter > 0){//finding a certain instance so I can throw values in and make this look nice
        os << temp->getTrigID() << " " << temp->getOuter() << "x";
    }
    else if(temp->getInner() == 1 && temp->getTrigID() == "cos" && temp->getOuter() == 1 && counter > 0){//finding a certain instance so I can throw values in and make this look nice
        os << temp->getTrigID() << " " << "x";
    }
    else if(temp->getInner() > 1 && temp->getTrigID() == "cos" && temp->getOuter() == 1 && counter > 0){//finding a certain instance so I can throw values in and make this look nice
        os << temp->getInner() << temp->getTrigID() << " " << "x";
    }
    else if(temp->getInner() > 1 && temp->getTrigID() == "cos" && temp->getOuter() > 1 && counter > 0){//finding a certain instance so I can throw values in and make this look nice
        os << temp->getInner() << temp->getTrigID() << " " << temp->getOuter() << "x";
    }
        //negatives
    else if(temp->getInner() == -1 && temp->getTrigID() == "cos" && temp->getOuter() > 1 && counter > 0){//finding a certain instance so I can throw values in and make this look nice
        os <<  temp->getTrigID() << " " << temp->getOuter() << "x";
    }
    else if(temp->getInner() == -1 && temp->getTrigID() == "cos" && temp->getOuter() == 1 && counter > 0){//finding a certain instance so I can throw values in and make this look nice
        os <<  temp->getTrigID() << " " << "x";
    }
    else if(temp->getInner() < 1 && temp->getTrigID() == "cos" && temp->getOuter() == 1 && counter > 0){//finding a certain instance so I can throw values in and make this look nice
        os <<  abs(temp->getInner()) << temp->getTrigID() << " " << "x";
    }
    else if(temp->getInner() < 1 && temp->getTrigID() == "cos" && temp->getOuter() > 1 && counter > 0){//finding a certain instance so I can throw values in and make this look nice
        os <<  abs(temp->getInner()) << temp->getTrigID() << " " << temp->getOuter() << "x";
    }
        //tan
    else if(temp->getInner() == 1 && temp->getTrigID() == "sec" && temp->getOuter() > 1 && counter == 0){//finding a certain instance so I can throw values in and make this look nice
        os << temp->getTrigID()<<"^2" << " " << temp->getOuter() << "x";
    }
    else if(temp->getInner() > 1 && temp->getTrigID() == "sec" && temp->getOuter() > 1 && counter == 0){//finding a certain instance so I can throw values in and make this look nice
        os << temp->getInner()<<  temp->getTrigID()<<"^2" << " " << temp->getOuter() << "x";
    }
    else if(temp->getInner() < 1 && temp->getTrigID() == "sec" && temp->getOuter() > 1 && counter == 0){//finding a certain instance so I can throw values in and make this look nice
        os << temp->getInner()<< temp->getTrigID()<<"^2" << " " << temp->getOuter() << "x";
    }
    else if(temp->getInner() > 1 && temp->getTrigID() == "sec" && temp->getOuter() == 1 && counter == 0){//finding a certain instance so I can throw values in and make this look nice
        os << temp->getInner() << temp->getTrigID()<<"^2" << " " << "x";
    }
    else if(temp->getInner() < 1 && temp->getTrigID() == "sec" && temp->getOuter() == 1 && counter == 0){//finding a certain instance so I can throw values in and make this look nice
        os << temp->getInner()<< temp->getTrigID()<<"^2" << " " << "x";
    }
    else if(temp->getInner() == 1 && temp->getTrigID() == "sec" && temp->getOuter() > 1 && counter > 0){//finding a certain instance so I can throw values in and make this look nice
        os << temp->getTrigID()<<"^2" << " " << temp->getOuter() << "x";
    }
    else if(temp->getInner() == 1 && temp->getTrigID() == "sec" && temp->getOuter() == 1 && counter > 0){//finding a certain instance so I can throw values in and make this look nice
        os << temp->getTrigID()<<"^2" << " " << "x";
    }
    else if(temp->getInner() > 1 && temp->getTrigID() == "sec" && temp->getOuter() == 1 && counter > 0){//finding a certain instance so I can throw values in and make this look nice
        os << temp->getInner() << temp->getTrigID()<<"^2" << " " << "x";
    }
    else if(temp->getInner() > 1 && temp->getTrigID() == "sec" && temp->getOuter() > 1 && counter > 0){//finding a certain instance so I can throw values in and make this look nice
        os << temp->getInner() << temp->getTrigID()<<"^2" << " " << temp->getOuter() << "x";
    }
        //negatives
    else if(temp->getInner() == -1 && temp->getTrigID() == "sec" && temp->getOuter() > 1 && counter > 0){//finding a certain instance so I can throw values in and make this look nice
        os <<  temp->getTrigID()<<"^2" << " " << temp->getOuter() << "x";
    }
    else if(temp->getInner() == -1 && temp->getTrigID() == "sec" && temp->getOuter() == 1 && counter > 0){//finding a certain instance so I can throw values in and make this look nice
        os <<  temp->getTrigID()<<"^2" << " " << "x";
    }
    else if(temp->getInner() < 1 && temp->getTrigID() == "sec" && temp->getOuter() == 1 && counter > 0){//finding a certain instance so I can throw values in and make this look nice
        os <<  abs(temp->getInner()) << temp->getTrigID()<<"^2" << " " << "x";
    }
    else if(temp->getInner() < 1 && temp->getTrigID() == "sec" && temp->getOuter() > 1 && counter > 0){//finding a certain instance so I can throw values in and make this look nice
        os <<  abs(temp->getInner()) << temp->getTrigID()<<"^2" << " " << temp->getOuter() << "x";
    }

    counter++; //check for counter
    return os; // return
}

