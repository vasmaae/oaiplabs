#pragma once

// ������������ ����� ����� � �������
#define MAX_LEN_WORD 80
// ������������ ���������� ����
#define MAX_WORDS 20000

int LoadWords(char* filename);
void fillArrayStrings();

void SelectionSortStrings();
void BubbleSortStrings();
void InsertSortStrings();
void QuickSortStrings();
void ShellSortStrings();

//int LinearSearchStrings(char* value);
//int BinarySearchStrings(char* value);
int isSortedStrings();

extern int n;
