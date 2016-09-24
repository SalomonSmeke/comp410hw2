#include "syscall.hh"
#include <fcntl.h>

int main(int argc, char** argv){

	unsigned int write_bytes = 100 * 1024 * 1024;

	unsigned int buffer_size = 1024;
	unsigned int descriptor = wrapped_open("out.txt", O_WRONLY | O_CREAT);

	unsigned int iterations = write_bytes/buffer_size;
	unsigned int remainingBytes = write_bytes%buffer_size;

	//Build some data to write out.
	char data[buffer_size];

	for (int i = 0; i < buffer_size-1; i++){
		data[i] = '*';
	}
	data[buffer_size-1] = '\0';

	for (int i = 0; i < iterations; i++){
		my_write(descriptor, data, buffer_size);
	}

	remainingBytes += iterations; //Each iteration looses 1 byte to null terminator.

	//Build some extra data to fill the size requirement.
	if (remainingBytes){
		char data_remainder[remainingBytes+1]; //null terminator bleed-over

		for (int i = 0; i < remainingBytes; i++){
			data_remainder[i] = '+';
		}
		data_remainder[remainingBytes] = '\0';

		my_write(descriptor, data_remainder, remainingBytes+1);
	}
}
