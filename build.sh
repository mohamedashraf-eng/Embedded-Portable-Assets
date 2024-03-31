#!/bin/bash

make clean

r="Core/PLibs/"
plf="Core/Platform/"
ll="LinkedList/Wx_Static_LinkedList.o"
q="Queue/Wx_Static_Queue.o"
s="Stack/Wx_Static_Stack.o"
# t="Tree/Wx_Static_Tree.o"
# g="Graph/Wx_Static_Graph.o"
cflags="-O0 -g -std=c99"
gcc main.c "$r$ll" "$r$q" "$r$s" -o output "$cflags" -I"$plf"

echo "======================================================"
sudo ./output
echo "======================================================"
