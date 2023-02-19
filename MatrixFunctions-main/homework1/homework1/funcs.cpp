#include <iostream>
#include <iomanip>
#include <ctime>
#include <string>
using namespace std;

int pur = 0;
int allPur = 0;

bool purchase(string name, int num, int price) {
	static int numberBuy = 0;
	numberBuy++;

	cout << "Purchase # " << numberBuy << endl;
	cout << "Product " << name << endl;

	int totalPrice = price * num;
	allPur += totalPrice;

	cout << "Total price : " << totalPrice << endl;
	cout << "All purchaces in shop : " << allPur << endl;
	cout << "_____________________________________" << endl;
	
	pur++;
	return pur;
};
