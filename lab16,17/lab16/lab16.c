#include <stdio.h>
#include <Windows.h>

#define NUM_ELEMENTS 10

int arr[NUM_ELEMENTS];
int n = 0;

void printElements() {
	int i = 0;
	while (i < n) {
		printf("%d ", arr[i]);
		i++;
	}
}

void keyboardInput() {
	printf("n = ");
	scanf_s("%d", &n);
	printf("input %d values: ", n);
	for (int i = 0; i < n; i++) {
		scanf_s("%d", &arr[i]);
	}
}

void oddsX10() {
	for (int i = 0; i < n; i++) {
		if (arr[i] % 2 == 1) {
			arr[i] = arr[i] * 10;
		}
	}
}
int findMin() {
	int min = arr[0];
	for (int i = 1; i < n; i++) {
		if (arr[i] < min) {
			min = arr[i];
		}
	}
	return min;
}

void bigger10() {
	int c = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] >= 10) {
			c++;
		}
	}
	printf("����� ����� > 10 - %d", c);
}

int x2() {
	int c = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] % 2 == 0) {
			c = i;
		}
	}
	return c;
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

int findIndexMax() {
	int min = arr[0];
	for (int i = 0; i < n; i++) {
		if (arr[i] > min) {
			min = i;
		}
	}
	return min;
}

int x1() {
	int c = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] % 2 == 0) {
			arr[i] = arr[i] * (-1);
		}
	}
	return c;
}

int x4() {
	int c = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] <= 4) {
			arr[i] = 4;
		}
	}
	return c;
}

void deleteElement() {
	printf("������ ���������� �������� = ");
	int index;
	scanf_s("%d", &index);
	for (int i = index; i < n; i++) {
		arr[i] = arr[i + 1];
	}
	n = n - 1;
}

void pasteElement() {
	n = n + 1;
	printf("�� ����� ����� �������� �������� = ");
	int index;
	scanf_s("%d", &index);
	printf("��� �������� = ");
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

void main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int item = 1;
	while (item != 0) {
		printf("\n");
		printf("-----------------------------------------\n");
		printf("���������� �������: < ");
		printElements();
		printf(" >\n");
		printf("1: ������ � ���������� ������\n");
		printf("2: x10 ��� ���� �������� ���������\n");
		printf("3: ����� ����������� �������\n");
		printf("4: ������� ��������� > 10\n");
		printf("5: x2 ��� ���������� �������\n");
		printf("6: ������� ������ ����� ������������\n");
		printf("7: x10 ��� �������� ������ ������������\n");
		printf("8: ����������� ������� min � max\n");
		printf("11: ������� �������� �������\n");
		printf("12: ��������� ����� ������� � �������� �����\n");
		printf("13: ������� ����������� �������\n");
		printf("14: ����� ����������� ��������� �������� 0\n");
		printf("\n");
		printf("0: ����� �� ���������\n");
		printf("��������� �������� >>>>>> ");
		scanf_s("%d", &item);
		switch (item) {
		case 0:
			break;
		case 1:
			keyboardInput();
			break;
		case 2:
			oddsX10();
			break;
		case 3: {
			int min = findMin();
			printf("min = %d\n", min);
			break;
		}
		case 4:
			bigger10();
			break;
		case 5: {
			int index = x2();
			if (index >= 0) {
				arr[index] *= 2;
			}
			break;
		}
		case 6: {
			int index = findIndexMin();
			printf("������ ������������ �������� = %d\n", index);
			int cnt = 0;
			for (int i = 0; i < index; i++) {
				if (arr[i] % 2 == 0) {
					cnt++;
				}
			}
			printf("����� ������������ %d ������ ���������\n", cnt);
			break;
		}
		case 7: {
			int index = findIndexMin();
			printf("������ ������������ �������� = %d\n", index);
			for (int i = index + 1; i < n; i++) {
				if (arr[i] % 2 != 0) {
					arr[i] *= 10;
				}
			}
			printElements();
			break;
		}
		case 8: {
			int index = findIndexMin();
			int index1 = findIndexMax();
			printf("������ ������������ �������� = %d\n", index);
			printf("������ �ax �������� = %d\n", index1);
			int c = arr[index];
			int d = arr[index1];
			arr[index] = arr[index1];
			arr[index1] = c;
			printElements();
			break;
		}
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
}