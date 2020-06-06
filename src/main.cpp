#include <iostream>

#include "../includes/myVector.h"

using namespace std;

int main(int argc, const char** argv)
{
    myVector<int> MyVec;
    size_t size = 3;
    MyVec.resize(3);
    MyVec[0] = 1;
    MyVec[1] = 20;
    MyVec[2] = 3;

    MyVec.resize(10);
    MyVec[5]=120;

    int arrSize = MyVec.getsize();

    for (size_t i = 0; i < arrSize; i++)
    {
        cout << MyVec[i] <<" ";
    }
    cout <<  endl;
    /* Another test, test matrix with operator [][] */
    myVector<myVector<int> > Matrix;

    Matrix.resize(3);
    int colsize = Matrix.getsize();
    for (size_t i = 0; i < colsize; i++)
    {
        Matrix[i].resize(3);
    }
    
    //Matrix[0][0]=1;
    


    return 0;
}