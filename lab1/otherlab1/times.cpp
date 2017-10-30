#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main( int argc, char** argt){
	//ensure proper run time arguments
	if (argc!=2){cout << "Usage: './times' 'time'\n";}
	
	char* time = argt[1];
	static_cast<int>(time);
	//static_cast<int>(time);
	string hours = argc;
	cout << "hours : " << hours << endl;
	cout << "time : " << time << endl;
	///hours = stoi(time);
	//check if 2 digits
	if((time >= 5) && (time < 12))//morning 5am-12
	{
		cout << "Good morning\n";
	}
	if((time >= 12) && (time < 19))//afternoon 12pm-7pm
	{
		cout << "Good afternoon\n";
	}
	if((time >= 19) && (time < 5))
	{
		cout << "Good night \n";
	}
	//check if 1  digit

	//cout << time << endl;//optional
	return 0;
}
