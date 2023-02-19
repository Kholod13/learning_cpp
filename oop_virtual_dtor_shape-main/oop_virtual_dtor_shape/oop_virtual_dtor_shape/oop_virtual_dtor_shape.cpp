#include <iostream>
#include <iostream>
#include <string>
using namespace std;

class Shape {
private:
	string name;
public:
	Shape() : name(""){}
	Shape(string name) : name(name)
	{
		this->name = name;
	}

	virtual ~Shape() {};

	virtual void Print() {
		cout << "----------- SHAPE ---------" << endl;
		cout << "Name: " << name << endl;

	}

};

struct Point {
	int x, y;
};

class Line : public Shape {
private:
	Point p;
	int length;
public:
	Line() : Shape(""), p({ 0, 0 }), length(0) {}
	Line(string name, int x, int y, int length) : Shape(name), p({ x,y }), length(length) // ось так доступматись в структуру
	{
	}

	void Print() override {
		Shape::Print();
		
		for (int i = 0; i < p.y;i++) {
			cout << endl;
		}
		for (int i = 0; i < p.x;i++) {
			cout << " ";
		}
		for (int i = 0; i < length; i++) {
			cout << "*";
		}
		cout << endl;
	}

};

class Rectangle : public Shape {
private:
	Point p;
	int width;
	int height;
public:
	Rectangle() : Shape(), p({0, 0}), width(0), height(0) {}
	Rectangle(string name, int x, int y, int width, int height) :
		Shape(name), p({x, y}), width(width), height(height)
	{
		this->width = width;
		this->height = height;
	}

	void Print() override {
		Shape::Print();

		for (int i = 0; i < p.y; i++) {
			cout << endl;
		}
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < p.x; j++) {
				cout << " ";
			}
			for (int j = 0; j < width; j++) {
				cout << "*";
			}
			cout << endl;
		}

	}

};


class Polyline : public Shape {
private:
	Point p;
	int numDots;
	int width;
public:
	Polyline() : Shape(), p({0, 0}), numDots(0){}
	Polyline(string name, int x, int y, int numDots, int width)
		: Shape(name), p({ x, y }), numDots(numDots), width(width) {

	}

	void Print() override {
		Shape::Print();

		for (int i = 0; i < p.y; i++) {
			cout << endl;
		}
		for (int i = 0; i < p.x; i++) {
			cout << " ";
		}

		bool counter = false;

		if (numDots == 1) {
			cout << "*";
			return;
		}

		for (int i = 0; i < numDots; i++) {

			if (counter == false) {
				for (int j = 0; j < width; j++) {
					for (int a = 0; a < j; a++) {
						cout << " ";
					}
					cout << "*";
					cout << endl;
				}
				counter = true;
			}else {
				int a = width;
				for (int j = 0; j < width;j++) {
					for (int b = 0; b < a; b++) {
						cout << " ";
					}
					a--;
					cout << "*";
					cout << endl;
				}
				counter = false;
			}
		}
	}

};


int main()
{
	Polyline p("pl", 1,1, 5, 10);
	p.Print();
}