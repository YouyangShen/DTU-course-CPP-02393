//============================================================================
// Name        : live01-allocation-stack-heap.cpp
// Description : How are vectors and arrays allocated? With solutions
//============================================================================

#include <iostream>
#include <vector>
using namespace std;

// See: http://www.learncpp.com/cpp-tutorial/79-the-stack-and-the-heap/

int *createArrayBAD() {
    int a[2]; // This array is created in the stack of this function
    a[0] = 1;
    a[1] = 2;
	return a; // When the function ends, the memory pointed by a is deallocated
}

int *createArrayGOOD() {
    int *a = new int[2]; // This array is created in the heap
    a[0] = 1;
    a[1] = 2;
	return a; // When the function ends, the memory pointed by a remains allocated
}

int main(){
    // This variable x is created in in the stack
    int x = 0;

    cout << "x is " << x << endl;

    // This opens a scope, just as when using for, while, if, ...
    {
        // This variable x is allocated in the stack, and masks the x above
        int x = 1;

        cout << "x is " << x << endl;

        // This opens yet another scope
        {
            // This variable x is allocated in the stack, and masks the x above
            int x = 2;
            cout << "x is " << x << endl;
        } // this closes the scope, the x above is deallocated

        cout << "x is " << x << endl;
    } // this closes the scope, the x above is deallocated

    cout << "x is " << x << endl;

    return 0;

}
