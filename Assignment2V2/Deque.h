#include <cstdlib>
#include <stdexcept>
using namespace std;

//template <class T>
class Node{
	public:
		 Node* left;
		 Node* right;
		 int thisIn;
		//Constructors
		Node();
		Node(const Node & in): left(in.left),right(in.right),thisIn(in.thisIn){}
};
//template <class T>
class Deque{
	private:
		int dequeSize;
		Node *front;
		Node *back;
	public:
		Deque();//default constructor
		
		//Copy Constructor
		//PARAM: Deque object
		//POST: Creates a deep copy of the parameter
		Deque(const Deque & obj){
			if(obj.front == NULL){
				front = NULL;
				back = NULL;
				dequeSize = 0;
			}
			copyDeque(this->front,obj.front);
		}
		//helper function
		void copyDeque(Node *thisfront, Node *inFront);
		
		//Destructor
		~Deque();

		//Overloaded Assignment Operator
		Deque & operator = (const Deque & obj);

		//------------------Mutators-------------------------

		//PRE: Deque declared or in scope
		//POST: Inserts at the front
		//PARAN: value = value to be inserted
//		template <class T>
		bool insertFront(int value);
		
		//pre: deque declared or in scope
		//post: inserts at back
		//param:  value = value to be inserted
//		template <class T>
		bool insertBack(int value);

		//PRE: Deque declared or in scope
		//POST: Removes value at front
		//PARAM: N/A
//		template <class T>
		int removeFront();
		
		//PRE: Deque declared or in scope
		//POST: Removes value at back
		//PARAM: N/A
//		template <class T>
		int removeBack();

		//PRE: Deque declared or in scope
		//POST: Look at value in front
		//PARAM: N/A
//		template <class T>
		int peekFront()const;

		//PRE: Deque declared or in scope
		//POST: Look at value in back
		//PARAM: N/A
//		template <class T>
		int peekBack()const;

		//PRE: Deque declared or in scope
		//POST: Check if class is empy (return true if it is else false)
		//PARAM: N/A
		bool empty() const;

		//PRE: Deque declared or in scope
		//POST: Find Current Size of Deque
		//PARAM: N/A
		int size() const;
};
//Constructor
Deque::Deque(){
	dequeSize = 0;
	front = new Node;
	back = new Node;
	front -> thisIn = NULL;
	back -> thisIn = NULL;
	front -> right = back;
	back -> left = front;
}
//Destructor
Deque::~Deque(){
	while (!empty()) removeFront();
	delete front;
	delete back;
}
//Insertions
bool Deque::insertFront(int value){
	if(front->right == back){
		front->thisIn = value;
		Node *in = new Node;
		front -> left = in;
		in -> right = front;
		dequeSize++;
	}
	Node *in = new Node;
	in -> left = NULL;
	in -> thisIn = value;
	in -> right = front;
	front -> left = in;
	dequeSize++;
	return true;
}
bool Deque::insertBack(int value){
	if(back->left == front){
		back->thisIn = value ;
		Node *in = new Node;
		back -> right = in;
		in -> left = back;
		dequeSize++;
	}
	Node *in = new Node;
	in -> right = NULL;
	in -> thisIn = value;
	in -> left = back;
	back -> right = in;
	dequeSize++;
	return true;
}
//removals
int Deque::removeBack(){ return 0;/*didnt have time to complete*/ }
int Deque::removeFront(){ return 0;/*didnt have time to complete*/ } 

//Is Empty?
bool Deque::empty() const {return ((front == back) ? true : false);}//true if front is the back

//Peeks
int Deque::peekFront() const {return front->thisIn;}
int Deque::peekBack() const {return back->thisIn;}

//Size?
int Deque::size() const {return dequeSize;}
