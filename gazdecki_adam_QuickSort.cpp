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
  double *number_array = nullptr;
  const size_t array_length = ReadFromFile(kUnsortedInputFile, &number_array);
  /*
  for (size_t i = 0; i < array_length; i++)
    cout << number_array[i] << endl;
  */
  /* Sorting */
  QuickSort(0, array_length-1, array_length, &number_array);
  /* Write To File */
  return 0;
}  // End of Main.

const size_t ReadFromFile(const string file_name, double** array) {
  std::ifstream input_stream(file_name);
  if (!input_stream) {
    cout << "gazdecki_adam_QuickSort: ReadfromFile function error!"
         << endl << endl;
    cout << "File exists, but file stream opened incorrectly." << endl
         << "Is the file encrypted or corrupted somehow?" << endl << endl;
    cout << "Program's behavior is undefined beyond this point." << endl
         << "Have a nice day!" << endl << endl;
    return -1;  // File exists but opened incorrectly. How?
  }
  // Find how many elements are in our input file.
  // Thanks handy-dandy iterator std library!
  size_t quantity_of_numbers = 0;
  std::istream_iterator<double> start(input_stream), end;
  quantity_of_numbers = std::distance(start, end);
  // Allocate memory and take data into array.
  *array = new double[quantity_of_numbers];
  // Move input file stream back to beginning of file.
  input_stream.clear();
  input_stream.seekg(0);
  // Fun fact about pointers-to-pointers. The abreviated square bracket syntax
  // begins to break-down and has undefined behavior. Example:
  // *array[i] is... not nice.
  string tmp = "";
  double* array_end = *array + quantity_of_numbers;
  for (double* itr = *array; itr < array_end; itr++) {
    input_stream >> tmp;
    *itr = stof(tmp);
  }
  input_stream.close();
  // Don't forget to return the length of your new array!
  return quantity_of_numbers;
}

void QuickSort(size_t left_ind, size_t right_ind, size_t array_length, 
               double** array) {
  cout << "Array values:" << endl;
  double* array_end = *array + array_length;
  for (double* itr = *array; itr < array_end; itr++) {
    cout << *itr << endl;
  }
  cout << endl;
  // Recursive halting condition first:
  // If your indexes cross or have only one element.
  if (array_length <= 1 || left_ind >= right_ind || *array == nullptr)
    return;
  // Partition array using median-of-three pivot.
  // Important note: Part of this optamization is that the selected values are
  // sorted to their psudo-correct positions before continuing.
  // This effects the next recursive call and removes a particular worst case:
  // Sorted with, first and last index swapped.
  double leftmost = *(*array + 0);
  double middle = *(*array + array_length/2);
  double rightmost = *(*array + array_length - 1);

  cout << "leftmost: " << leftmost << endl;
  cout << "middle: " << middle << endl;
  cout << "rightmost: " << rightmost << endl;

  size_t pivot_index;
  double pivot_value;
  double tmp;
  if ((leftmost > middle) ^ (leftmost > rightmost)) {
    // Leftmost is the median.
    pivot_index = 0;
    pivot_value = leftmost;
    // Sort.
    
  } else if ((middle < leftmost) ^ (middle < rightmost)) {
    // Rightmost is the median.
    pivot_index = array_length - 1;
    pivot_value = rightmost;
    // Sort.

  } else {
    // Middle is the median
    pivot_index = array_length/2;
    pivot_value = middle;
    // Sort.
    if (leftmost > rightmost) {
      tmp = rightmost;
      rightmost = leftmost;
      leftmost = tmp;
    }  // else do nothing.
  }
  // Every item is looped through and placed on the correct side of the pivot.
}

void WriteToFile(const string file_name) {
  //
}

// ~End of File.
