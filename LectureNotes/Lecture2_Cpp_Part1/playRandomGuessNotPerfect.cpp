#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
int main(){
	srand (time(NULL));
	int iSecret = rand() % 10 + 1, guess;
cout << "Guess what number I'm thinking..." << endl;
cin >> guess; 
while( guess != iSecret ) {
	cin.clear();
        cin.ignore(10000, '\n');
	cout << "Nope! Guess again." << endl;
	cin >> guess;

}
	cout << "Wow! You have superpowers! \n";
	return 0;
}


