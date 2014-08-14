CC ?= cc
CFLAGS := -std=c99 -pedantic -Wall -Wextra -g

.PHONY: all clean
.SUFFIXES: .c .o

all: libstack.a test
test: test.o libstack.a
	$(CC) -static -o $@ test.o -L. -lstack

libstack.a: cstack.o istack.o fstack.o dstack.o
	ar rcs $@ cstack.o istack.o fstack.o dstack.o

cstack.o: stack.c
	$(CC) $(CFLAGS) -c -o $@ -DSTACK_CHAR stack.c

istack.o: stack.c
	$(CC) $(CFLAGS) -c -o $@ -DSTACK_INT stack.c

fstack.o: stack.c
	$(CC) $(CFLAGS) -c -o $@ -DSTACK_FLOAT stack.c

dstack.o: stack.c
	$(CC) $(CFLAGS) -c -o $@ -DSTACK_DOUBLE stack.c

.c.o:
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f *.o *.core test
