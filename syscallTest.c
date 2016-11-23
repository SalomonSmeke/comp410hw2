/*
/ Test the iotest syscall
*/

#define __GNU_SOURCE
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

#define sys_iotest 329

int main(int argc, char** argv)
{
  unsigned int buffer_size = atoi(argv[1]);

	int returnValue;

	asm volatile (
		"syscall"
		: "=a" (returnValue)
		: "0"(sys_iotest), "S"(buffer_size)
		: "cc", "rcx", "r11", "memory"
	);
	return returnValue;
}
