#pragma once
#include <cstdlib>
#include <string>
#include <iostream>
using namespace std;

class LinkedList
{
public:
	LinkedList(void);
	LinkedList(const LinkedList & ls);//copy constructor
	~LinkedList(void); //destructor

	void insert(string);
	bool remove(string);
	bool empty()const;
	void print()const;
	void reverse_print()const;

	// Overloaded assignment operator
	LinkedList & operator= (const LinkedList & st);

private:
	
	class Node {
	public:
		string data;
		Node* next;

		Node(string s): data(s), next(NULL) {};
		Node(string s, Node* nd): data(s), next(nd) {};
	};

	Node* front;
	void deepCopy(const LinkedList & ls);
	void deleteList();
	void reverse_print_rec(Node* nd) const;
};



