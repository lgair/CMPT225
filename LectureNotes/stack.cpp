#include "stack.h"

stack::stack(void):top(0),arrSize(10),arr(new int[arrSize]){}
stack::stack(int n):top(0),arrSize(n),arr(new int[arrSize]){}
// copy constructor
stack::stack(const stack & st):arrSize(st.arrSize), top(st.top){
	copyStack(st);
}
//Destructor responsible for de allocating memory allocated by the class
stack::~stack(){delete[] arr;}
stack& stack::operation=(const stack & st){
	copyStack(st);
	return *this;	
}
//PRE:
//PARAM:
//POST;
void stack::push(int value){arr[top++] = value;}
//PRE:???
//POST: removes and returns value value at top of stack
int stack::pop(){return arr[--top];}
int stack::peek(){return arr[top-1];}
bool stack::empty(){return top;}

void stack::copyStack(){
	//make new array
	arr =  new int[arrSize];
	//copy content of parameter
	for(int i = 0; i < top; i++)
		arr[i] = st.arr[i];
}
