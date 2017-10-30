#include "LinkedList.h"

// Default constructor
// PARAM: 
// PRE:
// POST: Creates an empty list
LinkedList::LinkedList(void)
{
	front = NULL;
}

// Copy constructor
// PARAM: ls is the list to be assigned to the calling object
// PRE:
// POST: Creates an object that is a copy of ls
LinkedList::LinkedList(const LinkedList & ls)
{
	deepCopy(ls);
}

// Destructor
// PARAM:
// PRE:
// POST: Memory associated with list is de-allocated
LinkedList::~LinkedList(void)
{
	deleteList();
}

// Inserts string in list in lexographic order
// PARAM: s = string to be inserted
// PRE:
// POST: s is inserted in order into list
void LinkedList::insert(string s)
{
	// List is empty or s should be at front
	// Note the short circuit evaluation
	if(front == NULL || s < front->data){
		front = new Node(s, front);
	}else{
		Node* p = front; // for traversing list
		// Find correct position for s
		while(p->next != NULL && p->next->data < s){
			p = p->next;
		}
		p->next = new Node(s, p->next);
	}
}

// Removes first incidence of from the list
// PARAM: s = string to be removed
// PRE:
// POST: Removes s from list return true if s was in the
//       list, false otherwise
bool LinkedList::remove(string s)
{
	Node* temp = front;
	// list is empty
	if(temp == NULL){
		return false;
	}
	// s is first string in list
	if(temp->data == s){
		front = temp->next;
		delete temp;
		return true;
	}else{
		// Continue as long as element is less than s
		while(temp->next != NULL && temp->next->data < s){
			temp = temp->next;
		}
		// Delete s if found
		if(temp->next->data == s){
			Node* deletedNode = temp->next;
			temp->next = temp->next->next;
			delete deletedNode;
			return true;
		}else{
			return false;
		}
	}
}

bool LinkedList::empty()const
{
	return front == NULL;
}

// Overloaded assignment operator
// In ls1 = ls2 assigns ls2 to ls1 and returns ls1
// PARAM: ls = list to be assigned to the calling object
// PRE:
// POST: Copies ls to calling object, returns calling object
LinkedList & LinkedList::operator= (const LinkedList & ls)
{
	if(this != &ls){
		deleteList();
		deepCopy(ls);
	}
	return *this;
}

// Prints the contents of the list in reverse order
// i.e. in order, using recursion
// PARAM: 
// PRE:
// POST: Prints list
void LinkedList::print()const
{
	Node* temp = front;

	// Traverse list
	while(temp != NULL){
		cout << temp->data << endl;
		temp = temp->next;
	}
}

// Prints the contents of the list in reverse order
// i.e. in order, using recursion
// PARAM: 
// PRE:
// POST: Prints list in reverse order
void LinkedList::reverse_print()const
{
	reverse_print_rec(front);
}

// Recursive helper function for reverse_print
// PARAM: nd = the current node (to be printed)
// PRE:
// POST: Prints node
void LinkedList::reverse_print_rec(Node* nd) const
{
	if(nd != NULL){
		reverse_print_rec(nd->next);
		cout << nd->data << endl;
	}
}

// Makes a deep copy of a list
// PARAM: ls is the list to copied
// PRE: Calling object is empty
// POST: List contents are identical to ls
void LinkedList::deepCopy(const LinkedList & ls)
{
	front = NULL;
	
	// Only copy if ls is non-empty
	if(ls.front != NULL){
		Node* original = ls.front;
		Node* copy;
		// Copy the front
		copy = new Node(original->data, NULL);
		front = copy;
		original = original->next;

		// Traverse the original copying each node
		while(original != NULL){
			copy->next = new Node(original->data, NULL);
			copy = copy->next;
			original = original->next;
		}
	}
}

// Removes all the items from the list and
// deallocates dynamic memory associated with nodes
// PARAM: 
// PRE:
// POST: List is empty
void LinkedList::deleteList()
{
	Node* temp = front;
	// Traverse list
	while(temp != NULL){
		temp = front->next;
		delete front;
		front = temp;
	}
	front = NULL;
}


