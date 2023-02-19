#include <iostream>
#include <ctime>
#include <windows.h>
using namespace std;

class Time {
private:
	int hrs;
	int mins;
	int sec;
public:
	explicit Time() : hrs(0), mins(0), sec(0){}
	Time(int h, int m, int s) : hrs(h), mins(m), sec(s){}
	
	void Show() {
		cout << "\n---Time : ";
		if (hrs < 10 && hrs >= 0) {
			cout << "0" << hrs << ":";
		}
		else {
			cout << hrs << ":";
		}

		if (mins < 10 && mins >= 0) {
			cout << "0" << mins << ":";
		}
		else {
			cout << mins << ":";
		}

		if (sec < 10 && sec >= 0) {
			cout << "0" << sec;
		}
		else {
			cout << sec;
		}

		cout << endl;
	}

	void ParVals(int h, int m, int s) {
		if (h < 24 && h >= 0) {
			hrs = h;
		}
		else if (h > 23) {
			hrs = 23;
		}
		else if (h < 0) {
			hrs = 0;
		}

		if (m < 60 && m >= 0) {
			mins = m;
		}
		else if (m > 59) {
			mins = 59;
		}
		else if (m < 0) {
			mins = 0;
		}

		if (s < 60 && s >= 0) {
			sec = s;
		}
		else if (s > 59) {
			sec = 59;
		}
		else if (s < 0) {
			sec = 0;
		}
	}

	void TimeVal(float s) {

		if (s < 0 || s >= 86400) {
			cout << "\nIncorrect value!\n";
			return;
		}

		hrs = s / 60 / 60;

		if (s > 3600) {
			mins = s / 60 - (hrs * 60);
		}
		else {
			mins = s / 60;

		}
		
		sec = s - ((hrs * 60 + mins) * 60);
	}

	void Clock() {
		cout << "\n---Time : ";
		if (hrs < 10 && hrs >= 0) {
			cout << "0" << hrs << ":";
		}
		else if (hrs >= 10 && hrs < 24) {
			cout << hrs << ":";
		}


		if (mins < 10 && mins >= 0) {
			cout << "0" << mins << ":";
		}
		else if (mins >= 10 && mins < 60) {
			cout << mins << ":";
		}
		else {
			hrs++;
			mins = 0;
			cout << "0" << mins << ":";
		}

		if (sec < 10 && sec >= 0) {
			cout << "0" << sec;
		}
		else if(sec >= 10 && sec < 60) {
			cout << sec;
		}
		else {
			mins++;
			sec = 0;
			cout << "0" << sec;
		}
		cout << endl;

		if (hrs == 23 && mins == 59 && sec == 59) {
			hrs = 0;
			mins = 0;
			sec = 0;
		}
		else {
			sec++;
		}
		Sleep(1000);

		Clock();

	}

	void EqualTime(const Time& obj) {

		if (hrs > obj.hrs) {
			cout << "\nFirst timer is biggest!\n";
		}
		else if (hrs < obj.hrs) {
			cout << "\nSecond timer is biggest!\n";
		}
		else {
			if (mins > obj.mins) {
				cout << "\nFirst timer is biggest!\n";
			}
			else if (mins< obj.mins) {
				cout << "\nSecond timer is biggest!\n";
			}
			else {
				if (sec > obj.sec) {
					cout << "\nFirst timer is biggest!\n";
				}
				else if (sec < obj.sec) {
					cout << "\nSecond timer is biggest!\n";
				}
				else {
					cout << "\nTimers is equal\n";
				}
			}
		}
	}

	bool BoolMoreTime(const Time& obj) {

		if (hrs > obj.hrs) {
			return true;
		}
		else if (hrs < obj.hrs) {
			return false;
		}
		else {
			if (mins > obj.mins) {
				return true;
			}
			else if (mins < obj.mins) {
				return false;
			}
			else {
				if (sec > obj.sec) {
					return true;
				}
				else if (sec < obj.sec) {
					return false;
				}
			}
		}
	}

};

int main()
{
	Time time(12,57,57);
	//Time time1(12, 59, 57);

	time.Show();
	//time1.Show();

	//time.ParVals(0,2,11);
	//time.Show();

	time.TimeVal(86399);
	time.Show();
	//time.Show();

	//time.Clock();

	//time.EqualTime(time1);
	//cout << "\nBool res = " << time.BoolMoreTime(time1) << "\n";

}