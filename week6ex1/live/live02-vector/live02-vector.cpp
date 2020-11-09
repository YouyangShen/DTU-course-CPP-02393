//============================================================================
// Name        : live02-MyVector.cpp
// Description : My own vector implementation
//============================================================================

#include <iostream>
#include "MyVector.h"

using namespace std;

int main(void) {
    
    MyVector v = MyVector();

    cout << "Vector size: " << v.size() << endl;
    cout << "Vector contents: ";
    v.print();
    cout << endl;

    cout << "Adding a bunch of elements" << endl;
    for (int i = 0; i < 30; i++) {
        v.push_back(i * 10);
    }

    v[2] = 1000;
    
    cout << "The element at position 2 is: " << v[2] << endl;

    cout << "Vector contents: ";
    v.print();
    cout << endl;

    { // Start a new scope
        cout << "*** New scope starts here!" << endl;
        MyVector w = MyVector();
        MyVector z = v; // This invokes the "copy constructor" to initialize z
        
        w = v; // This invokes the operator= of z
        
        w[10] = 8888888;
        z[10] = 9999999;
        cout << "The contents of w are: ";
        w.print();
        cout << endl;

        cout << "The contents of z are: ";
        z.print();
        cout << endl;

        // The scope ends here, and both w and z are deallocated
    }

    cout << "The contents of v are: ";
    v.print();
    cout << endl;
}
