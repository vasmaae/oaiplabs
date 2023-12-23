#define _CRT_SECURE_NO_WARNINGS

#include <string.h>
#include <stdio.h>
#include <string.h>
#include "SortString.h"


static char filename[] = "";

// ������������ ����� ����� � �������
#define MAX_LEN_WORD 80
// ������������ ���������� ����
#define MAX_WORDS 20000

// �����, ����������� �� ����� 
char words[MAX_WORDS][MAX_LEN_WORD + 1];
// ���������� ���� � �������
int n = 0;

// ������ ��� ���������� 
char a[MAX_WORDS][MAX_LEN_WORD + 1];

int getNextDelim(FILE* fp, char token[]);
int getNextWord(FILE* fp, char token[]);

int LoadWords(char* filename) {
	// ������� ����
	FILE* fin = fopen(filename, "rt");
	if (fin == NULL) {
		// ���� ���� �� ������ ������� - �������� �� ����
		printf("File %s doesn't opened!\n", filename);
		return 0;
	}

	char token[MAX_LEN_WORD + 1];
	// ���� �� ����� �����
	while (!feof(fin)) {
		// ���� ���� ����������� - ����� ���
		while (getNextDelim(fin, token)) {
		}
		// ���� ���� ����� - ����� ���
		if (getNextWord(fin, token)) {
			if (n < MAX_WORDS) {
				strcpy(words[n], token);
				n++;
			}
			else {
				printf("Words are more than elements in array!!\n", filename);
				fclose(fin);
				return 0;
			}
		}
	}
	// ��������� ���� � �������
	fclose(fin);
	return 1;
}

// ���������� 0 - ���� ch - �� �����.
// ���������� 1 - ���� ch - �����.
// ��������� �������� ��� ��������� ���� (� ������ < 128)
// � ��� ������� ���� �� ��������� ANSI
int isalpha_my(unsigned char ch) {

	if (isalpha(ch))
		return 1;

	// ANSI ���������!!!
	if (ch >= 192 && ch <= 223)
		return 1;
	if (ch >= 224 && ch <= 255)
		return 1;

	return 0;
}

// ���������� 1 - ����  �� ����� �������� �����������.
// � ���� ������ � token ������������ ������, ���������� 
// ���� �����������.
// ���� � ����� ��� �� ����������� - ���������� 0.
// � ���� ������ ��������� token ������������.
int getNextDelim(FILE* fp, char token[])
{
	int ch = getc(fp);
	if (ch == EOF) {
		return 0;
	}
	if (isalpha_my((unsigned char)ch)) {
		ungetc(ch, fp);
		return 0;
	}
	token[0] = (unsigned char)ch;
	token[1] = '\0';
		return 1;
}

// ���������� 1 - ����  �� ����� ��������� �����.
// � ���� ������ � token ������������ ������, ���������� 
// ��� �����. ������������� ��� ����� �� ����� MAX_LEN_WORD ��������.
// ���� � ����� �� ���� ����� - ���������� 0.
// � ���� ������ token �������� ������ ������.
int getNextWord(FILE* fp, char token[])
{
	int i = 0;
	int ch;
	while (((ch = getc(fp)) != EOF) && (i < MAX_LEN_WORD)) {
		if (!isalpha_my((unsigned char)(ch))) {
			break;
		}
		token[i++] = ch;
	}
	ungetc(ch, fp);
	token[i] = '\0';
		if (i == 0)
			return 0;
	return 1;
}

void fillArrayStrings() {
	for (int i = 0; i < n; i++) {
		strcpy(a[i], words[i]);
	}
}

int isSortedStrings() {
	for (int i = 0; i < n - 1; i++) {
		if (strcmp(a[i], a[i + 1]) > 0) {
			return 0;
		}
	}
	return 1;
}

void SelectionSortStrings() {
	for (int i = 0; i < n - 1; i++) {
		int iMin = i;
		for (int j = i + 1; j < n; j++) {
			if (strcmp(a[j], a[iMin]) < 0) {
				iMin = j;
			}
		}
		if (i != iMin) {
			char tmp[MAX_LEN_WORD + 1];
			strcpy(tmp, a[i]);
			strcpy(a[i], a[iMin]);
			strcpy(a[iMin], tmp);
		}
	}
}

void BubbleSortStrings() {
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (strcmp(a[j], a[j + 1]) > 0) {
				char tmp[MAX_LEN_WORD + 1];
				strcpy(tmp, a[j]);
				strcpy(a[j], a[j + 1]);
				strcpy(a[j + 1], tmp);
			}
		}
	}
}

void InsertSortStrings() {
	for (int i = 1; i < n; i++) {
		char key[MAX_LEN_WORD + 1];
		strcpy(key, a[i]);
		int j = i - 1;
		while (j >= 0 && strcmp(a[j], key) > 0) {
			strcpy(a[j + 1], a[j]);
			j = j - 1;
		}
		strcpy(a[j + 1], key);
	}
}

void QuickSortStrings() {
	qsort(a, n, sizeof(a[0]), strcmp);
}

void ShellSortStrings() {
	int gap, i, j;
	char key[MAX_LEN_WORD + 1];
	for (gap = n / 2; gap > 0; gap /= 2) {
		for (i = gap; i < n; i++) {
			strcpy(key, a[i]);
			j = i;
			while (j >= gap && strcmp(a[j - gap], key) > 0) {
				strcpy(a[j], a[j - gap]);
				j -= gap;
			}
			strcpy(a[j], key);
		}
	}
}