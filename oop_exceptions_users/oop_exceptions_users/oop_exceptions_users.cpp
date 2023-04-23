#pragma once
#include <iostream>
#include <string>
#include <functional>
#include <exception>
using namespace std;

class User
{
	string firstname;
	string lastname;
	int yearOfBirth;
	string phonenumber;
	string email;
	string cardnumber;
	int postalindex;
public:
	User(string firstname, string lastname, int yearOfBirth, string phonenumber, string email, string cardnumber, int postalindex)
		: firstname(firstname), lastname(lastname), yearOfBirth(yearOfBirth), phonenumber(phonenumber), email(email), cardnumber(cardnumber), postalindex(postalindex) {}
	string GetFullname() { return firstname + " " + lastname; }
	void Show() const;
};

class MyDB
{
	int size;
	User** user;
public:
	MyDB() : size(0), user(nullptr) {}
	~MyDB();
	void add();
	void remove(int index);
	User& find(string name);
	void sort(function<bool(string, string)> fcn);
	void Show(int index) const { user[index]->Show(); }
	int GetSize() const { return size; }
};

class IncorrectName : public logic_error
{
public:
	IncorrectName(string message) : logic_error(message) {}
	const char* what() const override
	{
		return logic_error::what();
	}
};

string GetValidName()
{
	string name;
	cin >> name;
	if (name.size() < 2)
		throw IncorrectName("The name must be longer than 1 character");
	if (!isupper(name[0]))
		throw IncorrectName("The name must begin with a capital letter");
	return name;
}
int GetValidBirth()
{
	int yearOfBirth;
	cin >> yearOfBirth;
	if (yearOfBirth < 1930 || 2020 < yearOfBirth)
		throw exception("Birth year is invalid");
	else
		cout << "Year of birth success!\n";
	return yearOfBirth;
}
string GetValidPhoneNumber()
{
	string phonenumber;
	cin >> phonenumber;
	int digitCounter = 0;
	int size = phonenumber.size();
	if (size < 13)
		throw exception("The phone number is too small");
	if (!(phonenumber[0] == '+' && phonenumber[1] == '3' && phonenumber[2] == '8'))
		throw exception("The country code is incorrect");
	for (int i = 3; i < size; ++i)
	{
		if (isdigit(phonenumber[i]))
			++digitCounter;
		else if (phonenumber[i] == '-')
			continue;
		if (digitCounter == 1 && phonenumber[i] != '0')
			throw exception("The number is incorrect, there are invalid values");
	}
	if (digitCounter != 10)
		throw exception("The number of digits in the phone number does not match");
	else
		cout << "Phone number success!\n";
	return phonenumber;
}
string GetValidEmail()
{
	string email;
	cin >> email;
	int size = email.size();
	int isAtPosition = -1;
	int isDotAfterAt = -1;
	if (size < 5)
		throw exception("Incorrect email length");
	for (int i = 0; i < size; ++i)
	{
		if ((i < size - 1) && (email[i] == '.') && (email[i + 1] == '.'))
			throw exception("Incorrect format in email");
		if (!(isalnum(email[i]) || email[i] == '@' || email[i] == '.' || email[i] == '_'))
			throw exception("Incorrect character in email");
		if (((0 < isAtPosition) || i == 0) && email[i] == '@')
			throw exception("Incorrect format in email");
		if (i && email[i] == '@')
			isAtPosition = i;
		if (isAtPosition && email[i] == '.' && (isAtPosition < (i + 1)) && (isAtPosition < (i + 1)) != (email.size() - 1))
			isDotAfterAt = i;
	}
	if ((isAtPosition < 0) || (isDotAfterAt < 0) || (isAtPosition == (isDotAfterAt - 1)))
		throw exception("Incorrect format in email");
	else
		cout << "Email success!\n";
	return email;
}
string GetValidCardNumber()
{
	string cardnumber;
	string result;
	cin >> cardnumber;
	int size = cardnumber.size();
	int digitCounter = 0;
	for (size_t i = 0; i < size; i++)
	{
		if (isdigit(cardnumber[i]))
		{
			++digitCounter;
			result += cardnumber[i];
		}
	}
	if (digitCounter != 16)
		throw exception("Incorrect card number length");
	else
		cout << "Card number success!\n";
	return result;
}
int GetValidPostalCode()
{
	string postalindex;
	cin >> postalindex;
	int size = postalindex.size();
	if (size != 5)
		throw exception("Incorrect postal code length");
	if (!(postalindex[0] == '3' && postalindex[1] == '3'))
		throw exception("Invalid postal code");
	else
		cout << "Postal code success!\n";
	return std::stoi(postalindex);
}

MyDB::~MyDB()
{
	for (size_t i = 0; i < size; i++)
	{
		delete user[i];
	}
	delete[] user;
}

