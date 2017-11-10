#include <iostream>
#include <string>
#include <cmath>
#include "WordFrequency.h"
using namespace std;

class HashTable
{
public:
	HashTable(); //Default Constructor

	// size of n must be smallest prime >= 2n
	HashTable(int size);// Constructor
	HashTable(const HashTable & obj); // copy constructor
	~HashTable();// Destructor
//	HashTable & operator=(Hashtable obj);//overloaded assignment operator

	//---------- Accessor and Mutator methods ----------

	//PRE: Hashtable exists/ is in scope
	//PARAM: input = string to search for / insert
	//POST: inserts new pointer to wordfreq obj if input is not found, if found freq is increased if the load factor, alpha is > 2/3 increase size by appr 2x and copy
	void insert(string input);

	//PRE: Hashtable exists/in scope
	//PARAM: findThis = string to search for in data 
	//POST:  returns the frequency if found else 0
	int search(string findThis);
	
	//PRE: HashTable exists/in scope
	//PARAM: N/A
	//POST: Returns # of obj in table
	int size() const;

	//PRE: HashTable exists/in scope
	//PARAM: N/A
	//POST: Returns max # obj that fit in table
	int maxSize()const;

	//PRE: HashTable exists/ is in scope
	//PARAM:
	//POST: Returns the load value alpha, if load exceeds acceptable parameters returns -1
	double loadFactor()const;

	//PRE: HashTable exists / is in scope
	//PARAM: N/A
	//POST: Returns the pointer to the array of WordFrequency objects
	WordFrequency *dump()const;


	//----------------- Utility funcions ---------------
	void Deep_copy(const HashTable & obj); // copy constr helper


private:
	int n; // size of underlying arr
	int m; // current number of objects populating the arr
	WordFrequency** table; // refers to and array of WordFrequency pointersi
	// checks if the size of n is prime
	bool isPrime(int n){
		if (n = 1) return true; //1 is always prime
		for(int i = 2; i <= sqrt(n); i++)
			return (n%i != 0? true : false);
	}
	int HashValue(string str);

};
