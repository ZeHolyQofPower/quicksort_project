/* Copyright 2021 Adam Gazdecki
 */
/* The purpose of this file is to read in, sort files, and give time taken.
 * It will use QuickSort and a pivot of median-of-three to sort.
 * It will read in existing files from command line.
 * The input files will be delimited by spaces and vary in length.
 * It will not edit the input files.
 * It will create a new file to write sorted numbers to.
 * The name of these new sorted files will come from command line input.
 * The time taken to sort, in milliseconds alongside with the quantity of-
 * -numbers will be written to a specific existing file.
 */
#include <gazdecki_adam_QuickSort.h>

int main(int argc, char* argv[]) {
  /* Tweakable Constants */
  const char* kSearchDirectoryPtr = ".";
  /* Check Command-Line Usage */
  if (argc != 3) {
    // Usage information:
    cout << "gazdecki_adam_QuickSort: Argument error" << endl << endl;
    cout << "Usage:" << endl << endl;
    cout << "./gazdecki_adam_QuickSort {input file | output file}"
         << endl << endl;
    return -1;  // Incorrect argument number.
  }
  // Take in cmd-line arguments.
  const string kUnsortedInputFile = argv[1];
  const string kSortedOutputFile = argv[2];
  /* Check command line arguments' preconditions before using */
  DIR* directory_ptr = opendir(kSearchDirectoryPtr);
  // Check if directory pointer is working correctly.
  if (directory_ptr == NULL) {
    cout << "gazdecki_adam_QuickSort: Directory error" << endl << endl;
    cout << "Directory for output not found, or you may be on Windows."
         << endl << endl;
    return -2;  // "." Directory not found. This feature is not implemented.
  }
  // Check if output file already exists. If so, abort.
  struct dirent* dir_itr;
  while ((dir_itr = readdir(directory_ptr)) != NULL) {
    if (kSortedOutputFile == (dir_itr->d_name)) {
    cout << "gazdecki_adam_QuickSort: Output file already exists error"
         << endl << endl;
    cout << "Entered file name already found. No action will be taken."
         << endl << endl;
    closedir(directory_ptr);
    return -3;  // File already exists. Behavior is undefined so abort.
    }
  }
  dir_itr = nullptr;
  closedir(directory_ptr);
  // Check if input file actually exists.
  bool foundInputFile = false;
  string dir_name;
  directory_ptr = opendir(kSearchDirectoryPtr);
  while ((dir_itr = readdir(directory_ptr)) != NULL) {
    if (kUnsortedInputFile == (dir_itr->d_name)) {
      // We found it. Good!
      foundInputFile = true;
    }
  }
  if (!foundInputFile) {
    cout << "gazdecki_adam_QuickSort: Input file not found error"
         << endl << endl;
    cout << "Entered file name not found. No action will be taken."
         << endl << endl;
    closedir(directory_ptr);
    return -4;  // Input file was not found, or not entered correctly. Abort.
  }
  dir_itr = nullptr;
  closedir(directory_ptr);
  /* Read In From File */
  //double* number_array = ReadFromFile(kUnsortedInputFile);
  double *number_array = nullptr;
  ReadFromFile(kUnsortedInputFile, &number_array);
  for (size_t i = 0; i < 4; i++)
    cout << number_array[i] << endl;
  /* Sorting */
  /* Write To File */
  return 0;           
}  // End of Main.

void ReadFromFile(const string file_name, double** array) {
  // Thank you a_m0d for asking 1398307. I finally understand everything.
  std::ifstream input_stream(file_name);
  if (!input_stream) {
    cout << "gazdecki_adam_QuickSort: ReadfromFile function error!"
         << endl << endl;
    cout << "File stream opened incorrectly." << endl
         << "Is the file encrypted or corrupted somehow?" << endl << endl; 
    cout << "Program's behavior is undefined beyond this point." << endl
         << "Have a nice day!" << endl << endl;
    return;  // File exists but opened incorrectly. How?
  }
  // Find how many numbers are here so we can allocate memory.
  size_t quantity_of_numbers = 0;
  std::istream_iterator<double> start(input_stream), end;
  quantity_of_numbers = std::distance(start, end);
  *array = new double[quantity_of_numbers];
  cout << quantity_of_numbers << endl;
  // Fun fact about pointers-to-pointers. The abreviated square bracket syntax
  // begins to break-down and has undefined behavior. Example:
  // *array[i] is... not nice.
  double* array_end = *array + quantity_of_numbers;
  for (double* itr = *array; itr < array_end; itr++) {
    *itr = 0.8;
  }
}

void QuickSort(size_t left_itr, size_t right_itr, double& array) {
  //
}

void WriteToFile(const string file_name) {
  //
}

// ~End of File.
