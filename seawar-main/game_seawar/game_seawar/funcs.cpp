#include <iostream>
#include <ctime>
#include "windows.h"
using namespace std;

void printField(char field[][10], const int size) {
	cout << "\n   0 1 2 3 4 5 6 7 8 9  ";
	cout << "\n  ----------------------\n";

	for (int i = 0; i < size; i++) {
		
		cout << i << " |";

		for (int j = 0; j < size; j++) {
			cout << field[i][j] << " ";
		}
		cout << "|";
		cout << endl;
	}

	cout << "  ----------------------\n";
}

void emptyFillField(char field[][10], const int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			field[i][j] = '*';
		}
	}

};

void arrangementManual(char field[][10], const int size) {
	cout << "\nField";
	printField(field, size);
	cout << endl;

	cout << "You have ships:\n";
	cout << "4x (1x1)\n";
	cout << "3x (2x1)\n";
	cout << "2x (3x1)\n";
	cout << "1x (4x1)\n";

	int x, y;
	string dirrection;
	
	cout << "Input points for ship(1x1)\n";
	for (int i = 0; i < 4; i++) {

		int a = 1;
		for (int j = 0; a != 0; j++) {
			cout << "(x,y) input place for ship number #" << i + 1 << " >>";
			cin >> x >> y;

			if (x < 10 && y < 10 && x >= 0 && y >= 0 && field[y][x] == '*') {
				field[y][x] = char(35);
				a = 0;
			}
			else {
				cout << "\nIncorrect values!!\n";
			}
		}

		cout << "\nField";
		printField(field, size);
		cout << endl;

	}
	
	cout << "Input points for ship(2x1)\n";
	for (int i = 0; i < 3; i++) {

		int a = 1;
		for (; a != 0;) {
			cout << "(x,y) input place for ship number #" << i + 1 << " >>";
			cin >> x >> y;
			cout << "(top,bottom,right,left) direction of the ship >>";
			cin >> dirrection;

			if (dirrection == "top" && x >= 0 && x <= 9 && y > 0 && y <= 9 && field[y][x] == '*' && field[y - 1][x] == '*') {
				field[y][x] = char(35);
				field[y - 1][x] = char(35);
				a = 0;
			}
			else if(dirrection == "top" && ( x < 0 || x > 9 || y <= 0 || y > 9 || field[y][x] != '*' || field[y - 1][x] != '*')) {
				cout << "\nIncorrect values!!\n\n";
			}

			if (dirrection == "bottom" && x >= 0 && x <= 9 && y >= 0 && y < 9 && field[y][x] == '*' && field[y + 1][x] == '*') {
				field[y][x] = char(35);
				field[y + 1][x] = char(35);
				a = 0;
			}
			else if (dirrection == "bottom" &&( x < 0 || x > 9 || y <= 0 || y >= 9 || field[y][x] != '*' || field[y + 1][x] != '*')) {
				cout << "\nIncorrect values!!\n\n";
			}

			if (dirrection == "left" && x > 0 && x <= 9 && y >= 0 && y <= 9 && field[y][x] == '*' && field[y][x-1] == '*') {
				field[y][x] = char(35);
				field[y][x-1] = char(35);
				a = 0;
			}
			else if (dirrection == "left" && (x <= 0 || x > 9 || y < 0 || y > 9 || field[y][x] != '*' || field[y][x-1] != '*')) {
				cout << "\nIncorrect values!!\n\n";
			}

			if (dirrection == "right" && x >= 0 && x < 9 && y >= 0 && y <= 9 && field[y][x] == '*' && field[y][x + 1] == '*') {
				field[y][x] = char(35);
				field[y][x + 1] = char(35);
				a = 0;
			}
			else if (dirrection == "right" && (x < 0 || x >= 9 || y < 0 || y > 9 || field[y][x] != '*' || field[y][x + 1] != '*')) {
				cout << "\nIncorrect values!!\n\n";
			}

		}

		cout << "\nField";
		printField(field, size);
		cout << endl;
	}
	
	cout << "Input points for ship(3x1)\n";
	for (int i = 0; i < 2; i++) {

		int a = 1;
		for (int j = 0; a != 0; j++) {
			cout << "(x,y) input place for ship number #" << i + 1 << " >>";
			cin >> x >> y;
			cout << "(top,bottom,right,left) direction of the ship >>";
			cin >> dirrection;

			if (dirrection == "top" && y > 1 && field[y - 1][x] == '*' && field[y - 2][x] == '*') {
				field[y][x] = char(35);
				field[y - 1][x] = char(35);
				field[y - 2][x] = char(35);
				a = 0;
			}
			else if (y < 2 || field[y - 1][x] != '*' || field[y - 2][x] != '*') {
				cout << "\nIncorrect values!!\n";
			}

			if (dirrection == "bottom" && y < 8 && field[y + 1][x] == '*' && field[y + 2][x] == '*') {
				field[y][x] = char(35);
				field[y + 1][x] = char(35);
				field[y + 2][x] = char(35);
				a = 0;
			}
			else if (y >= 8 || field[y + 1][x] != '*' || field[y + 2][x] != '*') {
				cout << "\nIncorrect values!!\n";
			}

			if (dirrection == "left" && x > 1 && field[y][x - 1] == '*' && field[y][x - 2] == '*') {
				field[y][x] = char(35);
				field[y][x - 1] = char(35);
				field[y][x - 2] = char(35);
				a = 0;
			}
			else if (x <= 1 || field[y][x - 1] != '*' || field[y][x - 2] != '*') {
				cout << "\nIncorrect values!!\n";
			}

			if (dirrection == "right" && x < 8 && field[y][x + 1] == '*' && field[y][x + 2] == '*') {
				field[y][x] = char(35);
				field[y][x + 1] = char(35);
				field[y][x + 2] = char(35);
				a = 0;
			}
			else if (x >= 1 || field[y][x + 1] != '*' || field[y][x + 2] != '*') {
				cout << "\nIncorrect values!!\n";
			}

		}

		cout << "\nField";
		printField(field, size);
		cout << endl;

	}
	
	cout << "Input points for ship(4x1)\n";
	for (int i = 0; i < 1; i++) {

		int a = 1;
		for (int j = 0; a != 0; j++) {
			cout << "(x,y) input place for ship number #" << i + 1 << " >>";
			cin >> x >> y;
			cout << "(top,bottom,right,left) direction of the ship >>";
			cin >> dirrection;

			
			if (dirrection == "top" && y > 2 && field[y - 1][x] == '*' && field[y - 2][x] == '*' && field[y - 3][x] == '*') {
				field[y][x] = char(35);
				field[y - 1][x] = char(35);
				field[y - 2][x] = char(35);
				field[y - 3][x] = char(35);
				a = 0;
			}
			else if (y < 3 || field[y - 1][x] != '*' || field[y - 2][x] != '*' || field[y - 3][x] != '*') {
				cout << "\nIncorrect values!!\n";
			}

			if (dirrection == "bottom" && y < 7 && field[y + 1][x] == '*' && field[y + 2][x] == '*' && field[y + 3][x] == '*') {
				field[y][x] = char(35);
				field[y + 1][x] = char(35);
				field[y + 2][x] = char(35);
				field[y + 3][x] = char(35);
				a = 0;
			}
			else if (y >= 7 || field[y + 1][x] != '*' || field[y + 2][x] != '*' || field[y + 3][x] != '*') {
				cout << "\nIncorrect values!!\n";
			}

			if (dirrection == "left" && x > 2 && field[y][x - 1] == '*' && field[y][x - 2] == '*' && field[y][x - 3] == '*') {
				field[y][x] = char(35);
				field[y][x - 1] = char(35);
				field[y][x - 2] = char(35);
				field[y][x - 3] = char(35);
				a = 0;
			}
			else if (x <= 2 || field[y][x - 1] != '*' || field[y][x - 2] != '*' || field[y][x - 3] != '*') {
				cout << "\nIncorrect values!!\n";
			}

			if (dirrection == "right" && x < 7 && field[y][x + 1] == '*' && field[y][x + 2] == '*' && field[y][x + 3] == '*') {
				field[y][x] = char(35);
				field[y][x + 1] = char(35);
				field[y][x + 2] = char(35);
				field[y][x + 3] = char(35);
				a = 0;
			}
			else if (x >= 2 || field[y][x + 1] != '*' || field[y][x + 2] != '*' || field[y][x + 3] != '*') {
				cout << "\nIncorrect values!!\n";
			}

		}

		cout << "\nField";
		printField(field, size);
		cout << endl;

	}
	
}

