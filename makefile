# TODO This makefile needs to contain directions to compile and use this
# project. I should probably make them an exact duplicate of the README.md
COMPILER = g++ -std=c++11 -Wall -I .

## QuickSort ##
# Our QuickSort Project interacts with input file generator through arguments.
gazdecki_adam_QuickSort: gazdecki_adam_QuickSort.o
	$(COMPILER) -c $@ $^

gazdecki_adam_QuickSort.o: gazdecki_adam_QuickSort.cpp \
                           gazdecki_adam_QuickSort.h
	$(COMPILER) -o $@ $<

lint-gazdecki_adam_QuickSort: gazdecki_adam_QuickSort.cpp \
                              gazdecki_adam_QuickSort.h
	cpplint.py --root=./ $^

## Input file generator ##
# TODO "used to generate input ASCII files (Do NOT include in makefile)"
InputFileGenerator: InputFileGenerator.o
	$(COMPILER) -c $@ $^

InputFileGenerator.o: InputFileGenerator.cpp \
                      InputFileGenerator.h
	$(COMPILER) -o $@ $<

lint-InputFileGenerator: InputFileGenerator.cpp \
                         InputFileGenerator.h 
	cpplint.py --root=./ $^

## Utility Commands ##
clean:
	@rm ./*.o

lint-all: lint-gazdecki_adam_QuickSort lint-InputFileGenerator
