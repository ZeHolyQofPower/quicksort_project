/* Copyright 2021 Adam Gazdecki
 */
#include <InputFileGenerator.h>
using std::cout;
using std::cin;
using std::endl;
#include <dirent.h>  // Used for directory file checking.
#include <string>  // Used for argument processing.
// TODO(me) I'm not sure why cpplint made me add this line?
/* The purpose of this file (and its header) are to generate a file.
 * This file will be an ASCII file of random, unsorted, floating-point numbers.
 * Their range should be: [-100, 100]
 * They should be delimited by Blank Space.
 * The file generated should be titled 'input.txt'
 * This should generate different size files. By quantity of numbers.
 * This should be able to generate 100 different input files, per quantity.
 * ZERO functions should be touched by gazdecki_adam_QuickSort files.
 */

int main(int argc, char* argv[]) {
  // Check Command-line Usage. If wrong, Stop.
  if (argc != 3) {
    // Usage information:
    cout << "InputFileGenerator: argument error" << endl << endl;
    cout << "Usage:" << endl << endl;
    cout << "./InputFileGenerator {file "
         <<  "| \"number of unsorted floating-point numbers\"}"
         << endl << endl;
    return 1;  // Incorrect argument number.
  }
  // Take in cmd-line arguments.
  const std::string file_to_write_to = argv[1];
  const std::size_t quantity_of_unsorted_numbers = atoi(argv[2]);
  // Check if file already exists. If so, abort.
  DIR* directory_ptr = opendir(".");
  if (directory_ptr == NULL) {
    cout << "InputFileGenerator: OS directory error" << endl << endl;
    cout << "Directory not Found. You may be on Windows." << endl << endl;
    return 2;  // "." Directory not found. This should never happen?
  }
  struct dirent* dir_itr;
  // You cannot do pointer arithmetic with directory pointers.
  // All guides online use something similar to this while loop.
  while ((dir_itr = readdir(directory_ptr)) != NULL) {
    // TODO(me) Why am I not allowed to write the line?:
    /* if ("makefile" == (dir_itr->d_name)) { */
    // What does the warning mean?
    if (file_to_write_to == (dir_itr->d_name)) {
      // cout << "===Look\\/!===" << endl;
    cout << "InputFileGenerator: File already exists error" << endl << endl;
    cout << "Entered file name already found. No action will be taken."
         << endl << endl;
    closedir(directory_ptr);
    return 3;  // File already exists. Behavior is undefined so abort.
    }
    // cout << dir_itr->d_name << endl;
  }
  closedir(directory_ptr);
  // Check number input to see if was input correctly. atoi() Overflows.
  if (atoi(argv[2]) <= 0 && atoi(argv[2]) <= 2147483647) {
    cout << "InputFileGenerator: Number argument error" << endl << endl;
    cout << "Entered number must be positive and non-zero." << endl << endl;
    return 4;  // Number must be a non-zero positive integer.
  }
  cout << "--Success! End of input checks--" << endl;
  cout << "argv[2]: " << argv[2] << endl;
  cout << "atoi(argv[2]): " << quantity_of_unsorted_numbers << endl;
  return 0;
}

// ~End of File.
