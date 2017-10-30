#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <boost/lexical_cast.hpp>

using namespace std;

int getGuess(string message){
	int guess;
	cout << message << endl;
        string strGuess;
        cin >> strGuess;
        try {
                guess = boost::lexical_cast<int>( strGuess );
        }
        catch( boost::bad_lexical_cast const& ) {
                guess = getGuess("Input not acceptable. Please enter an integer.");                
        }
	
	return guess;
	
}

int main(){
	srand (time(NULL));
	int iSecret = rand() % 10 + 1, guess;
	guess = getGuess("Guess what number I'm thinking...");
	while( guess != iSecret ) 
		guess = getGuess("Nope! Guess again.");
	cout << "Wow! You have superpowers! \n";
	return 0;
}
