#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <Windows.h>

int a[1000];
int n;
int* pa;

void load1() {
	FILE* fin = fopen("in1.txt", "rt");
	if (fin == NULL) {
		printf("Входной файл не найден\n");
		return;
	}

	fscanf(fin, "%d", &n);
	for (int i = 0; i < n; i++)
		fscanf(fin, "%d", &a[i]);

	fclose(fin);
}

void saveResult1() {
	float sa = 0;
	float s = 0;
	for (int i = 0; i < n; i++) {
		s += a[i];
	}
	sa = s / n;

	int m = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] > sa) {
			m++;
		}
	}

	FILE* fout = fopen("out1.txt", "wt");
	if (fout == NULL) {
		printf("Выходной файл не найден\n");
		return;
	}

	fprintf(fout, "%d\n", m);
	for (int i = 0; i < n; i++) {
		if (a[i] > sa) {
			fprintf(fout, "%d ", a[i]);
		}
	}
	fclose(fout);
}

void load2() {
	FILE* fin = fopen("in1.txt", "rt");
	if (fin == NULL) {
		printf("Входной файл не найден\n");
		return;
	}

	fscanf(fin, "%d", &n);
	pa = (int*)malloc(sizeof(int) * n);

	for (int i = 0; i < n; i++) {
		fscanf(fin, "%d", &pa[i]);
	}
	fclose(fin);
}

void saveResult2() {
	float sa = 0;
	float s = 0;
	for (int i = 0; i < n; i++) {
		s += pa[i];
	}
	sa = s / n;

	int m = 0;
	for (int i = 0; i < n; i++) {
		if (pa[i] > sa) {
			m++;
		}
	}

	FILE* fout = fopen("out1.txt", "wt");
	if (fout == NULL) {
		printf("Выходной файл не найден\n");
		return;
	}

	fprintf(fout, "%d\n", m);
	for (int i = 0; i < n; i++) {
		if (pa[i] > sa) {
			fprintf(fout, "%d ", pa[i]);
		}
	}

	fclose(fout);
}

void load3() {
	FILE* fin = fopen("in3.txt", "rt");
	if (fin == NULL) {
		printf("Входной файл не найден\n");
		return;
	}

	fscanf(fin, "%d", &n);
	pa = (int*)malloc(sizeof(int) * n);

	for (int i = 0; i < n; i++) {
		fscanf(fin, "%d", &pa[i]);
	}
	fclose(fin);
}

void saveResult3() {
	float sa = 0;
	float s = 0;
	for (int i = 0; i < n; i++) {
		s += pa[i];
	}
	sa = s / n;

	int m = 0;
	for (int i = 0; i < n; i++) {
		if ((pa[i] < sa) && (pa[i] > 0)) {
			m++;
		}
	}

	FILE* fout = fopen("out3.txt", "wt");
	if (fout == NULL) {
		printf("Выходной файл не найден\n");
		return;
	}

	fprintf(fout, "%d\n", m);
	for (int i = 0; i < n; i++) {
		if ((pa[i] < sa) && (pa[i] > 0)) {
			fprintf(fout, "%d ", pa[i]);
		}
	}

	fclose(fout);
}

void load4() {
	FILE* fin = fopen("in4.txt", "rt");
	if (fin == NULL) {
		printf("Входной файл не найден\n");
		return;
	}

	fscanf(fin, "%d", &n);
	pa = (int*)malloc(sizeof(int) * n);

	for (int i = 0; i < n; i++) {
		fscanf(fin, "%d", &pa[i]);
	}
	fclose(fin);
}

void saveResult4() {
	float max = pa[0];
	float s = 0;
	for (int i = 0; i < n; i++) {
		if (pa[i] > max)
			max = pa[i];
	}
	max = max * 2 / 3;

	int m = 0;
	for (int i = 0; i < n; i++) {
		if (pa[i] >= max) {
			m++;
		}
	}

	FILE* fout = fopen("out4.txt", "wt");
	if (fout == NULL) {
		printf("Выходной файл не найден\n");
		return;
	}

	fprintf(fout, "%d\n", m);
	for (int i = 0; i < n; i++) {
		if (pa[i] >= max)
			fprintf(fout, "%d ", pa[i]);
	}

	fclose(fout);
}

void main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int zad = 1;
	while (zad != 0) {
		printf("Введите 0 для выхода или номер задачи: ");
		scanf_s("%d", &zad);
		switch (zad) {
		case 0:
			break;
		case 1:
			load1();
			saveResult1();
			break;
		case 2:
			load2();
			saveResult2();
			free(pa);
			break;
		case 3:
			load3();
			saveResult3();
			free(pa);
			break;
		case 4:
			load4();
			saveResult4();
			free(pa);
			break;
		}
	}
}