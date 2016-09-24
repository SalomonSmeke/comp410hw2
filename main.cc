#include "syscall.hh"

int main(int argc, char** argv){
	/* we're calling the write system call */
	/* file descriptor is 0 - standard output to the terminal */
	/* buffer is the string constant "hello" */
	/* the length of the buffer is 6 bytes */
	my_write(0, "hello", 6);
}
