#include "work_with_double_array.h"

void fill_rand(double** arr, const int row, const int column, const double start, const double end)
{
	random_device rd;
	mt19937 gen(rd());
	uniform_real_distribution<double> dist(start, end);

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			arr[i][j] = dist(gen);
		}
	}
}

void fill_rand(double** arr, const int size, const double start, const double end)
{
	random_device rd;
	mt19937 gen(rd());
	uniform_real_distribution<double> dist(start, end);

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			arr[i][j] = dist(gen);
		}
	}
}

// PRINT CHAR ARRAY
void print_arr(const char* arr) {

	if (arr == nullptr) {
		return;
	}

	cout << arr;
}