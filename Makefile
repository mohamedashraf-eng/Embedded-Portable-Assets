# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c99

# Directories
CORE_DIR = Core
PLATFORM_DIR = $(CORE_DIR)/Platform
PLIBS_DIR = $(CORE_DIR)/PLibs
LINKEDLIST_DIR = $(PLIBS_DIR)/LinkedList
QUEUE_DIR = $(PLIBS_DIR)/Queue
STACK_DIR = $(PLIBS_DIR)/Stack

# Source files
CORE_SRCS = $(CORE_DIR)/*.c $(PLATFORM_DIR)/*.c $(PLIBS_DIR)/**/*.c
LINKEDLIST_SRCS = $(LINKEDLIST_DIR)/Wx_LinkedList.c
QUEUE_SRCS = $(QUEUE_DIR)/Wx_Static_Queue.c
STACK_SRCS = $(STACK_DIR)/Wx_Static_Stack.c

# Object files
CORE_OBJS = $(patsubst %.c, %.o, $(wildcard $(CORE_SRCS)))
LINKEDLIST_OBJS = $(patsubst %.c, %.o, $(wildcard $(LINKEDLIST_SRCS)))
QUEUE_OBJS = $(patsubst %.c, %.o, $(wildcard $(QUEUE_SRCS)))
STACK_OBJS = $(patsubst %.c, %.o, $(wildcard $(STACK_SRCS)))

# Targets
all: linkedlist queue stack

linkedlist: $(CORE_OBJS) $(LINKEDLIST_OBJS)
	$(CC) $(CFLAGS) -o linkedlist $(CORE_OBJS) $(LINKEDLIST_OBJS) -IPLATFORM_DIR

queue: $(CORE_OBJS) $(QUEUE_OBJS)
	$(CC) $(CFLAGS) -o queue $(CORE_OBJS) $(QUEUE_OBJS) -IPLATFORM_DIR

stack: $(CORE_OBJS) $(STACK_OBJS)
	$(CC) $(CFLAGS) -o stack $(CORE_OBJS) $(STACK_OBJS) -IPLATFORM_DIR

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(CORE_OBJS) $(LINKEDLIST_OBJS) $(QUEUE_OBJS) $(STACK_OBJS) $(MAIN_OBJ)

.PHONY: all linkedlist queue stack main clean
