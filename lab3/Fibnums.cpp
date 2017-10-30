#include <iostream>
using namespace std;
int fib(int n);
int binearySearch( int arr[], int start, int end, int x);
double factorial (int x);
double factorialTail(int x, int result);

int main(){
	int fibn;
	int MinFact = 1;
	cout << "select integer : " << endl;
	cin >> fibn;
	cout << fib(fibn) << endl;
	cout << "Fibnum Factorial : " << factorial(fibn) << endl;
	cout << "Fibnum FactorialTail : " << factorialTail(fibn,MinFact) << endl;
}

int fib(int n){
	if (n == 0 || n == 1) return n;
	return fib(n-1) + fib(n-2);
}
int binearySearch( int arr[], int start, int end, int x){
	int mid = (start + end)/2;
	if (start > end) return -1;//base case
	else if (arr[mid] == x) return mid;//second base case
	else if (arr[mid] < x) return binearySearch(arr, mid+1, end, x);
	return binearySearch(arr,start,mid-1, x); // arr[mid] > target
}
double factorial(int x){
	if (x == 0 || x == 1) return 1;
	return x*factorial(x-1);
}
double factorialTail(int x, int result){
	if(x <= 1) return result;
	return factorialTail(x-1, result*x);
}
