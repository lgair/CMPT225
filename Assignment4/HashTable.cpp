#include <iostream>
#include <string>
#include <stddef.h>
#include "HashTable.h"
#include <cmath>
using namespace std;

//Constructors and Destructors
HashTable::HashTable(): n(101), m(0), table(NULL){}
HashTable::HashTable(int size): n(size), m(0), table(NULL){}

//Create Deep copy of HashTable Reference Paramenter
HashTable::HashTable(const HashTable & obj){
	Deep_copy(obj);
}

//Destructor
HashTable::~HashTable(){
	for(int i = 0; i < n; i++){
		delete[] table[i];
	}
	delete[] table;
}

//overloaded assignment operator
HashTable& HashTable::operator=(const HashTable& obj){
	if(this != &obj){
		for (int i = 0; i < n; i++){
			delete[] table[i];//Remove the left
		}
		HashTable(obj);//copy right into left
	}
	return *this;
}

void HashTable::insert(string input){
	double alpha = 0; //load factor
	alpha = loadFactor();
	if(alpha = -1){//load factor exceeded, resize array
		n += n;
		n = findPrime(n);
		HashTable(n);
		for (int i = 0; i < m; i++){
			for (int j = 0; j < n; j++){
				table[j] = table[i];
			}
		}
		// rehash table?
	}	
	int freq = search(input);
	//string not in table, insert at key value
	if (freq == 0){
	}
	//string in table one or more times insert via quadratic probing, 
	else if(freq <= 1){
		int i = 1;
		for(int q = 0; q < n; q = pow(i,2)){
			++i;
			if( table[q] == NULL ){ 
			//	insert;
			}
		}
	}
}

int HashTable::search(string findThis){
	int key = 0;
	//int keyFreq = 0;
	key = HashValue(findThis);
	// implement probing in the search
	if (table[key] != NULL && table[key]->getWord() == findThis)
		return table[key]->getFrequency();
	else
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
	WordFrequency *dumpTable[m];
	for(int i = 0; i < m; i++){
		for (int j = 0; j < n; j++){
			if(table[j] != NULL)
				dumpTable[i]=table[j];
		}
	}
	return *dumpTable;
}

//Utility Function
void HashTable::Deep_copy(const HashTable & obj){
	n = obj.n;
	m = obj.m;
	for (int i = 0; i < m; i++){
		if (obj.table[i] != NULL){
			table[i] = new WordFrequency(obj.table[i]->getWord(), obj.table[i]->getFrequency());
		}
		else
			table[i] = NULL;
	}
}
//function finds next prime from n linearly
int HashTable::findPrime(int n){
	int prime = n+1;
	while (!isPrime(prime)){prime++;}
	return prime;
}

int HashTable::HashValue(string str){
	int hash = 0;
	int j = str.length();
	for(int i = 0; i < j; i++){
		int asc = str[i] - 96;
		hash += asc*pow(32, j-(i+1));
	}
	hash %= n;
//	cout << "Hash Key is : " << hash << endl;
	return hash;
}
