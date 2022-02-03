#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	int text = 0;
	int proposal = 0; // предложение 
	int words = 0;
	int state = 0;
	proposal = words = 0;

	int word_number, symbol, i, j;
	int max, maxx;

	int number_оf_сharacters[100]{}; // количество симвовлов
	int composition_of_the_offer[100]{}; // состав предложения 
	cout << "Введите текст и по окончании ввода нажмите CTRL/Z" << endl;
	cout << "-----------------------------------------------------------------------------------" << endl;
	while ((text = getchar()) != EOF)
	{
		if ((text == ' ') or (text == '\n') or (text == '\t') or (text == ',') or (text == '-'))
			state = 0;
		else if ((text == '.') or (text == '!') or (text == '?')) {
			state = 0;
			proposal++;
		}
		else if (state == 0)
		{
			state = 1;
			words++;
			composition_of_the_offer[proposal + 1]++;
		}
		if (state == 1)
			number_оf_сharacters[words]++;
	}
	cout << endl;
	cout << "-----------------------------------------------------------------------------------" << endl;
	cout << "количество слов в тексте" << " " << words << endl;
	cout << "-----------------------------------------------------------------------------------" << endl;
	cout << "Гистограмма текста: " << endl;
	for (word_number = 1; word_number <= words; word_number++) {
		cout << endl;
		for (symbol = 1; symbol <= number_оf_сharacters[word_number]; symbol++)
			cout << "*";
	}
	cout << endl;
	cout << "-----------------------------------------------------------------------------------" << endl;
	cout << "количество предложений в тексте " << proposal << endl;
	cout << "-----------------------------------------------------------------------------------" << endl;

	for (i = 1; i <= proposal; i++) {
		cout << "в " << i << " предложении - " << composition_of_the_offer[i] << " слов(-а);  ";
	}
	cout << endl << endl;

	cout << "Диаграмма текста : " << endl;

	max = composition_of_the_offer[0]; //состав предложения 
	for (i = 1; i <= proposal; i++)
		if (composition_of_the_offer[i] > max)
			max = composition_of_the_offer[i];
	maxx = max;
	for (i = 1; i <= maxx; i++) {
		for (j = 1; j <= proposal; j++) {
			if (composition_of_the_offer[j] >= max) {

				cout << "*";
			}
			else
				cout << " ";
		}
		cout << endl;
		max--;
	}

	return 0;
}
