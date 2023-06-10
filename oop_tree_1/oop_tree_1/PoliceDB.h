#pragma once
#include <iostream>
#include "Tree.h"
#include "List.h"
using namespace std;

class Offence
{
	string carNumber;
	string descriprion;
public:
	Offence(string carNumber, string descriprion) : carNumber(carNumber), descriprion(descriprion) {}
	void SetDescription(string descriprion) { descriprion = descriprion; }
	string GetCarNumber() const { return carNumber; }
	string GetDescription() const { return descriprion; }
	friend ostream& operator<< (ostream& out, const Offence& Offence)
	{
		out << Offence.descriprion;
		return out;
	}
};
class Offender		
{
	string carNumber;
	LinkedList<Offence> offences;
public:
	Offender(string carNumber) : carNumber(carNumber) {}
	friend ostream& operator<< (ostream& out, const Offender& Offender)
	{
		out << Offender.carNumber << ":\n";
		Offender.offences.Show();
		return out;
	}
};

class PoliceBD
{
	Tree<Offender*> offenders;
};

