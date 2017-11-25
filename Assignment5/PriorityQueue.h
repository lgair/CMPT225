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
		
		//PRE:
		//PARAM:
		//POST:
		/*int heapify(){
			int parent = (queueSize - 1)/2;
			for (int i = ((queueSize - 1)/2); i <= 0; i--){
				if (arr[i] > arr[2i+1] && arr[2i+2]) continue;
				else if( arr[i] < arr[2i+1] || arr[2i+2]){
					if(arr[2i+2] > arr[i]){
						arr[i] = arr[i] + arr[2i+2];
						arr[2i+2]=arr[i]-arr[2i+2];
						arr[i] = arr[i] - arr[2i+2];
					}
					if(arr[2i+1] > arr[i]){
						arr[i] = arr[i] + arr[2i+1];
						arr[2i+1]=arr[i]-arr[2i+1];
						arr[i] = arr[i] - arr[2i+1];
					}
					
				}
			}
		}; // heapifies array of type T variables*/
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
		//PARAM:
		//POST:
		void insert(int data);
		
		//PRE:
		//PARAM:
		//POST:
		int remove();
		
		//PRE: object initailized
		//PARAM: N/A
		//POST: returns item in the heap with the highest priority
		int peek() const;//done

		//PRE: object initialized
		//PARAM:N/A
		//POST:returns QueueSize
		int size() const;//done

		//PRE: Object initailized
		//PARAM: N/A
		//POST: Returns ArrSize
		int maxSize() const;//done

		//PRE: object initialized
		//PARAM: N/A
		//POST: returns true if empty else false
		bool empty()const;//done

		//PRE: Object initailized
		//POST: sorts the heap
		//PARAM; arr = arr to sort, size = ArrSize
		int* sort(int arr, int size);

		//PRE: object initialized
		//PARAM: N/A
		//POST: Returns pointer to PriorityQueue's underlying arr
		int* contents();//done
		//utility
		void bubbleup(int size);
		void swapAtIndex(int i, int j);
};

//Constructors
//template <class T>
PriorityQueue::PriorityQueue(): arrSize (4), queueSize(0), arr (new int[arrSize]){}
//template <class T>
PriorityQueue::PriorityQueue(int* arr,int n): arrSize (2*n),  queueSize (n){
	for (int i = 0; i < queueSize; i++){
		insert(arr[i]);
	}
}
//Copy Constructor
PriorityQueue::PriorityQueue(PriorityQueue & obj){
	cerr<<"copyflag"<<endl;
	queueSize = obj.size();
	arrSize = obj.maxSize();
	arr = new int[arrSize];
	for(int i = 0; i < queueSize; i++){arr[i] = obj.arr[i];}
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
	bubbleup(queueSize);
	queueSize++;
}
void PriorityQueue::bubbleup(int i){
	int parent = (i - 1)/2;
	if (arr[i] > arr[parent]){
		swapAtIndex(i, parent);
		bubbleup(parent);
	}
}
void PriorityQueue::swapAtIndex(int i, int j){
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}
int PriorityQueue::remove(){
}
int PriorityQueue::peek()const{
	if(empty()){return arr[0];}
	else{throw std::runtime_error("Empty array");}//try catch block?
}
int PriorityQueue::size() const {return queueSize;}
int PriorityQueue::maxSize() const {return arrSize;}
bool PriorityQueue::empty() const {return (queueSize == 0 ? true:false);}
//template <class T>
int* PriorityQueue::contents()  { return arr;}
