#ifndef _sort_H_
#define _sort_H_

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void merge_sort(int *array, size_t size);
void print_array(const int *array, size_t size);
void merge(int *array, size_t size, size_t mid, int *tmp);
void merge_sort_rec(int *array, size_t size, int *tmp);

#endif /* _SORT_H_ */
