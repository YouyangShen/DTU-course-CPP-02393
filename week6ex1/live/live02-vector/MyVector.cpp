#include "MyVector.h"
#include <iostream>

// Constructor
MyVector::MyVector() {
    this->capacity = 10;
    this->content = new int[this->capacity];
    this->vsize = 0;
}

// Another constructor (called copy constructor)
// Notice that it is similar to operator= (see below), but here this->content
// is not initialized yet, hence it must not be delete[]d.
MyVector::MyVector(const MyVector &orig) {
    this->capacity = orig.capacity;
    this->vsize = orig.vsize;
    // this->content = orig.content; // WRONG!!!

    this->content = new int[this->capacity];

    for (int i = 0; i < this->vsize; i++) {
        this->content[i] = orig.content[i];
    }
}

// Destructor
MyVector::~MyVector() {
    delete[] this->content;
}

unsigned int MyVector::size() {
    return this->vsize;
}

void MyVector::print() {
    for (unsigned int i = 0; i < this->vsize; i++) {
        std::cout << content[i] << " ";
    }
    std:: cout << std::endl;
}

int MyVector::at(unsigned int i) {
    if (i >= this->vsize) {
        throw std::out_of_range("Access out of range");
    }
    return this->content[i];
}

int & MyVector::operator[](unsigned int i) {
    if (i >= this->vsize) {
        throw std::out_of_range("Access out of range");
    }
    return this->content[i];
}

void MyVector::push_back(int val) {
    if (this->vsize == this->capacity) {
        this->resize();
    }
    this->content[this->vsize] = val;
    this->vsize++;
}

void MyVector::resize() {
    this->capacity += 10;
    int *newContent = new int[this->capacity];

    for (unsigned int i = 0; i < this->vsize; i++) {
        newContent[i] = this->content[i];
    }

    delete[] this->content;
    this->content = newContent;
}

MyVector & MyVector::operator=(MyVector &orig) {
    this->capacity = orig.capacity;
    this->vsize = orig.vsize;
    // this->content = orig.content; // WRONG!!!

    delete[] this->content;
    this->content = new int[this->capacity];

    for (int i = 0; i < this->vsize; i++) {
        this->content[i] = orig.content[i];
    }

    return *this;
}
