#include <iostream>
#include <vector>
using namespace std;

class Transmission
{
private:
	string type;
public:
	Transmission() {}
	Transmission(string type) : type(type) {

	}
	string GetTypeTransmission() {
		return type;
	}
};

class Wheels
{
private:
	int inch;
	string timeTire;
public:
	Wheels() { }
	Wheels(int inch, string timeTire)
		: inch(inch), timeTire(timeTire) {

	}
	int GetInches() {
		return inch;
	}
};

class Body {
private:
	float width;
	float longest;
	string color;
public:
	Body() { }
	Body(float width, float longest, string color)
		: width(width), longest(longest), color(color) {

	}
	string GetColor() {
		return color;
	}
};

class Engine {
private:
	int maxSpeed;
	int power;
	string model;
public:
	Engine() { }
	Engine(int maxSpeed, int power, string model)
		: maxSpeed(maxSpeed), power(power), model(model) {

	}
	int GetPower() {
		return power;
	}
};
/*
class Driver
{
private:
	string name;
	string lastName;
	int age;
	int experience;
public:
	Driver() {	}
	Driver(string name, string lastName, int age, int experience)
		: name(name), lastName(lastName), age(age), experience(experience)
	{

	}
	void ShowInfo() {
		cout << "Name: " << name << endl;
		cout << "Last name: " << lastName << endl;
		cout << "Age: " << age << endl;
		cout << "Experience: " << experience << endl;
	}

};
*/
class Car {
private:
	string company;
	string model;

	Engine engine;
	Body body;
	Wheels wheels;
	Transmission transmission;

	const int SIZE = 4;
	vector<string> passengers;
	bool start = false;

public:
	Car(string company, string model)
		: company(company), model(model)
	{
		engine = Engine(206, 250, "Wolkswagen");
		body = Body(2.34, 5.5, "grey");
		wheels = Wheels(18, "winter");
		transmission = Transmission("auto");

		passengers.push_back("Vasya");

	}
	~Car() {
		passengers.clear();
	}

	void ShowPassengers() {
		
		cout << "Passengers : \n";

		for (int i = 0; i < SIZE; i++) {
			cout << "#" << i + 1 << " " << passengers[i] << endl;
		}

	}

	void Show() {
		
		cout << "Car: " << company << " " << model << "\n";
		cout << "Engine power: " << engine.GetPower() << endl;
		cout << "Color body: " << body.GetColor() << endl;
		cout << "Wheel inches: " << wheels.GetInches() << endl;
		cout << "Transmission type: " << transmission.GetTypeTransmission() << endl;

	}

	void AddPassenger(string name) {
		if (passengers.size() <= SIZE) {
			passengers.push_back(name);
		}
		else {
			cout << "Error - there is little space in the car!\т";
		}
	}

	bool StartStopCar() {
		if (start == false) {
			cout << "Car is start\n";
			start = true;
			return true;
		}
		if (start == true) {
			cout << "Car is sillenced\n";
			start = false;
			return false;
		}
	}

};

int main()
{
	Car car("Wolkswagen", "Touran");

	car.Show();
	car.ShowPassengers();
}