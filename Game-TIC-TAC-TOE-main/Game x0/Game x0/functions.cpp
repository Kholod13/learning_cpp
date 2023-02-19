#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;

const int SIZE = 3;
int counter = 0;

void fillEmptyField(char a[SIZE][SIZE]) {
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			a[i][j] = char(42);
		}
	}
}

void outputField(char a[SIZE][SIZE]) {
	cout << "Field : \n";
	
	cout << "  ";
	for (int i = 0; i < SIZE; i++) {
		cout << setw(2) << i;
	}
	cout << "\n  ";
	for (int i = 0; i < SIZE; i++) {
		cout << setw(2) << "__";
	}

	cout << endl;
	for (int i = 0; i < SIZE; i++) {
		cout << i << "|";
		for (int j = 0; j < SIZE; j++) {
			cout << setw(2) << a[i][j];
		}
		cout << endl;
	}
}

void courseP1(char a[SIZE][SIZE]) {
	int pH, pV;
	counter++;
	for (int i = 0; i < 2;) {
		cout << "\n|Course player 1(0)|\n";
		cout << "Input numbers(horizontal, vertical) >> ";
		cin >> pH >> pV;
		if (a[pV][pH] != char(42) && counter >= 9) {
			cout << "\n\n DRAW \n\n";
			break;
		}

		else {
			break;
		}
	}

	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			if (i == pV && j == pH) {
				a[i][j] = char(48);
			}
		}
	}
}
void courseP2(char a[SIZE][SIZE]) {
	int pH, pV;
	counter++;
	for (int i = 0; i < 2;) {
		cout << "\n|Course player 2(X)|\n";
		cout << "Input numbers(horizontal, vertical) >> ";
		cin >> pH >> pV;
		if (a[pV][pH] != char(42) && counter >=9) {
			cout << "\n\n DRAW \n\n";
			break;
		}

		else {
			break;
		}
	}

	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			if (i == pV && j == pH) {
				a[i][j] = char(120);
			}
		}
	}
}

void algorithmWin(char a[SIZE][SIZE]) {
	for (int i = 0; i < SIZE;) {

		courseP1(a);
		outputField(a);

		if (a[0][0] == char(120) && a[0][1] == char(120) && a[0][2] == char(120) ||
			a[1][0] == char(120) && a[1][1] == char(120) && a[1][2] == char(120) ||
			a[2][0] == char(120) && a[2][1] == char(120) && a[2][2] == char(120) ||

			a[0][0] == char(120) && a[1][0] == char(120) && a[2][0] == char(120) ||
			a[1][0] == char(120) && a[1][1] == char(120) && a[1][2] == char(120) ||
			a[2][0] == char(120) && a[2][1] == char(120) && a[2][2] == char(120) ||

			a[0][0] == char(120) && a[1][1] == char(120) && a[2][2] == char(120) ||
			a[0][2] == char(120) && a[1][1] == char(120) && a[2][0] == char(120)) {

			cout << "\n\n Player 2 WIN! \n\n";
			break;

		}
		else if (a[0][0] == char(48) && a[0][1] == char(48) && a[0][2] == char(48) ||
			a[1][0] == char(48) && a[1][1] == char(48) && a[1][2] == char(48) ||
			a[2][0] == char(48) && a[2][1] == char(48) && a[2][2] == char(48) ||

			a[0][0] == char(48) && a[1][0] == char(48) && a[2][0] == char(48) ||
			a[1][0] == char(48) && a[1][1] == char(48) && a[1][2] == char(48) ||
			a[2][0] == char(48) && a[2][1] == char(48) && a[2][2] == char(48) ||

			a[0][0] == char(48) && a[1][1] == char(48) && a[2][2] == char(48) ||
			a[0][2] == char(48) && a[1][1] == char(48) && a[2][0] == char(48)) {

			cout << "\n\n Player 1 WIN! \n\n";
			break;
		}

		courseP2(a);
		outputField(a);

		if (counter >= 9) {
			cout << "\n\n DRAW \n\n";
			break;
		}
	}
}

void gameX0(char a[SIZE][SIZE]) {
	fillEmptyField(a);
	
	cout << "| GAME X0 |\n\n";

	outputField(a);
	
	algorithmWin(a);
};