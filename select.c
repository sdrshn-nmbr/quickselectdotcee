#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include "select.h"

void swap(int *a_n1, int *a_n2)
{
	int temp = *a_n1;
	*a_n1 = *a_n2;
	*a_n2 = temp;
}

bool is_partition_correct(int const *numbers, size_t num_numbers, size_t num_numbers_0)
{
	int pivot = numbers[num_numbers_0 - 1];
	for (int i = 0; i < num_numbers_0; i++)
	{
		if (numbers[i] > pivot)
		{
			return false;
		}
	}

	for (int i = num_numbers_0; i < num_numbers; i++)
	{
		if (numbers[i] <= pivot) // <= as equal numbers should be in the left (smaller) partition
		{
			return false;
		}
	}

	return true;
}

size_t partition(int *numbers, size_t num_numbers)
{
	int pivot = numbers[num_numbers - 1];
	size_t num_numbers_0 = 0;

	for (size_t i = 0; i < num_numbers - 1; i++)
	{
		if (numbers[i] <= pivot)
		{
			num_numbers_0++;
			swap(&numbers[i], &numbers[num_numbers_0 - 1]);
		}
	}

	swap(&numbers[num_numbers_0], &numbers[num_numbers - 1]); // swap pivot to the middle with the last element in the left partition
	num_numbers_0++;

	assert(is_partition_correct(numbers, num_numbers, num_numbers_0)); // A, C, D, E
	assert(num_numbers_0 > 1);										   // B

	return num_numbers_0;
}

int get_kth_smallest(size_t k_0_based, int *numbers, size_t num_numbers)
{
	assert(k_0_based < num_numbers);

	if (num_numbers == 1)
	{
		return numbers[0];
	}

	size_t num_numbers_0 = partition(numbers, num_numbers);

	if (k_0_based == num_numbers_0 - 1)
	{
		return numbers[num_numbers_0 - 1];
	}
	else if (k_0_based < num_numbers_0 - 1)
	{
		return get_kth_smallest(k_0_based, numbers, num_numbers_0 - 1);
	}
	else
	{
		return get_kth_smallest(k_0_based - num_numbers_0, numbers + num_numbers_0, num_numbers - num_numbers_0);
	}
}

#define SELECT_C_V2 // Do not delete or modify this line.  It helps us track any updates.
/* vim: set tabstop=4 shiftwidth=4 fileencoding=utf-8 noexpandtab: */
