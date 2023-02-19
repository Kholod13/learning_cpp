#include <iostream>
using namespace std;

struct Coord {
	int cordX;
	int cordY;
} coord;

class Rectangle {
private:
	int width;
	int height;
	string symbol;
public:
	Rectangle() {
		width = 10;
		height = 5;
		symbol = "*";
	}

	Rectangle(string symbol)
	{
		this->width = 10;
		this->height = 5;
		this->symbol = symbol;
	}

	void GetSize(int size, string symbol) {
		if (size <= 40 && size >= 1) {
			this->width = size;
			this->height = size;
		}
		this->symbol = symbol;
	}

	void GetValues(int width, int height, string symbol)
	{
		if (width <= 40 && width >= 1) {
			this->width = width;
		}
		if (height <= 40 && height >= 1) {
			this->height = height;
		}
		this->symbol = symbol;
	}

	void Show() const {
		cout << "_________ Rectangle _______\n\n";
		//coord Y
		for (int j = 0; j < coord.cordY; j++) {
			cout << endl;
		}

		//coord X
		for (int j = 0; j < coord.cordX; j++) {
			cout << " ";
		}
		//

		for (int i = 0; i < width; i++) {
			cout << symbol;
		}
		cout << endl;
		for (int i = 0; i < height - 2; i++) {
			//coord X
			for (int j = 0; j < coord.cordX; j++) {
				cout << " ";
			}
			//
			cout << symbol;
			for (int j = 0; j < width - 2; j++) {
				cout << " ";
			}
			cout << symbol << endl;
		}
		//coord X
		for (int j = 0; j < coord.cordX; j++) {
			cout << " ";
		}
		//
		for (int i = 0; i < width; i++) {
			cout << symbol;
		}
		cout << endl;
	}

	void Edit(int width, int height) {
		if (width <= 40 && width >= 1) {
			this->width = width;
		}
		if (height <= 40 && height >= 1) {
			this->height = height;
		}
	}

	void Move(int xx, int yy) {

		coord.cordX = xx;
		coord.cordY = yy;

	}

};

int main()
{
	int xx = 0, yy = 0;
	cout << "Input coord X and Y >> ";
	cin >> xx >> yy;
	
	coord.cordX = xx;
	coord.cordY = yy;

	Rectangle myRec("*");
	myRec.Show();

	myRec.GetSize(3, "$");
	myRec.Show();

	myRec.GetValues(4, 4, "#");
	myRec.Show();

	myRec.Edit(2, 2);
	myRec.Show();

	myRec.Move(1,1);
	myRec.Show();
}