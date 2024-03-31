#!/bin/bash
echo "======================================================"
make clean
make
echo "======================================================"
r="Core/PLibs/"
plf="Core/Platform/"
ll="LinkedList/Wx_Static_LinkedList.o"
q="Queue/Wx_Static_Queue.o"
s="Stack/Wx_Static_Stack.o"
# t="Tree/Wx_Static_Tree.o"
# g="Graph/Wx_Static_Graph.o"
cflags="-g -std=c99"
gcc main.c "$r$ll" "$r$q" "$r$s" -o output_test_1 "$cflags" -I"$plf"
echo "======================================================"
ls -la
echo "======================================================"
echo "======================================================"
./output_test_1
echo "======================================================"
