// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
void inputArr(int*,int);
int searchArr(int*,int,int);
int main() {
    int size, ele, idx;
    int* buf = NULL;
    cout << "Enter the size of the array: ";
    cin >> size;
    // allocating the memory buffer + error handling
    try{
        buf = new int [size];
    }
    catch (bad_alloc){
        cout << "The size is too big.";
        return 0;
    }
    // using the allocated memory 
    cout << "Enter elements of the array :"; 
    inputArr(buf, size);
    cout << "Enter element to search : ";
    cin >> ele;
    idx = searchArr(buf, size, ele);
    if (idx == -1 ) cout <<ele <<" does not exist in the array.";
    else cout << ele << " is found in index " << idx <<".";
    delete[] buf;

    return 0;
}
void inputArr(int* arr,int size){
    for (int i = 0; i < size; ++i){
        cin >> *(arr+i);  // arr[i]
    }
    
}
int searchArr(int* arr,int size,int ele){
    for (int i = 0; i < size; ++i){
        if (arr[i] == ele ) 
        return i;
    }
    return -1;
}
