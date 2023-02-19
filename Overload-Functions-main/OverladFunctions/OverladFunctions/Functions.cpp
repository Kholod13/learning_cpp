#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;

//task1
/*
void fGaron(int s, int s1, int s2) {
	int S = 0;
	int p = s + s1 + s2;
	S = sqrt(p*(p - s) * (p - s1) * (p - s2));

	cout << "S = " << S << endl;
};
void fSimple(int s, int s1, int s2) {
	int S = 0;
	
	if (s < (s1) && s < (s2) && s1 == s2) {
		S = s * s1 / 2;
		cout << "S = " << S << endl;
	}
	else {
		cout << "S = " << S << endl;
	}
};
*/
//task2

void fillArray(int arr[], int size) {
	srand(unsigned(time(0)));
	for (int i = 0; i < size; i++) {
		arr[i] = rand() % 100 - 51;
	}
};
void printArray(const int arr[], int size) {
	cout << "Array :";
	for (int i = 0; i < size; i++) {
		cout << setw(5) << arr[i];
	};
	cout << endl;
};
int indFirst(const int arr[], int  size) {
	int left = -1;

	for (int i = 0; i < size/2; i++) {
		if (arr[i] < 0) {
			left = i;
			return left;
		}
	}

	return left;
};
int indLast(const int arr[], int  size) {
	int right = -1;

	for (int i = size-1; i > 0; i--) {
		if (arr[i] < 0) {
			right = i;
			return right;
		}
	}

	return right;
};
void reversePartArray(int arr[], int left, int right) {
	int difference = right /2;
	
	int c1 = left, c2 = right;

	for (int i = 0; i < difference; i++) {
			swap(arr[c1], arr[c2]);

			c1++;
			c2--;
	}
};