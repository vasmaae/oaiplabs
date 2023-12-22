#include <stdio.h>
#include <Windows.h>

int recFact(int a) {
	if (a == 0) {
		return 1;
	}
	else {
		return a * recFact(a - 1);
	}
}

void zad1() {
	printf("%d\n", recFact(5));
}

void rec1(int n) {
	printf(" %d", n);
	if (n > 1) {
		rec1(n - 2);
	}
}

void rec2(int n) {
	if (n > 1) {
		rec2(n - 2);
	}
	printf(" %d", n);
}

void rec3(int n) {
	printf(" %d", n);
	if (n > 1)
		rec3(n - 2);
	if (n != 1)
		printf(" %d", n);
}

void zad2() {
	rec1(11);
	printf(" rec1 FINISH\n");
	rec2(11);
	printf(" rec2 FINISH\n");
	rec3(11);
	printf(" rec3 FINISH\n");
}

void zad3() {
	rec1(7);
	printf(" rec1 FINISH\n");
	rec2(7);
	printf(" rec2 FINISH\n");
	rec3(7);
	printf(" rec3 FINISH\n");
}

void recEge1(int n) {
	if (n >= 1) {
		printf(" %d", n);
		recEge1(n - 1);
		recEge1(n - 1);
	}
}

void zad4() {
	recEge1(3);
	printf("\n");
}

void f1(int n) {
	if (n > 2) {
		printf("%d\n", n);
		f1(n - 3);
		f1(n - 4);
	}
}

void zad5() {
	f1(10);
}

void f2(int n) {
	printf("%d\n", n);
	if (n < 5) {
		f1(n + 1);
		f1(n + 3);
	}
}

void zad6() {
	f2(1);
}

void G3(int n);

void F3(int n) {
	if (n > 0) {
		G3(n - 1);
	}
}

void G3(int n) {
	printf("*");
	if (n > 1) {
		F3(n - 3);
	}
}

void zad7() {
	int n = 11;
	F3(n);
	printf("\n");
}

void main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int zad = 1;
	while (zad != 0) {
		printf("¬ведите задачу (0 - выход): ");
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
		case 7:
			zad7();
			break;
		}
	}
}