#include <iostream>
using namespace std;

const int SIZE = 50;

struct Student {

	char name[SIZE];
	unsigned int os : 4;
	unsigned int hardware : 4;
	unsigned int programming : 4;
	unsigned int english : 4;

};

void printStudent(const Student& student);
void enterStudent(Student& student);
void iniName(Student& student);

int main()
{
	//task1

	Student student{ 'Oleg', 8, 11, 9 };
	enterStudent(student);
	printStudent(student);

	
}
bool isValidName(char name[])
{
	bool res = true;
	for (int i = 0; name[i] != '\0'; i++) {
		if(!isalpha(name[i])) {
			//cout << "Incorrect name! Input again >> ";
			return false;
		}
	}
	return true;
}
//task1
void iniName(Student& student) {

	cout << "Input name >> ";
	cin >> student.name;
	while (isValidName(student.name) == false) {
		cout << "Incorrect name! Input again >> ";
		cin >> student.name;
		//isValidName(student.name);
	}


};
void printStudent(const Student& student) {
	cout << "Name - " << student.name << endl;
	cout << "Mark for OS - " << student.os << endl;
	cout << "Mark for hardware - " << student.hardware << endl;
	cout << "Mark for programming - " << student.programming << endl;
	cout << "Mark for english - " << student.english << endl;
	int col = (student.os + student.hardware + student.programming + student.english) / 4;
	cout << "CA mark - " << col << endl;
}

void enterStudent(Student& student) {
	int mark;

	cout << "Input mark for OS >> ";
	while (!(cin >> mark) or mark >12) {
		cout << "\n\t\tIncorrect mark!!! Input again >> ";
		cin.clear();
		cin.ignore(1000, '\n');
	}
	student.os = mark;

	cout << "Input mark for hardware >> ";
	while (!(cin >> mark) or mark > 12) {
		cout << "\n\t\tIncorrect mark!!! Input again >> ";
		cin.clear();
		cin.ignore(1000, '\n');
	}
	student.hardware = mark;

	cout << "Input mark for programming >> ";
	while (!(cin >> mark) or mark > 12) {
		cout << "\n\t\tIncorrect mark!!! Input again >> ";
		cin.clear();
		cin.ignore(1000, '\n');
	}
	student.programming = mark;

	cout << "Input mark for english >> ";
	while (!(cin >> mark) or mark > 12) {
		cout << "\n\t\tIncorrect mark!!! Input again >> ";
		cin.clear();
		cin.ignore(1000, '\n');
	}
	student.english = mark;

	iniName(student);
}