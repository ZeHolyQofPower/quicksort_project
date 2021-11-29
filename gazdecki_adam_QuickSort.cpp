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
  /* Sorting */
  QuickSort(number_array, (number_array + array_length - 1), array_length,
            &number_array);
  cout << "Array Values After Quicksort Call:" << endl;
  PrintArray(&number_array, array_length);
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

void QuickSort(double* leftmost_index, double* rightmost_index,
               size_t array_length, double** array) {
  cout << "Quicksort Call!" << endl;
//  cout << "lefty: " << *leftmost_index << " and my righty: "
//       << *rightmost_index << " and my length: " << array_length << endl;
  PrintArray(&leftmost_index, array_length);
  /* Recursive halting condition first: */
  // If your indexes cross or have only two elements.
  if (array_length <= 2 || leftmost_index >= rightmost_index
      || *array == nullptr)
    return;
  /* Partition array using median-of-three pivot. */
  // Important note: Part of this optimization is that the three values are
  // sorted to their psudo-correct positions before continuing.
  // This effects the next recursive call and removes a particular worst case:
  // Sorted input, but first and last indexes are swapped.
  double* middle_index = (leftmost_index + array_length/2);
  // These simple labels make life a lot easier.
  double leftmost = *leftmost_index;
  double middle = *middle_index;
  double rightmost = *rightmost_index;

  double not_nullptr = -1.0;  // Random NON-nullptr value for initalization.
  double* pivot_index [[maybe_unused]]= &not_nullptr;  // [[Supress warning]]
  double* tmp_ptr = &not_nullptr;
  // The second layer of this structure places the median in the middle.
//  cout << "Choosing pivot out of (" << leftmost << ", " << middle << ", "
//       << rightmost << ")" << endl;
  if ((leftmost > middle) ^ (leftmost > rightmost)) {
    // Leftmost is the median.
    *pivot_index = leftmost;
    *tmp_ptr = *middle_index;
    *middle_index = *leftmost_index;
    *leftmost_index = *tmp_ptr;
  } else if ((middle < leftmost) ^ (middle < rightmost)) {
    // Middle is the median
    *pivot_index = middle;
  } else {
    // Rightmost is the median.
    *pivot_index = rightmost;
    *tmp_ptr = *middle_index;
    *middle_index = *rightmost_index;
    *rightmost_index = *tmp_ptr;
  }
  // Median in the middle now, label index nicely, order the outer values.
  pivot_index = middle_index;
  if (leftmost > rightmost) {
    *tmp_ptr = *leftmost_index;
    *leftmost_index = *rightmost_index;
    *rightmost_index = *tmp_ptr;
  }
  cout << "pivot is: " << *pivot_index << "! at middle index: "
       << (pivot_index - *array) << " now." << endl;
//  cout << "Here are our three choices arranged in order: " << endl;
  PrintArray(array, array_length);
  // Every item is looped through and placed on the correct side of the pivot.
  double* i = leftmost_index;
  double* j = rightmost_index;
  while (i <= j) {
    // Loop through are check all the left elements.
    while (*i < *pivot_index/* && i < pivot_index*/) {
      if (i > pivot_index) {
//        cout << "oh no. i is on the wrong side. Guess I'll freeze." << endl;
      }
      i++;
    }
//    cout << "Found: " << *i << " that's more than or equal to the pivot on wrong side." << endl;
    // Loop through and check all the right elements.
    while (*j > *pivot_index/* && j > pivot_index*/) {
      if (j < pivot_index) {
//        cout << "oh no. j is on the wrong side. Guess I'll freeze." << endl;
      }
      j--;
    }
//    cout << "Found: " << *j << " that's less than or equal to the pivot on wrong side." << endl;
    // Make sure if someone crossed the pivot, they move it.
    //if ()
    // Now Swap elements to correct sides of pivot.
    if (i <= j) {
//        cout << "Swap i and j to opposite sides and keep going" << endl;
        *tmp_ptr = *i;
        *i = *j;
        *j = *tmp_ptr;
        // If the pivot is moved, do not allow i or j to get on the wrong side.
        if (i == pivot_index) {
//          cout << "PIVOT MOVED to j AHHHHHHH" << endl;
          pivot_index = j;
          j++;  // Uniterate so it sticks to the pivot
//          cout << "uh... j: " << (j - *array) << endl;
//          cout << "new pivot location: " << (pivot_index - *array) << endl;
        } else if (j == pivot_index) {
//          cout << "PIVOT MOVED to i AHHHHHHH" << endl;
          pivot_index = i;
          i--;
//          cout << "new pivot location: " << (pivot_index - *array) << endl;
        }
        i++;
        j--;
//        PrintArray(&leftmost_index, array_length);
//        cout << "===i is at " << *i << " and j is at " << *j << "===" << endl;
    }
  }
cout << "Arranged values around pivot:" << endl;
PrintArray(&leftmost_index, array_length);
  // Now recursively partition until all divided arrays are sorted.
/*
  cout << "leftmost_index: " << *leftmost_index << endl;
  cout << "rightmost_index: " << *rightmost_index << endl;
  cout << "i: " << *i << endl;
  cout << "j: " << *j << endl;
*/
  if (leftmost_index < j) {  // Partition Left Side.
    QuickSort(leftmost_index, j, (j - leftmost_index + 1), array);
  }
  if (rightmost_index > i) {  // Partition right Side.
    QuickSort(i, rightmost_index, (rightmost_index - i + 1), array);
  }
}  // End of QuickSort.

void WriteToFile(const string file_name) {
  //
}

void PrintArray(double** array_start_index, size_t length) {
  size_t count = 0;
  double* array_end = *array_start_index + length;
  for (double* itr = *array_start_index; itr < array_end; itr++) {
    count++;
    cout << *itr << "  " << "\t";
    if (count % 5 == 0)
      cout << endl;
  }
  cout << endl;
}

// ~End of File.
