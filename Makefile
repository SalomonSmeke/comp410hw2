CC=/usr/bin/g++
CFLAGS= -g -Wall -I.
LINKFLAGS= -g -Wall

all: clean demo

clean:
	rm -f demo *.o

demo: main.o syscall.o
	$(CC) $(LINKFLAGS) -o demo main.o syscall.o

main.o: main.cc syscall.hh
	$(CC) $(CFLAGS) -c main.cc -o main.o

syscall.o: syscall.cc syscall.hh
	$(CC) $(CFLAGS) -c syscall.cc -o syscall.o
