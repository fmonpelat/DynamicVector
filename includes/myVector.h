#ifndef _MYVECTOR_H_INCLUDED_
#define _MYVECTOR_H_INCLUDED_

#include <iostream>

using namespace std;


template <typename T>
class myVector
{
    private:
        int size,maxsize;
        T *array;
    public:
        myVector();
        myVector(int );
        myVector(const myVector<T> & );
        ~myVector();
        void resize(int );
        int getsize();
        T &operator[](int );
        bool operator==(myVector<T>);
        bool operator!=(myVector<T>);
};

template<typename T>
myVector<T>::myVector()
{
    this->maxsize = 1;
    this->array = new T[this->maxsize];
    this->size = 0;
}

template<typename T>
myVector<T>::myVector(int size)
{
    this->maxsize = size;
    this->array = new T[this->maxsize];
    this->size = 0;
}

template<typename T>
myVector<T>::myVector(const myVector<T> & vec)
{
}

template<typename T>
bool myVector<T>::operator==(myVector<T> a)
{
  if (a.maxsize != this->maxsize) return false;

  for (int i = 0; i < (a.maxsize); i++) {
    if (a[i] != this->array[i]) return false;
  }
}

template<typename T>
bool myVector<T>::operator!=(myVector<T> a)
{
  if (a.maxsize != this->maxsize) return true;

  for (int i = 0; i < (a.maxsize); i++) {
    if (a[i] != this->array[i]) return true;
  }
}

template<typename T>
T & myVector<T>::operator[](int index)
{
  if ((index - 1) >= this->maxsize) {
    resize(index + 1);
  }
  return this->array[index]; // returned as a reference
}
/*
template<typename T>
void myVector<T>::resize(int newSize)
{
  T *temp;
  temp = new T [newSize];
  for (int i = 0; i < (newSize); i++) {
     temp[i] = this->array[i];
  }
  delete[] this->array;
  this->array = temp;
  this->maxsize = newSize;
}
*/

template<typename T>
void myVector<T>::resize(int newSize)
{
  T *temp;
  temp = new T [newSize];

  if(newSize >= this->maxsize){
    for (int i = 0; i < this->maxsize; i++) 
      temp[i] = this->array[i]; 
  }
  else{
    for (int i = 0; i < newSize; i++) 
      temp[i] = this->array[i];
  }
  delete[] this->array;
  this->array = temp;
  this->maxsize = newSize;
  }


template<typename T>
int myVector<T>::getsize()
{
    return this->maxsize;
}

template<typename T>
myVector<T>::~myVector()
{
    delete [] this->array;
}


#endif /* _MYVECTOR_H_INCLUDED_ */