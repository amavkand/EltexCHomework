CC=gcc

all: directory

directory: directory.o
	$(CC) directory.o -o directory

directory.o: directory.c
	$(CC) -c directory.c

clean:
	rm -f directory *.o