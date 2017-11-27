#include <iostream> 
#include <string> 
#include <stdlib.h> 
#include <stdexcept> 

using namespace std; 

//template <class T>
class PriorityQueue {
private:
	int * arr; 
	int queueSize; 
	int arrSize; 

	//PRE: N/A
	//PARAM:arr = arr of template variables n = size of array
	//POST: heapifies array of template variables
	int heapify(int * arr, int size){
		for (int i = size/2-1; i >= 0; i--){
			maxHeapify(arr, size, i);
		}
	}

	//MAX heapify methood -- essentially bubbledown
	int maxHeapify(int *arr, int size, int i) {
		int parent = i;
		int leftChild = 2*i+1;
		int rightChild = 2*i+2;

		if(leftChild < size && arr[leftChild] > arr[parent]){
			parent = leftChild;
		}
		if(rightChild < size && arr[rightChild] > arr[parent]){
			parent = rightChild;
		}
		if(parent != i){
			std::swap(arr[parent], arr[i]);
			cout << "recursing" << endl;
			maxHeapify(arr,  size, parent);
		}
	}

	//helper function to print out the arr
	void arrPrint(int *arr, int size){
		for (int i = 0; i < size; i++){
			cout << arr[i]<<",";
		}
		cout << endl;
	}
public:
	//Constructors
	PriorityQueue(); 
	PriorityQueue(int vars[] , int size); 
	PriorityQueue(const PriorityQueue & obj); 
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
	int peek()const; //done

	//PRE: object initialized
	//PARAM:N/A
	//POST:returns QueueSize
	int size()const; //done

	//PRE: Object initailized
	//PARAM: N/A
	//POST: Returns ArrSize
	int maxSize()const; //done

	//PRE: object initialized
	//PARAM: N/A
	//POST: returns true if empty else false
	bool empty()const; //done

	//PRE: Object initailized
	//POST: sorts the heap
	//PARAM; arr = arr to sort, size = ArrSize
	void sort(int *arr, int n); 

	//PRE: object initialized
	//PARAM: N/A
	//POST: Returns pointer to PriorityQueue's underlying arr
	int *contents() const; //done

	//---------------------utility---------------------------
	void bubbleup(int i);
	void swapAtIndex(int i, int j);
	void bubbleDown(int i);
	void deepCopy(const PriorityQueue &obj);
	int printHeap(int i) const;
	
	//PRE: Object exists
	//PARAM: Initial call MUST index from the root (i = 0)
	//POST: returns true if the heap property exists else false
	bool isHeap(int i) const;
};

//Constructors
PriorityQueue::PriorityQueue() : arrSize(4), queueSize(0), arr(new int[arrSize]) {}
PriorityQueue::PriorityQueue(int vars[], int n){
	arrSize = 2 * n;
	queueSize = n;
	arr = new int[n];
	for (int i = 0; i < n; i++){
		cout <<"constrFlag" << endl;
		insert(vars[i]); //segfault
		//cout << i << endl;
	}
}

//Copy Constructor
PriorityQueue::PriorityQueue(const PriorityQueue &obj){
	deepCopy(obj);
}

//Overlaoded assignment operator
PriorityQueue &PriorityQueue::operator=(const PriorityQueue &obj){
	if (this != &obj){
		delete[] arr;
		deepCopy(obj);
	}
	return *this;
}

//Destructor
//template <class T>
PriorityQueue::~PriorityQueue() { delete[] arr; }

//template <class T>
void PriorityQueue::insert(int data){
	if (queueSize == arrSize){
		arrSize += arrSize;
		int *temp = new int[arrSize];
		for (int i = 0; i < arrSize; i++)
			temp[i] = arr[i];
		arr = new int[arrSize];
		for (int j = 0; j < arrSize; j++)
			arr[j] = temp[j];
		delete[] temp;
	}
	queueSize++;
	arr[queueSize - 1] = data;
	bubbleup(queueSize - 1);
}

int PriorityQueue::remove(){
	if (empty()){throw std::runtime_error("Empty array");}
	else{	
		int root = arr[0]; //root should be largest value in the queue
		arr[0] = arr[queueSize - 1];
		queueSize--;
		bubbleDown(0);
		return root;
	}
}

int PriorityQueue::peek() const{
	if (!empty()){return arr[0];}
	else{throw std::runtime_error("Empty array");} //try catch block?
}

//Getters
int PriorityQueue::size() const { return queueSize; }
int PriorityQueue::maxSize() const { return arrSize; }

//isEmpty test
bool PriorityQueue::empty() const { return (queueSize == 0); }

// in-place sort
void PriorityQueue::sort(int *arr, int n){
	//build heap
	arrPrint(arr,n);
	heapify(arr,n);
	arrPrint(arr,n);
}

//direct access to private variable
//template <class T>
int *PriorityQueue::contents() const { return arr; }

//Utility
void PriorityQueue::bubbleup(int i){
	int leftChild = i;
	int rightChild = i + 1;
	int parent = (i - 1) / 2;
	if (leftChild > 0 && arr[leftChild] > arr[parent]){
		swapAtIndex(leftChild, parent);
		cout << endl;
		bubbleup(parent);
	}
}

void PriorityQueue::bubbleDown(int i) {
 	int parent = i;
	int leftChild = 2*i+1;
	int rightChild = 2*i+2;
	if(leftChild < queueSize && arr[parent] < arr[leftChild]){
		parent = leftChild;
	}
	if(rightChild < queueSize && arr[parent] < arr[rightChild]){
		parent = rightChild;
	}//check children and swap to correct places
	if(parent != i){ 
		cout <<"swapping: "<<arr[leftChild]<<"<->"<<arr[rightChild]<<endl;
		swapAtIndex(parent, i);
		cout << "recursing" << endl;
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
bool PriorityQueue::isHeap(int i) const{
	int leftChild = 2*i+1;
	int rightChild = 2*i+2;
	int parent = i;
	if (leftChild > queueSize - 1){return true;} //parent has no children
	else if (rightChild > queueSize - 1){ // checks node with only left children
		return arr[parent] > arr[leftChild];
	}
	//parent has two children
	else{
		if ((arr[parent]>arr[leftChild])&&(arr[parent]>arr[rightChild])){
			return isHeap(leftChild) && isHeap(rightChild);
		}
		else{
			return false;
		}
	}
}
void PriorityQueue::deepCopy(const PriorityQueue &obj){
	queueSize = obj.queueSize;
	arrSize = obj.arrSize;
	arr = new int[arrSize];
	for (int i = 0; i < queueSize; i++){arr[i] = obj.arr[i];}
}

