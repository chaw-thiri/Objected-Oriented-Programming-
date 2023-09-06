
#include <iostream>
using namespace std;

//function prototypes
void inputArray(int*, int);
int searchIdx(int*, int, int);

int main(){
	int size, element, index;

	int* buf = nullptr;

	cout << "Enter the size of array : ";
	cin >> size;

	// allocate the memory buffer
	buf = new int[size]; // giving a value to the pointer, add an array to the pointer
	


	// use the allocated memory 
cout << "Enter elements of the array: ";
	inputArray(buf, size);

	cout << "Enter element to search : ";
	cin >> element;
	index = searchIdx(buf, size, element);

	if (index == -1)
		cout << element << " does not exist in the array.";
	else
		cout << element << " is found in index" << index << ".";

	// free allocated meemry 
	delete[] buf; // delete pointer array
}
void inputArray(int* buf, int size) {
	for (int i = 0; i < size; ++i)
		cin >> *(buf + i);

}
int searchIdx(int* buf, int size, int element) {
	for (int i = 0; i < size; ++i) {
		if (*(buf + i) == element)
			return i;

	}
	return -1;
