#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <boost/lexical_cast.hpp>
#include <string>

using namespace std;

int main (){
	srand(time(NULL));
	int iSecret = rand() % 10 +1 guess;
	guess = getGuess("guess what number I'm thinking...");
	while( guess!= iSecret )
		guess = getGuess("Nope guess again.");
	cout << "Wow! you've got superpowers!" << endl;
	return 0;

	//cout << "Hello world" << endl;
	//return 0;
}

int getGuess(string message){
	int guess;
	cout << message << endl;
	string strGuess;
 	cin >> strGuess;
	try { guess = boost::lexical_cast<int>( strGuess );}
	catch(boost::bad_lexical_cast const& ){
		guess = getGuess("Input not acceptable. please enter an integer.");
	}
	return guess;
}
