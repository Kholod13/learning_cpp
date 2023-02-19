#include <iostream>
#include <ctime>
#include <iomanip>
using namespace std;

const int SIZE = 5;

void fillMatrix(int a[SIZE][SIZE], int b[SIZE][SIZE]) {
	srand(unsigned(time(0)));

	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			a[i][j] = rand() % 101;
		}
	}
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			b[i][j] = rand() % 101;
		}
	}

};
void outputMatrix(int a[SIZE][SIZE], int b[SIZE][SIZE]) {
	cout << "Matrix A :\n";
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			cout << setw(5) << a[i][j];
		}
		cout << endl;
	}
	cout << endl;
	cout << "Matrix B :\n";
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			cout << setw(5) << b[i][j];
		}
		cout << endl;
	}
	cout << endl;
};
void sumMatrix(const int  a[][SIZE], const int b[][SIZE], int c[][SIZE]) {
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			c[i][j] = a[i][j] + b[i][j];
		}
	}

	cout << "Matrix SUM :\n";
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			cout << setw(5) << c[i][j];
		}
		cout << endl;
	}
	cout << endl;
};
void MultipleMatrix(int  a[][SIZE], int b[][SIZE], int val) {
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			a[i][j] *= val;
			b[i][j] *= val;
		}
	}
};