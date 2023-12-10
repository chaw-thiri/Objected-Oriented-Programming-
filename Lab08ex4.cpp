#include <iostream>
#include <iomanip>
using namespace std;
class Time {
private:
	int m_hr;
	int m_min;
	int m_sec;
	bool m_am = true;
public:
	Time(int hr, int min, int sec):
		m_hr {hr}, m_min{min}, m_sec{sec}
	{
		if (hr > 12) m_am = false;
	}
	void printTime(void) {
		cout << setfill('0') << setw(2) << m_hr << ":";
		cout << setfill('0') << setw(2) << m_min << ":";
		cout << setfill('0') << setw(2) << m_sec <<"\n";
	}
	void printTime(void) const {
		cout << setfill('0') << setw(2);
		if (m_am) {
			cout << setfill('0') << setw(2) << m_hr << ":";
			cout << setfill('0') << setw(2) << m_min << ":";
			cout << setfill('0') << setw(2) << m_sec << " AM\n";
		}
		else {
			cout << setfill('0') << setw(2) << m_hr-12 << ":";
			cout << setfill('0') << setw(2) << m_min << ":";
			cout << setfill('0') << setw(2) << m_sec << " PM\n";
		}
	}
};
int main() {
	const Time t0{ 7,3,5 };
	Time t1{ 13,45,9 };
	const Time t2{ t1 };
	
	cout << "t0: ";
	t0.printTime();
	cout << "t1: ";
	t1.printTime();
	cout << "t2: ";
	t2.printTime();
	return 0;
}