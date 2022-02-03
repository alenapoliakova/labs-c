#include <stdio.h>
#include <conio.h>
#include <iostream>

using namespace std;

int main()
{
    int n, m;
    cout << "Print matrix size: ";
    cin >> n;
    cout << "Print matrix: ";

    int** arr = new int* [n];

    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[n];
    }


    cout << "Print matrix: \n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }
    cout << "--------------------------\n";

    //Симметричность относительно вертикали
    bool res = true;
    for (int i = 0; i < n / 2; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i][j] != arr[i][n - j - 1])
            {
                res = false; break;
            }
        }
    }
    cout << "Symmetry with respect to the vertical: ";
    if (res) cout << "+";
    else cout << "-";

    //Симметричность относительной горизонтали
    res = true;
    for (int i = 0; i < n / 2; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[j][i] != arr[n - j - 1][i]) { res = false; break; }
        }
    }
    cout << "\nsymmetry with respect to the horizontal: ";
    if (res) cout << "+";
    else cout << "-";


    //Симметричность относительно центра
    res = true;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i][j] != arr[n - i - 1][n - j - 1]) { res = false; break; }
        }
    }
    cout << "\nsymmetry with respect to the center: ";
    if (res) cout << "+";
    else cout << "-";
    cout << "\n------------------------------\n";
    for (int i = 0; i < n; i++)
    {
        delete[]arr[i];
    }
    delete[]arr;
}
