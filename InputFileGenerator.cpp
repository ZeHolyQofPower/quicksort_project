/* Copyright 2021 Adam Gazdecki
 */
#include <InputFileGenerator.h>
using std::cout;
using std::cin;
using std::endl;
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
    //
    cout << "InputFileGenerator: argument error" << endl << endl;
    cout << "Usage:" << endl << endl;
    cout << "./InputFileGenerator {file "
         <<  "| \"number of unsorted floating-point numbers\"}"
         << endl << endl;
    return 1;  // Incorrect argument number.
  }
  cout << "arg string 1: " << argv[1] << endl;
  cout << "arg string 2: " << argv[2] << endl;
  // Check if file already exists. If so, abort.
  if (0) {
    // nope.
    return 2;  // File not found.
  }
  // Usage information:
  cout << "--Good Job--" << endl;
  return 0;
}

// ~End of File.
