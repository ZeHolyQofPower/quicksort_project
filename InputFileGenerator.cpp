/* Copyright 2021 Adam Gazdecki
 */
#include <InputFileGenerator.h>
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
  /* Tweakable Constants */
  // const string output_directory = "./fake_dir";
  const char* kOutputDirectoryPtr = ".";
  // TODO(me) Why cant I just point a char* to an existing string?
  // They are both const, so I don't think there's any overwrite danger?
  const double kMu = 0.0;
  const double kSigma = 50.0;
  const string kDelimiter = " ";
  const double kMinRange = -100.0;
  const double kMaxRange = 100.0;
  const string kFilePrefix = ".generated_";  // This allows reasonable cleanup.
  /* Check Command-Line Usage. */
  if (argc != 3) {
    // Usage information:
    cout << "InputFileGenerator: argument error" << endl << endl;
    cout << "Usage:" << endl << endl;
    cout << "./InputFileGenerator {file "
         <<  "| \"number of unsorted floating-point numbers\"}"
         << endl << endl;
    return -1;  // Incorrect argument number.
  }
  // Take in cmd-line arguments.
  const string kFileToWriteTo = kFilePrefix + argv[1];
  const size_t kQuantityOfUnsortedNumbers = atoi(argv[2]);
  /* Check command line arguments' preconditions before using */
  // Check if file already exists. If so, abort.
  DIR* directory_ptr = opendir(kOutputDirectoryPtr);
  // TODO(me) Why does this require a char* input? Why not any old string?
  if (directory_ptr == NULL) {
    cout << "InputFileGenerator: Directory error" << endl << endl;
    cout << "Directory for output not found, or you may be on Windows."
         << endl << endl;
/*
    cout << "If error persists, please create directory named:" << endl;
    cout << output_directory << endl << endl;
*/
    return -2;  // "." Directory not found. This should never happen?
  }
  struct dirent* dir_itr;
  // You cannot do pointer arithmetic with directory pointers.
  // All guides online use something similar to this while loop.
  while ((dir_itr = readdir(directory_ptr)) != NULL) {
    // TODO(me) Why am I not allowed to write the line?:
    /* if ("makefile" == (dir_itr->d_name)) { */
    // What does the warning mean?
    if (kFileToWriteTo == (dir_itr->d_name)) {
    cout << "InputFileGenerator: File already exists error" << endl << endl;
    cout << "Entered file name already found. No action will be taken."
         << endl << endl;
    closedir(directory_ptr);
    return -3;  // File already exists. Behavior is undefined so abort.
    }
  }
  closedir(directory_ptr);
  // Check number input to see if was input correctly. atoi() Overflows.
  if (atoi(argv[2]) <= 0 && atoi(argv[2]) <= 2147483647) {
    cout << "InputFileGenerator: Number argument error" << endl << endl;
    cout << "Entered number kMust be positive, non-zero, and not overflow."
         << endl << endl;
    return -4;  // Number kMust be a non-zero positive integer.
  }
  /* Create and write to file. */
  std::ofstream file_stream;
  // const string full_output_path = output_directory + "/" + kFileToWriteTo;
  // cout << full_output_path << endl;
  file_stream.open(kFileToWriteTo);
  // Number generation using normal distribution.
  std::random_device rand_dev;
  std::default_random_engine generator{rand_dev()};
  // I don't really understand why curly brackets to pass into engine?
  std::normal_distribution<double> distribution(kMu, kSigma);
  double tmp_number;
  size_t written_number_count = 0;
  while (written_number_count < kQuantityOfUnsortedNumbers) {
    // Generate number.
    tmp_number = distribution(generator);
    // Check bounds.
    if ((tmp_number >= kMinRange) && (tmp_number <= kMaxRange)) {
      file_stream << tmp_number << kDelimiter;
      written_number_count++;
      // Print to terminal.
/*
      cout << (written_number_count-1) << ": " << tmp_number << "\t";
      if ((written_number_count % 5) == 0)
        cout << endl;
*/
    }
  }
  file_stream.close();
  return 0;
}
// ~End of File.
