# TODO This makefile needs to contain directions to compile and use this
# project. I should probably make them an exact duplicate of the README.md
BASE_COMPILER = g++
COMPILER_ARGS = -std=c++11
COMPILER_ARGS += -Wall
COMPILER_ARGS += -I .

LINK = $(BASE_COMPILER) $(COMPILER_ARGS) -o
COMPILE = $(BASE_COMPILER) $(COMPILER_ARGS) -c
LINT = ~/Downloads/cpplint-master/cpplint.py --root=./

## QuickSort ##
# Our QuickSort Project interacts with input file generator through arguments.
gazdecki_adam_QuickSort: gazdecki_adam_QuickSort.o
	$(LINK) $@ $<

gazdecki_adam_QuickSort.o: gazdecki_adam_QuickSort.cpp \
                           gazdecki_adam_QuickSort.h
	$(COMPILE) $<

lint-gazdecki_adam_QuickSort: gazdecki_adam_QuickSort.cpp \
                              gazdecki_adam_QuickSort.h
	$(LINT) $^

## Input file generator ##
# TODO "used to generate input ASCII files (Do NOT include in makefile)"
InputFileGenerator: InputFileGenerator.o
	$(LINK) $@ $<

InputFileGenerator.o: InputFileGenerator.cpp \
                      InputFileGenerator.h
	$(COMPILE) $<

lint-InputFileGenerator: InputFileGenerator.cpp \
                         InputFileGenerator.h 
	$(LINT) $^

## Utility Commands ##
clean:
	@rm ./*.o
	@rm InputFileGenerator
	@rm .generated_*

clean-generated-files:
	@rm .generated_*

lint-all: lint-gazdecki_adam_QuickSort lint-InputFileGenerator
	echo "All linting successful!"
