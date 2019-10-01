#include <iostream>
#include <cstdlib>
#include <chrono>
using namespace std;

void print_array(int amount_of_elements, int *arr)
//Процедура для вывода массива arr (int) длины amount_of_elements в консоль, 10 элементов на одной строке
//Если значение элемента массива меньше 10 (у числа только 1 разряд), перед ним в консоль печатается дополнительный пробел.
//После выполнения процедуры курсор переводится на две строки вниз.
{
	int counter = 0;
	for (counter; counter < amount_of_elements; counter++)
	{
		if ((counter + 1) % 10 == 0 and counter != 0)
		{
			if (arr[counter] >= 10)
				cout << arr[counter] << "\n";
			else
				cout << " " << arr[counter] << "\n";
		}
		else
		{
			if (arr[counter] >= 10)
				cout << arr[counter] << " ";
			else
				cout << " " << arr[counter] << " ";
		}
	}
	cout << "\n";
	if (amount_of_elements % 10 != 0)
	{
		cout << "\n";
	}
}

void randomize_array(int amount_of_elements, int *arr)
//Процедура заполняет массив arr длины amount_of_elements случайными значениями [srand(time(NULL))] в диапазоне от 0 до 99 (int).
{
	srand(time(NULL));
	int counter = 0;
	for (counter; counter < amount_of_elements; counter++)
	{
		arr[counter] = rand() % 100;
	}
}

int main()
{
	char end = 'y';
	while (end == 'y')
	{
		const int N = 100; //Размер массива (Натуральные числа, "0" не включен).
		int random_array[N];
		
		//Счетчики для циклов for.
		int i = 0;
		int j = 0;
		
		randomize_array(N, random_array);
		cout << "random_array before sorting:\n\n";
		print_array(N, random_array);


		////Bubble sort
		int counter = N - 1;
		int exchange;
		do
		{
			j = 0; //Отвечает за досрочный выход из цикла при завершении сортировки
			for (i; i < counter; i++)
			{
				if (random_array[i] > random_array[i + 1])
				{
					exchange = random_array[i];
					random_array[i] = random_array[i + 1];
					random_array[i + 1] = exchange;
					j += 1;
				}
			}
			counter -= 1;
			i = 0;
		} while (j != 0);
		
		//Распечатываем отсортированный массив
		cout << "Bubble sort:\n\n";
		print_array(N, random_array);


		randomize_array(N, random_array);
		cout << "random_array before sorting:\n\n";
		print_array(N, random_array);


		//Shaker sort
		//Дополнительный счетчик
		int gcounter = 0;
		//Сбрасываем старый счетчик
		counter = N - 1;
		do
		{
			j = 0; //Отвечает за досрочный выход из цикла при завершении сортировки
			for (i; i < counter; i++)
			{
				if (random_array[i] > random_array[i + 1])
				{
					exchange = random_array[i];
					random_array[i] = random_array[i + 1];
					random_array[i + 1] = exchange;
					j += 1;
				}
			}
			i = gcounter; //После прохода направо самый левый элемент (из еще не отсортированых) остается в процессе сортировки
			gcounter += 1; //Отвечает за сужение границ сортировки
			counter = N - 1 - gcounter; //После прохода направо самый правый элемент (из еще не отсортированых) уже отсортирован
			for (counter; i < counter; counter--)
			{
				if (random_array[counter] < random_array[counter - 1])
				{
					exchange = random_array[counter];
					random_array[counter] = random_array[counter - 1];
					random_array[counter - 1] = exchange;
					j += 1;
				}
			}
			i = gcounter; //После прохода налево самый левый элемент (из еще не отсортированых) уже отсортирован
			counter = N - 1 - gcounter; //После прохода налево самый правый элемент (из еще не отсортированых) остается в процессе сортировки
		} while (j != 0);
		//Сбрасываем переменную i.
		i = 0;
		//Распечатываем отсортированный массив
		cout << "Shaker sort:\n\n";
		print_array(N, random_array);

		//Проверка на повторный запуск программы
		cout << "Run this program again now? (y/n)(one lowercase letter and 'Enter')\n\n";
		cin >> end;
	}
	return 0;
}