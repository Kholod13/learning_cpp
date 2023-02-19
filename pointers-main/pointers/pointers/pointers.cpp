#include <iostream>
#include <ctime>
using namespace std;

int globalMax(int arr[], int size);
int Max1(int arr[], int size);
int Max2(int arr[], int size);
void limitIndex(int arr[], int size);


int main() {
	//task 1
	/*
	int val1, val2, val3;

	int* ptr1 = &val1;
	int* ptr2 = &val2;
	int* ptr3 = &val3;

	cout << "Input value (1,2,3) >> ";
	cin >> *ptr1 >> *ptr2 >> *ptr3;
	cout << endl;

	if (*ptr1 > *ptr2 && *ptr1 > *ptr3) {
		cout << "VAL1 is biggest" << endl;
	}
	else if (*ptr2 > *ptr1 && *ptr2 > *ptr3) {
		cout << "VAL2 is biggest" << endl;
	}
	else if (*ptr3 > *ptr2 && *ptr3 > *ptr1) {
		cout << "VAL3 is biggest" << endl;
	}
	else {
		cout << "no biggest value" << endl;
	}
	*/
	//task2
	/*
	const int SIZE = 5;
	int arr[SIZE]{};
	int j = SIZE;
	int* ptr = &j;
	srand(unsigned(time(0)));

	for (int i = 0; i < SIZE; i++) {
		*(arr + i) = rand() % 21;
	}
	for (int i = 0; i < SIZE; i++) {
		cout << " " << *(arr + i);
	}
	cout << endl;

	for (int i = 0; i < SIZE/2; i++) {

		swap(*(arr + i), arr[-- * ptr]);

	}

	for (int i = 0; i < SIZE; i++) {
		cout << " " << *(arr + i);
	}
	*/
	//task3
	/*
	const int SIZE = 5;
	int arr[SIZE]{};
	int arr2[SIZE]{};
	int j = SIZE;
	int* ptr = &j;
	srand(unsigned(time(0)));

	for (int i = 0; i < SIZE; i++) {
		*(arr + i) = rand() % 21;
	}
	for (int i = 0; i < SIZE; i++) {
		cout << " " << *(arr + i);
	}
	cout << endl;

	for (int i = 0; i < SIZE; i++) {
		*(arr2 + i) = arr[--*ptr];
	}

	for (int i = 0; i < SIZE; i++) {
		cout << " " << *(arr2 + i);
	}
	*/
	//task4

	const int SIZE = 10;
	int arr[SIZE]{};
	srand(unsigned(time(0)));

	for (int i = 0; i < SIZE; i++) {
		*(arr + i) = rand() % 101;
	}
	for (int i = 0; i < SIZE; i++) {
		cout << " " << *(arr + i);
		if (i == SIZE / 2-1) {
			cout << "|";
		}
	}
	cout << endl;

	int max, max1, max2;

	max = globalMax(arr, SIZE);
	cout << "\nMax = " << max << endl;

	max1 = Max1(arr, SIZE);
	cout << "\nMax in first half = " << max1 << endl;

	max2 = Max2(arr, SIZE);
	cout << "\nMax in second half = " << max2 << endl;

	limitIndex(arr, SIZE);
}

int globalMax(int arr[], int size) {
  	int max = arr[0];
	for (int i = 1; i < size; i++) {

		if (*(arr + i) > max) {
			max = *(arr + i);
		}

	}
	return max;
};
int Max1(int arr[], int size) {
	int max = arr[0];
	for (int i = 1; i < size/2; i++) {

		if (*(arr + i) > max) {
			max = *(arr + i);
		}

	}
	return max;
};
int Max2(int arr[], int size) {
	int max = arr[size/2];
	for (int i = size/2+1; i < size; i++) {

		if (*(arr + i) > max) {
			max = *(arr + i);
		}

	}
	return max;
};
void limitIndex(int arr[], int size) {
	int val1, val2;
	int* ptr1 = &val1;
	int* ptr2 = &val2;

	cout << "\nInput limits >> ";
	cin >> *ptr1 >> *ptr2;

	int ind1 = 0, ind2 = 0;
	for (int i = 0; i < size; i++) {
		if (*ptr1 == arr[i]) {
			ind1 = i;
		}
		if (ind1 > 0 && *ptr2 == arr[i]) {
			ind2 = i;
		}
	}

	cout << endl;
	for (int i = ind1; i <= ind2; i++) {
		cout << " " << *(arr + i);
	}
	cout << endl;
	
};