#include <iostream>
using namespace std;

#include "Links.h"

int main()
{
	system("color 2");

	const int SIZE = 5;
	
	int matrixA[SIZE][SIZE];
	int matrixB[SIZE][SIZE];
	int matrixC[SIZE][SIZE];

	fillMatrix(matrixA, matrixB);
	outputMatrix(matrixA, matrixB);
	sumMatrix(matrixA, matrixB, matrixC);

	int value;
	cout << "Input multiple value >> ";
	cin >> value;
	MultipleMatrix(matrixA, matrixB, value);
	outputMatrix(matrixA, matrixB);
}