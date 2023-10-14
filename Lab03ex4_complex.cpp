#include <iostream>
using namespace std;
void GetMaximum(int*, int, int&);
void GetMinimum(int*, int, int&);
void GetAverage(int*, int, double*);
void FillList(int*, int);
int main() {
	int size;
	int* numList;
	//double avg;
	int max ;
	int min ;
	double avg;
	
	cout << "# of data you want to input :";
	cin >> size;
	numList = new int[size];
	FillList(numList, size);
	GetMaximum(numList, size, max);
	GetMinimum(numList, size, min);
	GetAverage(numList, size, &avg);

	cout << "Minimum value :" << min ;
	cout << "\nMaximum value :" << max;
	cout << "\nAverage value : " << avg;

		
	delete[] numList;
	return 0;

}
void FillList(int* arr, int size) {
	for (int i = 0; i < size; ++i) {
		cout << i << ". Input an integer: ";
		cin >> arr[i];
	}
	cout << endl;
}
void GetMaximum(int* arr, int size, int& max) {
	max = arr[0];
	for (int i = 1; i < size; ++i) {
		if (arr[i] > max) max = arr[i];
	}


}

void GetMinimum(int* arr, int size, int& min) {
	min = arr[0];
	for (int i = 1; i < size; ++i) {
		if (arr[i] < min) min = arr[i];
	}
	
}
void GetAverage(int* arr, int size, double* avg) {
	double sum = 0;
	for (int i = 0; i < size; ++i) {
		sum += arr[i];
	}
	*avg = sum / size;
}
