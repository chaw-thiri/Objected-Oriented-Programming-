#include<iostream>
#include<iomanip>
#include<ctime>
#include<cstdlib>
using namespace std;

class IntArray
{
private:
    int m_len{ 0 };
    int* m_data{ nullptr };

public:
    IntArray(int len)
        : m_len{ len }
    {
        m_data = new int[m_len];
    }
    ~IntArray() {
        if (m_data) delete[] m_data;
    }
    friend class IntArrayHandler;
};
class IntArrayHandler {
private:
    IntArray* mArrPtr;
public:
    IntArrayHandler(IntArray* arPtr) : mArrPtr {arPtr}
    {
        
       
    }
    void setArray(int* arr, int size) {
        for (int i = 0; i < size; i++) {
            mArrPtr->m_data[i] = arr[i];
        }
    }
    void displayArray() {
        for (int i = 0; i < mArrPtr->m_len; i++) {
            cout << "[" << i << "]" << mArrPtr->m_data[i] << endl;
        }
    }
    int sum() {
        int addition = 0;
        for (int i = 0; i < mArrPtr->m_len; i++) {
            addition += mArrPtr->m_data[i];
        }
        return addition;
    }
    void stat() {
        cout << "# of elements: " << mArrPtr->m_len << endl;
        double result = sum();
        double average = static_cast<double>(result) / static_cast<double>(mArrPtr->m_len);
        cout << setw(12)<<setfill(' ')<<internal << "Sum: " << result << endl;
        cout << setw(12) << setfill(' ') <<internal<< "Average: " << average<< endl;
    }
    void setIntArray(IntArray* ar) {
        for (int i = 0; i < ar->m_len; i++) {
            mArrPtr->m_data[i] = ar->m_data[i];
        }
    }
};

const int arSize = 20;

int main() {
    int i;
    int data1[arSize], data2[arSize];
    IntArray ar1{ arSize }, ar2{ arSize };
    srand((unsigned int)time(NULL));
    for (i = 0; i < arSize; ++i) {
        data1[i] = rand() % 100;
        data2[i] = rand() % 100;
    }
    IntArrayHandler handler{ &ar1 };
    handler.setArray(data1, arSize);
    cout << "== ar1: displayArray() ===" << endl;
    handler.displayArray();
    cout << "====== ar1: stat() =======" << endl;
    handler.stat();
    cout << "==========================" << endl;
    handler.setIntArray(&ar2);
    handler.setArray(data2, arSize);
    cout << endl << "== ar2: displayArray() ===" << endl;
    handler.displayArray();
    cout << "====== ar2: stat() =======" << endl;
    handler.stat();
    cout << "==========================" << endl;
    return 0;
}
