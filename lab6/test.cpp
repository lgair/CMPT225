#include <iostream>
#include <sstream>
#include <stdexcept>
#include "Fraction.h"
using namespace std;

int main(){
	Fraction fr1(3,4);
	Fraction fr2(5,8);
	cout << fr1 <<" == " << fr2 << endl << (fr1 == fr2? "true" : "False") << endl;
	cout << fr1 <<" != " << fr2 << endl << (fr1 != fr2? "true" : "False") << endl;
	cout << fr1 <<" < " << fr2 << endl << (fr1 < fr2? "true" : "False") << endl;
	cout << fr1 <<" <= " << fr2 << endl << (fr1 <= fr2? "true" : "False") << endl;
	cout << fr1 <<" > " << fr2 << endl << (fr1 > fr2? "true" : "False") << endl;
	cout << fr1 <<" >= " << fr2 << endl << (fr1 >= fr2? "true" : "False") << endl;
}
