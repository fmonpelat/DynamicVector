#ifndef _MYVECTOR_H_INCLUDED_
#define _MYVECTOR_H_INCLUDED_

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
        T &operator[](int );
        bool operator==(myVector<T>);
        bool operator!=(myVector<T>);
        myVector<T> &operator=(const myVector<T> &);
};

template<typename T>
myVector<T>::myVector()
{
    this->maxsize = 1;
    this->array = new T[this->maxsize];
    this->size = 0;

    for (int i = 0; i < this->maxsize; i++) 
      this->array[i] = 0; 

//  cout <<"Constructor sin Argumentos"<< endl;

}

template<typename T>
myVector<T>::myVector(int size)
{   
    this->maxsize = size;
    this->array = new T[this->maxsize];
    this->size = 0;

//      cout <<"Constructor por tamaño - size: "<< this->maxsize <<  endl;
//      cout << "     LLamado a: ";
}

template<typename T>
myVector<T>::myVector(const myVector<T> & vec)
{
//        cout <<"Constructor por vector"<< endl;
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

template <typename T>
myVector<T> &myVector<T>::operator=(const myVector<T> &rigth){

	if(&rigth != this){ /*Chequea que la dirección del objeto pasado (ejemplo Array B)
	 	 	 	 	 	 sea distinta de la direccion del objeto (ejemplo Array A)
	 	 	 	 	 	 sobre el que se ejecuta el código.*/
		if(size != rigth.maxsize){//Si el tamaño del Array A es distinto del Array B

			T *aux;
			aux = new T[rigth.maxsize];//Pido memoria del tamaño de Array B
			delete [] array;//Libero la memoria del Array A
			maxsize = rigth.maxsize;//Asigno el tamaño del Array B al Array A
			array = aux;//Asigno la memoria pedida al Array A

			for(int i = 0; i < maxsize; i++)
				array[i] = rigth.array[i];//Asigno los valores del Array B al Array A posicion por posicion

			return *this;//Devuelvo el objeto sobre el que se trabajo (Array A)
		}
		else{

			for(int i = 0; i < maxsize; i++)
				array[i] = rigth.array[i];//Asigno los valores del Array B al Array A posicion por posicion

			return *this; //al retotrnar una referencia permite x=y=z
		}
	}
	return *this;//Devuelvo el objeto sobre el que se trabajo (Array A)
}


template<typename T>
T & myVector<T>::operator[](int index)
{
  if ((index - 1) >= this->maxsize) {
    //cout << "     LLamado a: ";
    resize(index + 1);
  }

  this->size=index;

  return this->array[index]; // returned as a reference
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

/*
template<typename T>
void myVector<T>::resize(int newSize)
{
  
  cout << "in-resize" << endl;

  cout << "   Actual-vec-size: "<< this->maxsize << endl;

  T *temp;
  cout << "     LLamado a:\n"; //Constructor sin argumentos
  temp = new T [newSize];

//  for (int i = 0; i < newSize; i++){
//    cout << "     LLamado a: "; //Constructor por tamaño
//      temp[i](newSize);
//  }

  if(newSize > this->maxsize){
    cout << "     maxsize: " << this->maxsize << endl;
    cout << "     size: " << this->size << endl;
    for (int i = 0; i < maxsize; i++) {
      cout << "     Copiando direccónes de filas" << endl;
      temp[i] = this->array[i];
    }
  }
  else{
    for (int i = 0; i < newSize; i++){cout << "     aca2" << endl;
      temp[i] = this->array[i];
      }
      this->size=newSize;
  }
  cout << "     LLamado a: "; //Destructor
  delete[] this->array;
  this->array = temp;
  this->maxsize = newSize;

  cout << "   New-vec-size: "<< this->maxsize << endl;

  cout << "out-resize" << endl;

}
*/

template<typename T>
int myVector<T>::getsize()
{
    return this->maxsize;
}

template<typename T>
myVector<T>::~myVector()
{
  delete [] array;

//    cout<<"Destructor"<<endl;
}


#endif /* _MYVECTOR_H_INCLUDED_ */