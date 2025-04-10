#include "hw.h"

// Вот бы сделать это виде Класса
void resize_pointer_array_double(char**& ptr_names_arr, int& arr_size)
{
	if (ptr_names_arr == nullptr || arr_size <= 0) {
		return;
	}

	char** new_arr = new char* [arr_size * 2];

	for (int i = 0; i < arr_size; i++) {
		new_arr[i] = ptr_names_arr[i];
	}

	delete[] ptr_names_arr;
	ptr_names_arr = new_arr;
	arr_size *= 2;
}

// Resize the array of integers
void resize_array_double(int*& arr, int& arr_size)
{
	if (arr == nullptr || arr_size <= 0) {
		return;
	}

	int* new_arr = new int[arr_size * 2];

	for (int i = 0; i < arr_size; i++) {
		new_arr[i] = arr[i];
	}

	delete[] arr;
	arr = new_arr;
	arr_size *= 2;
}

// Add a name to the array
void add_name(char** names_arr, const char* name, int& count_names)
{
	if (names_arr == nullptr || count_names <= -1) {
		return;
	}

	size_t len = strlen(name) + 1;

	names_arr[count_names] = new char[len];
	strcpy_s(names_arr[count_names], len, name);
	count_names++;
}

// Sort the array
void sort_arr(char** names_arr, const int size)
{
	for (int i = 0; i < size; i++) {
		for (int j = i + 1; j < size; j++) {
			if (strcmp(names_arr[i], names_arr[j]) > 0) {
				char* temp = names_arr[j];
				names_arr[j] = names_arr[i];
				names_arr[i] = temp;
			}
		}
	}
}

// Check if the array contains a value
bool contains(int* arr, int size, int value) {
	for (int i = 0; i < size; ++i) {
		if (arr[i] == value) {
			return true;
		}
	}

	return false;
}

// Check if the 2D array contains a value
bool contains(int** arr, int rows, int cols, int value)
{
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			if (value == arr[i][j]) {
				return true;
			}
		}
	}

	return false;
}


void fill_common_all(int** A, int** B, int** C, int*& common_all, int& counter_common_all, int& size_common_all, const int& rowsA, const int& colsA, const int& rowsB, const int& colsB, const int& rowsC, const int& colsC)
{
	if (A == nullptr || B == nullptr || C == nullptr || common_all == nullptr) {
		return;
	}

	// Fill common_all with values from A
	for (int i = 0; i < rowsA; i++) {				// Вот этот двойной цикл нужно было запихнуть в функцию и перегружать её если нужно мне кажется
		for (int j = 0; j < colsA; j++) {
			// Get the value from A
			int value = A[i][j];

			// Check if value is already in common_all
			if (contains(common_all, counter_common_all, value)) {
				continue;
			}

			// Check if value is in B and C
			bool match_in_B = contains(B, rowsB, colsB, value);
			bool match_in_C = contains(C, rowsC, colsC, value);


			// If value is in both B and C, add it to common_all
			if (match_in_B && match_in_C) {
				// Check if we need to resize common_all
				if (size_common_all <= counter_common_all) {
					resize_array_double(common_all, size_common_all);
				}

				common_all[counter_common_all++] = value;
			}
		}
	}
}


