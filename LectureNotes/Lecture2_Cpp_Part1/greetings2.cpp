#include <iostream>
using namespace std;

int main(int argc, char** argv){
	if (argc != 2){
		cout << "Usage: executable.o name\n";
		return 1;
	}
	string name = argv[1];
	cout << "Hello " << name << ". Nice to meet you." << endl;
	return 0;
}
