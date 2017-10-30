#include <iostream>
#include <cstdlib>
#include <stdexcept>
using namespace std;

class Node{
	public:
		Node();
		Node(int num, Node* nd, Node* prev_nd):data(num),next(nd), prev(prev_nd){};

		//Sentinels
		Node* next;
		Node* prev;
		//data attribute
		int data;
};

class Deque{
	private:
		Node* front;
		Node* back;
		int DequeSize;
	protected:
		void add(Node* place, const int & e);//add node before current place
		void remove(Node* place);
	public:
		Deque();//default constructor
		
		//Copy Constructor
		//PARAM: Deque object
		//POST: Creates a deep copy of the parameter
		Deque(const Deque & obj);
		
		//Overloaded Assignment Operator
		Deque & operator = (const Deque &obj);
		
		//Destructor
		~Deque();

		//----------------------Mutators-----------------------
		
		//PRE: Deque Declared or in scope
		//POST: Inserts at front of Deque
		//PARAM: value = value to be inserted
		void insertFront(const int& value);
		
		//PRE: Deque Delcared or in scope
		//POST: Insert at back of the Deque
		//PARAM: value = value to be inserted
		void insertBack(const int& value);
		
		//PRE: Deque declared or in scope
		//POST: Removes value at front of Deque
		//PARAM: N/A
		void removeFront();
		
		//PRE: Deque declared or in scope
		//POST: Removes value at back of Deque
		//PARAM: N/A
		void removeBack();
		
		//PRE: Deque declared or in scope
		//POST: Peek at value at the front
		//PARAM: N/A
		const int & peekFront()const;
		
		//PRE: Deque declared or in scope
		//POST: Peek at value in back
		//PARAM: N/A
		const int & peekBack()const;
		
		//PRE: Deque declared or in scope
		//POST: Returns true if empty, else returs false
		//PARAM: N/A
		bool empty()const;

		//PRE: Deque declared or in Scope
		//POST: Returns the size of the Deque
		//PARAM: N/A 
		int size()const;
		
		//PRE: Deque Declared or in scope
		//POST: Copys Deque
		//PARAM:
		void copyDeque(Node thisObj, Node inFront); 

};
//Default Constructor
Deque::Deque(){
	front = new Node;
	back = new Node;
	front->data = NULL;
	back ->data = NULL;
	front->next = back;
	back->prev = front;
	DequeSize = 0;
}
//Copy Constructor (Deep  Copy)
Deque::Deque(const Deque & obj){
	if(obj.peekFront() == NULL){//copy empty deque
		front = NULL;
		back = NULL;
		DequeSize = 0;
	}	
	else{
		copyDeque(this->peekFront(), obj.peekFront());
	}
}
//Helper function to copy constructor
void Deque::copyDeque(Node thisFront, Node inFront){
	if(inFront == NULL) thisFront = NULL;
	thisFront = new Node;
	thisFront->data = inFront->data;
	copyDeque(thisFront->next, inFront->next);
}

//Destructor
Deque::~Deque(){
	while(!empty()) removeFront();
	delete front;
	delete back;
}

//Overloaded Assignment operator
//Deque & Deque::operator=(const){

//}

bool Deque::empty() const {return (front -> next == back);}	//is the Deque empty?

const int & Deque::peekFront()const {return front->next->data;}//peek data at front

const int & Deque::peekBack()const {return back->prev->data;}  //peek data at back

void Deque::add(Node* place, const int & e){
	Node* temp = new Node; temp -> data = e;
	temp -> next = place;
	temp -> prev = place -> prev;
	place->prev->next = place->prev = temp;
}

//insert at front
void Deque::insertFront(const int& value){
	Node *in = new Node;
	in->data = value;
	in->prev = front;
	front = in;
}
//insert at back
void Deque::insertBack(const int& value){
	Node *in = new Node;
	in->data = value;
	in->next = back;
	back = in;
}
