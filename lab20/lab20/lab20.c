#define _CRT_SECURE_NO_WARNINGS
#define NUM_ELEMENTS_1 8
#define NUM_ELEMENTS_2 10

#include <stdio.h>
#include <Windows.h>

int arr[NUM_ELEMENTS_1][NUM_ELEMENTS_2];
int n = 0;
int e = 0;
int j = 0;

void fillArrIJ() {
	printf("������� n = ");
	scanf("%d", &n);
	printf("\n");
	printf("������� e = ");
	scanf("%d", &e);
	printf("\n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < e; j++)
			arr[i][j] = i * 10 + j;
	}
	printf("!!!! fillArrIJ !!!!\n");
}

void fillZero() {
	printf("������� n = ");
	scanf("%d", &n);
	printf("\n");
	printf("������� e = ");
	scanf("%d", &e);
	printf("\n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < e; j++) 
			arr[i][j] = 0;
	}
	printf("!!!! fillZero !!!!\n");
}

void printElements() {
	printf("!!!! print() !!!!\n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < e; j++)
			printf("%3d ", arr[i][j]);
		printf("\n");
	}
}
void randomFill0_9() {
	printf("������� n = ");
	scanf("%d", &n);
	printf("\n");
	printf("������� e = ");
	scanf("%d", &e);
	printf("\n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < e; j++)
			arr[i][j] = rand() % 10;
	}
	printf("!!!! fillZero !!!!\n");
}
void odd_number() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < e; j++) {
			if (arr[i][j] % 2 != 0)
				arr[i][j] *= 10;
		}
	}
}
void cratnoeten() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < e; j++) {
			if (arr[i][j] % 10 == 0)
				arr[i][j] /= 10;
		}
	}
}
void inputByClava() {
	printf("������� n = ");
	scanf("%d", &n);
	printf("\n");
	printf("������� e = ");
	scanf("%d", &e);

	printf("input values: ");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < e; j++)
			scanf_s("%d", &arr[i][j]);
	}
}

void inputByFile() {
	FILE* fin;
	fin = fopen("C:\\Users\\����\\source\\repos\\laba20\\input.txt", "rt");
	if (fin == NULL) {
		printf("���� �� ������");
		return;
	}
	fscanf(fin, "%d", &n);
	fscanf(fin, "%d", &e);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			fscanf(fin, "%d ", &arr[i][j]);
	}
	fclose(fin);
}
void saveInFile() {
	int k = 0;
	FILE* fout;
	fout = fopen("C:\\Users\\����\\source\\repos\\laba20\\output.txt", "wt");
	if (fout == NULL) {
		printf("���� �� ������");
		return;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < e; j++) {
			if (k == n) {
				fprintf(fout, "\n");
				k = 0;
			}
			fprintf(fout, "%d ", arr[i][j]);
			k += 1;
		}
	}
	fclose(fout);

}

void DeleteLenNumber() {
	int r = 0;
	printf("����� ������ ������� �� ����� ������� �����? - ");
	scanf("%d", &r);
	for (r; r < n; r++) {
		for (int j = 0; j < e; j++) 
			arr[r][j] = arr[r + 1][j];
	}
	n = n - 1;
}

void AddTooStolb() {
	int r = 0;
	printf("����� ������� ��������������? - ");
	scanf("%d", &r);
	e = e + 1;
	for (int i = 0; i < n; i++) {
		for (int j = e; j > r; j--)
			arr[i][j] = arr[i][j - 1];
	}

}
void SRmaxMin() {
	int d = 0;
	int t = 0;
	int ma = -100000000000;
	int mi = 100000000000000;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < e; j++) {
			if (mi > arr[i][j]) {
				mi = arr[i][j];
				d = i;
				t = j;
			}

		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < e; j++) {
				if (ma < arr[i][j])
					ma = arr[i][j];
			}

		}
	}
	float sr;
	sr = (mi + ma) / 2;
	arr[d - 1][j] = sr;
	arr[d][j - 1] = sr;
}

void main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int item;
	do {
		printElements();
		printf("=============================\n");
		printf("�������� ������ ��� ��������:\n");
		printf("1. ��������� ���������� i * 10 + j\n");
		printf("2. ��������� ������\n");
		printf("3. ��������� ���������� ����������\n");
		printf("4. ��� �������� ��������� � 10 ���\n");
		printf("5. ��� ������� 10 ��������� � 10 ���\n");
		printf("6. ������ � ���������� ������\n");
		printf("7. ����� ������ �� �����\n");
		printf("8. ��������� � ���� ������\n");
		printf("9. ������� ������\n");
		printf("10. �������������� ������� �������\n");
		printf("0. ����� �� ���������\n");
		printf("��������� ��������>>>>>>>>>\n");

		scanf("%d", &item);

		switch (item) {
		case 1: {
			fillArrIJ();
			break;
		}
		case 2: {
			fillZero();
			break;
		}
		case 3: {
			randomFill0_9();
			break;
		}
		case 4: {
			odd_number();
			break;
		}
		case 5: {
			cratnoeten();
			break;
		}
		case 6: {
			inputByClava();
			break;
		}
		case 7: {
			inputByFile();
			break;
		}
		case 8: {
			saveInFile();
			break;
		}
		case 9: {
			DeleteLenNumber();
			break;
		}
		case 10: {
			AddTooStolb();
			break;
		}
		case 11: {
			SRmaxMin();
			break;
		}
		}
	} while (item != 0);
}
