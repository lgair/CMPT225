#include <iostream>
#include <string>
#include <stdexcept>
#include "PriorityQueue.h"
using namespace std;
void print(PriorityQueue & obj);

int main(){
	PriorityQueue obj1;
	PriorityQueue obj2;
	int foo[5]={69,420,2001,1812,1811};
	obj1.sort(foo,5);
	
//	PriorityQueue obj3(foo,5);
//	cout << obj3.contents()<< endl;
//	cout << obj3.size() << endl;
//	print(obj3);
	cout << "is obj1 empty? " << (obj1.empty()? "yes":"no") << endl;
	for (int i = 0; i < 5; i++){
		obj1.insert(i);
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
	for (int i = 0; i < 5 /*obj2.size()*/;i++){
		cout << endl;
		cout <<"remove " << i << ": " << obj2.remove() << endl;
		print(obj2);
	}
	PriorityQueue obj4;
	//obj4.remove();
}
void print(PriorityQueue & obj){
	int * data = obj.contents();
	for (int i = 0; i < obj.size(); i++){
		cout << data[i] << ",";
	}
	cout << endl;
	cout <<"isHeap??? " << (obj.isHeap(0)?"yes":"no") << endl;
}
