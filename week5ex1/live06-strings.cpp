//============================================================================
// Name        : live06-strings.cpp
// Description : Strings are assigned (=) using aliasing/pointers, but by making copies.
//============================================================================

#include <iostream>
#include <string>
using namespace std;

int main() {
	string s1 = "Test";

	cout << "s1 ("<< s1 <<") has length " << s1.length() <<"\n\n";

	// When you assign a string, you actually copy it
	string s2 = s1;

	s1[1] = 'b';

	cout << "s1 is: " << s1 << endl;
	cout << "s2 is: " << s2 << endl;

	return 0;
}
