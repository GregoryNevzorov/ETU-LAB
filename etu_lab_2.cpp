#include <iostream>
#include <cstdlib>
#include <chrono>
using namespace std;

void print_array(short int amount_of_elements, short int *arr)
//Процедура для вывода массива arr длины amount_of_elements в консоль, 10 элементов на строку.
//Если количество элементов в массиве больше 200, печатает по 20 элементов в строке.
//Если количество элементов в массиве больше 600, печатает по 40 элементов в строке.
//Если значение элемента массива меньше 10 (у числа только 1 разряд), перед ним в консоль печатается дополнительный пробел.
//После выполнения процедуры курсор переводится на две строки вниз.
{
	short int counter = 0;
	if (amount_of_elements <= 200)
	{
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
		if (amount_of_elements % 10 != 0)
		{
			cout << "\n";
		}
	}
	else if (amount_of_elements <= 600)
	{
		for (counter; counter < amount_of_elements; counter++)
		{
			if ((counter + 1) % 20 == 0 and counter != 0)
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
		if (amount_of_elements % 20 != 0)
		{
			cout << "\n";
		}
	}
	else
	{
		for (counter; counter < amount_of_elements; counter++)
		{
			if ((counter + 1) % 40 == 0 and counter != 0)
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
		if (amount_of_elements % 40 != 0)
		{
			cout << "\n";
		}
	}
	cout << "\n";
}

void randomize_array(short int amount_of_elements, short int *arr)
//Процедура заполняет массив arr длины amount_of_elements случайными значениями [srand(time(NULL))] в диапазоне от 0 до 99 (int).
{
	srand(time(NULL));
	short int counter = 0;
	for (counter; counter < amount_of_elements; counter++)
	{
		arr[counter] = rand() % 100;
	}
}

float bubble_sort(short int amount_of_elements, short int *arr)
{
	short int exchange;
	short int i = 0; //Переменная-счетчик для цикла for.
	short int early_exit; //Отвечает за досрочный выход из цикла при завершении сортировки.
	unsigned int start_time = clock();
	do
	{
		early_exit = 0;

		for (i; i < amount_of_elements - 1; i++)
		{
			if (arr[i] > arr[i + 1])
			{
				exchange = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = exchange;
				early_exit += 1;
			}
		}
		amount_of_elements -= 1;
		i = 0;
	}
	while (early_exit != 0);
	unsigned int end_time = clock();
	return float(end_time - start_time) / 1000;
}

float shaker_sort(short int amount_of_elements, short int *arr)
{
	short int left_border = 0;
	short int right_border = 0;
	short int exchange;
	long int early_exit; //Отвечает за досрочный выход из цикла при завершении сортировки.
	short int i; //Переменная-счетчик для цикла for.
	unsigned int start_time = clock();
	do
	{
		early_exit = 0;
		i = left_border;
		for (i; i < amount_of_elements - right_border - 1; i++)
		{
			if (arr[i] > arr[i + 1])
			{
				exchange = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = exchange;
				early_exit += 1;
			}
		}
		right_border += 1;
		i = amount_of_elements - right_border - 1; //Т.к. в массивах индексы нумеруются с нуля.
		for (i; i > left_border - 1; i--)
		{
			if (arr[i] < arr[i - 1])
			{
				exchange = arr[i];
				arr[i] = arr[i - 1];
				arr[i - 1] = exchange;
				early_exit += 1;
			}
		}
		left_border += 1;
	} while (early_exit != 0);
	unsigned int end_time = clock();
	return float(end_time - start_time) / 1000;
}

float comb_sort_simple(short int amount_of_elements, short int* arr)
{
	short int i = 0;
	short int counter = 0;
	short int exchange;
	unsigned int start_time = clock();
	while (counter != amount_of_elements - 1)
	{
		for (i; i <= counter; i++)
		{
			if (arr[i] > arr[amount_of_elements - 1 - counter + i])
			{
				exchange = arr[i];
				arr[i] = arr[amount_of_elements - 1 - counter + i];
				arr[amount_of_elements - 1 - counter + i] = exchange;
			}
		}
		i = 0;
		counter += 1;
	}
	unsigned int end_time = clock();
	return float(end_time - start_time) / 1000;
}

float comb_sort_golden_ratio(short int amount_of_elements, short int* arr)
{
	const float reduction_factor = 1.2473309F; // 1 / (1 - e ^ (-ф)) -- где "e" - основание натурального логарифма, а ф - золотое сечение.
	long int step = amount_of_elements - 1;
	short int i;
	short int exchange;
	short int early_exit;
	unsigned int start_time = clock();
	do
	{
		early_exit = 0;
		for (i = 0; i < amount_of_elements - step; i++)
		{
			if (arr[i] > arr[i +step])
			{
				exchange = arr[i];
				arr[i] = arr[i + step];
				arr[i + step] = exchange;
				early_exit += 1;
			}
		}
		step /= reduction_factor;
	}
	while (early_exit != 0 or step >= 1);
	unsigned int end_time = clock();
	return float(end_time - start_time) / 1000;
}

float insert_sort(short int amount_of_elements, short int* arr)
{
	short int buffer;
	short int i;
	unsigned int start_time = clock();
	for (short int subarray_size = 1; subarray_size < amount_of_elements ; subarray_size++)
	{
		buffer = arr[subarray_size];
		i = subarray_size;
		while (i != 0 and buffer < arr[i - 1])
		{
			arr[i] = arr[i - 1];
			i -= 1;
		}
		arr[i] = buffer;
	}
	unsigned int end_time = clock();
	return float(end_time - start_time) / 1000;
}

void quick_sort(short int* arr, short int low, short int high)
{                        //main()  -->  // 0 // amount_of_elements
	if (high - low < 2) return;
	short int exchange;
	short int left_index = low;
	short int right_index = high - 1;
	short int supporting_element_index = high - 1; //Опорный элемент - самый правый элемент.
	while (true)
	{
		for (left_index; left_index < high; left_index++)
		{
			if (arr[left_index] > arr[supporting_element_index])
			{
				break;
			}
		}
		if (left_index == high) left_index -= 1;
		for (right_index; low - 1 < right_index; right_index--)
		{
			if (arr[right_index] < arr[supporting_element_index])
			{
				break;
			}
		}
		if (right_index == low - 1) right_index += 1;
		if (left_index >= right_index)
		{
			exchange = arr[supporting_element_index];
			arr[supporting_element_index] = arr[left_index];
			arr[left_index] = exchange;
			supporting_element_index = left_index;
			break;
		}
		else
		{
			exchange = arr[left_index];
			arr[left_index] = arr[right_index];
			arr[right_index] = exchange;
		}
	}
	quick_sort(arr, low, supporting_element_index);
	quick_sort(arr, supporting_element_index + 1, high);
}

void number_of_averages(short int amount_of_elements, short int *arr) //between the minimum and maximum values ​​in the array.
//Требует на вход уже отсортированый в порядке возрастания массив!
{
	unsigned int start_time = clock();
	short int averages = (arr[0] + arr [amount_of_elements - 1]) / 2;
	short int counter = 0;
	short int for_return = 0;
	for (counter; counter < amount_of_elements; counter++)
	{
		if (arr[counter] > averages)
		{
			break;
		}
		else
		{
			if (arr[counter] == averages)
			{
				for_return += 1;
			}
		}
	}
	unsigned int end_time = clock();
	cout << float(end_time - start_time) / 1000 << " sec.\n";
	cout << "Averages = " << averages << "\n\n";
	cout << "Number of averages between the minimum and maximum values in the array = " << for_return << "\n\n";
}

void less_than_a(short int amount_of_elements, short int* arr)
//Требует на вход уже отсортированый в порядке возрастания массив!
{
	short int counter = amount_of_elements - 1;
	short int a;
	cout << "Enter the number 'a'(from -32767 before 32767 and only integer!)\n";
	cout << "The number of elements less than 'a' will be displayed\n";
	cin >> a;
	for (counter; 0 <= counter; counter--)
	{
		if (arr[counter] < a)
		{
			cout << "Answer: " << counter + 1 << "\n\n";
			return;
		}
	}
	cout << "There are no such elements in the array!\n\n";
}

void more_than_b(short int amount_of_elements, short int* arr)
//Требует на вход уже отсортированый в порядке возрастания массив!
{
	short int counter = 0;
	short int b;
	cout << "Enter the number 'b'(from -32767 before 32767 and only integer!)\n";
	cout << "The number of elements more than 'b' will be displayed\n";
	cin >> b;
	for (counter; counter < amount_of_elements; counter++)
	{
		if (arr[counter] > b)
		{
			cout << "Answer: " << amount_of_elements - counter << "\n\n";
			return;
		}
	}
	cout << "There are no such elements in the array!\n\n";
}

void task_2variant(short int amount_of_elements, short int* arr)
{
	short int i;
	short int sub; //Пользовательская величина
	short int even_value = 0; //Количество четных элементов с четными значениями
	short int odd_value = 0; //Количество нечетных элементов с нечетными значениями
	srand(time(NULL));
	short int random_value = rand() % 10;
	cout << "Enter the value by which you want to reduce all even elements. (Only integer numbers, 0 <= x < 3600)\n";
	// 3600 * 9(Максимально возможное случайное значение) = 32400. Это практически максимум short int.
	cin >> sub;
	cout << "\n";
	for (i = 0; i < amount_of_elements; i += 2)
	{
		arr[i] -= sub;
		arr[i] *= random_value;
		if (arr[i] % 2 == 0) even_value += 1;
	}
	for (i = 1; i < amount_of_elements; i += 2)
	{
		if (arr[i] % 2 == 1) odd_value += 1;
	}
	//print_array(amount_of_elements, arr); -- Неточное форматирование!
	cout << "Random value = " << random_value << "\n";
	cout << "Even value = " << even_value << "\n";
	cout << "Odd value = " << odd_value << "\n\n";
}

int main()
{
	char end = 'y';
	while (end == 'y')
	{
		const short int N = 5000; //Размер массива (Натуральные числа до 32767 включая, "0" не включен).
		short int *random_array = new short int[N]; //Массив помещается в "кучу", для стабильной работы стека.
		
		//Заполняем массив random_array случайными элементами и выводим его в консоль.
		randomize_array(N, random_array);
		cout << "random_array before sorting:\n\n";
		print_array(N, random_array);


		//Bubble sort
		float time1 = bubble_sort(N, random_array);
		//Распечатываем отсортированный массив.
		cout << "Bubble sort:\n\n";
		print_array(N, random_array);

		//Заполняем массив random_array случайными элементами и выводим его в консоль.
		randomize_array(N, random_array);
		cout << "random_array before sorting:\n\n";
		print_array(N, random_array);


		//Shaker sort
		float time2 = shaker_sort(N, random_array);
		//Распечатываем отсортированный массив.
		cout << "Shaker sort:\n\n";
		print_array(N, random_array);

		//Заполняем массив random_array случайными элементами и выводим его в консоль.
		randomize_array(N, random_array);
		cout << "random_array before sorting:\n\n";
		print_array(N, random_array);

		//Comb sort simple
		float time3 = comb_sort_simple(N, random_array);
		//Распечатываем отсортированный массив.
		cout << "Comb sort simple:\n\n";
		print_array(N, random_array);

		//Заполняем массив random_array случайными элементами и выводим его в консоль.
		randomize_array(N, random_array);
		cout << "random_array before sorting:\n\n";
		print_array(N, random_array);

		//Comb sort golden ratio
		float time4 = comb_sort_golden_ratio(N, random_array);
		//Распечатываем отсортированный массив.
		cout << "Comb sort golden ratio:\n\n";
		print_array(N, random_array);

		//Заполняем массив random_array случайными элементами и выводим его в консоль.
		randomize_array(N, random_array);
		cout << "random_array before sorting:\n\n";
		print_array(N, random_array);

		//Insert sort
		float time5 = insert_sort(N, random_array);
		//Распечатываем отсортированный массив.
		cout << "Insertion sort:\n\n";
		print_array(N, random_array);

		//Заполняем массив random_array случайными элементами и выводим его в консоль.
		randomize_array(N, random_array);
		cout << "random_array before sorting:\n\n";
		print_array(N, random_array);

		//Quick sort
		//Из-за рекурсии время удобнее считать вне процедуры.
		unsigned int start_time = clock();
		quick_sort(random_array, 0, N);
		unsigned int end_time = clock();
		float time6 = float(end_time - start_time) / 1000;
		//Распечатываем отсортированный массив.
		cout << "Quick sort:\n\n";
		print_array(N, random_array);

		//Время сортировки
		cout << "Sorting time:\n";
		cout << "Bubble sort - " << time1 << "sec.\n";
		cout << "Shaker sort - " << time2 << "sec.\n";
		cout << "Comb sort simple - " << time3 << "sec.\n";
		cout << "Comb sort golden ratio - " << time4 << "sec.\n";
		cout << "Insertion sort - " << time5 << "sec.\n";
		cout << "Quick sort - " << time6 << "sec.\n\n";

		//Вывод в консоль мин. и макс. элемента из сортированого random_array.
		cout << "Minimum = " << random_array[0] << "\n";
		cout << "Maximum = " << random_array[N - 1] << "\n\n";

		//Выводит количество элементов, равных среднему значения max и min.
		number_of_averages(N, random_array);
		//Т.к. в контексте данной задачи поиск занимает меньше одной тысячной секунды, реализовывать бинарную версию поиска не имеет смысла.

		//Выводит количество элементов в массиве, меньше "a"
		less_than_a(N, random_array);
		//Выводит количество элементов в массиве, больше "b"
		more_than_b(N, random_array);

		//Задание по вариантам.
		task_2variant(N, random_array);

		//Проверка на повторный запуск программы
		cout << "Run this program again now? (y/n)(one lowercase letter and 'Enter')\n\n";
		cin >> end;
	}
	return 0;
}