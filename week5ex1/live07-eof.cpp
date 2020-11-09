//============================================================================
// Name        : live07-eof.cpp
// Description : Two ways to detect the end-of-file (EOF) using cin >> var
//============================================================================

#include <iostream>
using namespace std;

int main() {
    cout << "To end your input, press either:" << endl;
    cout << "    * Enter and then CTRL+D (Linux, MacOS)" << endl;
    cout << "    * Enter and then CTRL+Z and then Enter (Windows)" << endl;

    string word;
    cout << "Please write something: ";

    // Suggested method: repeat until `cin >> word` returns false
    while (cin >> word) {
        cout << "Input: " << word << endl;
    }

    // Alternative method: repeat forever, and break if cin reports a failure
    // NOTE: to use the code below, you must comment out the 'while' loop above
    /*
    while (true) {
        cin >> word;
        if (cin.fail()) {
            break;
        }
        cout << "Input: " << word << endl;
    }
    */

    cout << "EOF!" << endl << endl;
    
    return 0;
}