void arrangementAuto(char field[][10], const int size){
	int x, y;
	string dirrection;
	srand(unsigned(time(0)));
	string dir[4]{ "top", "bottom", "left", "right" };

	for (int i = 0; i < 4; i++) {
		x = rand() % 10;
		y = rand() % 10;

		int a = 1;
		for (int j = 0; a != 0; j++) {

			if (x < 10 && y < 10 && field[y][x] == '*') {
				field[y][x] = char(35);
				a = 0;
			}
		}
	}

	for (int i = 0; i < 3; i++) {

		int a = 1;
		for (int j = 0; a != 0; j++) {
			x = rand() % 10;
			y = rand() % 10;
			dirrection = dir[rand() % 4];

			if (dirrection == "top" && y > 0 && field[y - 1][x] == '*') {
				field[y][x] = char(35);
				field[y - 1][x] = char(35);
				a = 0;
			}

			if (dirrection == "bottom" && y < 9 && field[y + 1][x] == '*') {
				field[y][x] = char(35);
				field[y + 1][x] = char(35);
				a = 0;
			}

			if (dirrection == "left" && x > 0 && field[y][x - 1] == '*') {
				field[y][x] = char(35);
				field[y][x - 1] = char(35);
				a = 0;
			}

			if (dirrection == "right" && x < 9 && field[y][x + 1] == '*') {
				field[y][x] = char(35);
				field[y][x + 1] = char(35);
				a = 0;
			}

		}
	}

	for (int i = 0; i < 2; i++) {

		int a = 1;
		for (int j = 0; a != 0; j++) {
			x = rand() % 10;
			y = rand() % 10;
			dirrection = dir[rand() % 4];
			
			if (dirrection == "top" && y > 1 && field[y - 1][x] == '*' && field[y - 2][x] == '*') {
				field[y][x] = char(35);
				field[y - 1][x] = char(35);
				field[y - 2][x] = char(35);
				a = 0;
			}

			if (dirrection == "bottom" && y < 8 && field[y + 1][x] == '*' && field[y + 2][x] == '*') {
				field[y][x] = char(35);
				field[y + 1][x] = char(35);
				field[y + 2][x] = char(35);
				a = 0;
			}

			if (dirrection == "left" && x > 1 && field[y][x - 1] == '*' && field[y][x - 2] == '*') {
				field[y][x] = char(35);
				field[y][x - 1] = char(35);
				field[y][x - 2] = char(35);
				a = 0;
			}

			if (dirrection == "right" && x < 8 && field[y][x + 1] == '*' && field[y][x + 2] == '*') {
				field[y][x] = char(35);
				field[y][x + 1] = char(35);
				field[y][x + 2] = char(35);
				a = 0;
			}
		}
	}

	for (int i = 0; i < 1; i++) {

		int a = 1;
		for (int j = 0; a != 0; j++) {
			x = rand() % 10;
			y = rand() % 10;
			dirrection = dir[rand() % 4];

			if (dirrection == "top" && y > 2 && field[y - 1][x] == '*' && field[y - 2][x] == '*' && field[y - 3][x] == '*') {
				field[y][x] = char(35);
				field[y - 1][x] = char(35);
				field[y - 2][x] = char(35);
				field[y - 3][x] = char(35);
				a = 0;
			}

			if (dirrection == "bottom" && y < 7 && field[y + 1][x] == '*' && field[y + 2][x] == '*' && field[y + 3][x] == '*') {
				field[y][x] = char(35);
				field[y + 1][x] = char(35);
				field[y + 2][x] = char(35);
				field[y + 3][x] = char(35);
				a = 0;
			}

			if (dirrection == "left" && x > 2 && field[y][x - 1] == '*' && field[y][x - 2] == '*' && field[y][x - 3] == '*') {
				field[y][x] = char(35);
				field[y][x - 1] = char(35);
				field[y][x - 2] = char(35);
				field[y][x - 3] = char(35);
				a = 0;
			}

			if (dirrection == "right" && x < 7 && field[y][x + 1] == '*' && field[y][x + 2] == '*' && field[y][x + 3] == '*') {
				field[y][x] = char(35);
				field[y][x + 1] = char(35);
				field[y][x + 2] = char(35);
				field[y][x + 3] = char(35);
				a = 0;
			}

		}
	}

}