void MyDB::add()
{
	cout << "-----------Add new User-----------\n";
	//============================================================
	string firstname;
	while (true)
	{
		cout << "\nEnter firstname: ";
		try
		{
			firstname = GetValidName();
			break;
		}
		catch (const IncorrectName& ex)
		{
			cout << "Message: " << ex.what() << endl;
		}
	}
	//============================================================
	string lastname;
	while (true)
	{
		cout << "\nEnter lastname: ";
		try
		{
			lastname = GetValidName();
			break;
		}
		catch (const IncorrectName& ex)
		{
			cout << "Message: " << ex.what() << endl;
		}
	}
	//============================================================
	int yearOfBirth;
	while (true)
	{
		cout << "\nEnter year of birth: ";
		try
		{
			yearOfBirth = GetValidBirth();
			break;
		}
		catch (const std::exception& ex)
		{
			cout << "Message: " << ex.what() << endl;
		}
	}
	//============================================================
	string phonenumber;
	while (true)
	{
		cout << "\nEnter phone number: ";
		try
		{
			phonenumber = GetValidPhoneNumber();
			break;
		}
		catch (const std::exception& ex)
		{
			cout << "Message: " << ex.what() << endl;
		}
	}
	//============================================================
	string email;
	while (true)
	{
		cout << "\nEnter email: ";
		try
		{
			email = GetValidEmail();
			break;
		}
		catch (const std::exception& ex)
		{
			cout << "Message: " << ex.what() << endl;
		}
	}

	//============================================================
	string cardnumber;
	while (true)
	{
		cout << "\nEnter card number: ";
		try
		{
			cardnumber = GetValidCardNumber();
			break;
		}
		catch (const std::exception& ex)
		{
			cout << "Message: " << ex.what() << endl;
		}
	}

	//============================================================
	int postalcode;
	while (true)
	{
		cout << "\nEnter postal code: ";
		try
		{
			postalcode = GetValidPostalCode();
			break;
		}
		catch (const std::exception& ex)
		{
			cout << "Message: " << ex.what() << endl;
		}
	}

	++size;
	User** tmp = new User * [size];
	for (size_t i = 0; i < size - 1; i++)
		tmp[i] = user[i];
	tmp[size - 1] = new User(firstname, lastname, yearOfBirth, phonenumber, email, cardnumber, postalcode);;
	delete[] user;
	user = tmp;
}

void MyDB::remove(int index)
{
	if (size <= 0 || index < 0 || size <= index)
		throw out_of_range("Out of the range");
	--size;
	int count = 0;
	User** arr2 = new User * [size];
	for (int i = 0; i < size + 1 && count < size; i++)
	{
		if (i != index)
		{
			arr2[count] = user[i];
			count++;
		}
	}
	delete[] user;
	user = arr2;
}

User& MyDB::find(string name)
{
	for (size_t i = 0; i < size; i++)
	{
		if (0 <= (*user[i]).GetFullname().find(name))
			return *user[i];
	}
}

void MyDB::sort(std::function<bool(string, string)> fcn)
{
	if (size <= 0)
		return;
	bool swapped;
	int counter = 0;
	User* tmp = nullptr;
	do
	{
		swapped = 0;
		for (int j = 0; j < size - 1 - counter; j++)
		{
			if (fcn(user[j]->GetFullname(), user[j + 1]->GetFullname()))
			{
				swapped = 1;
				tmp = user[j];
				user[j] = user[j + 1];
				user[j + 1] = tmp;
			}
		}
		counter++;
	} while (swapped);
}

void User::Show() const
{
	cout << "------------------------\n";
	cout << "Name - " << firstname << " " << lastname << endl;
	cout << "Year of birth - " << yearOfBirth << endl;
	cout << "Phone number - " << phonenumber << endl;
	cout << "E-mail - " << email << endl;
	cout << "Credit card number - " << cardnumber << endl;
	cout << "Postal code number - " << postalindex << endl;
}

bool sortUP(string n1, string n2) { return (n2 < n1); }
bool sortDOWN(string n1, string n2) { return (n1 < n2); }
int main()
{
	MyDB database;
	database.add();
	database.add();
	int size = database.GetSize();
	for (size_t i = 0; i < size; i++)
		database.Show(i);
	User* tmpUser = &database.find("Fred");
	(*tmpUser).Show();
	database.sort(sortUP);
	for (size_t i = 0; i < size; i++)
		database.Show(i);
	try
	{
		database.remove(0);
	}
	catch (const std::out_of_range& ex)
	{
		cout << "Message: " << ex.what() << endl;
	}
	size = database.GetSize();
	for (size_t i = 0; i < size; i++)
		database.Show(i);
}
