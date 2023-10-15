#include <iostream>
using namespace std;
class IntArray {
private:
	int m_len = 0;
	int* m_data = nullptr;
public:
	IntArray(int len) : m_len{ len } {
		m_data = new int[m_len];
	}
	IntArray(const IntArray& arr) :m_len{arr.m_len} {
		m_data = new int[m_len];
		for (int i = 0; i < m_len; ++i) {
			m_data[i] = arr.m_data[i];
		}

	}
	~IntArray() {
		if (m_data) delete[] m_data;
	}
	void set(int idx, int value) {
		if (idx >= 0 && idx < m_len) { // check if the idx is within the size of the array
			m_data[idx] = value;
		}
	}
	int get(int idx, int err) const {
		if (idx >= 0 && idx < m_len) {
			return m_data[idx];
			
		}
		return err;
	}
};

int main() {
	int i;
	cout << "==== IntArray a{10} ===" << endl;
	IntArray a{ 10 };
	for ( i = 0; i < 10; ++i) {
		a.set(i, i * 10 + 5);
	
	}
	cout << "a: ";
	for (i = 0; i < 10; ++i) {
		cout <<a.get(i, -1) << " ";	}
	cout << endl;

	cout << "==== IntArray b{a} ===" << endl;
	cout << "b: ";
	IntArray b{ a };
	for (i = 0; i < 10; ++i) {
		cout << b.get(i, -1) << " ";
	}
	cout << endl;
	
}
