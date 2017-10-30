#include <string>
#pragma once
using namespace std;

class StringSet
{
	private:

	string*  myString;
	int StringSize;
	int StringMax;
	void strCopy(const StringSet & obj);
	int NOTFOUND(){
		return -1;
	}

	public:
	//Constructor
	StringSet();

	//PARAM:StringSet object
	//POST: Creates Deep copy of PARAM
	StringSet(const StringSet &);
	
	// overloaded assignment operator
	StringSet & operator = (const StringSet &obj);

	//Destructor
	~StringSet();

	//PRE: StringSet Class declared or in scope
	//PARAM:stringSet = myString to be inserted
	//POST: inserts a string at the end of the object
	bool insert(string);
	
	//Helper to insert
	void doubleStrSize();

	//PRE: StringSet object in scope
	//POST: prints out values in myString
	void print() const;

	/*-----Finds index of searched string-----
	PRE: String object for parameter
	PARAM: StringSet object
	POST: returns index of found string, returns -1 otherwise*/
	int find (string search)const;

	//PRE:Stringset Object declared or in scope
	//PARAM:string = myString to be removed
	//POST: Removes listed string and replaces with what is at
	// 	the end of the array
	bool remove(string);

	//PRE:StringSet obj declared
	//POST: Returns Size of String
	int size() const;

	string getStr(int index) const;
	
	//PRE:StringSet obj1 & obj2
	//PARAM:StringSet = myString
	//POST:Returns a StringSet Object that contains the union of
	//     called object and the parameter
	StringSet unions(const StringSet &) const;

	//PRE: StringSet obj1 & obj2
	//PARAM: StringSet Obj
	//POST: Returns a StringSet Object that contains intersection of
	//	called object and the parameter
	StringSet intersection(const StringSet &) const;

	//PRE:StringSet obj1 & obj2
	//PARAM: StringSet = myString
	//POST:returns obj witht the diffeerence of obj1 & obj2
	StringSet difference(const StringSet &) const;

};
