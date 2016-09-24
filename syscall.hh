#pragma once

typedef int sisize_t;
typedef unsigned int uisize_t;

sisize_t my_write(int fd, const void *buffer, uisize_t size);

sisize_t wrapped_open(const char *path, int args);
