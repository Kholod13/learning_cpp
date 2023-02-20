#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

struct Ticket {
    int ser;
    int num;
    int y;
    int m;
    int d;
    string placeDeparture;
    string placeArrival;
};

class AviaTickets {
private:
    vector<Ticket> tickets;

    void ReviewOne(int n) {
        cout << "Ticket serial: " << tickets[n].ser << endl;
        cout << "Ticket number: " << tickets[n].ser << endl;
        cout << "Time:\nyear: " << tickets[n].ser << endl;
        cout << "month: " << tickets[n].ser << endl;
        cout << "day: " << tickets[n].ser << endl;
        cout << "Place departure: " << tickets[n].ser << endl;
        cout << "Place arrival: " << tickets[n].ser << endl;
    }

public:
    AviaTickets()
    {

    }

    void Add() {
        
        srand(unsigned(time(0)));

        Ticket t;

        t.ser = rand() % 100;
        t.num = rand() % 100000;

        cout << "Input year >> ";
        cin >> t.y;
        cout << "Input month >> ";
        cin >> t.m;
        cout << "Input day >> ";
        cin >> t.d;
        cout << "Input place departure >> ";
        cin >> t.placeDeparture;
        cout << "Input place arrival >> ";
        cin >> t.placeArrival;

        tickets.push_back(t);
    }

    void Review() {

        for (int i = 0; i <= tickets.size(); i++) {
            cout << "Ticket serial: " << tickets[i].ser << endl;
            cout << "Ticket number: " << tickets[i].ser << endl;
            cout << "Time:\nyear: " << tickets[i].ser << endl;
            cout << "month: " << tickets[i].ser << endl;
            cout << "day: " << tickets[i].ser << endl;
            cout << "Place departure: " << tickets[i].ser << endl;
            cout << "Place arrival: " << tickets[i].ser << endl;
        }

    }

    void Search() {

        int ser, num;
        cout << "Input ticket serial number >> ";
        cin >> ser;
        cout << "Input ticket number >> ";
        cin >> num;

        for (int i = 0; i <= tickets.size(); i++) {
            
            if (tickets[i].ser == ser && tickets[i].num == num) {
                ReviewOne(i);
                cout << "---------------------------------\n\n";
            }

        }

    }

};

int main()
{
    AviaTickets a;

    a.Add();
    a.Add();
    a.Review();
    a.Search();

}
