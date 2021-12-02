## Welcome to Adam Gazdecki's CSCE350 Project.
A Median-of-Three Implementation and Empirical Analysis of the QuickSort Algorithm.
# Directions for Compilation and Use.
### 1. Download The Repository.
You should be able to download the compressed package from dropbox.

Unfortunatly my github repository is private so you won't be able to clone it yourself directly. I am willing to share the repository or download with other professors if you email me at gazdecki@email.sc.edu . I am not willing to share this with any students at any point though.
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
Any and all feedback is appreciated.
