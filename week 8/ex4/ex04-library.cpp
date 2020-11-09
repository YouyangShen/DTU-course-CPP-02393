#include "ex04-library.h"
#include <iostream>

using namespace std;

//Do not modify
template<class T>
void Node<T>::printNode(){
	cout << "Name: " << name << ", value: " << value ;
	cout << ", children: " << children.size() << endl;
}

//Exercise 4 (a) Check and correct if necessary
template<class T>
Node<T>::Node(string name, T value){
	this->name = name;
	this->value = value;
}

//Exercise 4 (b) Implement getName, getValue, and addChild
template<class T>
string Node<T>::getName(){
	return name;
	//put your code here
}

template<class T>
T Node<T>::getValue(){
	return value;
	//put your code here
}

template<class T>
void Node<T>::addChild(Node<T> * child){
	children.push_back(child);//put your code here
}

//Exercise 4 (c) Implement this method
template<class T>
void Node<T>::printLeafNodes(){
	if(children.size()>0){
		for(int i=0;i<children.size();i++){
		children[i]->printLeafNodes();
		}
	}
	else {
		cout << this->name << ' ' << this->value << ' ';
	}
	//put your code here
}

//Exercise 4 (d) Implement this method
template<class T>
int Node<T>::countMembersOfSubTree(){
	int count = 1;
	
	
	if(children.size()>0){
		
			//count=count + children.size();
		for (int i =0;i<children.size();i++){
			
			
			 count = count + children[i]->countMembersOfSubTree();
		
		}
		
	}
	 return count;
//put your code here
}

//Do not modify
template class Node<string>;