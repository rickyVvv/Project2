#include <iostream>
#include <string>
#include "LList.h"
#include <fstream>
#include <sstream>
using namespace std;
//Ritesh Virlley Rxv20008
void derive(Node* yes) //my derive function that gets a node
{
    //declaring all variables
    int outer = 0;
    int exp = 0;
    int newouter = 0;
    int newexp = 0;
    int newinner =0;
    int inner = 0;
    if (yes->getExp() >= 2 && yes->getOuter() != 0 && yes->getTrigID() == "na") { //while exp is > or equal to 2 i will multiply outer by it
        outer = yes->getOuter(); //outer = outer
        exp = yes->getExp(); //int exp will get the exponent
        newouter = outer * exp; //this is the deriving part we multiple exponent by outer
        newexp = exp - 1; //and now we will make the exp -1
        yes->setOuter(newouter);//setting a new outer
        yes->setExp(newexp); //setting a new exp

    } else if (yes->getExp() == 1 && yes->getTrigID() == "na") { //if exponent is 1
        yes->setExp(0); //setting new exp

    } else if (yes->getExp() <= -1 && yes->getOuter() != 0 && yes->getTrigID() == "na") { //if exponent is negative we take a different approach
        outer = yes->getOuter(); //outer equals node outer
        exp = yes->getExp(); //exp is new exp
        newouter = outer * exp; // deriving to get new outer
        newexp = exp - 1; //exp is subtracted by one
        yes->setOuter(newouter); //setting new outer
        yes->setExp(newexp); //setting new exo
    } else if (yes->getExp() == 0 && yes->getTrigID() == "na") { //when there is no exponent just a coefficent
        yes->setOuter(0); // setting new outter

    } else if (yes->getOuter() == 1 && yes->getExp() < -1 && yes->getTrigID() == "na") { //now we will be looking for seperate test cases
        exp = yes->getExp(); // getting a new exp
        newexp = exp - 1; //exponent is subtracted
        yes->setOuter(exp); //outer will equal our exponent for this case
        yes->setExp(newexp); //still need to derive our exp

    } else if (yes->getTrigID() == "sin" && yes->getInner() > 1 && yes->getOuter() == 1) {//now we will be looking for seperate test cases using sin
        yes->setTrigID("cos"); //sin = cos

    } else if (yes->getTrigID() == "cos" && yes->getInner() == 1 && yes->getOuter() == 1) {//now we will be looking for seperate test cases using cos
        yes->setInner(-1); //cos = -sin
        yes->setTrigID("sin");

    } else if (yes->getTrigID() == "cos" && yes->getInner() == -1 && yes->getOuter() > 1) {//now we will be looking for seperate test cases using cos
        outer = yes->getOuter(); // old outer
        inner = yes->getInner() * -1; //cos = - sin
        yes->setInner(outer * inner);//new inner
        yes->setTrigID("sin");

    } else if (yes->getTrigID() == "tan" && yes->getInner() == 1 && yes->getOuter() > 1) {//now we will be looking for seperate test cases using tan
        outer = yes->getOuter(); //getting outer
        inner = yes->getInner();//getting inner
        yes->setInner(outer * inner); //setting new inner
        yes->setTrigID("sec"); //setting trid ID


    } else if (yes->getTrigID() == "cos" && yes->getInner() >= 2 && yes->getOuter() >= 1) {//now we will be looking for seperate test cases using cos
        outer = yes->getOuter();//getting outer
        inner = yes->getInner() * -1;//cos = - sin
        yes->setInner(outer * inner);//new inner
        yes->setTrigID("sin");
    }
    else if (yes->getTrigID() == "tan" && yes->getInner() >= 1 && yes->getOuter() >= 1) {//now we will be looking for seperate test cases using tan
        outer = yes->getOuter();//getting outer
        inner = yes->getInner();//getting inner
        yes->setInner(outer * inner);//new inner
        yes->setTrigID("sec");
    }
    else if(yes->getTrigID() == "cos" && yes->getOuter() < 0 && yes->getInner() ==1){ //now we will be looking for seperate test cases using cos
        outer = yes->getOuter();//getting outer
        inner = yes->getInner();//getting inner
        newinner = outer * inner * -1;//cos = - sin
        yes->setInner(newinner);//new inner
        yes->setOuter(outer * -1);//cos = - sin
        yes->setTrigID("sin");
    }
}

