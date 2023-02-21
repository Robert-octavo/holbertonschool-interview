#ifndef _SLIDE_LINE_H_
#define _SLIDE_LINE_H_

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#define SLIDE_LEFT 1
#define SLIDE_RIGHT 2

int slide_line(int *line, size_t size, int direction);
void slide_left(int *line, size_t size);
void slide_right(int *line, size_t size);

#endif /* _SLIDE_LINE_H_ */
