#include "MyVector.h"

#include <iostream>

//The constructors
template<class T>
MyVector<T>::MyVector() {
	capacity=1;
	size=0;
	content=new T[capacity];
}

template<class T>
MyVector<T>::MyVector(int initialCapacity) {
	capacity=initialCapacity;
	size=0;
	content=new T[capacity];
}

//The destructor: dellacate allocated memory
template<class T>
MyVector<T>::~MyVector() {
	delete [] content;
}

template<class T>
int MyVector<T>::getCapacity() {
	return capacity;
}

template<class T>
int MyVector<T>::getSize() {
	return size;
}

template<class T>
void MyVector<T>::push_back(T v){
	//If the array reached the current capacity, we have to increase it.
	if(size == capacity){
		resize();
	}
	content[size]=v;
	size=size+1;
}

template<class T>
void MyVector<T>::resize(){
	T * old_content = content;

	capacity=capacity*2;
	content=new T[capacity];

	for(int i=0;i<size;i++){
		content[i]=old_content[i];
	}

	delete[] old_content;
}

template<class T>
T MyVector<T>::at(unsigned int where){
	if(where >=size){
		throw std::out_of_range("you went out of range of your vector");
	}

	return content[where];
}

// Here we overload the operator _[_] to access
// myvector elements in array-style
template<class T>
T & MyVector<T>::operator[](unsigned int i)
{
    if(i>=size){
        throw std::out_of_range ("you went out of range of your myvector!");
    }
    // note that we do not return an element
    // but a reference to an element (see return type)
    return content[i];
}


// A user defined assignment operator
template<class T>
MyVector<T> & MyVector<T>::operator=(MyVector & v){
    // This is what the default would do
    this->capacity = v.capacity;
    this->size = v.size;
    //this->content = v.content; // which would just copy the pointer

    delete [] this->content;
    // we need instead to create a new copy of the underlying array
    this->content = new T[this->capacity];
    for(unsigned int i=0; i<size; i++){
        this->content[i] = v.content[i];
    }
    return * this;
}

