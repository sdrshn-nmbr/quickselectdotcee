// DO NOT CHANGE ANYTHING IN THIS FILE (unless directed to do so in writing by instructor)
#ifndef __SELECT_H__
#define __SELECT_H__

#include <stdlib.h>
#include <stdbool.h>

int get_kth_smallest(size_t k_0_based, int* numbers, size_t num_numbers);

// Support functions
void swap(int* a_n1, int* a_n2);
size_t partition(int* numbers, size_t num_numbers);
bool is_partition_correct(int const* numbers, size_t num_numbers, size_t num_numbers_0);

#define __SELECT_H__
#define SELECT_H_V2  // Do not delete or modify this line.  It helps us track any updates.
#endif /* end of include guard: __SELECT_H__ */
