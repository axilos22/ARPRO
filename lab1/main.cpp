#include <iostream>
#include <string>
#include <cstdio>
#include <math.h>
#include <vector>

enum season { SPRING=0, SUMMER, FALL, WINTER };
enum control_policies{ sliding_mode, neural_network, PID, compliant, none};

typedef unsigned int uint;

namespace EMARO_ARIA {
    void display() {
        std::cout << "I am here !" << std::endl;
    }
}

uint sum(uint a, uint b) {
    return a+b;
}

void printControlPolicy(control_policies cp) {
    std::string outStr = "Control policy is : ";
    switch (cp) {
    case sliding_mode:
        outStr += "Sliding mode";
        break;
    case neural_network:
        outStr += "Neural network";
        break;
    case PID:
        outStr += "PID";
        break;
    case compliant:
        outStr += "Compliant";
        break;
    case none:
        outStr = "No control policy";
    default:
        outStr = "Unknown control policy";
        break;
    }
    std::cout << outStr<< std::endl;
}

void letterFunction() {
    char letter = 'a';
    char* pLetter = &letter;
    char letterX = 'x';
    pLetter = &letterX;
    pLetter++;
    //We dont see x anymore because we corrupted the letter pointer by incrementing it.
    //The value pointed by pLetter is not x anymore, but a random content of memory so answer b)
    *pLetter = 'c';
    //What we did here is write into the pointer address (so pLetter+1) for the character 'c', however, this adress has not been reserved by our program
    //anwser c)
    std::cout << "My letter : " << *pLetter << std::endl;
}

void doSomething(int &a, int &b, int c) {
    //output prediction :
    //012 --> 312
    //300 --> 002
    //012 --> 302 --> correct
    //302 --> 202 --> correct
    //300 --> 002
    a=b+c;
    b=0;
    c=0;
}

void doSomethingModified(int a, int b, int c) {
    //We modified the input type of the ints.
    //This function will perform operations with copies of variables. The original variables are not changed
    a=b+c;
    b=0;
    c=0;
}

double mySqrt(double &input) {
    double out = sqrt(input);
    input = 0;
    return out;
}

double mySqrtCorrected(double input) {
    double out = sqrt(input);
    input = 0;
    return out;
}

bool isSortedAscending(const std::vector <int> &A) {
    for(int k=1;k<A.size();k++) {
        if(A[k-1]>A[k])
            return false;
        else
            return true;
    }
}

bool swapAscending(std::vector <int> &A) {
    bool retCode = false;
    for(int k=1;k<A.size();k++) {
        if(A[k-1]<A[k]) {
            int temp = A[k-1];
            A[k-1] = A[k];
            A[k] = temp;
            retCode = true;
        }
    }
    return retCode;
}

int main()
{
    //cout << "Hello World!" << endl;
    //q1
    //printControlPolicy(neural_network);
    //q2
    //uint number = sum(10,11);
    //printf("sum is %d\n",number);
    //q3
    //EMARO_ARIA::display();
    //letterFunction();
    //int a=5,b=1,c=2;
    //printf("a=%d b=%d c=%d\n",a,b,c);
    //doSomethingModified(a,b,c);
    //printf("a=%d b=%d c=%d\n",a,b,c);
    //qII 3) c)
    //As the variable is modified, it can't be a const or a value parameter, because the content inputed is modified.
    //The anwser is c) because the parameter should be a copy so that modification don't affect the variable so a value instead of being a reference
    //double input = 36.0;
    //printf("my input is %f\n",input);
    //double output = mySqrtCorrected(input);
    //printf("My input was %f, my ouput is %f\n",input,output);
    //qII 3) e) in the first case we are pre incrementing (--c) so from now on c is not 1 but 0. at the end we divide by c so division by zero gives infinite
    //in the 2nd case we are post incrementing (c--) so from now on c remain at 1. Division by 1 is no problem so we have a normal value

    std::vector<int> A;
    A.push_back(6);
    A.push_back(3);
    A.push_back(11);
    swapAscending(A);
    std::cout << A.size() << std::endl;
    printf("a(1)=%d, a(2)=%d, a(3)=%d\n",A[1],A[2],A[3]);
    return 0;
}
