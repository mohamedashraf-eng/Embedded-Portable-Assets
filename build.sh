#!/bin/bash
echo "======================================================"
make clean
# make

echo "======================================================"
r="Core/PLibs/"
plf="Core/Platform/"
ll="LinkedList/Wx_Static_LinkedList.c"
q="Queue/Wx_Static_Queue.c"
s="Stack/Wx_Static_Stackc"
# t="Tree/Wx_Static_Tree.o"
# g="Graph/Wx_Static_Graph.o"
cflags="-g -std=c99"
gcc main.c -o output_test_1 "$r$ll" "$r$q" "$r$s" -I"$plf"
# gcc main.c "$cflags" "$r$ll" "$r$q" "$r$s" -o output_test_1 -I"$plf"
echo "======================================================"
# ls -la
# echo "======================================================"
# echo "======================================================"
# ./output_test_1
# echo "======================================================"
