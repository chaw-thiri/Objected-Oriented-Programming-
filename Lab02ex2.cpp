#include <iostream>
using namespace std;

// prototypes
void MatInput(int*, int, int);
void MatAdd(int*, int*, int*, int, int);
void MatDisplay(int*, int, int);

int main() {
	int row, col;
	int* mat1, * mat2, * matAdd;
	cout << "Enter the size of matrix(row, col): ";
	cin >> row >> col;

	// allocate the memory buffers for the three matrices
	mat1 = new (nothrow)int[row*col];
	mat2 = new (nothrow)int[row*col];
	matAdd = new (nothrow)int[row*col];
	if (mat1 == NULL || mat2 == NULL || matAdd == NULL){
	    cout << "Error in memory allocation";
	}
    else{
        // use the buffers
    	cout << "Enter elements in 1st matric of size" << row << 'x' << col << ":\n";
    	MatInput(mat1, row, col);
    	cout << "Enter elements in 2nd matric of size" << row << 'x' << col << ":\n";
    	MatInput(mat2, row, col);
    
    	MatAdd(mat1, mat2, matAdd, row, col); 
    
    	cout << "Sum of two matrices \n";
    	MatDisplay(matAdd, row, col);
    }
	

	delete[] mat1, mat2, matAdd;


}
void MatInput(int* mat, int row, int col) {
	int size = row * col;
	for (int i = 0; i < size; ++i) {
		cin >> *(mat+i);
	}

}
void MatAdd(int* mat1, int* mat2, int* mat3, int row, int col) {
	int size = row * col;
	for (int i = 0; i < size; ++i) {
		*(mat3 + i) = (*(mat1 + i)) + ( *(mat2 + i));
	}

}
void MatDisplay(int* mat, int row , int col) {
	int size = row * col;
	for (int i = 0; i < size; ++i) {
	    
		cout << *(mat + i) << " ";
		
		if ((i + 1) % col == 0) cout << "\n"; // ******
		
	}

}
