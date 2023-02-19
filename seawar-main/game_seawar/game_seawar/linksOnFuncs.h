#pragma once

void arrangementManual(char field[][10], const int size);
void arrangementAuto(char field[][10], const int size);
void printField(char field[][10], const int size);
void emptyFillField(char field[][10], const int size);
void gamePBRandomShot(const int size, char showField1[][10], char showField2[][10], char field1[][10], char field2[][10]);
void gameBBRandomShot(const int size, char showField1[][10], char showField2[][10], char field1[][10], char field2[][10]);
int checkStep(int x, int y, char show[][10], char field[][10], int size);
