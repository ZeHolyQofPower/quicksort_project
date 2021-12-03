Welcome to Adam Gazdecki's CSCE350 QuickSort Project.
A Median-of-Three Implementation and Empirical Analysis of the QuickSort Algorithm.
# Directions for Compilation and Use.
### 0. Stack Overflow Errors.  :(
The elephant in the project are the segfaults. There is ONE bug I know about. I fully understand why and how it occures. How to fix it is beyond my abilities.

When quicksorting arrays of size 'n', the stack depth is size 'n'. The stack in memory is filled with calls of my quicksort function over and over until it runs out of space. Using `gdb` on the core dump confirms this. Because I'm inexperienced at using `gdb`, `valgrind` with the flag `--verbose` also shows the stack overflow error clearly.

I know my heap allocation is CLEAN. I have a single instance of "new" and a single instance of "delete" in the entire project. Valgrind also shows there are no possible memory leaks.

I have tried my best to make sure I'm storing the array in the heap without copying. I am not moving the data on or off the stack. I am using minimal function calls in my main method. For example, I removed a separate partition function. I have confirmed, using some crazy goto statements I removed, that the completion of quicksort calls on the stack are occuring in a depth first order. I have tried allocating more memory for the stack by using the flag `-fsplit-stack`. I have asked every professor, cs-student, and friend that would listen about this bug and nobody has any idea how to help. So if you have ANY idea why my program does this and nobody else's, please please please tell me, it's benn driving me crazy.
### 1. Download The Repository.
You should be able to download the compressed package from dropbox.

Unfortunatly my github repository is private so you won't be able to clone it yourself directly. I am willing to share the repository or download with other professors if you email me at gazdecki@email.sc.edu . I am not willing to share this with any students at any point in the past, present, or future.
### 2. Build Instructions.
The command
`make build` or `make`
Should be able to build all needed binaries automatically. If there are any unusual errors or missing inclusions, try again on the Departmental Linux machines.

If you are tinkering with the code, you may notice the
`make clean`
command throws weird errors. Running the command
`make one-of-everything && make clean`
should fix any strange behavior. This is due to the command calling on so many other sub-parts.
### 3. Usage Instructions.
There are checks for all command line usage, so it's quite challenging to do something wrong or on accident. 
I hope any directions or errors I write are clear.

InputFileGenerator interacts with the command line for all input and output.
The first argument is the base name for the file it's generating.
The second argument is the quantity of unsorted numbers for it to generate.
`./InputFileGenerator input.txt 10` will create the file `.generated_input.txt`

For deletion of all files starting with `.generated_*` run the command:
`make clean-generated-files`

gazdecki_adam_QuickSort interacts with the command line for file input and output.
The execution of the QuickSort function is directly appended to the end of the file `executionTime.txt`.
`./gazdecki_adam_QuickSort input.txt output.txt` will create the file `.sorted_output.txt`

For deletion of all files starting with `.sorted_*` run the command:
`make clean-sorted-files`
### 4. Check Out Cool Stuff.
I'm very proud of this project!

There's tons of cool stuff I've learned and added to this project, and I hope you can appreciate my attention to detail, and clear documentation.
Any and all feedback is appreciated. Have a great holiday!
