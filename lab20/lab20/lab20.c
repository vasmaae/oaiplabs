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
	printf("введите n = ");
	scanf("%d", &n);
	printf("\n");
	printf("введите e = ");
	scanf("%d", &e);
	printf("\n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < e; j++)
			arr[i][j] = i * 10 + j;
	}
	printf("!!!! fillArrIJ !!!!\n");
}

void fillZero() {
	printf("введите n = ");
	scanf("%d", &n);
	printf("\n");
	printf("введите e = ");
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
	printf("введите n = ");
	scanf("%d", &n);
	printf("\n");
	printf("введите e = ");
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
	printf("введите n = ");
	scanf("%d", &n);
	printf("\n");
	printf("введите e = ");
	scanf("%d", &e);

	printf("input values: ");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < e; j++)
			scanf_s("%d", &arr[i][j]);
	}
}

void inputByFile() {
	FILE* fin;
	fin = fopen("C:\\Users\\Макс\\source\\repos\\laba20\\input.txt", "rt");
	if (fin == NULL) {
		printf("Файл не найден");
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
	fout = fopen("C:\\Users\\Макс\\source\\repos\\laba20\\output.txt", "wt");
	if (fout == NULL) {
		printf("Файл не создан");
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
	printf("какую строку кикнуть из этого потного лобби? - ");
	scanf("%d", &r);
	for (r; r < n; r++) {
		for (int j = 0; j < e; j++) 
			arr[r][j] = arr[r + 1][j];
	}
	n = n - 1;
}

void AddTooStolb() {
	int r = 0;
	printf("какой столбец продублировать? - ");
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
		printf("Выберите нужную вам операцию:\n");
		printf("1. Заполнить значениями i * 10 + j\n");
		printf("2. Заполнить нулями\n");
		printf("3. Заполнить случайными значениями\n");
		printf("4. Все нечетные увеличить в 10 раз\n");
		printf("5. все кратные 10 уменьшить в 10 раз\n");
		printf("6. ввести с клавиатуры массив\n");
		printf("7. взять массив из файла\n");
		printf("8. сохранить в файл массив\n");
		printf("9. Удалить строку\n");
		printf("10. Проудблировать столбец массива\n");
		printf("0. Выйти из программы\n");
		printf("Выбранная операция>>>>>>>>>\n");

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
