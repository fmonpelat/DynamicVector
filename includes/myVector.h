#ifndef _MYVECTOR_H_INCLUDED_
#define _MYVECTOR_H_INCLUDED_

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

#include <iostream>
#include <string.h>
#include <stdio.h>

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
        void print();
        T &operator[](int );
        bool operator==(myVector<T>);
        bool operator!=(myVector<T>);
        myVector<T> &operator=(const myVector<T> &);
};

// Constructors
template<typename T>
myVector<T>::myVector()
{
    this->maxsize = 1;
    this->array = new T[this->maxsize];
    this->size = 0;

    for (int i = 0; i < this->maxsize; i++) 
      this->array[i] = 0;
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
myVector<T>::~myVector()
{
  delete [] this->array;
}

// Operators overload
template<typename T>
bool myVector<T>::operator==(myVector<T> a)
{
  if (a.maxsize != this->maxsize)
    return false;

  for (int i = 0; i < (a.maxsize); i++)
  {
    if (a[i] != this->array[i])
      return false;
  }
}

template<typename T>
bool myVector<T>::operator!=(myVector<T> a)
{
  if (a.maxsize != this->maxsize)
    return true;

  for (int i = 0; i < (a.maxsize); i++)
  {
    if (a[i] != this->array[i])
      return true;
  }
}

template <typename T>
myVector<T> &myVector<T>::operator=(const myVector<T> &rigth)
{
	if(&rigth != this)
  { /* Chequea que la dirección del objeto pasado (ejemplo Array B)
	 	   sea distinta de la direccion del objeto (ejemplo Array A)
	 	 	 sobre el que se ejecuta el código
    */
		if(this->size != rigth.maxsize)
    {
      // Si el tamaño del Array A es distinto del Array B
      this->resize(rigth.maxsize);

			for(int i = 0; i < this->maxsize; i++)
				this->array[i] = rigth.array[i]; // Asigno los valores del Array B al Array A posicion por posicion

			return *this; // Devuelvo el objeto sobre el que se trabajo (Array A)
		}
		else
    {
			for(int i = 0; i < maxsize; i++)
				array[i] = rigth.array[i]; // Asigno los valores del Array B al Array A posicion por posicion

			return *this; // al retornar una referencia permite x=y=z
		}
	}
	return *this; //Devuelvo el objeto sobre el que se trabajo (Array A)
}


template<typename T>
T & myVector<T>::operator[](int index)
{
  if ((index - 1) >= this->maxsize)
  {
    resize(index + 1);
  }
  this->size=index;
  return this->array[index];
}

template<typename T>
void myVector<T>::resize(int newSize)
{
  T *temp;
  temp = new T [newSize];
  for (int i = 0; i < this->maxsize; i++) {
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
void myVector<T>::print()
{
    cout << "[ ";
    for (size_t i = 0; i < this->maxsize; i++)
    {
        cout << this->array[i] << " ";
        if(i!=(this->maxsize-1))
          cout << ", ";
    }
    cout << " ]";
}


#endif /* _MYVECTOR_H_INCLUDED_ */