int checkStep(int x, int y, char show[][10], char field[][10], int size) {

	if (field[y][x] == '#') {
		show[y][x] = '#';

		cout << "\n|Field|\n";
		printField(show, size);

		return 1;
	}
	if (field[y][x] == '*') {
		show[y][x] = '.';

		cout << "\n|Field|\n";
		printField(show, size);

		return 0;
	}

};

void gamePBRandomShot(const int size, char showField1[][10], char showField2[][10], char field1[][10], char field2[][10]) {

	emptyFillField(showField1, size);
	emptyFillField(showField2, size);

	char copyField1[10][10]{};
	char copyField2[10][10]{};

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			copyField1[i][j] = field1[i][j];
			copyField2[i][j] = field2[i][j];
		}
	}

	int marker = 0;

	for (; marker != 1;) {

		cout << "\n|Player 1|\n";
		printField(showField1, size);
		cout << "\n|Player 2|\n";
		printField(showField2, size);

		//step player 1
		for (int hitting = 1; hitting != 0;) {

			int x = 11, y = 11;
			int a = 0;

			for (; a != 1;) {

				cout << "\nPlayer 1 your queue (x,y) >> ";
				cin >> x >> y;

				if (x <= 9 || x >= 0 || y <= 9 || y >= 0 || showField2[y][x] == '*') {
					a = 1;
				}
			}

			int res = checkStep(x, y, showField2, field2, size);
			hitting = res;
		}

		//step player 2
		for (int hitting = 1; hitting != 0;) {

			srand(unsigned(time(0)));

			int x = 11, y = 11;
			int a = 0;

			for (; a != 1;) {
				x = rand() % 10;
				y = rand() % 10;

				if (x <= 9 || x >= 0 || y <= 9 || y >= 0 || showField2[y][x] == '*') {
					a = 1;
				}
			}

			cout << "\nPlayer 2 (BOT) your queue\n";
			Sleep(2000);

			int res = checkStep(x, y, showField1, field1, size);
			hitting = res;
		}
	
		//menu
		cout << "\nMENU\n|0 - continue game|\n|1 - end game|\n|2 - pause game|\n|3 - start again|\n >>>>> ";
		cin >> marker;

		if (marker == 2) {
			cout << "\n|PAUSE||PAUSE||PAUSE| Enter '0' for start >> ";
			cin >> marker;
		}
		if (marker == 3) {

			emptyFillField(showField1, size);
			emptyFillField(showField2, size);

			for (int i = 0; i < size; i++) {
				for (int j = 0; j < size; j++) {
					field1[i][j] = copyField1[i][j];
					field2[i][j] = copyField2[i][j];
				}
			}

		}

	}

};

