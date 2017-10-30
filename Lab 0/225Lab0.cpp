#include <iostream>
#include <iomanip>
using namespace std;
//Luke Gair CMPT 225 Lab 0 Assignment written September 8th 2017
//function takes dynamic array and sums all the items in it and prints the sums
//function deletes the dynamic array before termination

//functuon header
int sumArray(int arr[],int sizeOfArray);

int main(){
	int ArrSize = 0;
	int num = 0;
	int* values = nullptr;
	std::cout << "how many numbers would you like to input?" << endl;
	std::cin >> ArrSize;
	values = new int[ArrSize];//allocates a new dynamic array of ArrSize
	for (int i = 0; i < ArrSize; i++){
		std::cout <<"Please enter the " << i+1 <<" number: ";
		std::cin >> num;
		values[i] = num;
	}
	std::cout<<"The sum of the array is: "<<sumArray(values,ArrSize)<<endl;
	return 0;
}

int sumArray( int arr[],int sizeOfArray){
	int sum = 0;
	for(int i = 0; i < sizeOfArray; i++){
		sum += arr[i];
	}
	delete[] arr;
	return sum;
}