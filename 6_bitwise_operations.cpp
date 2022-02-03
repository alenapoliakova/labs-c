#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <locale.h>
#include <math.h>
int main()
{
	setlocale(LC_ALL, "Russian");
	int  sdv, m;
	int nad, nad1;
	unsigned int num;
	unsigned int num1;
	printf("Введите число: ");
	scanf_s("%u", &num);
	num1 = num;
	printf("\nВведите число позиций сдвига : ");
	scanf_s("%d", &sdv);
	printf("\n ------------------------------------------------------- \n");
	printf("Десятичная запись данного числа: %u \n", num);
	printf("Двоичная запись данного числа: ");
	m = 1;
	for (int i = sizeof(num) * 8 - 1; i >= 0; i--) { 
		if ((num >> i) & m) printf("1");
		else printf("0");
	}

	nad = num << (sizeof(num) * 8 - sdv);
	num >>= sdv;
	num |= nad;
	printf("\nдесятичная запись преобразованного числа при сдвиге вправо: %u \n", num);
	printf("двоичная запись преобразованного числа при сдвиге вправо:");
	for (int i = sizeof(num) * 8 - 1; i >= 0; i--) {
		if ((num >> i) & m) printf("1");
		else printf("0");
	}
	m = 1;
	nad1 = num1 >> (sizeof(num1) * 8 - sdv);
	num1 <<= sdv;
	num1 |= nad1;
	printf("\nДесятичная запись преобразованного числа при сдвиге ввлево: %u \n", num1);
	printf("Двоичная запись преобразованного числа при сдвиге вправо:");
	for (int k = sizeof(num1) * 8 - 1; k >= 0; k--) {
		if ((num1 >> k) & m) printf("1");
		else printf("0");
	}
	return (0);
}
