#define _CRT_SECURE_NO_WARNINGS
#define NUM_ELEMENTS 10

#include <stdio.h>
#include <Windows.h>

int arr[NUM_ELEMENTS];
int n = 0;

void zad1() {
	printf("Гуторов Иван\nЗадача 1\n");
	
	int a, b, c;
	int p;

	scanf_s("%d%d%d", &a, &b, &c);
	printf("Ввели: %d, %d, %d\n", a, b, c);

	p = a * b * c;
	printf("p = %d\n", p);
}

void zad2() {
	printf("Гуторов Иван\nЗадача 2\n");

	int a, b, c;
	int p;

	FILE* fin = fopen("in2.txt", "rt");
	if (fin == NULL) {
		printf("Входной файл не найден");
		return;
	}

	fscanf(fin, "%d%d%d", &a, &b, &c);
	fclose(fin);
	printf("Ввели: %d, %d, %d\n", a, b, c);

	p = a * b * c;
	printf("p = %d\n", p);

	FILE* fout;
	fout = fopen("out2.txt", "wt");
	if (fout == NULL) {
		printf("Выходной файл не создался");
		return;
	}

	fprintf(fout, "%d", p);
	fclose(fout);
}

void zad3() {
	printf("Гуторов Иван\nЗадача 3\n");

	int a, b, c, d, e;
	int s;

	scanf_s("%d%d%d%d%d", &a, &b, &c, &d, &e);
	printf("Ввели: %d, %d, %d, %d, %d\n", a, b, c, d, e);

	s = a + b + c + d + e;
	printf("s = %d\n", s);
}

void zad4() {
	printf("Гуторов Иван\nЗадача 4\n");

	int a, b, c, d, e;
	int s;

	FILE* fin = fopen("in4.txt", "rt");
	if (fin == NULL) {
		printf("Входной файл не найден");
		return;
	}

	fscanf(fin, "%d%d%d%d%d", &a, &b, &c, &d, &e);
	fclose(fin);
	printf("Ввели: %d, %d, %d, %d, %d\n", a, b, c, d, e);

	s = a + b + c + d + e;
	printf("s = %d\n", s);

	FILE* fout;
	fout = fopen("out4.txt", "wt");
	if (fout == NULL) {
		printf("Выходной файл не создался");
		return;
	}

	fprintf(fout, "%d", s);
	fclose(fout);
}

void zad5() {
	printf("Гуторов Иван\nЗадача 5\n");

	int a[10];
	int n, i;

	FILE* fin = fopen("in5.txt", "rt");
	if (fin == NULL) {
		printf("Входной файл не найден");
		return;
	}

	fscanf(fin, "%d", &n);
	for (i = 0; i < n; i++)
		fscanf(fin, "%d", &a[i]);
	fclose(fin);

	printf("Введен массив a[%d] = ", n);
	for (i = 0; i < n; i++)
		printf("%d ", a[i]);

	int s = 0;
	for (i = 0; i < n; i++)
		s += a[i];
	float sa = (float)s / n;
	printf("\nsa = %f\n", sa);
	
	for (i = 0; i < n; i++) {
			if (a[i] > sa)
				a[i] *= 10;
		}

	printf("Ввели массив a[%d] = ", n);
		for (i = 0; i < n; i++)
			printf("%d ", a[i]);

	FILE* fout;
	fout = fopen("out5.txt", "wt");
	if (fout == NULL) {
		printf("Выходной файл не создался");
		return;
	}

	fprintf(fout, "%d\n", n);

	for (i = 0; i < n; i++) {
		fprintf(fout, "%d ", a[i]);
	}
	fclose(fout);
}

