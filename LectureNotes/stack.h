#pragma once
class stack
{
public:
//constructors and destructors
//default constructor
	stack();
	stack(int n);
	stack(const stack & st);//passed by reference
	~stack();
	stack& operator=(const stack & st); 
//Mutators
//PRE:
//PARAM value = value to be inserted
//POST:value is inserted at the top of the stack
	void push(int value);
//PRE:
//PARAM:---
//POST:Removes and returns the value at the top of the stack
	int pop();

//Accessors
//PRE:
//POST: returns value at top of stack
	int peek();
private:
	int* arr;
	int top;
	int arrSize;
	void copyStack(const stack & st);
};
