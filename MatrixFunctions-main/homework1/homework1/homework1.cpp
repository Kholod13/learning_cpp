//task2
#include <iostream>
using namespace std;

extern bool purchase(string name, int num, int price);
extern int pur;

int main() {
	purchase("earpod", 1, 5000);
	int number = purchase("mouse", 2, 300);

	cout << "Purchases : " << pur << endl;
}