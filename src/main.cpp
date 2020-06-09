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
    cout << "\n" << endl;
    /* Another test, test matrix with operator [][] */
    myVector<myVector<int> > Matrix;
    
//    cout<<"\nRESIZE DE LA COLUMNA\n" <<endl;
    Matrix.resize(4);
//    cout << Matrix.getsize() << endl;
    int colsize = Matrix.getsize();

//   cout << "Filas: " << colsize << endl;

    for(int i = 0; i < colsize; i++){
//        cout<<"\nRESIZE DE LA FILA " << i << "\n" <<endl;
        Matrix[i].resize(10);
//        cout<<"Fuera de resize fil " << i <<endl;
        int filsize = Matrix[i].getsize();
        
        for(int j=0; j < filsize; j++){
//             cout<<"hola3 ";
            Matrix[i][j]=j;
            cout << Matrix[i][j] << " ";
//           cout<<"hola4 ";
         }cout << endl;
     }

    cout << endl;

    myVector<myVector<int> > Matriz;
    
//    cout<<"\nRESIZE DE LA COLUMNA\n" <<endl;
    Matriz.resize(5);

    int colsize2 = Matriz.getsize();

//    cout << colsize2 << endl;
    
//    matrix2[0].resize(6);cout<<"chau"<<endl;
//    int filsize3 = matrix2[0].getsize();
//    cout << filsize3 << endl;
    
    for (int i = 0; i < colsize2; i++){
//        cout<<"\nRESIZE DE LA FILA " << i << "\n" <<endl;
        Matriz[i].resize(6);
//        cout<<"Fuera de resize fil " << i <<endl;
        int filsize2 = Matriz[i].getsize();
        
        for(int j=0; j< filsize2; j++){
            Matriz[i][j]=2;
            cout << Matriz[i][j] << " ";
        }cout << endl;
    }
    
    myVector<myVector<int> > Matrix3;

    Matrix3.resize(3);
    int colsize3 = Matrix3.getsize();
    for (size_t i = 0; i < colsize3; i++)
    {
        Matrix3[i].resize(3);
    }

    Matrix[0][0]=1;

    return 0;
}