//============================================================================
// Name        : live00-aarayInitialization.cpp
// Description : Arrays' entries are not necessarily initialized to zero!
//============================================================================

#include <iostream>
using namespace std;

int main() {
	cout << "Dynamically allocated array" << endl;

	int n = 10;
	int *array = new int[n]; // The values in this array are not initialized
	for(int i=0; i<n; i++) {
		cout << array[i] << ' ';
	}
	cout << endl;
	delete[] array;

	array = new int[n](); // The values in this array are initialized to 0
	for(int i=0; i<n; i++) {
		cout << array[i] << ' ';
	}
	cout << endl;

	delete[] array;
	
	//////////////////////////////////////////////////////////////////////////

	cout << endl << "Statically allocated array" << endl;
	int arrayStatic[10]; // The values in this array are not initialized
	for(int i=0; i<10; i++) {
		cout << arrayStatic[i] << ' ';
	}
	cout << endl;

	int arrayStaticTwo[10] = {}; // The values in this array are initialized to 0
	for(int i=0; i<10; i++) {
		cout << arrayStaticTwo[i] << ' ';
	}
	cout << endl;

	return 0;
}
