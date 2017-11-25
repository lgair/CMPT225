#include <iostream>
#include <string>
#include <stdexcept>
#include "PriorityQueue.h"
using namespace std;

int main(){
PriorityQueue obj1;
PriorityQueue obj2;
cout << obj1.contents()<< endl;
//cerr << obj1.peek()<<endl;
int foo[5]={0,1,2,3,4};
//PriorityQueue(*foo,5);
cout << "queueSize: " << obj1.size() << endl << "arrSize: " << obj1.maxSize() << endl;
cout << "is obj1 empty? " << (obj1.empty()? "yes":"no") << endl;
for (int i = 0; i < 6; i++) obj1.insert(i);
cout << "is obj1 empty? " << (obj1.empty()? "yes":"no") << endl;
obj2 = obj1;
cout << "is obj2 empty? " << (obj2.empty()? "yes":"no") << endl;
cout << "queueSize: " << obj2.size() << endl;
cout << "arrSize: " << obj2.maxSize() << endl;
}