void zad6() {
	printf("Гуторов Иван\nЗадача 6\n");

	int a[10];
	int n, i;

	FILE* fin = fopen("in6.txt", "rt");
	if (fin == NULL) {
		printf("Входной файл не найден");
		return;
	}

	fscanf(fin, "%d", &n);
	for (i = 0; i < n; i++)
		fscanf(fin, "%d", &a[i]);
	fclose(fin);

	printf("Введен массив a[%d] = ", n);
	for (i = 0; i < n; i++)
		printf("%d ", a[i]);

	int s = 0;
	for (i = 0; i < n; i++)
		s += a[i];
	float sa = (float)s / n;
	printf("\nsa = %f\n", sa);

	for (i = 0; i < n; i++) {
		if ((a[i] < sa) && (a[i] % 2 == 0))
			a[i] /= 2;
	}

	printf("Ввели массив a[%d] = ", n);
	for (i = 0; i < n; i++)
		printf("%d ", a[i]);

	FILE* fout;
	fout = fopen("out6.txt", "wt");
	if (fout == NULL) {
		printf("Выходной файл не создался");
		return;
	}

	fprintf(fout, "%d\n", n);

	for (i = 0; i < n; i++) {
		fprintf(fout, "%d \n", a[i]);
	}
	fclose(fout);
}

void printElements() {
	int i = 0;
	while (i < n) {
		printf("%d ", arr[i]);
		i++;
	}
}

int findIndexMin() {
	int min = arr[0];
	int d = 0;
	for (int i = 1; i < n; i++) {
		if (arr[i] < min) {
			min = arr[i];
			d = i;
		}
	}
	return d;
}

void deleteMinElement() {
	int min = findIndexMin();
	for (int i = min; i < n; i++) {
		arr[i] = arr[i + 1];
	}
	n = n - 1;
}

void deleteElement() {
	printf("Индекс удаляемого элемента = ");
	int index;
	scanf_s("%d", &index);
	for (int i = index; i < n; i++) {
		arr[i] = arr[i + 1];
	}
	n = n - 1;
}

void pasteElement() {
	n = n + 1;
	printf("На какое место вставить элемента = ");
	int index;
	scanf_s("%d", &index);
	printf("Что вставить = ");
	int d;
	scanf_s("%d", &d);
	for (int i = n - 1; i > index; i--) {
		arr[i] = arr[i - 1];
	}
	arr[index] = d;
}

void pastePeredMinElement() {
	int x = findIndexMin();
	n = n + 1;
	for (int i = n - 1; i > x; i--) {
		arr[i] = arr[i - 1];
	}
	arr[x] = 0;
}

void zad78() {
	int item = 1;

	FILE* fin = fopen("in78.txt", "rt");
	if (fin == NULL) {
		printf("Входной файл не найден");
		return;
	}

	fscanf(fin, "%d", &n);

	for (int i = 0; i < n; i++)
		fscanf(fin, "%d", &arr[i]);
	fclose(fin);

	while (item != 0) {
		printf("\n");
		printf("-----------------------------------------\n");
		printf("Содержимое массива: < ");
		printElements();
		printf(" >\n");
		printf("11: Удалить заданный элемент\n");
		printf("12: Вставляем новый элемент в заданное место\n");
		printf("13: Удалить минимальный элемент\n");
		printf("14: Перед минимальным элементом вставить 0\n");
		printf("\n");
		printf("0: Выйти из программы\n");
		printf("Выбранная операция >>>>>> ");
		scanf_s("%d", &item);
		switch (item) {
		case 0:
			break;
		case 11:
			deleteElement();
			break;
		case 12:
			pasteElement();
			break;
		case 13:
			deleteMinElement();
			break;
		case 14:
			pastePeredMinElement();
			break;
		}
	}
	FILE* fout;
	fout = fopen("out78.txt", "wt");
	if (fout == NULL) {
		printf("Выходной файл не создался");
		return;
	}

	fprintf(fout, "%d\n", n);

	for (int i = 0; i < n; i++) {
		fprintf(fout, "%d \n", arr[i]);
	}
	fclose(fout);
}

void main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int zad = 1;
	while (zad != 0) {
		printf("\nВведите задачу: ");
		scanf_s("%d", &zad);
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
		case 6:
			zad6();
			break;
		case 78:
			zad78();
			break;
		}
	}
}