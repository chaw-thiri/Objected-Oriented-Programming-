#include <iostream>
#include <string>
#include <algorithm>
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
	if (base == 10) {
		cout << "Decimal : " << num << endl;
		return ;
	}
	 
	string hex_string; int remainder;
	while (num > 0) {
		remainder = num % base;
		hex_string.append(to_string(remainder));
		num = num / base;
	}
	reverse(hex_string.begin(), hex_string.end());
	int final_num = stoi(hex_string);
	if (base == 8) cout << "Octal :" << final_num << endl;
	else if (base == 16) cout << "Hexadecimal :" << final_num << endl;
	else cout << "ERROR: unknown base.\n" ;
		
	
}
