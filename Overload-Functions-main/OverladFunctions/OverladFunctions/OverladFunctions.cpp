#include <iostream>
using namespace std;

#include "Functions.cpp"
#include "arrays.h"

int main()
{
	system("color 2");
	//task1
	/*
	int side, side1, side2;

	cout << "Input sides tringle (first basis) >> ";
	cin >> side >> side1 >> side2;
	  
	cout << "Formula Goron'a\n";
	fGaron(side, side1, side2);
	cout << endl;

	int S;
	cout << "Formula basic\n";
	fSimple(side, side1, side2);
	*/
	//task2
	const  int SIZE = 10;
	int arr[SIZE];
	fillArray(arr, SIZE);
	printArray(arr, SIZE);
	int left = indFirst(arr, SIZE);
	int right = indLast(arr, SIZE);
	reversePartArray(arr, left, right);
	printArray(arr, SIZE);
}