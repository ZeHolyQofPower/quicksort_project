#!/bin/bash
for i in 10 100 1000 10000 100000
do
	for j in {0..100..1}
	do
		./InputFileGenerator "input_of_$i.number$j.txt" $i
		./gazdecki_adam_QuickSort ".generated_input_of_$i.number$j.txt" "output_of_$i.number$j.txt"
	done
done
