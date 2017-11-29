#include <iostream>
#include <string>
#include <stdexcept>
#include "PriorityQueue.h"
using namespace std;
void print(PriorityQueue<int> & obj);
void printS(PriorityQueue<string> &obj);

void test1(){
	int arr[] = {5, 9, 6, 7, 1, 3, 8};
	int size = 7;
	PriorityQueue<int> pq1(arr, size);

	int* temp = pq1.contents();
	for(int i = 0; i < pq1.size(); i++){
		cout << temp[i] << " ";
	}
	pq1.insert(10);
	print(pq1);
}

int main(){
	PriorityQueue<int> obj1;
	PriorityQueue<int> obj2;
	int foo[6]={69,420,2001,1812,1811,1997};
	int bar[6] = {10,10,10,10,10,19};
	obj1.sort(foo,6);
	string foo2[3] ={"1","2","3"};
	PriorityQueue<string> obj4(foo2,3);
	printS(obj4);
	obj4.remove();
	obj4.insert("5");
	//printS(obj4);
	PriorityQueue<string> obj5;
	//obj5.insert("hallo");
	PriorityQueue<int> obj3(bar, 6);
//	cout << obj3.contents()<< endl;
//	cout << obj3.size() << endl;
	print(obj3);
//	cout << "is obj1 empty? " << (obj1.empty()? "yes":"no") << endl;
	for (int i = 0; i < 6; i++){
		obj1.insert(i+69);
		print(obj1);
	}
	cout <<"obj1.peek(): " << obj1.peek()<<endl;
	cout << "is obj1 empty? " << (obj1.empty()? "yes":"no") << endl;
	obj2 = obj1;
//	cout << "is obj2 empty? " << (obj2.empty()? "yes":"no") << endl;
//	cout << "queueSize: " << obj2.size() << endl;
//	cout << "arrSize: " << obj2.maxSize() << endl;
	cout << "Print Heap, then remove: " << endl;
	print(obj2);
//	cout << "obj2 remove: " << obj2.remove() << endl;
	//print(obj2);
	//obj2.remove();
	for (int i = 0; i < 6/* obj2.size()*/;i++){
		cout <<"remove " << i << ": " << obj2.remove() << endl;
		print(obj2);
	}
	//obj4.remove();
	cout << "running test1" <<endl;
	test1();
}
void print(PriorityQueue<int> & obj){
	int * data = obj.contents();
	for (int i = 0; i < obj.size(); i++){
		cout << data[i] << ",";
	}
	cout << endl;
	cout <<"isHeap??? " << (obj.isHeap(0)?"yes":"no") << endl << endl;
}
void printS(PriorityQueue<string> & obj){
	string * data = obj.contents();
	for (int i = 0; i < obj.size(); i++){
		cout << data[i] << ",";
	}
	cout << endl;
	cout <<"isHeap??? " << (obj.isHeap(0)?"yes":"no") << endl << endl;

}
