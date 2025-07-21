#ifndef WINDOWS_LINUX_H
#define WINDOWS_LINUX_H

#include <stdlib.h>
#include <stdio.h>

void clear_screen(void);

void system_pause(void);

void *system_malloc(size_t);

char *my_getline(FILE *);

#endif
