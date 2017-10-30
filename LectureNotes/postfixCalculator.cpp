#include <iostream>
#include "stack.h"
using namespace std;

void pushpotTest();
void copyTest();
void assignmentTest();

int main()
{
	//std::cout << "hello world" << endl;
//	stack st;
//	for( int i = 0; i < n; i++){st.push(i+1);}
//	for (int i = 0; i < n; i++){cout << st.pop() <<endl;}
//	return 0;
//	copytest();
	assignmentTest();
	return 0;
}

void pushpoptest() {
	cout << endl <<;
		
}

void copytest(){
	cout << "copy test" << endl << endl;
	int n =4
	stack st1(n);
	for (int i = 0; i <n; i++){st1.push(i+1;}
	stack st2(n);
	st2.push(21);
	st2.push(22)
	cout << "top  of stack2" << st2.peek() << endl;
	cout << "empty stack 2:" << endl;
	while(!st2.empty()){cout << st2.pop()<<endl;}
	while(!st1.empty()){cout<< st1.pop()<<endl;}
	cout << "stacktest complete" << endl;
}