void fill_unique_all(int** A, int** B, int** C, int*& unique_all, int& counter_unique_all, int& size_unique_all, const int& rowsA, const int& colsA, const int& rowsB, const int& colsB, const int& rowsC, const int& colsC)
{
	if (A == nullptr || B == nullptr || C == nullptr || unique_all == nullptr) {
		return;
	}

	// Fill unique_all with values from A
	for (int i = 0; i < rowsA; i++) {
		for (int j = 0; j < colsA; j++) {
			// Get the value from A
			int value = A[i][j];

			// Check if value is already in unique_all
			if (contains(unique_all, counter_unique_all, value)) {
				continue;
			}

			// Check if value is in B and C
			bool match_in_B = contains(B, rowsB, colsB, value);
			bool match_in_C = contains(C, rowsC, colsC, value);

			// If value is not in B and C, add it to unique_all
			if (match_in_B == false && match_in_C == false) {
				if (size_unique_all <= counter_unique_all) {
					resize_array_double(unique_all, size_unique_all);
				}

				unique_all[counter_unique_all++] = value;
			}
		}
	}

	// Fill unique_all with values from B
	for (int i = 0; i < rowsB; i++) {
		for (int j = 0; j < colsB; j++) {
			// Get the value from B
			int value = B[i][j];

			// Check if value is already in unique_all
			if (contains(unique_all, counter_unique_all, value)) {
				continue;
			}

			// Check if value is in A and C
			bool match_in_A = contains(A, rowsA, colsA, value);
			bool match_in_C = contains(C, rowsC, colsC, value);

			// If value is not in A and C, add it to unique_all
			if (match_in_A == false && match_in_C == false) {
				if (size_unique_all <= counter_unique_all) {
					resize_array_double(unique_all, size_unique_all);
				}

				unique_all[counter_unique_all++] = value;
			}
		}
	}

	// Fill unique_all with values from C
	for (int i = 0; i < rowsC; i++) {
		for (int j = 0; j < colsC; j++) {
			int value = C[i][j];


			if (contains(unique_all, counter_unique_all, value)) {
				continue;
			}

			bool match_in_B = contains(B, rowsB, colsB, value);
			bool match_in_A = contains(A, rowsA, colsA, value);

			if (match_in_B == false && match_in_A == false) {
				if (size_unique_all <= counter_unique_all) {
					resize_array_double(unique_all, size_unique_all);
				}

				unique_all[counter_unique_all++] = value;
			}
		}
	}
}

// Fill common_AC with values from A and C
void fill_common_AC(int** A, int** C, int*& common_AC, int& counter_common_AC, int& size_common_AC, const int& rowsA, const int& colsA, const int& rowsC, const int& colsC)
{
	for (int i = 0; i < rowsA; i++) {
		for (int j = 0; j < colsA; j++) {
			int value = A[i][j];

			// Check if value is already in common_AC
			if (contains(common_AC, counter_common_AC, value)) {
				continue;
			}

			// Check if value is in C
			bool match_in_C = contains(C, rowsC, colsC, value);

			// If value is in C, add it to common_AC
			if (match_in_C) {
				if (size_common_AC <= counter_common_AC) {
					resize_array_double(common_AC, size_common_AC);
				}

				common_AC[counter_common_AC++] = value;
			}
		}
	}
}

// Fill unique_negatives with values from A
void fill_unique_negatives(int** A, int** B, int** C, int*& unique_negatives, int& counter_unique_negatives, int& size_unique_negatives, const int& rowsA, const int& colsA, const int& rowsB, const int& colsB, const int& rowsC, const int& colsC)
{
	if (A == nullptr || B == nullptr || C == nullptr || unique_negatives == nullptr) {
		return;
	}

	for (int i = 0; i < rowsA; i++) {
		for (int j = 0; j < colsA; j++) {
			int value = A[i][j];

			// Check if value is negative
			if (value >= 0) {
				continue;
			}

			// Check if value is already in unique_negatives
			if (contains(unique_negatives, counter_unique_negatives, value)) {
				continue;
			}

			// Check if value is in B and C
			bool match_in_B = contains(B, rowsB, colsB, value);
			bool match_in_C = contains(C, rowsC, colsC, value);

			// If value is in both B and C, add it to unique_negatives
			if (match_in_B && match_in_C) {
				if (size_unique_negatives <= counter_unique_negatives) {
					resize_array_double(unique_negatives, size_unique_negatives);
				}
				
				unique_negatives[counter_unique_negatives++] = value;
			}
		}
	}
}







