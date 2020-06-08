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
    
    Matrix.resize(4);
    
//    cout << Matrix.getsize() << endl;
    int colsize = Matrix.getsize();

   cout << colsize << endl;

    for(int i = 0; i < colsize; i++){
//        cout<<"hola2"<<endl;
        Matrix[i].resize(10);
        int filsize = Matrix[i].getsize();
         for(int j=0; j < filsize; j++){
//             cout<<"hola3 ";
            Matrix[i][j]=j;
            cout << Matrix[i][j] << " ";
//           cout<<"hola4 ";
         }cout << endl;
     }

myVector<myVector<int> > matrix2;
   matrix2.resize(5);

   int colsize2 = matrix2.getsize();

   cout << colsize2 << "hola5" << endl;

    for (size_t i = 0; i < colsize2; i++)
    { matrix2[i].resize(2);
    int filsize2 = matrix2.getsize();
        for(size_t j=0; i< filsize2; j++){
        matrix2[i][j]=2;
        cout << matrix2[i][j] << " ";}
    }
    
    //Matrix[0][0]=1;



    return 0;
}