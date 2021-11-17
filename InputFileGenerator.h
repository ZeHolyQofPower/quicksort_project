/* Copyright 2021 Adam Gazdecki
 */
#ifndef INPUTFILEGENERATOR_H_
#define INPUTFILEGENERATOR_H_

// Fun fact, my linter determines order of inclusions.
#include <dirent.h>  // Used for directory file checking.
#include <iostream>  // Used for debugging output.
using std::cout;
using std::endl;
// TODO(me) I'm not sure why cpplint made me add this line? I suspect atoi().
#include <string>  // Used for argument processing.
using std::string;
#include <cstddef>  // Using size_t.
using std::size_t;
#include <fstream>  // Used for writing to files.
#include <random>  // Used for generating random numbers.

#endif  // INPUTFILEGENERATOR_H_
// ~End of File.
