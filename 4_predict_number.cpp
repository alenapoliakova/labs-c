#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
	bool flag_for_while = true;

	while (flag_for_while) {
		srand(time(NULL));
		char s;
		int x;
		int number;
		int number_of_attempts;
		bool flag = false;

		number = 0 + rand() % (100 - 0 + 1);
		cout << "Введите количество попыток: ";
		cin >> number_of_attempts;

		int count = 1;

		while (count <= number_of_attempts) {
			cout << "Введите число: ";
			cin >> x;
			if (x == number) {
				flag = true;
				cout << "Правильно!" << endl;
				cout << "Количество попыток: " << count << endl;
				break;
			}
			else if (x > number) {
				cout << "Введенное число больше по сравнению со сгенерированным числом  " << endl;
				count += 1;
			}
			else {
				cout << "Введенное число меньше по сравнению со сгенерированным числом  " << endl;
				count += 1;
			}
		}
		if (!flag)
			cout << "Сгенерированное число: " << number << endl;
    
		cout << "Продолжить игру Y/N?" << endl;
		cin >> s;
		if (s == 'Y' or s == 'y') flag_for_while = true;
		else flag_for_while = false;
	}
}
