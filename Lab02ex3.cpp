// TOPIC : matrice multiplication using one dimentional array with (dynamic memory allocation using pointers)

#include <iostream>
using namespace std;

// i will be refering matric 1 values as row1 , col 1 and matrix 2 values as row2, col2
// this program assumes the two matrices are of identical sizes i.e. row1= row2, col1 = col2;
// however, i add necessary cmts to solve non-identical matrices as well.
// 
// IMPORTANT FACTS
// Fact 1: To multipy two matricee, col1 == col2( e.g. M1 = 3 x 2, M2 = 2 x 3)
// Fact 2: resulting matrix size : MatMuli[row1][col2] : 3 x 3  


// prototypes
void MatInput(int*, int, int);
void MatMul(int*, int*, int*, int, int);
void MatDisplay(int*, int, int);

int main() {
	int row, col;
	int* mat1, * mat2, * matMul;
	cout << "Enter the size of matrix(row, col): ";
	cin >> row >> col;

	// allocate the memory buffers for the three matrices
	mat1 = new int[row*col];
	mat2 = new int[row*col];
	matMul = new int[row*col]; 

	// use the buffers
	cout << "Enter elements in 1st matric of size" << row << 'x' << col << ":\n";
	MatInput(mat1, row, col);
	cout << "Enter elements in 2nd matric of size" << row << 'x' << col << ":\n";
	MatInput(mat2, row, col);

	MatMul(mat1, mat2, matMul, row, col);

	cout << "Multiplication of two matrices \n";
	MatDisplay(matMul, row, col);

	delete[] mat1, mat2, matMul;


}
void MatInput(int* mat, int row, int col) {
	int size = row * col;
	for (int i = 0; i < size; ++i) {
		cin >> *(mat+i);
	}

}



void MatDisplay(int* mat, int row , int col) {
	int size = row * col;
	for (int i = 0; i < size; ++i) {
		cout << *(mat + i);
		if ((i+1) % 3 == 0) cout << "\n";
		else cout << " ";
		
	}

}


void MatMul(int* mat1, int* mat2, int* matMul, int row, int col) {
	for (int i = 0; i < row; ++i) { // row = row1
		for (int j = 0; j < col; ++j) { // col = col2 , reference:  Fact 1 
			int sum = 0;
			for (int k = 0; k < col; ++k) { // col = col1 ; it is ok is user row2 here  ; reference: Fact 2
			// for (int k = 0; k < col OR rol; ++k)
				sum += mat1[(i * col) + k] * mat2[(k * col) + j]; // mat1[x] is the same as *(mat1+x) ; review pointer lesson if confuse
				// be careful : col in (i * col) is col1 , 
				//				col in (k * col) is col2
				

 
			}
			matMul[i * col + j] = sum; // sum1 sum2 sum3

		}
		// sum1 sum2 sum3
		// sum4 sum5 sum6
		// sum7 sum8 sum9

	}
}
