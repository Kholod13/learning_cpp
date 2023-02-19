#include <iostream>
#include <cstring>
#include <string>
using namespace std;

enum Genre {
	programming, business, horror, none
};

struct Book {
	string name;
	string author;
	string edition;
	Genre genre;
};

void printBooks(const Book arr[], int num);
void printOneBook(const Book& book);
void editBook(Book& book);
void searchAuthor(Book arr[], const int num);
void searchBook(Book arr[], const int num);
void sortBooksForName(Book arr[], const int num);
void sortBooksForAuthor(Book arr[], const int num);
void sortBooksForEdition(Book arr[], const int num);
void addBook(Book arr[], int& realNum);
void deleteBook(Book arr[], int& realNum);

int main()
{
	const  int maxNum = 101;
	int realNum = 10;
	Book books[maxNum]
	{
		{"Fluent Python", "Luciano Ramalho", "O'Reilly Media, Inc.",
		Genre::programming},
		{"Eloquent JavaScript", "Marijn Haverbeke", "O'Reilly Media, Inc.",
		Genre::programming},
		{"Effective Modern C++", "Scott Meyers", "O'Reilly Media, Inc.",
		Genre::programming},
		{"Rich Dad Poor Dad", "Robert T. Kiyosaki", "Amazon book clubs",
		Genre::business},
		{"Never Split the Difference", "Chris Voss", "Amazon book clubs",
		Genre::business},
		{"The 48 Laws of Power", "Robert Greene", "Amazon book clubs",
		Genre::business},
		{"Fairy Tale", "Stephen King", "Simon & Schuster, Inc",
		Genre::horror},
		{"The Mist", "Stephen King", "Scribner",
		Genre::horror},
		{"House of Leaves", "Mark Z. Danielewski", "Pantheon",
		Genre::horror},
		{"Secluded Cabin Sleeps Six", "Lisa Unger", "Park Row",
		Genre::horror}
		
	};
	
	const int SIZE = 30;

	int n = 0;
	cout << "1 - sort for name \n2 - sort for author \n3 - sort for edition \n4 - search book \n5 - search author \n6 - edit book \n7 - add new book \n8 - del book \n0 - exit programm\n";
	cout << "Input variant >> ";
	cin >> n;

	switch (n)
	{
	case 1:
		sortBooksForName(books, realNum);
		printBooks(books, realNum);
		return 0;
	case 2:
		sortBooksForAuthor(books, realNum);
		printBooks(books, realNum);
		return 0;
	case 3:
		sortBooksForEdition(books, realNum);
		printBooks(books, realNum);
		return 0;
	case 4:
		searchBook(books, realNum);
		return 0;
	case 5:
		searchAuthor(books, realNum);
		return 0;
	case 6:
		//edit
		int num;
		cout << "\n\n\tEdit book number >> ";
		cin >> num;
		editBook(books[num - 1]);
		printBooks(books, realNum);
		return 0;
	case 7:
		//add
		addBook(books, realNum);
		if (realNum <= 100)
		{
			printBooks(books, realNum);
		}
		return 0;
	case 8:
		//del
		printBooks(books, realNum);
		deleteBook(books, realNum);
		printBooks(books, realNum);
		return 0;
	default:
		break;
	}

}

void deleteBook(Book arr[], int& realNum) {
	int n;
	cout << "\nInput number delete book >> ";
	cin >> n;

	arr[n - 1].name = '\0';
	arr[n - 1].author = '\0';
	arr[n - 1].edition = '\0';
	arr[n - 1].genre = (Genre)none;

	swap(arr[n - 1], arr[realNum - 1]);

	realNum--;

}

void enterOneBook(Book& book) {
	cout << "\n\t\tBook name : ";
	cin >> book.name;
	cout << "\n\t\tBook author : ";
	cin >> book.author;
	cout << "\n\t\tBook edition : ";
	cin >> book.edition;

	cout << "\n\t\tBook genre (0 - programming, 1 - business, 2 - horror, 3 - none) : ";
	int genre;
	cin >> genre;
	book.genre = (Genre)genre;

}

void  addBook(Book arr[], int& realNum) {
	if (realNum > 100)
	{
		cout << " >>>>>>>>> Sorry, we cannot  to  add new book(low place)\n";
		return;
	}
	++realNum;
	enterOneBook(arr[realNum - 1]);

};

void sortBooksForEdition(Book arr[], const int num) {
	cout << "\nSort library for edition >>>\n";

	Book temp[1]
	{
		{"none", "none", "none",Genre::none},
	};

	for (int i = 0; i < num; i++) {

		for (int j = i + 1; j < num; j++) {
			if (arr[tolower(i)].edition > arr[tolower(j)].edition) {
				temp[0] = arr[i];
				arr[i] = arr[j];
				arr[j] = temp[0];
			}
		}
	}
};

void sortBooksForAuthor(Book arr[], const int num) {
	cout << "\nSort library for author >>>\n";

	Book temp[1]
	{
		{"none", "none", "none",Genre::none},
	};

	for (int i = 0; i < num; i++) {

		for (int j = i + 1; j < num; j++) {
			if (arr[tolower(i)].author > arr[tolower(j)].author) {
				temp[0] = arr[i];
				arr[i] = arr[j];
				arr[j] = temp[0];
			}
		}
	}
};

void sortBooksForName(Book arr[], const int num) {
	cout << "\nSort library for name >>>\n";
	
	Book temp[1]
	{
		{"none", "none", "none",Genre::none},
	};

	for (int i = 0; i < num; i++) {
		
		for (int j = i + 1; j < num; j++) {
			if (arr[tolower(i)].name > arr[tolower(j)].name) {
				temp[0] = arr[i];
				arr[i] = arr[j];
				arr[j] = temp[0];
			}
		}
	}

};

void searchBook(Book arr[], const int num) {
	string val1, val2;
	cout << "\n\t\tInput search book name >> ";
	cin >> val1 >> val2;
	string value = val1 + " " + val2;

	for (int i = 0; i < num; i++) {
		if (value ==  arr[i].name) {
			cout << ">> \n";
			printOneBook(arr[i]);
			cout << endl;
		}

	}
};

void searchAuthor(Book arr[], const int num) {
	string val1, val2;
	cout << "\n\t\tInput search book name >> ";
	cin >> val1 >> val2;
	string value = val1 + " " + val2;

	for (int i = 0; i < num; i++) {
		if (value == arr[i].author) {
			cout << ">> \n";
			printOneBook(arr[i]);
			cout << endl;
		}
	
	}

};

void editBook(Book& book) {
	cout << "\n\t\tBook name: ";
	cin >> book.name;
	cout << "\n\t\tBook author: ";
	cin >> book.author;
	cout << "\n\t\tBook edition: ";
	cin >> book.edition;	

	cout << "\n\t\tPizza size (0-programming, 1-business, 2-horror) : ";
	int size;
	cin >> size;
	book.genre = (Genre)size;
};

string getGenreName(Genre g) {
	if (g == Genre::programming)
		return "programming";
	if (g == Genre::business)
		return "business";
	if (g == Genre::horror)
		return "horror";
	return "None genre";
}

void printBooks(const Book arr[], int num)
{
	for (int i = 0; i < num; i++)
	{
		cout << "\n#" << i + 1 << " Book\n";
		printOneBook(arr[i]);
		cout << endl;
	}
}

void printOneBook(const Book& book) {
	cout << "Name: " << book.name << endl;
	cout << "by " << book.author << endl;
	cout << "Publisher(s): " << book.edition << endl;
	cout << "Genre: " << getGenreName(book.genre);
}