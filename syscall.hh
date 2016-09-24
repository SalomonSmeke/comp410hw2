#pragma once

typedef int ssize_t;
typedef unsigned int isize_t;

ssize_t my_write(int fd, const void *buffer, isize_t size);

ssize_t wrapped_open(const void *path, int args);
