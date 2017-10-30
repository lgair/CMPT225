// cmpt225LinkedList.cpp : Defines the entry point for the console application.
//

#include "LinkedList.h"
#include <iostream>

using namespace std;

void insertTest();
void removeTest();
void copyTest();
void assignTest();
void printTest();
void reversePrintTest();
LinkedList listabc();
void removeAndPrint(LinkedList & ls, string s);
int sum(int x);


int main()
{
	//insertTest();
	//removeTest();
	//copyTest();
	//assignTest();
	//printTest();
	reversePrintTest();

	//int x = 5000;
	//cout << "sum of 1 to " << x << " = " << sum(x);
	
	cout << endl << endl;
	cin.get();
	return 0;
}

void insertTest()
{
	LinkedList ls;
	ls.insert("demeter");
	ls.insert("ares");
	ls.insert("poseiden");
	ls.insert("zeus");
	ls.insert("hades");
	ls.insert("athena");
	ls.insert("hermes");
	ls.insert("artemis");
	ls.insert("apollo");
	ls.insert("aphrodite");
	ls.print();
}

void removeTest()
{
	LinkedList ls;
	ls.insert("demeter");
	ls.insert("ares");
	ls.insert("poseiden");
	ls.insert("zeus");
	ls.print();
	removeAndPrint(ls, "ares");
	removeAndPrint(ls, "poseiden");
	removeAndPrint(ls, "thor");
	removeAndPrint(ls, "zeus");
	removeAndPrint(ls, "demeter");
	removeAndPrint(ls, "demeter");
	ls.insert("hades");
	ls.insert("athena");
	ls.insert("hermes");
	removeAndPrint(ls, "hermes");
}

void copyTest()
{
	LinkedList ls1;
	ls1.insert("hades");
	ls1.insert("athena");
	ls1.insert("hermes");
	ls1.insert("artemis");

	LinkedList ls2(ls1);
	cout << "ls1" << endl << "---" << endl;
	ls1.print();
	cout << endl << "remove hades and artemis from ls1" << endl;
	cout << "ls2" << endl << "---" << endl;
	ls2.print();
}

void assignTest()
{
	LinkedList ls;
	ls = listabc();
	ls = ls;
	ls.print();
}

void printTest()
{
	LinkedList ls;
	ls.insert("demeter");
	ls.insert("ares");
	ls.insert("poseiden");
	ls.insert("zeus");
	ls.insert("hades");
	ls.insert("athena");
	ls.insert("hermes");
	ls.insert("artemis");
	ls.insert("appolo");
	ls.insert("aphrodite");
	ls.print();
}

void reversePrintTest()
{
	LinkedList ls;
	ls.insert("demeter");
	ls.insert("ares");
	ls.insert("poseiden");
	ls.insert("zeus");
	ls.insert("hades");
	ls.insert("athena");
	ls.insert("hermes");
	ls.insert("artemis");
	ls.insert("appolo");
	ls.insert("aphrodite");
	ls.reverse_print();
}

LinkedList listabc()
{
	LinkedList result;
	result.insert("hades");
	result.insert("athena");
	result.insert("hermes");
	result.insert("artemis");
	return result;
}

void removeAndPrint(LinkedList & ls, string s)
{
	cout << endl << "remove " << s << endl;
	ls.remove(s);
	ls.print();
}

int sum(int x){
	if (x == 0 || x == 1){
		return x; 
	} else {
 		return x + sum(x - 1);
	}
}

