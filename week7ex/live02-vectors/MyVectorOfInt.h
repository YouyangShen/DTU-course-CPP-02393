#ifndef MYVECTOROFINT_H_
#define MYVECTOROFINT_H_

class MyVectorOfInt {
private:
	//Array where elements are actually stored
	int *content;
	//Current size
	int size;
	//Current capacity
	int capacity;
	//Necessary to increase capacity (by copying content in a new array) if neeeded
	void resize();

public:
	//The constructors
	MyVectorOfInt();
	MyVectorOfInt(int initialCapacity);

	//The destructor
	~MyVectorOfInt();

	//Get capacity and size.
	int getCapacity();
	int getSize();

	//Add element at the end
	void push_back(int v);

	//Get element at position where
	int at(unsigned int where);
	int & operator[](unsigned int where);

	//Redefinition of the assignment operator. Necessary to properly copy content.
	MyVectorOfInt & operator=(MyVectorOfInt &);
};

#endif /* MYVECTOROFINT_H_ */
