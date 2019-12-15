#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <chrono>
#include <fstream>

using namespace std;

short int menuInput()
{
	system("cls");

	short int numberOfSelectedOption = 1;
	short int* pressedButtonCode = new short int;
	while (true)
	{
		if (numberOfSelectedOption == 1)
		{
			HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(handle, FOREGROUND_GREEN);
			cout << "1. Random integer from 0 to 99\n";
			SetConsoleTextAttribute(handle, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		}
		else
		{
			cout << "1. Random integer from 0 to 99\n";
		}
		if (numberOfSelectedOption == 2)
		{
			HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(handle, FOREGROUND_GREEN);
			cout << "2. Input from TXT file\n";
			SetConsoleTextAttribute(handle, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		}
		else
		{
			cout << "2. Input from TXT file\n";
		}
		if (numberOfSelectedOption == 3)
		{
			HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(handle, FOREGROUND_GREEN);
			cout << "3. Manual input\n";
			SetConsoleTextAttribute(handle, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		}
		else
		{
			cout << "3. Manual input\n";
		}

		*pressedButtonCode = _getch();
		system("cls");
		switch (*pressedButtonCode)
		{
		case 72: // 'Стрелка вверх'


		case 87: // 'W'


		case 119: // 'w'


		case 150: // 'Ц'


		case 230:  // 'ц'
			numberOfSelectedOption -= 1;
			if (numberOfSelectedOption < 1)
			{
				numberOfSelectedOption = 3;
			}
			break;

		case 80: // 'Стрелка вниз'


		case 83: // 'S'


		case 115: // 's'


		case 155: // 'Ы'


		case 235: // 'ы'
			numberOfSelectedOption += 1;
			if (numberOfSelectedOption > 3)
			{
				numberOfSelectedOption = 1;
			}
			break;

		case 13: // 'Enter'
			delete pressedButtonCode;
			return numberOfSelectedOption;
			break;

		default:
			break;
		}
	}
}

short int menuSort()
{
	system("cls");

	short int numberOfSelectedOption = 1;
	short int* pressedButtonCode = new short int;
	while (true)
	{
		if (numberOfSelectedOption == 1)
		{
			HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(handle, FOREGROUND_GREEN);
			cout << "1. Bubble sort\n";
			SetConsoleTextAttribute(handle, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		}
		else
		{
			cout << "1. Bubble sort\n";
		}
		if (numberOfSelectedOption == 2)
		{
			HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(handle, FOREGROUND_GREEN);
			cout << "2. Shaker sort\n";
			SetConsoleTextAttribute(handle, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		}
		else
		{
			cout << "2. Shaker sort\n";
		}
		if (numberOfSelectedOption == 3)
		{
			HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(handle, FOREGROUND_GREEN);
			cout << "3. Comb sort simple\n";
			SetConsoleTextAttribute(handle, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		}
		else
		{
			cout << "3. Comb sort simple\n";
		}
		if (numberOfSelectedOption == 4)
		{
			HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(handle, FOREGROUND_GREEN);
			cout << "4. Comb sort\n";
			SetConsoleTextAttribute(handle, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		}
		else
		{
			cout << "4. Comb sort\n";
		}
		if (numberOfSelectedOption == 5)
		{
			HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(handle, FOREGROUND_GREEN);
			cout << "5. Insert sort\n";
			SetConsoleTextAttribute(handle, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		}
		else
		{
			cout << "5. Insert sort\n";
		}
		if (numberOfSelectedOption == 6)
		{
			HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(handle, FOREGROUND_GREEN);
			cout << "6. Quick sort\n";
			SetConsoleTextAttribute(handle, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		}
		else
		{
			cout << "6. Quick sort\n";
		}
		if (numberOfSelectedOption == 7)
		{
			HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(handle, FOREGROUND_GREEN);
			cout << "7. All sort\n";
			SetConsoleTextAttribute(handle, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		}
		else
		{
			cout << "7. All sort\n";
		}

		*pressedButtonCode = _getch();
		system("cls");
		switch (*pressedButtonCode)
		{
		case 72: // 'Стрелка вверх'


		case 87: // 'W'


		case 119: // 'w'


		case 150: // 'Ц'


		case 230:  // 'ц'
			numberOfSelectedOption -= 1;
			if (numberOfSelectedOption < 1)
			{
				numberOfSelectedOption = 7;
			}
			break;

		case 80: // 'Стрелка вниз'


		case 83: // 'S'


		case 115: // 's'


		case 155: // 'Ы'


		case 235: // 'ы'
			numberOfSelectedOption += 1;
			if (numberOfSelectedOption > 7)
			{
				numberOfSelectedOption = 1;
			}
			break;

		case 13: // 'Enter'
			delete pressedButtonCode;
			return numberOfSelectedOption;
			break;

		default:
			break;
		}
	}
}

void amountElementsManualInput(long int* amountElements)
{
	system("cls");
	while (true)
	{
		cout << "Enter amount of elements (long integer, not zero and negative numbers): ";
		cin >> *amountElements;
		if (*amountElements > 1)
		{
			cout << "An array of this size can lead to malfunctions of the program, continuing to work, you take responsibility for the consequences.";
			cout << "Press Enter to continue or close the program.";
			system("pause");
		}
	}
	cout << "\n";
}

void amountElementsTXTInput(long int* amountElements)
//data.txt
{
	system("cls");
	ifstream data("data.txt");
	data >> *amountElements;
	data.close();
}

void arrayRandomFilling(long int* array, long int amountElements)
//Процедура заполняет массив случайными значениями в диапазоне от 0 до 99 (int).
{
	srand(time(NULL));
	for (long int i = 0; i < amountElements; i++)
	{
		array[i] = rand() % 100;
	}
}

void arrayManualFilling(long int* array, long int amountElements)
{
	for (long int i = 0; i < amountElements; i++)
	{
		cout << (i + 1) << ". ";
		cin >> array[i];
	}
	cout << "\n";
}

void arrayTXTFilling(long int* array, long int amountElements)
{
	ifstream data("data.txt");
	long int bufferLongInteger;
	data >> bufferLongInteger; //amountElements not needed
	for (long int i = 0; i < amountElements; i++)
	{
		data >> bufferLongInteger;
		array[i] = bufferLongInteger;
	}
	data.close();
}

void arrayConsolePrint(long int* array, long int amountElements, short int quantityDigitsLargestNumber = 2)
{
	long int numberElementsPerLine = 10;
	if (amountElements > 100)
	{
		numberElementsPerLine = amountElements / 10;
		if (numberElementsPerLine > (40 / (quantityDigitsLargestNumber / 2)))
		{
			numberElementsPerLine = (40 / (quantityDigitsLargestNumber / 2));
		}
	}
	for (long int i = 0; i < amountElements; i++)
	{
		cout.width(quantityDigitsLargestNumber + 1);
		if ((i + 1) % numberElementsPerLine != 0)
		{
			cout << array[i];
		}
		else
		{
			cout << array[i] << "\n";
		}
	}
	if (amountElements % numberElementsPerLine != 0)
	{
		cout << "\n";
	}
	cout << "\n";
}

double bubble_sort(long int* arr, long int amount_of_elements)
{
	short int exchange;
	short int i = 0; //Переменная-счетчик для цикла for.
	short int early_exit; //Отвечает за досрочный выход из цикла при завершении сортировки.
	double start_time = clock();
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
	double end_time = clock();
	return ((end_time - start_time) / 1000);
}

double shaker_sort(long int* arr, long int amount_of_elements)
{
	short int left_border = 0;
	short int right_border = 0;
	short int exchange;
	long int early_exit; //Отвечает за досрочный выход из цикла при завершении сортировки.
	short int i; //Переменная-счетчик для цикла for.
	double start_time = clock();
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
	double end_time = clock();
	return ((end_time - start_time) / 1000);
}

double comb_sort_simple(long int* arr, long int amount_of_elements)
{
	short int i = 0;
	short int counter = 0;
	short int exchange;
	double start_time = clock();
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
	double end_time = clock();
	return ((end_time - start_time) / 1000);
}

double comb_sort_golden_ratio(long int* arr, long int amount_of_elements)
{
	const float reduction_factor = 1.2473309F; // 1 / (1 - e ^ (-ф)) -- где "e" - основание натурального логарифма, а ф - золотое сечение.
	long int step = amount_of_elements - 1;
	short int i;
	short int exchange;
	short int early_exit;
	double start_time = clock();
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
	double end_time = clock();
	return ((end_time - start_time) / 1000);
}

double insert_sort(long int* arr, long int amount_of_elements)
{
	short int buffer;
	short int i;
	double start_time = clock();
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
	double end_time = clock();
	return ((end_time - start_time) / 1000);
}

void quick_sort(long int* arr, short int low, short int high)
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

void number_of_averages(long int* arr, long int amount_of_elements) //between the minimum and maximum values ​​in the array.
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

void less_than_a(long int* arr, long int amount_of_elements)
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

void more_than_b(long int* arr, long int amount_of_elements)
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

void task_2variant(long int* arr, long int amount_of_elements)
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
	//arrayConsolePrint(amount_of_elements, arr);
	cout << "Random value = " << random_value << "\n";
	cout << "Even value = " << even_value << "\n";
	cout << "Odd value = " << odd_value << "\n\n";
}

int main()
{
	long int amountElements = -1;
	short int selectedFunctionNumber;
	while (true)
	{
		selectedFunctionNumber = menuInput();
		switch (selectedFunctionNumber)
		{
		case 1:
			amountElementsManualInput(&amountElements);
			break;

		case 2:
			amountElementsTXTInput(&amountElements);
			break;

		case 3:
			amountElementsManualInput(&amountElements);
			break;

		default:
			cout << "ERROR!\n";
			break;
		}

		long int* mainArray = new long int[amountElements];
		
		switch (selectedFunctionNumber)
		{
		case 1:
			arrayRandomFilling(mainArray, amountElements);
			break;

		case 2:
			arrayTXTFilling(mainArray, amountElements);
			break;

		case 3:
			arrayManualFilling(mainArray, amountElements);
			break;

		default:
			cout << "ERROR!\n";
			break;
		}

		arrayConsolePrint(mainArray, amountElements);
		system("pause");
		
		while (true)
		{
			selectedFunctionNumber = menuSort();
			switch (selectedFunctionNumber)
			{
			case 1:
				
				break;

			case 2:
				
				break;

			case 3:
				
				break;

			case 4:

				break;

			case 5:

				break;

			case 6:

				break;

			case 7:

				break;

			default:
				cout << "ERROR!\n";
				break;
			}

		}


		////Вывод в консоль мин. и макс. элемента из сортированого mainArray.
		//cout << "Minimum = " << mainArray[0] << "\n";
		//cout << "Maximum = " << mainArray[amountElements - 1] << "\n\n";

		////Выводит количество элементов, равных среднему значения max и min.
		//number_of_averages(amountElements, mainArray);
		////Т.к. в контексте данной задачи поиск занимает меньше одной тысячной секунды, реализовывать бинарную версию поиска не имеет смысла.

		////Выводит количество элементов в массиве, меньше "a"
		//less_than_a(amountElements, mainArray);
		////Выводит количество элементов в массиве, больше "b"
		//more_than_b(amountElements, mainArray);

		////Задание по вариантам.
		//task_2variant(amountElements, mainArray);

		delete[] mainArray;
	}
	return 0;
}