// 9 лабораторная работа: Программа сортировки строк текста в алфавитном порядке
#include <iostream>
#include <stdlib.h>
using namespace std;

bool strcmp_my(char* a, char* b) {
	while (*a != 0 && *b != 0) {
		if (*a > *b) return true; // сравнение строк
		else if ((*a < *b))return false;
		a++;
		b++;
	}
	return false;
}

void sort(char** mn, int N) {
	for (int i = 0; i < N - 1; i++) {
		for (int j = 1; j < N; j++) {
			if (strcmp_my(*(mn + j - 1), *(mn + j))) {
				char* p = *(mn + j);
				*(mn + j) = *(mn + j - 1);
				*(mn + j - 1) = p;
			}
		}
	}
}


int main() {
	setlocale(LC_ALL, "Russian");
	int n = 0;
	char** str;
	char** str_cpy;
	str = (char**)malloc(1 * sizeof(char*)); //malloc -запрос памяти в ближней "куче"
	str_cpy = (char**)malloc(1 * sizeof(char*));

	for (int i = 0;; i++) {
		str = (char**)realloc(str, (i + 2) * sizeof(char*)); //realloc - перераспределить ранее выделенную память
		str_cpy = (char**)realloc(str_cpy, (i + 2) * sizeof(char*));
		str[i] = (char*)malloc(100 * sizeof(char));
		str_cpy[i] = (char*)malloc(100 * sizeof(char));
		cin.getline(str_cpy[i], 100); //getline - ввод данных из консольного окна
		str[i] = str_cpy[i];
		if (*str[i] == '\0') break;
		n++;
	}

	system("cls"); //очистка экрана консоли
	sort(str, n);
	cout << "-----------------------------" << endl
		<< "Исходные строки: " << endl;
	for (int h = 0; h < n; h++) { 
		cout << str_cpy[h] << endl;
	}
	cout << "-----------------------------" << endl
		<< "Отсортированные строки: " << endl;
	for (int k = 0; k < n; k++) {
		cout << str[k] << endl;
	}

	free(str_cpy); //освобождение памяти 
	free(str); //освобождение памяти 

	return 0;
}
