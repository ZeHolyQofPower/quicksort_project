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

/* This function takes the values in a file, and writes them to a dynamically
 * allocated array. array is an output parameter.
 * I apologize for the usage of a pointer-to-a-pointer. I had never tried it
 * before and wanted to see how "bad" it was to implement. This was hard.
 * 
 * Returns the quantity of numbers in the file/array.
 * 
 * Preconditions: Delimiter is a space. Input file exists.
 */
const size_t ReadFromFile(const string file_name, double** array);

/* This function quicksorts the values in an array.
 * It uses a median-of-three pivot.
 * 
 * Precondition: None?
 */
void QuickSort(size_t left_itr, size_t right_itr, double& array);

/* This function takes the values in an array, and writes them to a new file.
 * 
 * Precondition: The file must NOT already exist.
 */
void WriteToFile(const string file_name);

#endif  // GAZDECKI_ADAM_QUICKSORT_H_
// ~End of File.
