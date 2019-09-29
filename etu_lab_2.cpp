#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
	const int N = 50; // Размер массива (Натуральные числа, "0" не включен)
	int random_array[N];
	int j = 0;
	//Цикл заполняет массив random_array случайными значениями в диапазоне от 0 до 99 (int), затем выводит все элементы массива в консоль, по 10 на строку.
	//Если значение элемента массива меньше 10 (только 1 разряд), перед ним в консоль печатается дополнительный пробел.
	for (int i = 0; i < N; i++)
	{
		random_array[i] = rand() % 100;
		j += 1;
		if (j % 10 == 0)
		{
			if (random_array[i] >= 10)
				cout << random_array[i] << "\n";
			else
				cout << " " << random_array[i] << "\n";
		}
		else
		{
			if (random_array[i] >= 10)
				cout << random_array[i] << " ";
			else
				cout << " " << random_array[i] << " ";
		}
	}
	return 0;
}