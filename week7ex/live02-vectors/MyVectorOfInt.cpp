#include "MyVectorOfInt.h"

#include <iostream>

//The constructors
MyVectorOfInt::MyVectorOfInt() {
	capacity=1;
	size=0;
	content=new int[capacity];
}

MyVectorOfInt::MyVectorOfInt(int initialCapacity) {
	capacity=initialCapacity;
	size=0;
	content=new int[capacity];
}

//The destructor: dellacate allocated memory
MyVectorOfInt::~MyVectorOfInt() {
	delete [] content;
}

int MyVectorOfInt::getCapacity() {
	return capacity;
}

int MyVectorOfInt::getSize() {
	return size;
}

void MyVectorOfInt::push_back(int v){
	//If the array reached the current capacity, we have to increase it.
	if(size == capacity){
		resize();
	}
	content[size]=v;
	size=size+1;
}

void MyVectorOfInt::resize(){
	int * old_content = content;

	capacity=capacity*2;
	content=new int[capacity];

	for(int i=0;i<size;i++){
		content[i]=old_content[i];
	}

	delete[] old_content;
}

int MyVectorOfInt::at(unsigned int where){
	if(where >=size){
		throw std::out_of_range("you went out of range of your vector");
	}

	return content[where];
}

// Here we overload the operator _[_] to access
// myvector elements in array-style
int & MyVectorOfInt::operator[](unsigned int i)
{
    if(i>=size){
        throw std::out_of_range ("you went out of range of your myvector!");
    }
    // note that we do not return an element
    // but a reference to an element (see return type)
    return content[i];
}


// A user defined assignment operator
MyVectorOfInt & MyVectorOfInt::operator=(MyVectorOfInt & v){
    // This is what the default would do
    this->capacity = v.capacity;
    this->size = v.size;
    //this->content = v.content; // which would just copy the pointer

    delete [] this->content;
    // we need instead to create a new copy of the underlying array
    this->content = new int[this->capacity];
    for(unsigned int i=0; i<size; i++){
        this->content[i] = v.content[i];
    }
    return * this;
}

