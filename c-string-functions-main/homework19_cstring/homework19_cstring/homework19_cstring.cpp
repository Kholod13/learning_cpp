#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int main()
{
	//task1
	/*
	const int SIZE = 100;
	char buf[SIZE] = "COmpares at most count characters booook of two possibly null-terminated arrays.";
	char sym[] = "aeouiAEOUI";

	cout << endl << buf << endl;

	char* p = strpbrk(buf, sym);
	int counter = 0;

	for (int i = 0; buf[i] != '\0'; i++) {
		
		if (p != nullptr) {
			strcpy(buf, buf + i);
			counter++;
		}

	}
	
	cout << "\n\t\tNumber letters = " << counter << endl;
	*/
	//task2
	/*
	const int SIZE = 100;
	
	char word1[SIZE]{};
	char word2[SIZE]{};
	char word3[SIZE]{};
	char word4[SIZE]{};
	char word5[SIZE]{};

	cout << "Input word >> " << word1;
	cin >> word1;
	cout << "Input word >> " << word2;
	cin >> word2;
	cout << "Input word >> " << word3;
	cin >> word3;
	cout << "Input word >> " << word4;
	cin >> word4;
	cout << "Input word >> " << word5;
	cin >> word5;

	
	if (word1[strlen(word1)] == word2[strlen(word2)] &&
		word1[0] == word2[0]) {
		strcat(word1, word2);
	}
	if (word1[strlen(word1)] == word3[strlen(word3)] &&
		word1[0] == word3[0]) {
		strcat(word1, word3);
	}
	if (word1[strlen(word1)] == word4[strlen(word4)] &&
		word1[0] == word4[0]) {
		strcat(word1, word4);
	}
	if (word1[strlen(word1)] == word5[strlen(word5)] &&
		word1[0] == word5[0]) {
		strcat(word1, word5);
	}

	if (word2[strlen(word2)] == word3[strlen(word3)] &&
		word2[0] == word3[0]) {
		strcat(word2, word3);
	}
	if (word2[strlen(word2)] == word4[strlen(word4)] &&
		word2[0] == word4[0]) {
		strcat(word2, word4);
	}
	if (word2[strlen(word2)] == word5[strlen(word5)] &&
		word2[0] == word5[0]) {
		strcat(word2, word5);
	}

	if (word3[strlen(word3)] == word4[strlen(word4)] &&
		word3[0] == word4[0]) {
		strcat(word3, word4);
	}
	if (word3[strlen(word3)] == word5[strlen(word5)] &&
		word3[0] == word5[0]) {
		strcat(word3, word5);
	}

	if (word4[strlen(word4)] == word5[strlen(word5)] &&
		word4[0] == word5[0]) {
		strcat(word4, word5);
	}
	
	cout << "\n|About update|\n";

	cout << endl << word1 << endl;
	cout << endl << word2 << endl;
	cout << endl << word3 << endl;
	cout << endl << word4 << endl;
	*/
	//task3
	/*
	const int SIZE = 100;
	char line[SIZE]{};
	char pastLine[SIZE]{};
	char correctWords[SIZE + SIZE + SIZE]{};
	char stop[5] = "stop";

	int counter = 0;
	int countWords = 0;

	while (true){
		countWords++;
		strcpy(pastLine, line);
		cout << "Input word >> ";
		cin >> line;

		if (pastLine[0] == line[0] && pastLine[1] == line[1]) {

			if (counter == 0) {
				strcat(correctWords, pastLine);
			}

			strcat(correctWords, " ");
			strcat(correctWords, line);
			counter++;
		}
		
		if (line[0] == 's' && line[1] == 't' &&
			line[2] == 'o' && line[3] == 'p') {
			break;
		}

	}
	countWords--;
	cout << "\nNumber words >> " << countWords << endl;
	cout << "\nBig line >> " << correctWords << endl;
	*/
}