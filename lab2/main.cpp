#include <iostream>
#include <cstdio>
#include <math.h>

#include <boost/date_time/posix_time/posix_time_types.hpp>
//namespace renaming
namespace localTimeNs = boost::posix_time;
//typeshortening
typedef localTimeNs::ptime mTime;
typedef localTimeNs::microsec_clock mClock;
typedef localTimeNs::time_duration mDuration;

using namespace std;

void functionA() {
    mTime t1 = mClock::local_time();
    for (int i = 0; i < 100000; ++i) {
    }
    mTime t2 = mClock::local_time();
    mDuration d = t2-t1;
    long timeInMillis = d.total_microseconds();
    cout << "time passed: " <<timeInMillis << endl;
}
/** III.2 a)
 * @brief someMethod
 * Some method is crashing because it uses a table that has not be allocated in memory.
 * So the matrix pointer produces a segmentation fault.
 */
void someMethod() {
    cout << "start program" <<endl;
    int rows = 10000;
    int cols = rows;
    int matrix[cols][rows];
    for(int i; i<rows;i++) {
        for(int j=0;j<cols;j++) {
            matrix[i][j]=i+j;
        }
    }
    cout << "matrix initilized !" << endl;
}

/** III.2 b)
 * @brief someBetterMethod
 * This method is now using dynamic memory allocation: the program provides the size of the table it need to allocate
 * and then asks to lock this part of memory for its private uses.
 * Some betterMethod worked because contrary to someMethod, it pre-allocated the memory for storing the matrices.
 * The use of keyword "new" and of adresses of table (int **) allows the program to allocate in memory the requested
 * size for storing a rows x cols matrix of integers.
 */

/** III.2 c)
 * The 1st execution is much more faster than the 2nd one.
 * prints :
 *execution time (normal)= 85µs
 *execution time (inverted)= 1791417µs
 * ------------------------------------
 *execution time (normal)= 99µs
 *execution time (inverted)= 1783506µs
 * To explain this reason we 1st have to exaplain how are matrix stored in memory:
 * For a two dimentional table
 * In the memory, the program will store adresses of the sub-table into table boxes. So to fill the whole matrix the program will:
 * 1- allocate a table
 * 2- fill out this table with adresses of the sub-tables
 * In the 1st case once we are in a table, we fill out all the other cases of the table so the jump in memory is not high.
 * In the 2nd case once we filled one case of a table, we jump to another table to fill the other kth case of this table.
 * The jumps in memory are really high and are much more numerous
*/
void someBetterMethod(bool rowCols) {
//    cout << "start matrix init";
    int rows = 10000, cols = rows;

    int **matrix = new int*[rows];
    for(int i=0; i<rows;++i) {
        matrix[i] = new int[cols];
    }

    if(rowCols == true) {
        for(int i=0;i<rows;++i) {
            for(int j=0;j<cols;++j) {
                matrix[i][j]=i+j;
            }
        }
    } else {
        for(int i=0;i<rows;++i) {
            for(int j=0;j<cols;++j) {
                matrix[j][i]=i+j;
            }
        }
    }

    for(int i=0;i<rows;++i) {
        delete [] matrix[i];
    }
    delete [] matrix;
//    cout << "matrix initialized !" << endl;
}

/** III.2 d)
 * The computational failure is due to the high number of iteration done. Except for the case of x=1,
 * the computer keep computing negative values and as the function is recusive, it enters a loop
 * which has no ending condition (infinite recusive loop/infinite recusion). The program crashes when there is no more avaliable
 * room in memory (more precisely in the stack) for storing all the variables for those recursive calls.
 * in order to fix this, we change the stopping condition  x==1 to x<=1
*/
int execution = 0;
int Fib(int x) {
    execution++;
    cout << "execution  #" << execution << endl;
//    if(x==1) {
    if(x<=1) {
        cout << "x=1" << endl;
        return 1;
    }
    else {
        cout << "x=" << x << endl;
        return Fib(x-1)+Fib(x-2);
    }
}

int main()
{
//    someMethod();
//    mTime t = mClock::local_time();
//    mDuration d = mClock::local_time()-t;
//    someBetterMethod(true);
//    cout << "execution time (normal)= " << d.total_microseconds() << "µs" << endl;
//    t = mClock::local_time();
//    someBetterMethod(false);
//    d = mClock::local_time()-t;
//    cout << "execution time (inverted)= " << d.total_microseconds() << "µs" << endl;

    int x = 5;
    int fibX = Fib(x);
    cout << "Fib(" << x << ")= "<< fibX << endl;
    return 0;
}
