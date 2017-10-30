#pragma once
class ArrayClass
{
	private:
		int*arr;
		int arrSize;
		int n;
		
	public:
		/* Constuctors and Destructors
		POST: Creates an ArrayClass object with an array of size 2
		PARAM:*/
		ArrayClass();
		/*Destructor
		POST: De-allocates Dynamic memory associated with the object*/
		~ArrayClass();
		/*Accessors and Mutators
		Set value of next free element
		PRE:
		POST: sets intex n to value, doubles size of arr if n == arrSize, increments n
		PARAM: value = value to be set*/
		void insert( int value);
		/*Returns the sum of the values stored in the array
		PRE:
		POST: returns sum of the first n elements of arr*/
		int sum();
		/*Returns the number of elements stored in the array
		PRE:
		POST: returns n*/
		int size();
		//PRE:---
		//PARAM:---
		//POST: Displays current values indexed in array
		virtual void peek(;
};
