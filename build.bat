@echo off

make clean

make

set r=Core/PLibs/
set plf = Core/Platform/
set ll=LinkedList/Wx_Static_LinkedList.o
set q=Queue/Wx_Static_Queue.o
set s=Stack/Wx_Static_Stack.o
@REM set t=Tree/Wx_Static_Queue.o
@REM set g=Graph/Wx_Static_Queue.o
set cflags=-O0 -g -std=c99
gcc main.c %r%/%ll% %r%/%q% %r%/%s% -o output.exe %cflags% -I/%plf%

echo ======================================================
output.exe
echo ======================================================
