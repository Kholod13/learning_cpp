#include <iostream>
#include "windows.h"
using namespace std;

class Device {
private:
    string model;
    int weight;
    int number;
    int price;
public:
    Device() : Device("", 0, 0, 0) { }
    Device(string model, int weight, int number, int price) : model(model), weight(0), number(0), price(0) {
        this->model = model;
        this->weight = weight;
        this->number = number;
        this->price = price;
    }

     int GetPrice() {
        return price;
    }

     int GetWeight() {
         return weight;
     }

    void ShowInfo() const {
        cout << "\n------- Device ------\n";
        cout << "Model : " << model << endl;
        cout << "Weight : " << weight << endl;
        cout << "Serial number : " << number << endl;
        cout << "Price : " << price << endl;
    }
    
    bool sens = false;
    bool Sensor() {
        
        if (sens == false) {
            sens = true;
            return true;
        }
        else {
            sens = false;
            return false;
        }

    }

    void DidWork(Device& other) const {
        int val = other.Sensor();

        if (sens == true) {
            for (int i = 0; val != false && i < 5; i++) {
                cout << "\nDevice is working...";
                Sleep(5000);
            }
            cout << "\nStop working!\n";
        }
        else {
            cout << "\nDevice is off!\n";
        }
    }

};

class Printer : public Device {
private:
    string firm;
    int format;
public:
    Printer() : firm(""), format(0), Device() { }
    Printer(string model, int weight, int number, int price, string firm, int format)
        : Device(model, weight, number, price) {
        this->firm = firm;
        this->format = format;
    }

    void ShowInfo() const {
        Device::ShowInfo();
        cout << "Firm : " << firm << endl;
        cout << "Format : " << format << endl;
        cout << "Device : Printer\n";
    }

    bool sens = false;
    bool Sensor() {

        if (sens == false) {
            sens = true;
            return true;
        }
        else {
            sens = false;
            return false;
        }

    }

    void DidWork(Printer& other) const {
        int val = other.Sensor();

        if (sens == true) {
            for (int i = 0; val != false && i < 5; i++) {
                cout << "\nDevice is working...";
                Sleep(5000);
            }
            cout << "\nStop working!\n";
        }
        else {
            cout << "\nDevice is off!\n";
        }
    }

};

class Router : public Device {
private:
    int ghz;
    int speed;
public:
    Router() : ghz(0), speed(0), Device() { }
    Router(string model, int weight, int number, int price, int ghz, int speed)
        : Device(model, weight, number, price) {
        this->ghz = ghz;
        this->speed = speed;
    }

    void ShowInfo() const {
        Device::ShowInfo();
        cout << "Ghz : " << ghz << endl;
        cout << "Speed : " << speed << endl;
        cout << "Device : Router\n";
    }

    bool sens = false;
    bool Sensor() {

        if (sens == false) {
            sens = true;
            return true;
        }
        else {
            sens = false;
            return false;
        }

    }

    void DidWork(Router& other) const {
        int val = other.Sensor();

        if (sens == true) {
            for (int i = 0; val != false && i < 5; i++) {
                cout << "\nDevice is working...";
                Sleep(5000);
            }
            cout << "\nStop working!\n";
        }
        else {
            cout << "\nDevice is off!\n";
        }
    }

};

class TV : public Device {
private:
    int ghz;
    int inch;
public:
    TV() : ghz(0), inch(0), Device() { }
    TV(string model, int weight, int number, int price, int ghz, int inch)
        : Device(model, weight, number, price) {
        this->ghz = ghz;
        this->inch = inch;
    }

    void ShowInfo() const {
        Device::ShowInfo();
        cout << "Ghz : " << ghz << endl;
        cout << "Speed : " << inch << endl;
        cout << "Device : TV\n";
    }

    bool sens = false;
    bool Sensor() {

        if (sens == false) {
            sens = true;
            return true;
        }
        else {
            sens = false;
            return false;
        }

    }

    void DidWork(TV& other) const {
        int val = other.Sensor();

        if (sens == true) {
            for (int i = 0; val != false && i < 5; i++) {
                cout << "\nDevice is working...";
                Sleep(5000);
            }
            cout << "\nStop working!\n";
        }
        else {
            cout << "\nDevice is off!\n";
        }
    }

};

class Monitor : public Device {
private:
    int ghz;
    int inch;
public:
    Monitor() : ghz(0), inch(0), Device() { }
    Monitor(string model, int weight, int number, int price, int ghz, int inch)
        : Device(model, weight, number, price) {
        this->ghz = ghz;
        this->inch = inch;
    }

    void ShowInfo() const {
        Device::ShowInfo();
        cout << "Ghz : " << ghz << endl;
        cout << "Speed : " << inch << endl;
        cout << "Device : Monitor\n";
    }

    bool sens = false;
    bool Sensor() {

        if (sens == false) {
            sens = true;
            return true;
        }
        else {
            sens = false;
            return false;
        }

    }

    void DidWork(Monitor& other) const {
        int val = other.Sensor();

        if (sens == true) {
            for (int i = 0; val != false && i < 5; i++) {
                cout << "\nDevice is working...";
                Sleep(5000);
            }
            cout << "\nStop working!\n";
        }
        else {
            cout << "\nDevice is off!\n";
        }
    }

};

void showArr(Device* arr, int size);
void averagePrice(Device* arr, int size);
void weightDevices(Device* arr, int size);

int main()
{
    Device dev("hiro", 34, 34, 3);

    dev.ShowInfo();
    dev.Sensor();
    dev.DidWork(dev);
    

    const int SIZE = 5;
    Device arr[SIZE]{
        Printer("sf",6, 6,6,"f", 5),
        Router("sf", 6, 6, 6, 6, 5),
        TV("sf", 6, 6, 6, 67, 5),
        Monitor("sf", 6, 6, 6, 75, 5),
        Monitor("ssdf", 6, 65, 65, 75, 5),
    };

    showArr(arr, SIZE);
    averagePrice(arr, SIZE);
    weightDevices(arr, SIZE);
}

void weightDevices(Device* arr, int size) {

    int res = 0;

    for (int i = 0; i < size; i++) {
        res += arr[i].GetWeight();
    }

    cout << "\Weight summ = " << res << endl;

};

void averagePrice(Device* arr, int size) {

    int res = 0;

    for (int i = 0; i < size; i++) {
        res += arr[i].GetPrice();
    }

    cout << "\nAverage price = " << res << endl;

};

void showArr(Device* arr, int size) {
    cout << "\n|Devices list with basic characteristics|\n";
    for (int i = 0; i < size; i++) {
        arr[i].ShowInfo();
    }
}