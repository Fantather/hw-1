#include "hw.h"
#include "work_with_double_array.h"

int main()
{
    // TASK 1
	const int max_name_length = 100;				// Maximum size of the name
	char current_name[max_name_length];				// Array to store a single name

	int names_capacity = 5;							// Maximum size of the array with names
	char** names_arr = new char* [names_capacity];	// Array of pointers to store names

	int name_count = 0;								// Number of names to be entered

    
	cout << "Enter 5 names:\n";
	for (int i = name_count; i < names_capacity; i++) {
		// Check if the array is full and resize it if necessary
		if (name_count >= names_capacity) {
			resize_pointer_array_double(names_arr, names_capacity);
		}

		cin.getline(current_name, max_name_length);
		add_name(names_arr, current_name, name_count);
	}

	// Sort the array
	cout << "\nArray after sort:\n";
	sort_arr(names_arr, names_capacity);
	for (int i = 0; i < name_count; i++) {
		print_arr(names_arr[i]);
		cout << endl;
	}

	delete_arr(names_arr, names_capacity);


	//TASK 2
	int rowsA, colsA;
	int rowsB, colsB;
	int rowsC, colsC;

	// Random number range
	int START = -10;
	int END = 10;

	cout << "\n\nTask 2\n";
	cout << "Enter rows and columns for matrix A: ";
	cin >> rowsA >> colsA;

	cout << "Enter rows and columns for matrix B: ";
	cin >> rowsB >> colsB;

	cout << "Enter rows and columns for matrix C: ";
	cin >> rowsC >> colsC;

	// Size of arrays
	int size_common_all = colsA;
	int size_unique_all = colsA;
	int size_common_AC = colsA;
	int size_unique_negatives = colsA;

	// counter to track the number of elements in the arrays
	int counter_common_all = 0;
	int counter_unique_all = 0;
	int counter_common_AC = 0;
	int counter_unique_negatives = 0;

	// Initialize arrays
	int* common_all = new int[size_common_all];
	int* unique_all = new int[size_unique_all];
	int* common_AC = new int[size_common_AC];
	int* unique_negatives = new int[size_unique_negatives];

	// Initialize 2D arrays
	int** A = init_2d_arr<int>(rowsA, colsA);
	int** B = init_2d_arr<int>(rowsB, colsB);
	int** C = init_2d_arr<int>(rowsC, colsC);

	// Fill arrays with random values
	fill_rand(A, rowsA, colsA, START, END);
	fill_rand(B, rowsB, colsB, START, END);
	fill_rand(C, rowsC, colsC, START, END);
	
	// Print arrays
	cout << "\nArray A:\n";
	print_arr(A, rowsA, colsA);

	cout << "\nArray B:\n";
	print_arr(B, rowsB, colsB);

	cout << "\nArray C:\n";
	print_arr(C, rowsC, colsC);

	// Print results
	cout << "\nList with commons: ";
	fill_common_all(A, B, C, common_all, counter_common_all, size_common_all, rowsA, colsA, rowsB, colsB, rowsC, colsC);
	print_arr(common_all, counter_common_all);

	cout << "\nList with uniques: ";
	fill_unique_all(A, B, C, unique_all, counter_unique_all, size_unique_all, rowsA, colsA, rowsB, colsB, rowsC, colsC);
	print_arr(unique_all, counter_unique_all);

	cout << "\nList with commons A and C: ";
	fill_common_AC(A, C, common_AC, counter_common_AC, size_common_AC, rowsA, colsA, rowsC, colsC);
	print_arr(common_AC, counter_common_AC);

	cout << "\nList with uniques negatives: ";
	fill_unique_negatives(A, B, C, unique_negatives, counter_unique_negatives, size_unique_negatives, rowsA, colsA, rowsB, colsB, rowsC, colsC);
	print_arr(unique_negatives, counter_unique_negatives);

	cout << endl;

	// Delete arrays
	delete_arr(A, rowsA);
	delete_arr(B, rowsB);
	delete_arr(C, rowsC);

	delete[] common_all;
	delete[] unique_all;
	delete[] common_AC;
	delete[] unique_negatives;
}

//Задание 1
//Написать программу, которая дает пользователю ввести 5 фамилий студентов, а затем сортирует их по возрастанию.
//
//Задание 2
//Есть 3 двумерных массива A, B, C. Количество строк и столбцов для них вводит пользователь с клавиатуры для каждого из них.Реализуйте
//
//Создайте одномерный массив, который содержит общие значения для A, B, C;
//Создайте одномерный массив, который содержит уникальные значения для A, B, C;
//Создайте одномерный массив, который содержит общие значения для A и C;
//Создайте одномерный массив, который содержит отрицательные значения для A, B, C без повторений.