// DO NOT USE THIS FILE IN select.c (final submission).

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <string.h>  // for memcpy(…)
#include "select.h"
#include "test_utils.h"

int* copy_numbers(int const* numbers, size_t num_numbers) {
	int* copy_of_numbers = malloc(num_numbers * sizeof copy_of_numbers[0]);
	return memcpy(copy_of_numbers, numbers, num_numbers * sizeof copy_of_numbers[0]);
}

int compare_ints(void const* a_lhs, void const* a_rhs) {
	// This is a compare function.  It is used by the qsort(..) function to sort the numbers.
	return *(int*)a_lhs - *(int*)a_rhs; // <0 if lhs < rhs;  =0 if lhs == rhs;  >0 if lhs > rhs
}

int* copy_numbers_sorted(int const* numbers, size_t num_numbers) {
	int* copy_of_numbers = malloc(num_numbers * sizeof copy_of_numbers[0]);
	memcpy(copy_of_numbers, numbers, num_numbers * sizeof copy_of_numbers[0]);
	qsort(copy_of_numbers, num_numbers, sizeof copy_of_numbers[0], compare_ints);
	return copy_of_numbers;
}

int* create_pseudo_random_numbers(size_t num_numbers) {
	int* numbers = malloc(num_numbers * sizeof numbers[0]);
	for(size_t i = 0; i < num_numbers; i++) {
		numbers[i] = rand();
		assert(numbers[i] >= 0);
	}
	return numbers;
}

void print_numbers(int* numbers, size_t start_idx, size_t num_numbers_to_print) {
	for(size_t i = start_idx; i < start_idx + num_numbers_to_print; i++) {
		printf("numbers[%zd] == %10d", i, numbers[i]);
	}
}

void print_success_msg(char const* msg) {
	printf("%s", "\x1b[32m");
	printf("SUCCESS: %s\n", msg);
	printf("%s", "\x1b[0m");
}

bool test_get_kth_smallest(size_t k_0_based, int const* numbers, size_t num_numbers) {
	// Test get_kth_smallest(..) on a copy of numbers (to not affect subsequent tests).
	int* numbers_copy = copy_numbers(numbers, num_numbers);

	// Check the result.  We sort using the standard qsort(..) library.
	qsort(numbers_copy, num_numbers, sizeof numbers_copy[0], compare_ints);
	int kth_smallest = get_kth_smallest(k_0_based, numbers_copy, num_numbers);
	bool is_result_correct = kth_smallest == numbers_copy[k_0_based];

	// Clean up
	free(numbers_copy);

	return is_result_correct;
}

#define TEST_UTILS_C_V1  // Do not delete or modify this line.  It helps us track any updates.
/* vim: set tabstop=4 shiftwidth=4 fileencoding=utf-8 noexpandtab: */
