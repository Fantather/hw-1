#pragma once
#include <iostream>
#include "work_with_double_array.h"
using namespace std;
 
// Task 1
void resize_pointer_array_double(char**& ptr_names_arr, int& arr_size); // Resize the array of pointers
void resize_array_double(int*& arr, int& arr_size);						// Resize the array of integers
void add_name(char** names_arr, const char* name, int& count_names);	// Add a name to the array
void sort_arr(char** names_arr, const int size);						// Sort the array of names

// Task 2
bool contains(int* arr, int size, int value);				// Check if the array contains a value
bool contains(int** arr, int rows, int cols, int value);	// Check if the 2D array contains a value

void fill_common_all(int** A, int** B, int** C, int*& common_all, int& counter_common_all, int& size_common_all, const int& rowsA, const int& colsA, const int& rowsB, const int& colsB, const int& rowsC, const int& colsC);
void fill_unique_all(int** A, int** B, int** C, int*& unique_all, int& counter_unique_all, int& size_unique_all, const int& rowsA, const int& colsA, const int& rowsB, const int& colsB, const int& rowsC, const int& colsC);
void fill_common_AC(int** A, int** C, int*& common_AC, int& counter_common_AC, int& size_common_AC, const int& rowsA, const int& colsA, const int& rowsC, const int& colsC);
void fill_unique_negatives(int** A, int** B, int** C, int*& unique_negatives, int& counter_unique_negatives, int& size_unique_negatives, const int& rowsA, const int& colsA, const int& rowsB, const int& colsB, const int& rowsC, const int& colsC);