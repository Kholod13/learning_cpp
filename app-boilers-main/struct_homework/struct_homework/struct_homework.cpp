#include <iostream>
using namespace std;

struct Boiler {
	string company = "none";
	string color = "none";
	int power = 0;
	int amount = 0;
	int temeperature = 0;
};

void inputData(Boiler& emp);
void printData(const Boiler& emp);
void iniTemperature(Boiler& emp);
bool isValidTemperature(int emp);
void iniMagTemperature(Boiler& emp);
bool isValidMagTemperature(Boiler& emp);
void iniReducTemperature(Boiler& emp);
bool isValidReducTemperature(Boiler& emp);
void compressionBoilers(const Boiler& emp1, const Boiler& emp2);

int pastValTemperature = 65;
int main()
{
	//task with boiler

	Boiler boiler1{};
	Boiler boiler2{};
	cout << "\n\t\tBOILER\n\n";
	//boiler 1
	inputData(boiler1);
	printData(boiler1);

	iniMagTemperature(boiler1);
	printData(boiler1);

	iniReducTemperature(boiler1);
	printData(boiler1);

	//boiler 2

	inputData(boiler2);
	printData(boiler2);
	compressionBoilers(boiler1, boiler2);

}

void compressionBoilers(const Boiler& emp1, const Boiler& emp2) {
	cout << "\n\nPower Boiler #1 - " << emp1.power;
	cout << "\nPower Boiler #2 - " << emp2.power;

	if (emp1.power > emp2.power) {
		cout << "\n\n|Boiler #1 has more capacity|";
	}
	if (emp1.power < emp2.power) {
		cout << "\n\n|Boiler #2 has more capacity|";
	}
	cout << endl;
};

bool isValidReducTemperature(Boiler& emp) {
	bool res = true;
	if (emp.temeperature > pastValTemperature) {

		return false;
	}
	return true;
};

void iniReducTemperature(Boiler& emp) {
	cout << "\n\nInput new value temperature (reduction) >> ";
	cin >> emp.temeperature;
	while (isValidReducTemperature(emp) == false) {
		cout << "Incorrect value! Input again smallest temperature (" << pastValTemperature << ") >> ";
		cin >> emp.temeperature;
	}
	pastValTemperature = emp.temeperature;
};

bool isValidMagTemperature(Boiler& emp) {
	bool res = true;
	if (emp.temeperature < pastValTemperature) {

		return false;
	}
	return true;
};

void iniMagTemperature(Boiler& emp) {
	cout << "\n\nInput new value temperature (increased) >> ";
	cin >> emp.temeperature;
	while (isValidMagTemperature(emp) == false) {
		cout << "Incorrect value! Input again biggest temperature (" << pastValTemperature << ") >> ";
		cin >> emp.temeperature;
	}
	pastValTemperature = emp.temeperature;
};

bool isValidTemperature(int emp)
{
	bool res = true;
	if (emp < 65 || emp > 120) {
		return false;
	}
	return true;
}

void iniTemperature(Boiler& emp) {

	cout << "Input temperature >> ";
	cin >> emp.temeperature;
	while (isValidTemperature(emp.temeperature) == false) {
		cout << "Incorrect value! Input again >> ";
		cin >> emp.temeperature;
	}
	pastValTemperature = emp.temeperature;
};

void inputData(Boiler& emp) {
	cout << "Input company >> ";
	cin >> emp.company;
	cout << "Input color >> ";
	cin >> emp.color;
	cout << "Input power >> ";
	cin >> emp.power;
	cout << "Input amount >> ";
	cin >> emp.amount;
	iniTemperature(emp);
};

void printData(const Boiler& emp) {
	cout << "\nCompany : " << emp.company;
	cout << "\nColor : " << emp.color;
	cout << "\nPower : " << emp.power;
	cout << "\nAmount : " << emp.amount;
	cout << "\nTemperature : " << emp.temeperature;
};