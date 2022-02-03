#include <iostream>
using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
	int d, m = 1, g, y, x;
	bool flag = true;
	int number_week;
	int months[] = {31,28,31,30,31,30,31,31,30,31,30,31};

	while (flag) {
		cout << "Введите число: ";
		cin >> d;
		cout << "Введите месяц: ";
		cin >> m;
		cout << "Введите год: ";
		cin >> g;
		if (g % 4 == 0 && g % 100 != 0 || g % 400 == 0)months[1] = 29;
		else months[1] = 28;
		if (!(1582 <= g && g <= 4902 && m <= 12 && m >= 1 && d <= months[m - 1] && d >= 1)) {
			cout << "Введены некорректные данные: ";
			if (!(1582 <= g && g <= 4902)) cout << "число: " << g << ' ';
			if (m <= 12 && m >= 1) cout << "месяц: " << m << ' ';
			if (d <= months[m - 1] && d >= 1) cout << "год: ";
			cout << endl;
			cout << "------------------" << endl;
			cout << "Введите данные еще раз!" << endl;
		}
		else flag = false;
	}

	if (m <= 2) {
		m += 10;
		g--;
	}
	else m -= 2;
	y = g % 100;
	x = g / 100;

	number_week = (int)(2.6 * m - 0.2) + d + y + y / 4 + x / 4 - 2 * x;
	number_week %= 7;
	if (number_week < 0) number_week += 7;

	cout << "День недели: ";

	switch (number_week) {
	case(0):
		cout << "Воскресенье" << endl;
		break;
	case(1):
		cout << "Понедельник" << endl;
		break;
	case(2):
		cout << "Вторник" << endl;
		break;
	case(3):
		cout << "Среда" << endl;
		break;
	case(4):
		cout << "Четверг" << endl;
		break;
	case(5):
		cout << "Пятница" << endl;
		break;
	case(6):
		cout << "Суббота" << endl;
		break;
	default:
		cout << "Ошибка" << endl;
		break;
	}
	return 0;
}
