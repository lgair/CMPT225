#include "StringSet.h"
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;
//Function Prototype
void constructorTest();
void insertTest();
void removeTest();
void SizeTest();
void UnionTest();
void interTest();
void diffTest();
void generalTest();
void generalTest2();

int main(){
	cout << "Running: " << endl;
	constructorTest();
//	insertTest();
	removeTest();
	SizeTest();
	UnionTest();
	interTest();
	diffTest();
	generalTest();
	generalTest2();
	return 0;
}
void constructorTest(){
	StringSet str1;
	cout << "Constructor Test: " << endl;
	cout << "------------------------------" << endl;
	cout << "String Size: : " << str1.size() << " should be zero." << endl;
	cout << setw(20) << "Complete" << endl << endl;
}

void insertTest(){
	// inserts hello world and hi into StringSet Variable
	// also tests for duplicates
	StringSet obj1;
	int n;
	cout << "Insert Test: " << endl;
	cout << "------------------------------"<< endl << endl;
	cout << "How many strings to insert? : ";
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		string ins;
		cout << "	Insert string "<< i+1 <<" : ";
		cin >> ins;
		cout << "	Inserting : "<< ins << endl;
		obj1.insert(ins);
	}
	cout << endl;
	obj1.print();

	cout << setw(20) << "Complete" << endl << endl;
}

void removeTest(){
	StringSet obj1;
	cout << "Remove Test: " << endl;
	cout << "------------------------------"<< endl << endl;
	obj1.insert("Apple");
	obj1.insert("Pear");
	obj1.insert("Peach");
	obj1.insert("Tomato");
	obj1.print();
	cout << "Removing a String : " << endl;
	obj1.remove("Apple");
	obj1.print();
	cout << setw(20) << "Complete" << endl << endl;
}
void SizeTest(){
	StringSet obj1;
	cout << "Size Test: " << endl;
	cout << "------------------------------"<< endl << endl;
	obj1.insert("Apple");
	obj1.insert("Pear");
	obj1.insert("Peach");
	obj1.insert("Tomato");
	obj1.print();
	cout << obj1.size() << endl;
	cout << setw(20) << "Complete" << endl << endl;

}
void UnionTest(){
	StringSet obj1;
	cout << "Union Test: " << endl;
	cout << "------------------------------"<< endl << endl;
	cout << "StringSet 1 : " << endl;
	obj1.insert("Apple");
	obj1.insert("Pear");
	obj1.insert("Peach");
	obj1.insert("Tomato");
	obj1.print();
	cout << "StringSet 2 : " << endl;
	StringSet obj2;
	obj2.insert("Apple");
	obj2.insert("Pear");
	obj2.insert("Tomato");
	obj2.insert("Plum");
	obj2.print();
	StringSet obj3(obj1.unions(obj2));
	cout << "StringSet union : " << endl;
	obj3.print();
	cout << setw(20) << "Complete" << endl << endl;
}
void interTest(){
	StringSet obj1;
	cout << "Intersection Test: " << endl;
	cout << "------------------------------"<< endl << endl;
	cout << "StringSet 1 : " << endl;
	obj1.insert("Apple");
	obj1.insert("Pear");
	obj1.insert("Peach");
	obj1.insert("Tomato");
	obj1.print();
	cout << "StringSet 2 : " << endl;
	StringSet obj2;
	obj2.insert("Apple");
	obj2.insert("Pear");
	obj2.insert("Tomato");
	obj2.insert("Plum");
	obj2.print();
	StringSet obj3(obj1.intersection(obj2));
	cout << "StringSet Intersection : " << endl;
	obj3.print();
	cout << setw(20) << "Complete" << endl << endl;
}	

void diffTest(){
	StringSet obj1;
	cout << "difference Test: " << endl;
	cout << "------------------------------"<< endl << endl;
	cout << "StringSet 1 : " << endl;
	obj1.insert("Apple");
	obj1.insert("Pear");
	obj1.insert("plum");
	StringSet obj2;
	obj2.insert("Apple");
	obj2.insert("pear");
	obj1.print();
	obj2.print();
	StringSet obj3(obj1.difference(obj2));
	obj3.print();
	cout << setw(20) << "Complete" << endl << endl;
}

void generalTest() {

	StringSet obj1;
	StringSet obj2;
	cout << "GENERAL TEST:" << endl;
	obj1.insert("Apple");
	obj1.insert("Orange");
	obj1.insert("Carrot");
	obj1.insert("Cherry");

	obj2.insert("Carrot");
	obj2.insert("Cherry");
	obj2.insert("Tomato");

	StringSet obj5(obj1.unions(obj2));
	cout << "Union of Obj1 and Obj2" << endl;
	obj5.print(); // Expected values: "Apple, Orange, Carrot, Cherry, Tomato"
	cout << endl;

	StringSet obj6(obj1.difference(obj2));
	cout << "Obj1 - Obj2 (Difference)" << endl;
	obj6.print(); // Expected values: "Apple, Orange"
	cout << endl;

	StringSet obj7(obj1.intersection(obj2));
	cout << "Intersection of Obj1 and Obj2" << endl;
	obj7.print(); // Expected values: "Carrot, Cherry"
	cout << endl;

	StringSet obj3(obj2);
	cout << "Object 3 Copy" << endl;
	obj3.print(); // Expected values: "Apple, Orange, Carrot, Cherry"
	cout << endl;
//
	StringSet obj4 = obj1;
	cout << "Object 4 Copy" << endl;
	obj4.print(); // Expected values: "Apple, Carrot, Cherry, Tomato"
	cout << endl;

	obj1.remove("Apple");
	obj2.remove("Cherry");

	cout << "Object 1 Values (Remove)" << endl;
	obj1.print(); // Expected values: "Orange, Carrot, Cherry"
	cout << endl;

	cout << "Object 2 Values (Remove)" << endl;
	obj2.print(); // Expected values: "Carrot, Tomato"
	cout << endl;

}

void generalTest2() {

		StringSet obj1;
		StringSet obj2;
		cout << "GENERAL TEST 2:" << endl;
		obj2.insert("Apple");
		obj2.insert("Orange");
		obj2.insert("Carrot");
		obj2.insert("Cherry");

		obj1.insert("Carrot");
		obj1.insert("Cherry");
		obj1.insert("Tomato");

		StringSet obj5(obj1.unions(obj2));
		cout << "Union of Obj1 and Obj2" << endl;
		obj5.print(); // Expected values: "Apple, Orange, Carrot, Cherry, Tomato"
		cout << endl;

		StringSet obj6(obj1.difference(obj2));
		cout << "Obj1 - Obj2 (Difference)" << endl;
		obj6.print(); // Expected values: "Tomato"
		cout << endl;

		StringSet obj7(obj1.intersection(obj2));
		cout << "Intersection of Obj1 and Obj2" << endl;
		obj7.print(); // Expected values: "Carrot, Cherry"
		cout << endl;

		StringSet obj3(obj2);
		cout << "Object 3 Copy" << endl;
		obj3.print(); // Expected values: "Apple, Orange, Carrot, Cherry"
		cout << endl;

		StringSet obj4 = obj1;
		cout << "Object 4 Copy" << endl;
		obj4.print(); // Expected values: "Carrot, Cherry, Tomato"
		cout << endl;

		obj2.remove("Apple");
		obj1.remove("Cherry");

		cout << "Object 2 Values (Remove)" << endl;
		obj2.print(); // Expected values: "Orange, Carrot, Cherry"
		cout << endl;

		cout << "Object 1 Values (Remove)" << endl;
		obj1.print(); // Expected values: "Carrot, Tomato"
		cout << endl;

	}

