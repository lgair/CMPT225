#include <iostream>
#include <string>
#include <stddef.h>
#include "HashTable.h"
using namespace std;

//Constructors and Destructors
HashTable::HashTable(): n(101), m(0), table(NULL){}
HashTable::HashTable(int size): n(size), m(0), table(NULL){}
//Create Deep copy of HashTable Reference Paramenter
HashTable::HashTable(const HashTable & obj){
	Deep_copy(obj);
}
//overloaded assignment
//HashTable& HashTable::operator=(HashTable obj){
	// Implement overloaded assignment here
//}

void HashTable::insert(string input){
	
}

int HashTable::search(string findThis){
	bool found = false;
	//if (findThis == found)
	//	return getFrequency();
	//else
		return 0;
}

int HashTable::size()const{
	return m;
}

int HashTable::maxSize()const{
	return n;
}

double HashTable::loadFactor()const{
	double alpha = n/m;
	double MAX =  2/3;
	return (alpha < MAX ? alpha : -1);
}

WordFrequency *HashTable::dump()const{
	return *table;
}

//Utility Function
void HashTable::Deep_copy(const HashTable & obj){
	//Implement Deep Copy here
}
