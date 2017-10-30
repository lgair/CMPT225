#include <iostream>
#include <string>                                                                                         class WordFrequency
{
public:
	WordFrequency();// Default Constructor
	WordFrequency(string word);// Copy Constructor
	WordFrequency();// Destructor
	WordFrequency & operator=(WordFrequency obj); //Overloaded Assignment operator
	
	//Accessors and Mutators
	//PRE: WordFrequency object exists or is in scope
	//PARAM: N/A
	//POST: increments the frequency of the word
	void increment();
	
	//PRE: WordFrequency object exists or is in scope
	//PARAM: N/A
	//POST: Returns the current frequency value
	int getFrequency() const;

	//PRE: WordFrequency object exists or is in scope
	//PARAM: N/A
	//POST: Returns word value
	string getWord() const;
private:
string word;
int frequency;
};

