#pragma once
#include <iostream>
#include <random>
using namespace std;

// INIT ARRAY
template<typename T>
T** init_2d_arr(const int row, const int column);



// FILL DOUBLE ARRAY
template <typename T>
void fill_rand(T** arr, const int row, const int column, const T start, const T end);
void fill_rand(double** arr, const int row, const int column, const double start, const double end);

// Matrix
template <typename T>
void fill_rand(T** arr, const int size, const T start, const T end);
void fill_rand(double** arr, const int size, const double start, const double end);



// DELETE
template <typename T>
inline void delete_arr(T**& arr, const int size);



// PRINT DOUBLE ARRAY
template <typename T>
void print_arr(T** arr, const int row, const int column);

template <typename T>
void print_arr(const T* arr, const int size);
void print_arr(const char* arr);

//________________________________________________________________________________________________________________

// INIT DOUBLE ARRAY
template<typename T>
T** init_2d_arr(const int row, const int column)
{
	T** arr = new T * [row];

	for (int ROW = 0; ROW < row; ROW++) {
		arr[ROW] = new T[column];
	}

	return arr;
}


// FILL ARRAY
template<typename T>
inline void fill_rand(T** arr, const int row, const int column, const T start, const T end)
{
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<T> dist(start, end);

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			arr[i][j] = dist(gen);
		}
	}
}


// FILL MATRIX
template <typename T>
inline void fill_rand(T** arr, const int size, const T start, const T end)
{
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<T> dist(start, end);

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			arr[i][j] = dist(gen);
		}
	}
}


// DELETE
template<typename T>
inline void delete_arr(T**& arr, const int size)
{
	if (!arr || size <= 0) return;

	for (int i = 0; i < size; i++) {
		delete[] arr[i];
	}

	delete[] arr;
	arr = nullptr;
}


// PRINT DOUBLE ARRAY
template <typename T>
void print_arr(T** arr, const int row, const int column) {
	for (int ROW = 0; ROW < row; ROW++) {
		for (int COLUMN = 0; COLUMN < column; COLUMN++) {
			cout << arr[ROW][COLUMN] << " ";
		}
		cout << endl;
	}
}

// Print ARRAY
template<typename T>
inline void print_arr(T* arr, const int size)
{
	if (arr == nullptr || size <= 0) {
		return;
	}

	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
}

