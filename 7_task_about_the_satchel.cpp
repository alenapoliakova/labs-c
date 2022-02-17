#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include <math.h>
int main()
{
    setlocale(LC_ALL, "Russian");
    int kol, gruz, pol[50], ves[50];
    int max = 0, obpol, obves, kves, ke, m = 1; // obpol - общая полезность, obves - общий вес
    // kves - вес оптимума, max - значение оптимума, ke - конечное k
    double comb;

    printf("Сколько предметов находится в ранце и какова грузоподъемность? :\n");
    scanf_s("%d %d", &kol, &gruz);

    printf("\n---------------------------------------------------------------\n");

    for (int i = 0; i <= kol - 1; i++) {
        printf("Введите полезность и вес %d-го предмета :\n", i + 1);
        scanf_s("%d %d", &pol[i], &ves[i]);
    }

    printf("\n---------------------------------------------------------------\n");

    comb = pow(2, kol);

    printf("Вместимость :%d \n", gruz);
    for (int k = 0; k <= comb; k++) {
        obpol = 0;
        obves = 0;
        for (int j = 0; j <= kol; j += 1) {
            if ((k >> j) % 2 == 1) {
                obpol += pol[j];
                obves += ves[j];
            }
        }
        if ((obves <= gruz) && (max < obpol)) {
            max = obpol;
            ke = k;
            kves = obves;
        }
    }
    printf("Значение оптимума:%d ;Вес оптимума:%d\n", max, kves);
    printf("Решение задачи:");
    for (int i = (kol - 1); i >= 0; i--) {
        if ((ke >> i) & m) printf("1");
        else printf("0");
    }
    return (0);
}
