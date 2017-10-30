#include <iostream>
using namespace std;

const int max_num_items = 10; 
int sorted[max_num_items];
int n=0;

int right_place(int* sorted_array, int & n, int x){
	int x_index = n;
        for (int i = 0; i<n; i++){
                if (sorted_array[i] >= x){
                        x_index = i;
                        break;
                }
        }
	return x_index;
}

void print(int* sorted_array, int n);

void update(int* sorted_array, int & n, int x )
{
	// finding the rightful place of x
	int x_index = right_place(sorted_array, n, x);

	n++;

	// shift everything starting from x_index to the right to open a space for x
	for (int i= n-2; i>= x_index; i--)
		sorted_array[i+1] = sorted_array[i]; 
	
	sorted_array[x_index] = x;
	print(sorted_array, n);
}

void print(int* sorted_array, int n){
	for (int i=0; i<n; i++)
                cout << sorted_array[i] << " ";
        cout << endl;
}

int main(){
	int x = -100; 
	while ((n < max_num_items) && (x != -1)){
		cin >> x;
		if (x > 0 ){
			update(sorted, n, x);
			//print(sorted, n);
		}
		cin.clear();
		cin.ignore(1000, '\n');
	}
	
	return -1;
}

