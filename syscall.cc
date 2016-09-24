#include "syscall.hh"

/* taken from linux kernel source in arch/x86/entry/syscalls/syscall_64.tbl */
/* system call constants */
#define READ_SYSTEM_CALL 0
#define WRITE_SYSTEM_CALL 1
#define OPEN_SYSTEM_CALL 2
#define CLOSE_SYSTEM_CALL 3
/* system call constants */

ssize_t wrapped_open(const void *path, int args){
	ssize_t returnValue;

	asm volatile (
		"syscall"
		: "=a" (returnValue)
		: "0"(OPEN_SYSTEM_CALL), "D"(path), "d"(args)
		: "cc", "rcx", "r11", "memory"
	);

	return returnValue;
}

/*
 *	low level c++/assembly code for Intel 64-bit CPU to make a call to the write system call
 */
ssize_t my_write(int fd, const void *buffer, isize_t size) {
	ssize_t returnValue;

	/* inline assembly in GCC syntax:

		asm ( assembler template
		: output operands
		: input operands
		: list of clobbered registers
		);

		"asm volatile" tells GCC that our code goes exactly where we put it

		assembler template:
			"syscall" - call the 64-bit intell instruction "syscall"

		output operands:
			"=a" means that the return value will be in the "a" register (EAX)
			     this is by convention for C++

		input operands:
			"0"(WRITE_SYSTEM_CALL) - passes constant (1) using register EAX
			"D"(fd) - passes value of (fd) variable using register EDI
			"S"(buffer) - passes value of buffer using register ESI
			"d"(size) - passes value of size variable using register EDX


		clobber list (tells the compiler about the post-state effects of what we did):
			"cc"  - flags register gets clobbered
			"rcx" - rcx register gets clobbered
			"r11" - register 11 gets clobbered
			"memory" - memory gets clobbered
	*/

	asm volatile (
		"syscall"
		: "=a" (returnValue)
		: "0"(WRITE_SYSTEM_CALL), "D"(fd), "S"(buffer), "d"(size)
		: "cc", "rcx", "r11", "memory"
	);

	return returnValue;
}
