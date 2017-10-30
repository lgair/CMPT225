//lab5 test file
// cmpt225testLab.cpp : Defines the entry point for the console application.
//
#include <iostream>
#include "LinkedList.h"
using namespace std;
 
void removeTest();
void rmTest1();//removing item from empty list
void rmTest2();//removing value at the head and tail the list
void rmTest3();// list of identical values?
void rmTest4();
void rmTest5();
//void rmTest6();
int main()
{
	removeTest();//seems to work
//	rmTest1();// aha! segmentation fault
	rmTest2();// fails to remove head, segmentation fault on tail removal
//	rmTest3();// segementation fault on removal of consecutive values
//	rmTest4();// previous is not set properly, print reversal fails
	rmTest5();// size is not updated
	return 0;
}
//works when there are values to be found
void removeTest()
{

       LinkedList list;
       int arr[] = { 1,3,5,7,3,5,7,9 };
       int n = 8;
	for (int i = 0; i < n; ++i) {
              list.insertTail(arr[i]);
       }

	list.printForwards();
	cout << "remove 3s: " << list.remove(3) << endl;
       list.printForwards();
       cout << endl;
}
// empty list
void rmTest1(){
	LinkedList list;
	int arr[] = {};
	int n = 0;
	for(int i = 0; i < n; i++)
		list.insertTail(arr[i]);

	list.printForwards();
	cout << "Remove 7s: " << list.remove(7) << endl;
	list.printForwards();
	cout << endl;
}
//remove value at head
void rmTest2(){
       LinkedList list;
       int arr[] = { 1,3,5,7,3,5,7,9 };
       int n = 8;
	for (int i = 0; i < n; ++i) {
              list.insertTail(arr[i]);
       }

	list.printForwards();
	int HEAD = 1;
	int TAIL = 9;
	cout << "remove head and tail of list: " <<endl;
	if(list.remove(HEAD) == 0) cout << "Removal of head Failed" << endl;
	//if(list.remove(TAIL) == 0) cout << "Removal of tail Failed" << endl;
	//removal of tail results in segmentation fault
       list.printForwards();
       cout << endl;
}
// remove value at tail


//remove consecutive items
void rmTest3(){
	//when list has all items the same
       LinkedList list;
       int arr[] = { 1,1,1,1,1,1,1,1 };
       int n = 8;
	for (int i = 0; i < n; ++i) {
              list.insertTail(arr[i]);
       }

	list.printForwards();
	cout << "Remove 0s : " << list.remove(0) << endl;
	cout << "Remove 1s (all items in list):" << list.remove(1) << endl;
	cout << endl;
}
// print reversal
void rmTest4(){
       LinkedList list;
       int arr[] = { 1,3,5,7,3,5,7,9 };
       int n = 8;
       cout << "Remove 3s: " << list.remove(3) << endl;
	for (int i = 0; i < n; ++i) {
              list.insertTail(arr[i]);
       }

	list.printForwards();
	list.printBackwards();// fails here
}
//size fail
void rmTest5(){
       LinkedList list;
       int arr[] = { 1,3,5,7,3,5,7,9 };
       int n = 8;
	for (int i = 0; i < n; ++i) {
              list.insertTail(arr[i]);
       }

	list.printForwards();
	cout << "Remove 3s: " << list.remove(3) << endl;
	cout << "Curent size should be 6: reported size--" << list.size() << endl;
}
