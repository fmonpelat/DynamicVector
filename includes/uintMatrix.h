#ifndef _UINTMATRIX_H_INCLUDED_
#define _UINTMATRIX_H_INCLUDED_
#include <iostream>
#include "myVector.h"

using namespace std;


class uintMatrix
{
  private:
    myVector<myVector<uint> > matrix;
  public:
    uintMatrix();
    myVector<uint>& operator[] (size_t r) { return matrix[r]; }
    //uintMatrix (int r, int c) : matrix(r, myVector<uint>(c, uint())) { }
};


#endif /* _UINTMATRIX_H_INCLUDED_ */
