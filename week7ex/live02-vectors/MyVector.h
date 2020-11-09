#ifndef MYVECTOR_H
#define MYVECTOR_H

template<class T>
class MyVector {
private:
	//Array where elements are actually stored
	T *content;
	//Current size
	int size;
	//Current capacity
	int capacity;
	//Necessary to increase capacity (by copying content in a new array) if neeeded
	void resize();

public:
	//The constructors
	MyVector();
	MyVector(int initialCapacity);

	//The destructor
	~MyVector();

	//Get capacity and size.
	int getCapacity();
	int getSize();

	//Add element at the end
	void push_back(T v);

	//Get element at position where
	T at(unsigned int where);
	T & operator[](unsigned int where);

	//Redefinition of the assignment operator. Necessary to properly copy content.
	MyVector& operator=(MyVector &);
};

#include "MyVector.tpp"

#endif /* MYVECTOR_H */
