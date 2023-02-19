#include <iostream>
#include <fstream>
#include <string>
#include <bitset>
#include <iostream>
using namespace std;

class File {
private:
	string name = "";
protected:
	fstream file;
	
public:
	File() : name("text.txt") {
	}
	File(string name) : name(name) {
		
		file.open(name);
		
	}
	~File()
	{
		file.close();
	}

	void Write() {

		const int SIZE = 100;
		char text[SIZE];
		cout << "Input new text to file >> ";
		cin.getline(text, SIZE);

		file << text << endl;

	}

	void Clear() {
		file.close();
		file.open(name, ios_base::trunc);
		cout << "File was clear!\n";
	}

	virtual void Display() {
		file.close();
		file.open(name);
		cout << "\nFile contant: \n";
		
		string line = "";

		while (!file.eof()) {

			getline(file, line);
			cout << line << endl;

		}
	}
};

class ASCIIFile : public File {
public:
	ASCIIFile(string name) : File(name){

	}

	void Display() override {
		cout << "\nFile contant with ASCII: \n";

		char sym;
		while (!file.eof()) {
			file.get(sym);

			if (!file.eof()) {
				cout << int(sym) << " ";
			}
			else {
				break;
			}
		}
		cout << endl;
	}

};



class Double : public File {
public:
	Double(string name) : File(name) {

	}

	void Display() override {
		cout << "\nFile contant with binary code: \n";

		char sym;
		while (!file.eof()) {
			file.get(sym);
			bitset<8> b(sym);

			if (!file.eof()) {
				cout << b << " ";
			}
			else {
				break;
			}
		}
		cout << endl;

	}
};

int main()
{
	
	File f("file.txt");

	f.Write();
	f.Write();

	f.Display();

	ASCIIFile s("file.txt");

	s.Display();

	Double a("file.txt");

	a.Display();
}
