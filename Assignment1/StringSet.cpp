#include <iostream>
#include <string>
//#include <algorithm>
//#include <functional>
#include "StringSet.h"
using namespace std;
//constructor
StringSet::StringSet(){
	StringSize = 0;
	StringMax = 2;
	myString = new string[StringMax];
}
//Copy Constructor
StringSet::StringSet(const StringSet & obj){
	StringMax = obj.StringMax;
	StringSize = obj.StringSize;
	myString = new std::string[StringMax];
	for(int k = 0; k < StringSize; k++) myString[k]=obj.myString[k];
}
//Overloaded Assignment operator
StringSet & StringSet::operator=(const StringSet &obj){
	if(this != &obj){
		delete[] myString;//remove the left
		StringSet(obj);//copy into left
	}
	return *this;
}
//Destructor
StringSet::~StringSet(){delete[] myString;}

//PRE: StringSet Class declared or in scope
//PARAM:stringSet = myString to be inserted
//POST: inserts a string at the end of the object
bool StringSet::insert(string str){
	if(find(str)!= NOTFOUND())return false;
	if(StringSize >= StringMax) doubleStrSize();
	myString[StringSize] = str;
	StringSize++;
	return true;
}
//helper to insert
void StringSet::doubleStrSize(){
	//results in string array with 2x index size
	string* temp = new string[StringMax];
	for(int i = 0; i < StringSize; i++) temp[i] = myString[i];//copy
	StringMax += StringMax; // double StringMaz
	myString = new string[StringMax];
	for(int i = 0; i < StringSize; i++) myString[i] = temp[i];//swap
	delete[] temp;
}

void StringSet::print() const {
	cout << "Printing StringSet Object: ... " << endl;
	for (int i = 0; i < StringSize; i++){
		cout << "Index : "<< i << "	" << myString[i] << endl;
	}
}

/*-----Finds index of searched string-----
PRE: String object for parameter
PARAM: StringSet object
POST: returns index of found string, returns -1 otherwise*/
int StringSet::find(const string search) const{
	for( int i = 0;  i < StringSize; i++){
		if( myString[i] == search ) return i;//value found
	}
	return -1;//value not in string array
}

//PRE:Stringset Object declared or in scope
//PARAM:string = myString to be removed
//POST: Removes listed string and replaces with what is at
//      the end of the array
bool StringSet::remove(string str){
	int FindIndex = find(str);
	if(FindIndex != NOTFOUND()){
		myString[FindIndex] = myString[StringSize-1];
		StringSize--;
		return true;
	}
	return false;
}

int StringSet::size() const{return StringSize;}

string StringSet::getStr(int index) const{return myString[index];}

/* -----Union between calling object and parameter;-----
PRE: Calling object and parameter(both type StringSet)
PARAM:StringSet object
POST:Returns a intersection StringSet*/
StringSet StringSet::unions(const StringSet& obj) const{//union is or
	StringSet U(*this);
	int SizeMax = StringSize;
	if (StringSize < obj.StringSize){//check if calling object is smaller than the param
		SizeMax = obj.StringSize;
		}
	for(int i = 0; i < SizeMax;i++){
		string strSearch = obj.getStr(i);
		//no need to test if we find strSearch here
		//because we already make a call to find in insert.
		//inserts words in both sets
		U.insert(strSearch);
	}
	return U;
}

/* -----Intersection between calling object and parameter;-----
PRE: Calling object and parameter(both type StringSet)
PARAM:StringSet object
POST:Returns intersection object*/
StringSet StringSet::intersection(const StringSet & obj) const{
	StringSet I;
	int SizeMax = StringSize;
	if (StringSize < obj.StringSize){//check if calling object is smaller than the param
		SizeMax = obj.StringSize;
		}
	for(int i = 0; i < SizeMax;i++){
		int strFind = obj.find(getStr(i));
		//no need to test if we find strSearch here
		//because we already make a call to find in insert.
		//inserts words that are in both sets
		if(strFind == -1) I.insert(obj.getStr(i));
	}
	return I;
}

//PRE:StringSet obj1 & obj2
//PARAM: StringSet = myString
//POST:returns obj witht the diffeerence of obj1 & obj2
StringSet StringSet::difference(const StringSet & obj) const{
	StringSet diff(*this);
	for(int k = 0; k < obj.StringSize; k++){
	diff.remove(obj.getStr(k));
	//removes values found in second object only from the first
	}
	return diff;
}
