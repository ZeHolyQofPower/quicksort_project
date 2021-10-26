# This makefile needs to contain directions to compile and use this project.
# I should probably make them a duplicate of the README.md

COMPILER = g++ -std=c++11 -Wall -I .

gazdecki_adam_QuickSort: gazdecki_adam_QuickSort.o
	$(COMPILER) -c $@ $^

gazdecki_adam_QuickSort.o: gazdecki_adam_QuickSort.cpp \
                           gazdecki_adam_QuickSort.h
	$(COMPILER) -o $@ $<

lint-gazdecki_adam_QuickSort: gazdecki_adam_QuickSort.cpp \
                              gazdecki_adam_QuickSort.h
	cpplint.py --root=./ $^

clean:
	rm ./*.o
