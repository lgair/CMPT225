#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdexcept>

using namespace std;

//template <class T>
class PriorityQueue{
	private:
		int *arr;
		int queueSize;
		int arrSize;
		
		//PRE: N/A
		//PARAM:arr = arr of template variables n = size of array
		//POST: heapifies array of template variables
		int heapify(int* arr, int n){}; // heapifies array of type T variables*/
	public:
		//Constructors
		PriorityQueue();
		PriorityQueue(int*,int size);
		PriorityQueue( PriorityQueue & obj);
		//Destructor
		~PriorityQueue();
		//Overloaded Assignment Operator
		PriorityQueue & operator = (const PriorityQueue & obj);

		//------------------Data methods----------------------
		
		//PRE:
		//PARAM: data = template variable to insert
		//POST: inserts into ADT and maintains MAXHEAP properties
		void insert(int data);
		
		//PRE: obj exists
		//PARAM: N/A
		//POST: Extracts value with highest priority and ensures max heap 
		//properties are maintaned
		int remove();
		
		//PRE: object initailized
		//PARAM: N/A
		//POST: returns item in the heap with the highest priority
		int peek()const;//done

		//PRE: object initialized
		//PARAM:N/A
		//POST:returns QueueSize
		int size()const;//done

		//PRE: Object initailized
		//PARAM: N/A
		//POST: Returns ArrSize
		int maxSize()const;//done

		//PRE: object initialized
		//PARAM: N/A
		//POST: returns true if empty else false
		bool empty()const;//done

		//PRE: Object initailized
		//POST: sorts the heap
		//PARAM; arr = arr to sort, size = ArrSize
		void sort(int* arr, int n);

		//PRE: object initialized
		//PARAM: N/A
		//POST: Returns pointer to PriorityQueue's underlying arr
		int* contents()const;//done

		//---------------------utility---------------------------
		void bubbleup(int i);
		void swapAtIndex(int i, int j);
		void bubbleDown(int i);
		
		//PRE: Object exists
		//PARAM: Initial call MUST index from the root (i = 0)
		//POST: returns true if the heap property exists else false
		bool isHeap(int i)const;
};

//Constructors
//template <class T>
PriorityQueue::PriorityQueue(): arrSize (4), queueSize(0), arr (new int[arrSize]){}
//template <class T>
PriorityQueue::PriorityQueue(int* arr,int n): arrSize (2*n),  queueSize (n){
	for (int i = 0; i < queueSize-1; i++){
		insert(arr[i]);
	}
}

//Copy Constructor
PriorityQueue::PriorityQueue(PriorityQueue & obj){
	cerr<<"copyflag"<<endl;
	queueSize = obj.size();
	arrSize = obj.maxSize();
	arr = new int[arrSize];
	for(int i = 0; i < queueSize-1; i++){arr[i] = obj.arr[i];}
}

//Overlaoded assignment operator
PriorityQueue & PriorityQueue::operator=(const PriorityQueue & obj){
	if(this != &obj){
		cerr << "flag1"<< endl;
		delete[] arr;
		PriorityQueue(obj);
	}
	cerr << "flag2"<< endl;
	return *this;
}

//Destructor
//template <class T>
PriorityQueue::~PriorityQueue(){delete[] arr;}

//template <class T>
void PriorityQueue::insert(int data){
	if(queueSize == arrSize){
		arrSize += arrSize;
		int* temp = new int[arrSize];
		for (int i = 0; i < arrSize; i++)temp[i] = arr[i];
		arr = new int[arrSize];
		for ( int j = 0; j < arrSize; j++ ) arr[j] = temp[j];
		delete[] temp;
	}
	arr[queueSize] = data;
	if(!isHeap(0)){bubbleup(queueSize);}
	queueSize++;
}

int PriorityQueue::remove(){
	if(empty()){throw std::runtime_error("Empty array");}
	int root = arr[0];//root should be largest value in the queue
	arr[0] = arr[queueSize-1];
	if(!isHeap(0)){bubbleDown(0);}
	queueSize--;
	return root;
}

int PriorityQueue::peek()const{
	if(empty()){return arr[0];}
	else{throw std::runtime_error("Empty array");}//try catch block?
}

//Getters
int PriorityQueue::size() const {return queueSize;}
int PriorityQueue::maxSize() const {return arrSize;}

//isEmpty test
bool PriorityQueue::empty() const {return (queueSize == 0 ? true:false);}

// in-place sort
void PriorityQueue::sort(int* arr, int n){
	heapify(arr, n);
}

//direct access to private variable
//template <class T>
int* PriorityQueue::contents() const {return arr;}

//Utility
void PriorityQueue::bubbleup(int i){
	int parent = (i - 1)/2;
	if (arr[i] > arr[parent]){
		swapAtIndex(i, parent);
		bubbleup(parent);
	}
}
void PriorityQueue::bubbleDown(int i){
	int parent = i;
	int leftChild = 2*i+1;
	int rightChild = 2*i+2;
	if(leftChild < queueSize && arr[parent] > arr[leftChild]){
		parent = leftChild;
	}
	if(rightChild < queueSize && arr[parent] > arr[rightChild]){
		parent = rightChild;
	}
	//check children and swap to correct places
	if(parent != i){
		swapAtIndex(leftChild,rightChild);
		bubbleDown(parent);
	}
}

// standard swap function
void PriorityQueue::swapAtIndex(int i, int j){
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

//checks if the heap property is preserved
bool PriorityQueue::isHeap(int i)const{
	if(2*i+1 > queueSize-1){return true;}//i has no children
	else if(2*i+2 > queueSize-1){// checks node with only left children
		return arr[i] < arr[2*i+1];
	}
	//i has two children
	else{
		if((arr[i] < arr[2*i+1])&&(arr[i] < arr[2*i+2])){
			return isHeap(2*i+1) && isHeap(2*i+2);
		}
		else {
			return false;
		}
	}
}
