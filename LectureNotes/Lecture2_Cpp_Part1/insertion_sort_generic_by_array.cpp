#include <iostream>
using namespace std;

const int max_num_items = 10; 

template<typename Type>
int right_place(Type* sorted_array, int & n, Type x){
	int x_index = n;
        for (int i = 0; i<n; i++){
                if (sorted_array[i] >= x){
                        x_index = i;
                        break;
                }
        }
	return x_index;
}

template<typename Type>
void update(Type* sorted_array, int & n, Type x )
{
	// finding the rightful place of x
	int x_index = right_place(sorted_array, n, x);

	n++;

	// shift everything starting from x_index to the right to open a space for x
	for (int i= n-2; i>= x_index; i--)
		sorted_array[i+1] = sorted_array[i]; 
	
	sorted_array[x_index] = x;
}

template<typename Type>
void print(Type* sorted_array, int n){
	for (int i=0; i<n; i++)
                cout << sorted_array[i] << " ";
        cout << endl;
}

void sort_string(){
	string sorted[max_num_items];
	int n=0;

	string x = "<start>";
        while ((n < max_num_items) && (x != "<stop>")){
                cin >> x;
                update(sorted, n, x);
                print(sorted, n);
        }
}

void sort_positive_int(){
	int sorted[max_num_items];
        int n=0;

	int x=-100;
	while ((n < max_num_items) && (x != -1)){
		cin >> x;
		if (x > 0 ){
			update(sorted, n, x);
			print(sorted, n);
		}
		cin.clear();
              cin.ignore(1000, '\n');
	}
}

int main(){
	cout << "Enter a maximum of " << max_num_items << " strings to be sorted. Enter <stop> to stop.\n";
	sort_string();
	cout << "Enter a maximum of " << max_num_items << " positive integers to be sorted. Enter -1 to stop.\n";
	sort_positive_int();
	
	return -1;
}

