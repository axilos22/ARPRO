#include <iostream>
#include <math.h>
using namespace std;

class CTest {
    int* integer;
    public:
    CTest(){
        integer=new int(1);
        cout << "CTest object constructed" << endl ;
    }
    ~CTest()
    {
        delete integer;
        cout << "CTest object destroyed" << endl ;
    }
    int getInteger() {
        return *integer;
    }
};

/** Lab IV
 * c) We are getting an error since integer is a private attribute and can't be accessed out of the class.
 * To solve this problem, we use a getter. We could also make it public but it would be a bad solution
 * in terms of Oriented Object Programming (encapsulation notion).
 * d) The destructor is run since at the end of the function, all local variables are deallocated. So when methodA() ends,
 * the CTest variable declared is deallocated.
 */
void methodA() {
    CTest t;
//    cout << *t.integer << endl;
    cout <<"@methodA Integer= "<< t.getInteger() << endl;
}
/**
 * Lab IV
 * e)Contrary to method A, here we do not create a local copy, we declare a pointer for a new object. At the end of this function,
 * as t is not a local variable, it wont be deallocated.
 * If we want the same behaviour as A (and avoid memory leak) we should manually delete the pointer we allocated in this function.
 */
void methodB() {
    CTest *t = new CTest();
    cout <<"@methodB Integer= "<< t->getInteger() << endl;
    delete t;
}

int partIVmain() {
    cout << "Program begins" << endl;
    methodA();
    methodB();
    cout << "Program ends" << endl;
}
