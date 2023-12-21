#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <Windows.h>
#include <ctype.h>

void zad1() {
	char name[12];
	printf("Введите ваше имя: ");
	fgets(name, 11, stdin);
	printf("Приветствую тебя, %s\n", name);
}

void zad2() {
	printf("Введите символ = ");
	int ch = getchar();

	if (ch != '\n')
		while (getchar() != '\n');

	for (int c = ch; c <= ch + 19; c++) {
		printf("'%c' (%d)\n", c, c);
	}
	printf("\n\n\n");
}

void zad3() {
	printf("Введите символ = ");
	int ch = getchar();

	if (ch != '\n')
		while (getchar() != '\n');

	for (int c = ch; c >= ch - 29; c--) {
		printf("'%c' (%d)\n", c, c);
	}
	printf("\n\n\n");
}

void zad4() {
	char s[80];
	printf("Введите новую строку: ");
	fgets(s, 79, stdin);
	printf("\nВы ввели строку s = \"%s\"", s);

	int cnt = 0;
	for (int i = 0; i < strlen(s); i++) {
		if (s[i] == ' ')
			cnt++;
	}
	printf("\nВ ней %d пробелов\n", cnt);
}

void zad5() {
	char s[80];
	printf("Введите новую строку: ");
	fgets(s, 79, stdin);
	printf("\nВы ввели строку s = \"%s\"", s);

	for (int i = 0; i < strlen(s); i++) {
		if (s[i] == ' ')
			s[i] = '#';
	}
	printf("\nСтрока после обработки = \"%s\"", s);
}

void zad6_1() {
	char s[80];
	printf("Введите новую строку: ");
	fgets(s, 79, stdin);
	printf("\nВы ввели строку s = \"%s\"", s);

	for (int i = 0; s[i] != '\0'; i++) {
		if (isdigit(s[i]))
			s[i] = '$';
	}
	printf("\nСтрока после обработки = \"%s\"", s);
}

int myIsDigit(char c) {
	if ((c >= '0') && (c <= '9'))
		return 1;
	return 0;
}

void zad6_2() {
	char s[80];
	printf("Введите новую строку: ");
	fgets(s, 79, stdin);
	printf("\nВы ввели строку s = \"%s\"", s);

	for (int i = 0; s[i] != '\0'; i++) {
		if (myIsDigit(s[i]))
			s[i] = '$';
	}
	printf("\nСтрока после обработки = \"%s\"", s);
}

void zad7_1() {
	char s[80];
	printf("Введите новую строку: ");
	fgets(s, 79, stdin);
	printf("\nВы ввели строку s = \"%s\"", s);

	for (int i = 0; s[i] != '\0'; i++) 
		s[i] = toupper(s[i]);
	printf("\nСтрока после обработки = \"%s\"", s);
}

int myToupper(int c) {
	int new_c = c;
	if (c >= 'a' && c <= 'z')
		new_c = 'A' + (c - 'a');
	if (c >= 'а' && c <= 'я')
		new_c = 'А' + (c - 'а');
	/*if (c >= 'р' && c <= 'я')
		new_c = 'Р' + (c - 'р');*/
	if (c == 'ё')
		new_c = 'Ё';
	return new_c;
}

void zad7_2() {
	char s[80];
	printf("Введите новую строку: ");
	fgets(s, 79, stdin);
	printf("\nВы ввели строку s = \"%s\"", s);

	for (int i = 0; s[i] != '\0'; i++)
		s[i] = myToupper(s[i]);
	printf("\nСтрока после обработки = \"%s\"", s);
}

void main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int zad = 1;
	while (zad != 0) {
		printf("\n\nВведите номер задачи (0 для выхода): ");
		scanf_s("%d", &zad);
		getchar();
		switch (zad) {
		case 0:
			break;
		case 1:
			zad1();
			break;
		case 2:
			zad2();
			break;
		case 3:
			zad3();
			break;
		case 4:
			zad4();
			break;
		case 5:
			zad5();
			break;
		case 61:
			zad6_1();
			break;
		case 62:
			zad6_2();
			break;
		case 71:
			zad7_1();
			break;
		case 72:
			zad7_2();
			break;
		}
	}
}