#include "syscall.hh"
#include <fcntl.h>

int main(int argc, char** argv){

	unsigned int write_bytes = 100 * 1000 * 1000; //100 * kb * mb

	unsigned int buffer_size = 100; //seg fault if too large
	unsigned int descriptor = wrapped_open("out", O_WRONLY | O_CREAT);

	unsigned int iterations = write_bytes / buffer_size;
	unsigned int remainingBytes = write_bytes % buffer_size;

	unsigned int i;

	char data[buffer_size]; //this is just random garbage at this pt. I could just print this. but ->
	//\_O_/ is more fun
	for (i = 0; i < buffer_size; i++){
		switch (i%5) {
			case 0:
				data[i] = '\\';
				break;
			case 1:
				data[i] = '_';
				break;
			case 2:
				data[i] = 'O';
				break;
			case 3:
				data[i] = '_';
				break;
			case 4: data[i] = '/';
		}
	}
	//data[buffer_size-1] = '\0'; not doing this. but i should

	for (i = 0; i < iterations; i++) my_write(descriptor, data, buffer_size); //puke this data into that file

	//Build some extra data to fill the size requirement in case buffer isnt divisor.
	if (remainingBytes){
		char data_remainder[remainingBytes];
		for (i = 0; i < remainingBytes; i++) data_remainder[i] = 'r';
		my_write(descriptor, data_remainder, remainingBytes);
	}
}
