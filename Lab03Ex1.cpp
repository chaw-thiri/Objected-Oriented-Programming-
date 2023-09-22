#include <iostream>
using namespace std;


int main() {
	int mark=0;
	
	while (mark >= 0) {
		cout << "Enter your score of the exam: ";
		cin >> mark;
		char grade;
		if (mark < 0) {
			cout << "End of the program";
			break;
		}
		else if (mark > 100){
			cout << "Invalid input. Please try again\n";
			continue;
		}

		 grade = (mark >= 90) ? 'A':
			 (mark < 90 and mark >= 80) ? 'B' :
			(mark < 80 and mark >= 70) ? 'C' :
			(mark < 70 and mark >= 60) ? 'D' :
			'F';
		 if (grade == 'A') cout << "Congratulations. ";
		 else if (grade == 'F') cout << "Sorry. ";
		 cout << "Your grade: " << grade << endl << endl;
		
	}
	
}
