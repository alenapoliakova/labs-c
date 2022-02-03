// 10 - рекурсивные функции
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void sort(int a[], int l, int r) { //функция сортировки слиянием массива, где а-исходный массив, l-левая граница рассматриваемой части матрицы, r - правая граница рассматриваемой части матрицы (включительно) 
    int i, j, p; //вспомогательные переменные
    if (r - l < 4) { //если рассматриваемая последовательности имеет меньше 5 элементов, после выполнения этого блока рекурсивность прекращается
        for (i = l + 1; i < r + 1; i++) { //сортировка вставками, где рассматривается каждый i элемент
            j = i - 1;
            while ((j >= l) && (a[i] < a[j])) { //поиск места для рассматриваемого элемента на промежутке [0; i-1]
                j--;
            }
            int t = a[i];
            p = j + 1; //позиция, где должен стоять рассматриваемый элемент
            for (j = i; j >= p + 1; j--) { //сдвиг всех элементов на промежутке [p; i-1] на одну позицию вправо
                a[j] = a[j - 1];
            }
            a[p] = t; //вставка рассматриваемого элемента на необходимое место
        }
    }
    else {

        int m = (l + r) / 2; //центральный элемент рассматриваемой части массива
        sort(a, l, m); //сортировка правой половины рассматриваемой части массива
        sort(a, m + 1, r); //сортировка левой половины рассматриваемой части массива, переход к дальнейшему коду означает окончание сортировки обеих половин рассматриваемой части массива, далее их слияние
        int a1[100]; //вспомогательный массив
        i = l; //индекс для последовательной работы с правой половиной
        j = m + 1; //индекс для последовательной работы с левой половиной
        p = l; //индекс для заполнения вспомогателного массива
        while ((i <= m) && (j <= r)) { //пока не закончаться элемнты в правой или левой части выполняется последовательное заполнение вспомогательного массива
            if (a[i] <= a[j]) {
                a1[p] = a[i];
                p++;
                i++;
            }
            else {
                a1[p] = a[j];
                p++;
                j++;
            }
        }
        while (i <= m) { //если раньше закончились элементы в левой части, заполняем остаток вспомогательного массива оставшимися элементами из правой части
            a1[p] = a[i];
            p++;
            i++;
        }
        while (j <= r) { //если раньше закончились элементы в правой части, заполняем остаток вспомогательного массива оставшимися элементами из левой части
            a1[p] = a[j];
            p++;
            j++;
        }
        for (i = l; i <= r; i++) { //перезапись элементов рассматриваемой части массива в исходный массив
            a[i] = a1[i];
        }
    }

}
int main()
{
    srand(time(NULL));
    setlocale(LC_ALL, "Russian");
    cout << "Введите количество элементов последовательности: ";
    int num; //количество элементов
    int arr[100]; //массив
    cin >> num; //ввод количества элементов
    cout << "\nИсходная последовательность: ";
    for (int i = 0; i < num; i++) { //заполнение массива рандомными элементами 
        arr[i] = rand() % 100 + 1;
        cout << arr[i] << " "; //вывод очередного элемента на экран
    }
    cout << "\n\nОтсортировнная последовательность: ";
    sort(arr, 0, num - 1); //функция сортировки
    for (int i = 0; i < num; i++) { //вывод отсортированного массива
        cout << arr[i] << " ";
    }
}