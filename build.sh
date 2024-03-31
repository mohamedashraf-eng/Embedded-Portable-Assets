#!/bin/bash

make clean
make

r="Core/PLibs/"
plf="Core/Platform/"
ll="LinkedList/Wx_Static_LinkedList.o"
q="Queue/Wx_Static_Queue.o"
s="Stack/Wx_Static_Stack.o"
# t="Tree/Wx_Static_Queue.o"
# g="Graph/Wx_Static_Queue.o"
cflags="-O0 -g -std=c99"
gcc main.c "$r$ll" "$r$q" "$r$s" -o output.exe "$cflags" -I"$plf"

echo "======================================================"
./output.exe
echo "======================================================"
