#include <iostream>
#include "ArrayClass.h"

using namespace std;
//function prototype
void exceptionTest();

int main(){
	//arrayClassTest();
	exceptionTest();

	return 0;
}
void exceptionTest(){
	ArrayClass ac;
	//insert 1 - 10 inegers in ac
	int n = 10;
	int value = 9;
	for(int i = 0; i < n; i++){
		ac.insert(i+1);
	}
	//get and set values(may throw errors)


	try{
		for(int i = 0; i <= ac.size();++i){
			cout << ac.get(i) << endl;
		}
	}
	catch(std::out_of_range oor){
		cout << oor.what() << endl;
	}
	try{
		for(int i = 0; i <= ac.size();++i){
			ac.set(i,value);
		}
	}
	catch(std::out_of_range oor){
		cout << oor.what() << endl;
	}
}
