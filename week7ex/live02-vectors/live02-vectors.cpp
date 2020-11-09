//============================================================================
// Name        : live02-vectors.cpp
// Description : Motivation for using templates: vector of int, of double, ...
//               all share most of the code.
//============================================================================

#include <iostream>
using namespace std;

//#include "MyVectorOfInt.h"
#include "MyVector.h"

int main() {
	MyVector<int> a;
	MyVector<int> b(10);

	for (int i = 0; i < 10; i++) {
		a.push_back(i);
	}

	for (int i = 0; i < a.getSize(); i++) {
		cout << a[i] << " ";
	}
	cout << endl;
	// Output: 0 1 2 3 4 5 6 7 8 9

	for (int i = 0; i < a.getSize(); i++) {
		a[i] = a[i] + 2.5;
	}
	cout << endl;

	for(int i = 0; i < a.getSize(); i++){
		cout << a[i] << " ";
	}
	cout << endl;
	// Output: 2 3 4 5 6 7 8 9 10 11
}

