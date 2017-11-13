#include <iostream>
#include <string>

using namespace std;

class WordFrequency
{
public:
	WordFrequency();// Default Constructor
	WordFrequency(string word);//Copy Consructors
	WordFrequency(string word, int freq);

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
