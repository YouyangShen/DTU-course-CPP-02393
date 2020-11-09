//============================================================================
// Name        : live05-fileIO.cpp
// Description : Example on how to read/write in files
//============================================================================

#include <iostream>
#include <fstream>
using namespace std;

int main() {
	cout << "Which file would you like to read?" << endl;
	string fileName;

	cin >> fileName;

	ifstream infile;
	infile.open(fileName);

	//infile.open(fileName.c_str());
	if(infile.fail()){
		cout << "I could not open the file " << fileName << endl;
		cout << "I give you another chance. Which file would you like to read?" << endl;
		cin >> fileName;
		infile.clear();
		infile.open(fileName);
		if(infile.fail()){
			cout << "I could not open the file " << fileName << endl;
			return 1;
		}
	}

	cout << endl << endl << "Read using infile >> s" << endl << endl;

	string s;
	while(!infile.fail()){
		infile >> s;
		if(infile.fail()){
			break;
		} else {
			cout << s << endl;
		}

	}

	infile.close();

	cout << endl << endl << "Read using int character = infile.get()" << endl << endl;
	infile.open(fileName);
	while(!infile.fail()){
		int character = infile.get();
		if(infile.fail()){
			break;
		} else {
			cout << (char)character;
		}

	}

	infile.close();

	cout << endl << endl << "Read using int character = infile.get()" << endl << endl;
	infile.open(fileName);
	int ch;
	while((ch=infile.get())!=EOF){
		cout << (char)ch;
	}
	infile.close();


	cout << endl << endl << "Read using getline(infile,line) + save copy.txt" << endl << endl;
	infile.open(fileName);

	ofstream outfile;
	outfile.open("copy.txt");

	string line;
	while(!infile.fail()){
		getline(infile,line);
		if(infile.fail()){
			break;
		} else {
			cout << line << endl;
			outfile << line << endl;
		}
	}
	infile.close();

	outfile.close();

	return 0;
}
