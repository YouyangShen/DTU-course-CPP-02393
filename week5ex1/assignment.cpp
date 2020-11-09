#include<iostream>
#include <fstream>
#include <vector>
#include <stack>
#include <set>
#include <algorithm>
#include <string>
using namespace std;
vector<int> aVector;
vector<int> bVector;

void avector(vector<string> &s){
	unsigned int x;
	
	for (int i=0;i<s.size();i++){
		if (s[i]== "a"){
			x=stoi(s[i+1]);
			aVector.push_back(x);
		}
	}
}

void bvector(vector<string> &s){
	unsigned int x;
	
	for (int i=0;i<s.size();i++){
		if (s[i]== "b"){
			x=stoi(s[i+1]);
			bVector.push_back(x);
		}
	}
}

int main(){
	string value;
    vector<string> input;
    cin >> value;
    input.push_back(value);
    while(cin.get() != '\n')
    {
        cin >> value;
        input.push_back(value);
    }
	avector(input);
	sort(aVector.begin(),aVector.end());
	for(int i=0;i<aVector.size();i++){
		cout << aVector[i] << " ";
	}
	bvector(input);
	sort(bVector.begin(),bVector.end());
	for(int i=0;i<bVector.size();i++){
		cout << bVector[i] << " ";
	}

}