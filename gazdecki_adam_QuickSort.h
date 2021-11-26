/* Copyright 2021 Adam Gazdecki
 */
#ifndef GAZDECKI_ADAM_QUICKSORT_H_
#define GAZDECKI_ADAM_QUICKSORT_H_

#include <dirent.h>  // Used for directory file checking.
#include <iostream>  // Used for debugging output.
using std::cout;
using std::cin;
using std::endl;
#include <string>  // Used for argument processing.
using std::string;
#include <fstream>  // Used for writing to files.

/* This function takes the values in a file, and writes them to an array.
 * 
 * Preconditions: Delimiter is a space. Input file exists.
 */
double* ReadFromFile(const string file_name);

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
