CC := gcc

all: password string

password: password.o
	$(CC) password.o -o password

password.o: password.c
	$(CC) -g -c -std=c89 -fno-stack-protector -no-pie password.c

string: string.o
	$(CC) string.o -o string

string.o: string.c
	$(CC) -c string.c

clean:
	rm -f password string *.txt *.o