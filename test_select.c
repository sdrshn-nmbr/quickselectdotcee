#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <time.h>
#include "select.h"
#include "test_utils.h" // Do not include in select.c
// #include "special_test_cases.h"  // TODO: uncomment after you have added a test that uses them

int main(int argc, char *argv[])
{
	srand(time(NULL)); // This makes the pseudo-random number generator return different numbers
					   // each time you run your tests.  If you want it to use the same numbers
					   // each time, change it to srand(1) (or some other constant instead of 1).

	// Test swap(…)
	int n1 = 5;
	int n2 = 6;
	swap(&n1, &n2);
	assert(n1 == 6);
	assert(n2 == 5);
	print_success_msg("swap(…)");

	// Create an array of numbers.
	size_t num_numbers = 20;
	int *numbers = create_pseudo_random_numbers(num_numbers);

	// Test is_partition_correct(…) with a correct partition.
	int numbers_good_partition[] = {4, 5, 2, 5, 9, 8, 7, 6, 8, 9};
	size_t num_numbers_good_partition = sizeof numbers_good_partition / sizeof numbers_good_partition[0];
	size_t num_numbers_0_good_partition = 4;
	assert(is_partition_correct(numbers_good_partition, num_numbers_good_partition, num_numbers_0_good_partition));
	print_success_msg("is_partition_correct(…) -- good partition");

	// Test is_partition_correct(…) with incorrect partition (to verify that it can detect problems)
	int numbers_bad_partition_1[] = {0, 5, 2, 5, 9, 8, 7, 6, 8, 0};
	size_t num_numbers_bad_partition_1 = sizeof numbers_bad_partition_1 / sizeof numbers_bad_partition_1[0];
	size_t num_numbers_0_bad_partition_1 = 4;
	assert(!is_partition_correct(numbers_bad_partition_1, num_numbers_bad_partition_1, num_numbers_0_bad_partition_1));
	print_success_msg("is_partition_correct(…) -- bad partition");

	// Test is_partition_correct(…) with incorrect partition (to verify that it can detect problems)
	int numbers_bad_partition_2[] = {0, 1, 2, 5, 5, 8, 7, 6, 8, 9};
	size_t num_numbers_bad_partition_2 = sizeof numbers_bad_partition_2 / sizeof numbers_bad_partition_2[0]; // 10
	size_t num_numbers_0_bad_partition_2 = 4;
	assert(!is_partition_correct(numbers_bad_partition_2, num_numbers_bad_partition_2, num_numbers_0_bad_partition_2));
	print_success_msg("is_partition_correct(…) -- bad partition");

	// Test partition(…)
	int *numbers_copy = copy_numbers(numbers, num_numbers);
	size_t num_in_left = partition(numbers_copy, num_numbers);
	assert(is_partition_correct(numbers_copy, num_numbers, num_in_left));
	free(numbers_copy);
	print_success_msg("partition(…)");

	// Test get_kth_smallest(…)
	assert(test_get_kth_smallest(0, numbers, num_numbers));
	assert(test_get_kth_smallest(1, numbers, num_numbers));
	assert(test_get_kth_smallest(2, numbers, num_numbers));
	free(numbers);
	print_success_msg("get_kth_smallest(…)");

	return EXIT_SUCCESS;
}

#define TEST_SELECT_C_V3 // Do not delete or modify this line.  It helps us track any updates.
/* vim: set tabstop=4 shiftwidth=4 fileencoding=utf-8 noexpandtab: */
