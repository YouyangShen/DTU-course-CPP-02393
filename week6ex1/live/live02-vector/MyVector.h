#ifndef MYVECTOR_H_
#define MYVECTOR_H_

class MyVector {

public:
    // Constructors
    MyVector();
    MyVector(const MyVector& orig);
    // The last constructor above is called the "copy constructor"
    // It is invoked when performing e.g.:
    // MyVector w = v;  (it allows to initialize w using v's contents)

    // Destructor
    ~MyVector(); // Destructor

    void print();
    unsigned int size(void);
    void push_back(int val);
    int at(unsigned int i);
    int & operator[](unsigned int i);
    MyVector & operator=(MyVector &orig);

private:
    int *content;
    unsigned int capacity; // Size of array pointed by content
    unsigned int vsize; // "Visible" size of vector

    void resize();
};

#endif /* MYVECTOR_H_ */
