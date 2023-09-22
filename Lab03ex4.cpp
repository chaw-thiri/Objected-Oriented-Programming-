
// •	The size of the array would expand as big as the user input number.
// •	So, Dynamic memory allocation is used to accommodate the varying sizes.
// •	After using the array, its place in the computer is cleared up using the delete keyword.
// •	GetMax function: firstly, the number at index 0 is pointed as the max num and then compared with another number in the array as the pointer traverses through the array using the for loop.
// •	The reverse is true for the GetMin function.

#include <iostream>
using namespace std;

int GetMaximum(int*, int);
int GetMinimum(int*, int);
double GetAverage(int*, int);
int main() {
	int size;
	cout << "# of data want to input: ";
	cin >> size;
	int* arr;
	arr = new int[size];

	for (int i = 0; i < size; ++i) {
		cout << i << ". Input an interger: ";
		cin >> *(arr + i);
	}
	cout << endl;

	cout << "Minimum value is " << GetMinimum(arr, size) << endl;
	cout << "Maximium value is " << GetMaximum(arr, size) << endl;
	cout << "Average value is " << GetAverage(arr, size) << endl;

	delete[] arr;
	return 0;
}
int GetMaximum(int* arr, int size) {
	int maxi = *arr;
	for (int i = 0; i < size; ++i) {
		maxi = (*(arr + i) > maxi) ? *(arr + i) : maxi;
	}
	return maxi;
}

int GetMinimum(int* arr, int size) {
	int mini = *arr;
	for (int i = 0; i < size; ++i) {
		mini = (*(arr + i) < mini) ? *(arr + i) : mini;
	}
	return mini;
}

double GetAverage(int* arr, int size) {
	double avg= 0;
	for (int i = 0; i < size; ++i) {
		avg += *(arr + i);
	}
	return avg / size;

}
