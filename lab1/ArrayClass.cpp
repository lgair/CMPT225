#include "ArrayClass.h"
#include <new>
#include <iostream>
#include <iomanip>
using namespace std;
/* ---defenitions--- 
Contructor
POST: Creates an ArrayClass object with and array of size 2
PARAM:

~Destructor
POST: De-allocates dynamic memory associated with object

Size returns the number of elements stored in the array
PRE: Creates and ArrayClass object with an Array of size 2
POST: Returns n

Insert Sets the next free element
PRE:
POST: Sets index n to value, doubles size of arr if n == arrsize, increments n
PARAM: value = value to be set*

Sum adds up all the elements currently in the array
PRE:
POST: returns sumArray */
ArrayClass::ArrayClass(): arrSize (2), arr (new int[arrSize]), n (0){}
ArrayClass::~ArrayClass(){delete[] arr;}
int ArrayClass::size(){return n;}
void ArrayClass::insert(int value)
{
	if ( n == arrSize)//check if array is full
	{
		arrSize +=  arrSize;
		int* temp = new int[arrSize];
		for ( int i = 0; i < arrSize; i++){temp[i] = arr[i];}
		arr =  new int [arrSize];
		for ( int j = 0; j < arrSize; j++){arr[j] = temp[j];}
		delete[] temp;
	}
	arr[n] = value;
	n++;
}
int ArrayClass::sum(){
	int sum = 0;
	for(int i = 0; i < n; i++){
		sum += arr[i];
	}
//	delete[] arr;
	return sum;
}
void ArrayClass::peek(){
	for (int i = 0; i<n ; i++){
	cout << setw(7) << i << setw (13) << arr[i] << endl << endl;
	}

}

