//"Scientific" calculator by Pablo Minaya (Enanonymus). I made this for pure fun

#include<iostream>
#include<math.h> //This library contains complex mathematical functions
#include<stdlib.h>
using namespace std;

double dTerm1 , dTerm2; //The two numbers the user will introduce to be operated
double fAns; //The answer the calculator will give to the user
char cOperatorNotComplex;
char cOperatorComplex;

int operateSimple() //Function for simple operations
{
    switch (cOperatorNotComplex)
    {
        case '+': fAns = dTerm1 + dTerm2;break;//Sum
        case '-': fAns = dTerm1 - dTerm2;break;//Subtraction
        case '*': fAns = dTerm1 * dTerm2;break;//Multiplication
        case '/': //Division
            if (dTerm2==0 && dTerm1==0)//The dumbass user tried to divide 0 by 0, summoning a demon and opening a gate to hell
            {
                system("CLS");//Clear screen
                cout<<"N E V E R    D I V I D E    Z E R O    B Y    Z E R O\n";
                abort(); //Crash it for the sake of the meme
            }
            else if (dTerm2==0)//The user divided some number by 0 (That is correct in certain cases)
            {
                cout<<"\u221E";//Code for character infinity (may not look well on the program)
            }
            else //The user did what they were supposed to do
            {
                fAns = dTerm1 / dTerm2;
            }
            break;
        case '^': fAns = pow(dTerm1, dTerm2);break;
    }
}

int operateComplex()//Ok this was too easy to code. May have issues. Check later
{
    switch (cOperatorComplex)
    {
    case 's':
        fAns = sin(dTerm1);
        break;
    case 'c':
        fAns = cos(dTerm1);
        break;
    case 't':
        fAns = tan(dTerm1);
        break;
    case 'l':
        fAns = log10(dTerm1);
        break;
    case 'v':
        fAns = sqrt(dTerm1);
        break;
    }
}

int main()
{
    char decision;
    cout<<"\"Scientific\" calculator by Enanonymus. I made this for pure fun\nWhat kind of operation do you want?\nEnter S for simple, Enter C for complex: ";
    cin>>decision;
    if (decision == 'S' || decision == 's')
    {
        system("CLS");
        cout<<"Simple operation.\nInsert the first number: ";
        cin>>dTerm1;
        cout<<"Insert the second number: ";
        cin>>dTerm2;
        cout<<"What kind of operation do you wish to do with this two numbers?";
        cout<<"\n\n(+, -, *, /, ^)";
        cin>>cOperatorNotComplex;
        operateSimple();
        cout<<"\n"<<fAns<<"\n";
    }
    else if (decision == 'C' || decision == 'c')
    {
        system("CLS");
        cout<<"Complex operation.\nInsert the number: ";
        cin>>dTerm1;
        cout<<"What do you wish to calculate?\nsin: s, cos: c, tan: t, log: l, square root: v\n";
        cin>>cOperatorComplex;
        operateComplex();
        cout<<"\n"<<fAns<<"\n";
    }
    else
    {
        system("CLS");
        cout<<"This is what you get for being dumb";
        abort();
    }
    return 0;
}
