#include <iostream>
using namespace std;
void cout_int(int, int = 10);
int main() {
	cout_int(100);
	cout_int(100, 8);
	cout_int(100, 10);
	cout_int(100, 16);
	cout_int(100, 20);
	return 0;
}
void cout_int(int num, int base) {
	if (base == 10)
		cout << num;
	else if (base == 8)
		cout << oct << num;
	else if (base == 16)
		cout << hex << num;
	else
		cout << "ERROR: unknown base";
	cout << endl;
}
