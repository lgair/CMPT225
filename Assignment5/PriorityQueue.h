#include <iostream> 
#include <string> 
#include <stdlib.h> 
#include <stdexcept> 

using namespace std; 

template <class T>
class PriorityQueue {
private:
	T * arr; 
	int queueSize; 
	int arrSize; 

	//PRE: N/A
	//PARAM:arr = arr of template variables n = size of array
	//POST: heapifies array of template variables
	void heapify(T * arr, int size){
		for (int i = size/2-1; i >= 0; i--){
			maxHeapify(arr, size, i);
		}
	}

	//MAX heapify methood -- essentially bubbledown
	void maxHeapify(T *arr, int size, int i) {
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
			maxHeapify(arr,  size, parent);
		}
	}

	//helper function to print out the arr
	void arrPrint(T *arr, int size){
		for (int i = 0; i < size; i++){
			cout << arr[i]<<",";
		}
		cout << endl;
	}
public:
	//Constructors
	PriorityQueue(); 
	PriorityQueue(T vars[] , int size); 
	PriorityQueue(const PriorityQueue<T> & obj); 
	//Destructor
	~PriorityQueue(); 
	//Overloaded Assignment Operator
	PriorityQueue<T> & operator = (const PriorityQueue<T> & obj); 

	//------------------Data methods----------------------

	//PRE:
	//PARAM: data = template variable to insert
	//POST: inserts into ADT and maintains MAXHEAP properties
	void insert(T data); 

	//PRE: obj exists
	//PARAM: N/A
	//POST: Extracts value with highest priority and ensures max heap
	//properties are maintaned
	T remove(); 

	//PRE: object initailized
	//PARAM: N/A
	//POST: returns item in the heap with the highest priority
	T peek()const; //done

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
	void sort(T *arr, int n); 

	//PRE: object initialized
	//PARAM: N/A
	//POST: Returns pointer to PriorityQueue's underlying arr
	T *contents() const; //done

	//---------------------utility---------------------------
	void bubbleup(int i);
	void swapAtIndex(int i, int j);
	void bubbleDown(int i);
	void deepCopy(const PriorityQueue<T> &obj);
	int printHeap(int i) const;
	
	//PRE: Object exists
	//PARAM: Initial call MUST index from the root (i = 0)
	//POST: returns true if the heap property exists else false
	bool isHeap(int i) const;
};

//Constructors
template <class T>
PriorityQueue<T>::PriorityQueue() : arrSize(4), queueSize(0), arr(new T[arrSize]){}
template <class T>
PriorityQueue<T>::PriorityQueue(T vars[], int n){
	arrSize = n;
	queueSize = n;
	arr = new T[n];
	for (int i = 0; i < n; i++){
		arr[i] = vars[i]; //segfault
	}
	heapify(arr,n);
}

//Copy Constructor
template <class T>
PriorityQueue<T>::PriorityQueue(const PriorityQueue<T> &obj){
	deepCopy(obj);
}

//Overlaoded assignment operator
template <class T>
PriorityQueue<T> &PriorityQueue<T>::operator=(const PriorityQueue<T> &obj){
	if (this != &obj){
		delete[] arr;
		deepCopy(obj);
	}
	return *this;
}

//Destructor
template <class T>
PriorityQueue<T>::~PriorityQueue() { delete[] arr; }

//insert
template <class T>
void PriorityQueue<T>::insert(T data){
	if (queueSize == arrSize){
		arrSize += arrSize;
		T *temp = new T[arrSize];
		for (int i = 0; i < arrSize; i++)
			temp[i] = arr[i];
		arr = new T[arrSize];
		for (int j = 0; j < arrSize; j++)
			arr[j] = temp[j];
		delete[] temp;
	}
	queueSize++;
	arr[queueSize - 1] = data;
	bubbleup(queueSize - 1);
}

template <class T>
T PriorityQueue<T>::remove(){
	if (empty()){throw std::runtime_error("Empty array");}
	else{		
		T root = arr[0]; //root should be largest value in the queue
		arr[0] = arr[queueSize - 1];
		queueSize--;
		bubbleDown(0);
		return root;
	}
}
template <class T>
T PriorityQueue<T>::peek() const{
	if (!empty()){return arr[0];}
	else{throw std::runtime_error("Empty array");} //try catch block?
}

//Getters
template <class T>
int PriorityQueue<T>::size() const { return queueSize; }
template <class T>
int PriorityQueue<T>::maxSize() const { return arrSize; }

//isEmpty test
template <class T>
bool PriorityQueue<T>::empty() const { return (queueSize == 0); }

// in-place sort
template <class T>
void PriorityQueue<T>::sort(T *arr, int n){
	heapify(arr,n);
	for(int i = n-1; i >= 0; i--){
		std::swap(arr[0],arr[i]);
		maxHeapify(arr, n, 0);
	}
	arrPrint(arr,n);
}

//direct access to private variable
template <class T>
T *PriorityQueue<T>::contents() const { return arr; }

//Utility
template <class T>
void PriorityQueue<T>::bubbleup(int i){
	int leftChild = i;
	int rightChild = i + 1;
	int parent = (i - 1) / 2;
	if (leftChild > 0 && arr[leftChild] > arr[parent]){
		std::swap(arr[leftChild],arr[parent]);
		bubbleup(parent);
	}
}

template <class T>
void PriorityQueue<T>::bubbleDown(int i) {
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
	//	cout <<"swapping: "<<arr[leftChild]<<"<->"<<arr[rightChild]<<endl;
		std::swap(arr[parent], arr[i]);
	//	cout << "recursing" << endl;
		bubbleDown(parent);
	}
}

// standard swap function
template <class T>
void PriorityQueue<T>::swapAtIndex(int i, int j){
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

//checks if the heap property is preserved
template <class T>
bool PriorityQueue<T>::isHeap(int i) const{
	int leftChild = 2*i+1;
	int rightChild = 2*i+2;
	int parent = i;
	if (leftChild > queueSize - 1){return true;} //parent has no children
	else if (rightChild > queueSize - 1){//checks node with only left children
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
//Helper to copy constructor and overloaded assignment operator
template <class T>
void PriorityQueue<T>::deepCopy(const PriorityQueue<T> &obj){
	queueSize = obj.queueSize;
	arrSize = obj.arrSize;
	arr = new T[arrSize];
	for (int i = 0; i < queueSize; i++){arr[i] = obj.arr[i];}
}

