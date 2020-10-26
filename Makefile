CC=gcc
IFLAGS=-I.
CFLAGS=-g

myls: myls.o stringout.o
	$(CC) $(CFLAGS) -o myls myls.o stringout.o
