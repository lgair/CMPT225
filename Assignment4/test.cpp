#include <iostream>
#include <string>
#include <stddef.h>
#include "hashtable.h"
#include <cmath>
using namespace std;

bool testPrime(int n);
int computeHash(string str);
int findP( int n);

int main(){
	int k = 12345678;
	bool prime = testPrime(k);
	cout <<"Is "<< k << " prime or not prime? : " << ((prime==0) ? "Not Prime" : "Prime") << endl;
	cout << "Next Prime : " << findP(k) << endl;
	string str =  "cat";
	cout << "Hashing : " << str << endl;
	computeHash(str);
}
bool testPrime(int n){
	bool test = false;
	if(n == 1) return true;
	for (int i = 2; i <= sqrt(n); i++){
		test = ((n%i != 0) ? true : false);
		if (!test) return false;
	}
	return test;
}
int computeHash(string str){
	int n = 26;
	int hash = 0;
	int j = str.length(); 
	for(int i = 0; i < j; i++){
		int asc = str[i] - 96;
		cout << asc << endl << endl;
		hash += asc*pow(32, j-(i+1));
	}
	hash = hash % n;
	cout <<"Hash key is: "<< hash << endl;
	return hash;
}
int findP(int n){
	int find = n+1;
	while(!testPrime(find)){find++;}
	return find;
}
