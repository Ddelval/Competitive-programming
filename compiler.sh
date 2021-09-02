#!/bin/bash

makefile="

DEBUG_FLAGS=-Wall -fsanitize=address -g -DDEBUG -DLOCAL
SPEED_FLAGS=-O2
a_db.out: $2
	g++-10  $^  \$(DEBUG_FLAGS) -o a_db.out

a_f.out: $2
	g++-10  $^  \$(SPEED_FLAGS) -o a_f.out

a.out: $2
	g++-10 $^ 
"

if [[ $# -ne 2 ]]; then
		printf  "\e[31;1mNot enough arguments\e[39;0m\n"
		exit -1
fi

if [[ $1 -eq 2 ]]; then
echo "$makefile" | make --file='-'  a_f.out
printf  "\e[32;1mRunning program:\e[39;0m\n"
time ./a_f.out <in.in
elif [[ $1 -eq 1 ]]; then
echo "$makefile" | make --file='-'  a_db.out
printf  "\e[32;1mRunning program:\e[39;0m\n"
./a_db.out <in.in
else
echo "$makefile" | make --file='-'  a.out
printf  "\e[32;1mRunning program:\e[39;0m\n"
./a.out <in.in
fi