int main() {
    //declaring our variables
    string as = "";
    string equation = "";
    cin >> as;
    ifstream fn(as);
    string temp = "";
    int how = 0;
    while(getline(fn,equation)){
        how++;
    }

    fn.close();
    fn.open(as);
    ofstream fl("derive.txt");
    while (!fn) { //good coding practice check to see if bad file
        cout << "bad file";
        return 1;
    }

    while (getline(fn, equation)) //simple nested while loop
    {
        //declaring variables
        bool removed = false;
        Node *anchor = new Node;
        Node *yes = anchor;

        while (equation != "") { //while my equation string is empty i will keep on line parsing until it is! and if its not i have a condition to make it empty
            bool negative = false;//check for negative
            bool exit = false; //is exit true?
            if(equation.at(1) == '-'){ //checking for negative
                negative = true; //make it true
                equation.erase(0,3);  //substr
            }
            else if(equation.at(1) == '+'){//check for positive
                equation.erase(0,3); //substr
            }
            for (long unsigned int i = 0; i < equation.length(); i++) { //for loop
                if (equation.at(i) == ' ') { //substring using equation.at(i)
                    if (equation.at(i + 1) == '+' || equation.at(i+1) == '-') { //finding our signs again
                        temp = equation.substr(0, i); //substr = cutting string
                        equation = equation.erase(0, i);//substr = cutting string

                        exit= true; // declaring variables
                        removed = true;
                        break;

                    }

                }

            }
            if (exit != true) { //if this is true we will run this loop just one more time and get out
                temp = equation;
                equation = "";
            }
            for (long unsigned int j = 0; j < temp.length(); j++) //a for loop that parses temp
            {
                int k = 0;
                k++; //prevent errors
                if (temp.at(j) == 's' || temp.at(j) == 'c' || temp.at(j) == 't') { //finding trig values
                    if (temp.at(j) == 's')
                    {
                        yes->setTrigID("sin");//finding trig values -1000 so trig can go in the back
                        yes->setExp(-10000+k);
                    }
                    else if (temp.at(j) == 't')
                    {
                        yes->setTrigID("tan");//finding trig values -1000 so trig can go in the back
                        yes->setExp(-10000+k);
                    }
                    else if (temp.at(j) == 'c')
                    {
                        yes->setTrigID("cos");//finding trig values -1000 so trig can go in the back
                        yes->setExp(-10000+k);
                    }
                    if (j == 0) {
                        yes->setInner(1); //setting inner
                    }
                    else{ //else lets find some other position of inner
                        int x = 0;
                        string temp1 = temp.substr(0,j);//substr = cutting string
                        stringstream a(temp1); //using stringstream to convert so i dont get errors
                        a >> x; //this is making what is inside temp into a integer
                        yes->setInner(x);//setting inner
                    }
                    temp = temp.substr(j + 4); //cutting the string
                    for (int i = 0; i < temp.length(); i++) //now lets find outer
                    {
                        if (temp.length() == 1) //if length is one because of cutting string that means the outter is one
                        {
                            yes->setOuter(1);
                            break;
                        }
                        else if (temp.at(i) == 'x') //else  lets cut the outer and find it
                        {
                            int sdsd = 0; //random
                            temp = temp.substr(0, i);//substr = cutting string
                            stringstream a(temp); //making it a int
                            a >> sdsd;//changing it up to int
                            yes->setOuter(sdsd);//setting it
                            break;


                        }


                    }


                } else if (temp.at(j) == 'x' && j != 0) { //now we are looking for exponents
                    int outer = 0; //declaring integers
                    int exp = 0;
                    string str = temp.substr(0, j);//substr = cutting string
                    stringstream a(str);//converting
                    a >> outer;//converting
                    yes->setOuter(outer);//setting outer
                    temp = temp.substr(j+1); //substr = cutting string
                    if(temp.length() != 0){
                        temp.erase(0,1);
                        stringstream a(temp);//converting
                        a >> exp;//converting
                        yes->setExp(exp); //getting exponent

                    }
                    else
                    {
                        yes->setExp(1);//getting exponent
                    }

                    break;
                }
                else if(temp.at(j) == 'x' && j ==0)
                {
                    int exp=0;
                    yes->setOuter(1);//setting outer
                    temp = temp.erase(0,1);//substr = cutting string
                    if(temp.length() != 0){
                        temp.erase(0,1);//substr = cutting string
                        stringstream a(temp);//converting
                        a >> exp;//converting
                        yes->setExp(exp);//getting exponent

                    }
                    else
                    {
                        yes->setExp(1);//getting exponent
                    }

                }
                if (removed == false) {
                    int outer21 = 0;
                    stringstream a(equation);//converting
                    a >> outer21;//converting
                    yes->setOuter(outer21);//setting outer


                }

            }
            if(negative == true){
                yes->setOuter(yes->getOuter() * -1);//setting outer
            }
            if(equation!="")
                yes->setNext(new Node); //check case
            yes = yes->getNext();
        }
        yes = anchor; //yes = anchor
        LList *temp1 = new LList(anchor); //making list
        temp1->sort(); //sorting
        Node* temp12 = temp1->getHead(); //now lets find deriving
        while(temp12){//while temp node exist and had to make it like this or i got infinite loops 24/7
            derive(temp12);//derive
            temp12 = temp12->getNext(); //get next
        }
        fl << (*temp1); //print to file
        temp1->~LList(); //deconstruct
    }
    fl.close();
    fn.close();
    return 0;


}
