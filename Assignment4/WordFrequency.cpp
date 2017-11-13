#include <iostream>
#include <string>
#include "WordFrequency.h"
using namespace std;

//default constructor
WordFrequency::WordFrequency(void){
	string word = "";// should be empy string
	frequency = 1;
}
//copy constructor
WordFrequency::WordFrequency(string inWord){
	string word = inWord;
	frequency = 1;
}

WordFrequency::WordFrequency(string inWord, int freq){
	string word = inWord;
	frequency = freq;
}

//--------------Accessors and Mutators----------------
void WordFrequency::increment(){
	frequency++;
}

int WordFrequency::getFrequency()const{
	return frequency;
}

string WordFrequency::getWord()const{
	return word;
}

