#include "ex02-library.h"
#include <iostream>

//Do not modify
int Node::countChildren(){
	return children.size();
}

//Exercise 2 (a) Implement the constructor and getName()
Node::Node(string name){
	this->name = name;//put your code here
}

string Node::getName(){
	return this->name;//put your code here
}

//Exercise 2 (b) Implement this method
void Node::addChild(Node * child){
	children.push_back(child);//put your code here
}

//Exercise 2 (c) Check and correct if necessary
void Node::printParentNodes(){
		
	if(children.size()>0){
		cout << this->name << ' ';
		for(int i=0; i<children.size();i++){
		children[i]->printParentNodes();  //cout the address not the string
	    }
	}
}

//Exercise 2 (d) Implement this method
void Node::printMembersOfSubTree(int generation){
	if(children.size()>=0){
		cout << this->name << ' ' << generation << ' ';
		generation++;
		for (int i =0;i<children.size();i++){
		           
			  children[i]->printMembersOfSubTree(generation);
		     
		}
	}	
		//put your code here
}
