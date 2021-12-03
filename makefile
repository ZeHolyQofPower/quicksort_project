# TODO This makefile needs to contain directions to compile and use this
# project. I should probably make them an exact duplicate of the README.md
BASE_COMPILER = g++
COMPILER_ARGS = -std=c++11
COMPILER_ARGS += -Wall
COMPILER_ARGS += -Wextra
# COMPILER_ARGS += -fsplit-stack
COMPILER_ARGS += -I .

LINK = $(BASE_COMPILER) $(COMPILER_ARGS) -o
COMPILE = $(BASE_COMPILER) $(COMPILER_ARGS) -c
LINT = @~/Downloads/cpplint-master/cpplint.py --root=./

## Build ##
build: InputFileGenerator gazdecki_adam_QuickSort
	./create_gazdecki_adam_executionTime.bash

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
	@echo "QuickSort linting good.\n"

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
	@echo "InputFileGenerator linting good.\n"

## Utility Commands ##
# TODO(me) I'm having trouble ordering these logically?
# How can I handle larger projects using this kind of clean cmd?
clean:# one-of-everything
	@rm ./*.o
	@rm InputFileGenerator
	@rm gazdecki_adam_QuickSort
	@rm gazdecki_adam_executionTime.txt
	@rm .generated_*
	@rm .sorted_*

clean-generated-files:
	@rm .generated_*

clean-sorted-files:
	@rm .sorted_*

lint-all: lint-gazdecki_adam_QuickSort lint-InputFileGenerator
	@echo "All linting successful!"

# This functions runs through to make one of every type of file clean wants.
one-of-everything: InputFileGenerator gazdecki_adam_QuickSort
	@./InputFileGenerator silly_file_name.txt 1
	@./gazdecki_adam_QuickSort .generated_silly_file_name.txt silly_file_name.txt

