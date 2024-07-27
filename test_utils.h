#include <stdlib.h>

// DO NOT INCLUDE THIS FILE IN select.c.

int* copy_numbers(int const* numbers, size_t num_numbers);
int* copy_numbers_sorted(int const* numbers, size_t num_numbers);
int compare_ints(void const* a_lhs, void const* a_rhs);
int* create_pseudo_random_numbers(size_t num_numbers);
void print_numbers(int* numbers, size_t start_idx, size_t num_numbers_to_print);
void print_success_msg(char const* msg);
bool test_get_kth_smallest(size_t k_0_based, int const* numbers, size_t num_numbers);

#define TEST_UTILS_H_V1  // Do not delete or modify this line.  It helps us track any updates.
/* vim: set tabstop=4 shiftwidth=4 fileencoding=utf-8 noexpandtab: */
