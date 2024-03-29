/* Copyright 2021 Adam Gazdecki
 */
#ifndef GAZDECKI_ADAM_QUICKSORT_H_
#define GAZDECKI_ADAM_QUICKSORT_H_

#include <dirent.h>  // Used for directory file checking.
#include <iostream>  // Used for debugging output.
using std::cout;
using std::cin;
using std::endl;
#include <string>  // Used for argument processing. Also stof().
using std::string;
#include <fstream>  // Used for writing to files.
#include <iterator>  // Used for counting elements in files.
#include <chrono>  // Used for timing QuickSort function. NOLINT

/* This function takes the values in a file, and writes them to a dynamically
 * allocated array. Array is an output parameter.
 * I apologize for the usage of a pointer-to-a-pointer. I had never tried it
 * before and wanted to see how "bad" it was to implement. This was hard.
 * 
 * Returns the quantity of numbers in the file/array.
 * 
 * Preconditions: Delimiter is a space. Input file exists.
 */
size_t ReadFromFile(const string file_name, float** array);

/* This function quicksorts the values in an array.
 * It uses a median-of-three pivot.
 * 
 * Precondition: None.
 */
void QuickSort(float* leftmost_index, float* rightmost_index,
               size_t array_length, float** array);

/* This function takes the values in an array, and writes them to a new file.
 * 
 * Precondition: The file must NOT already exist.
 */
void WriteToFile(const string file_name, float** array,
                 const size_t length);

/* This function prints the values of the array to console for debugging.
 * 
 * Precondition: There should be a bug that needs calling.
 */
void PrintArray(float** array_start_index, size_t length);

#endif  // GAZDECKI_ADAM_QUICKSORT_H_
// ~End of File.
