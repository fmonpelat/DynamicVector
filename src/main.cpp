#include <iostream>
#include <time.h>
#include "../includes/myVector.h"
/* 
MIT License

Copyright (c) 2020

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

using namespace std;

int main(int argc, const char** argv)
{
    /* Test 1: Dynamic vector
    */
    cout << "Test 1: Dynamic vector: " << endl;
    myVector<int> MyVec;
    size_t size = 3;
    MyVec.resize(3);
    MyVec[0] = 1;
    MyVec[1] = 20;
    MyVec[2] = 3;

    MyVec.resize(10);
    
    size = MyVec.getsize();

    srand (time(NULL));
    for (size_t i = 0; i < size; i++)
        MyVec[i] = rand() % 100;

    MyVec.print();
    cout << endl;

    /* Test 2: Dynamic matrix
    */
    cout << "\nTest 2: Dynamic vector of vectors: " << endl;
    myVector<myVector<int> > Matrix;
    
    // resizing and populating matrix
    Matrix.resize(4); // row resize by 4 positions
    int rowSize = Matrix.getsize();
    srand (time(NULL));
    for(int i = 0; i < rowSize; i++)
    {
        Matrix[i].resize(10); // col resize by 10 (Matrix defined as row x col = 4x10)
        int colSize = Matrix[i].getsize();
        for(int j=0; j < colSize; j++)
        {
            Matrix[i][j] = rand() % 10;
         }
     }
    // printing matrix
    cout << "[";
    for (size_t i = 0; i < rowSize; i++)
    {
        if(i!=0)
            cout << " ";
        Matrix[i].print();
        if(i!=(rowSize-1))
            cout << "," << endl;
    }
    cout << "]" << endl;

    return 0;
}