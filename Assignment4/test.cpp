#include <iostream>
#include <string>
#include <stddef.h>
#include "hashtable.h"
#include <cmath>
using namespace std;

int main(){
	int hash = 0;
	string str =  "dog";
	int j = str.length();
	for(int i = 0; i < j; i++){
		int asc = str[i] - 96;
		cout << asc << endl << endl;
		hash += asc*pow(32, j-(i+1));
	}
	cout << hash << endl;
	return hash;
}
