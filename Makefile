#
# Template Makefile from 3157
#

CC  = gcc

# Let's leave a place holder for additional include directories

INCLUDES =

# Compilation options:

CFLAGS   = -g -Wall $(INCLUDES)

# Linking options:

main:
	gcc shell.c -o shell

.PHONY: clean
clean:
	rm -f *.o *~ a.out core shell

.PHONY: all
all: clean default

