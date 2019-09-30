#include <iostream>
#include <cstdlib>
#include <chrono>
using namespace std;

void print_array(int amount_of_elements, int counter, int counter10, int arr[])
//Процедура для вывода массива в консоль, 10 элементов на одной строке
//Если значение элемента массива меньше 10 (у числа только 1 разряд), перед ним в консоль печатается дополнительный пробел.
{
	for (counter; counter < amount_of_elements; counter++)
	{
		counter10 += 1;
		if (counter10 % 10 == 0)
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
}

int main()
{
	char end = 'y';
	while (end == 'y' )
	{
		//Размер массива (Натуральные числа, "0" не включен).
		const int N = 100;
		int random_array[N];
		//Счетчики для циклов for.
		int i = 0;
		int j = 0;
		//Цикл заполняет массив random_array случайными значениями в диапазоне от 0 до 99 (int).
		srand(time(NULL));
		for (i; i < N; i++) random_array[i] = rand() % 100;
		//Сбрасываем переменную i.
		i = 0;
		//Теперь вывод массива в консоль вынесен в отдельную функцию - print_array.
		cout << "\nrandom_array before sorting:\n\n";
		print_array(N, i, j, random_array);


		//Bubble sort
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
		cout << "\nBubble sort:\n\n";
		print_array(N, i, j, random_array);


		//Цикл повторно заполняет массив random_array случайными значениями в диапазоне от 0 до 99 (int).
		srand(time(NULL));
		for (i; i < N; i++) random_array[i] = rand() % 100;
		//Сбрасываем переменную i.
		i = 0;
		//Теперь вывод массива в консоль вынесен в отдельную функцию - print_array.
		cout << "\nrandom_array before sorting:\n\n";
		print_array(N, i, j, random_array);


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
		cout << "\nShaker sort:\n\n";
		print_array(N, i, j, random_array);

		//Проверка на повторный запуск программы
		cout << "\nRun this program again now? (y/n)(one lowercase letter and 'Enter')";
		cin >> end;
	}
	return 0;
}