void gameBBRandomShot(const int size, char showField1[][10], char showField2[][10], char field1[][10], char field2[][10]) {

	emptyFillField(showField1, size);
	emptyFillField(showField2, size);

	char copyField1[10][10]{};
	char copyField2[10][10]{};

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			copyField1[i][j] = field1[i][j];
			copyField2[i][j] = field2[i][j];
		}
	}

	int marker = 0;

	for (; marker != 1;) {

		cout << "\n|Player 1|\n";
		printField(showField1, size);
		cout << "\n|Player 2|\n";
		printField(showField2, size);

		//step player 1
		for (int hitting = 1; hitting != 0;) {

			srand(unsigned(time(0)));

			int x = 11, y = 11;
			int a = 0;

			for (; a != 1;) {
				x = rand() % 10;
				y = rand() % 10;

				if (x <= 9 || x >= 0 || y <= 9 || y >= 0 || showField2[y][x] == '*') {
					a = 1;
				}
			}

			cout << "\nPlayer 1 (BOT) your queue\n";
			Sleep(2000);

			int res = checkStep(x, y, showField2, field2, size);
			hitting = res;
		}

		//step player 2
		for (int hitting = 1; hitting != 0;) {

			srand(unsigned(time(0)));

			int x = 11, y = 11;
			int a = 0;

			for (; a != 1;) {
				x = rand() % 10;
				y = rand() % 10;

				if (x <= 9 || x >= 0 || y <= 9 || y >= 0 || showField2[y][x] == '*') {
					a = 1;
				}
			}

			cout << "\nPlayer 2 (BOT) your queue\n";
			Sleep(2000);

			int res = checkStep(x, y, showField1, field1, size);
			hitting = res;
		}

		//menu
		cout << "\nMENU\n|0 - continue game|\n|1 - end game|\n|2 - pause game|\n|3 - start again|\n >>>>> ";
		cin >> marker;

		if (marker == 2) {
			cout << "\n|PAUSE||PAUSE||PAUSE| Enter '0' for start >> ";
			cin >> marker;
		}
		if (marker == 3) {

			emptyFillField(showField1, size);
			emptyFillField(showField2, size);

			for (int i = 0; i < size; i++) {
				for (int j = 0; j < size; j++) {
					field1[i][j] = copyField1[i][j];
					field2[i][j] = copyField2[i][j];
				}
			}

		}

	}

};