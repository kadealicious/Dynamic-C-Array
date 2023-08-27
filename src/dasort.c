#include<string.h>
#include"dasort.h"

/**
 * @brief Helper function to partition the array during the quick sort algorithm.
 *
 * @param array The dynamic array to partition.
 * @param indexLow the low index for partitioning.
 * @param indexHigh the high index for partitioning.
 * 
 * @return The array's new pivot position.
 */
size_t daHelperQuickSortPartition(daArray* array, size_t indexLow, size_t indexHigh)
{
	void* pivot = daGet(array, indexHigh);

	size_t i = (indexLow - 1);

	for(size_t j = indexLow; j < indexHigh; j++)
	{
		void* elementToCompare = daGet(array, j);

		// If elementToCompare is less than pivot, swap them.
		if(memcmp(elementToCompare, pivot, array->elementByteSize) < 0)
		{
			daSwap(array, ++i, j);
		}
	}

	daSwap(array, (i + 1), indexHigh);
	return (i + 1);
}
/**
 * @brief Perform a quick sort on the dynamic array using byte comparisions.
 *
 * @param array The dynamic array to sort.
 * @param indexLow the low index for sorting.
 * @param indexHigh the high index for sorting.
 * 
 * @return True if the array was able to be sorted, false otherwise.
 */
bool daQuickSort(daArray* array, size_t indexLow, size_t indexHigh)
{
	if(indexHigh >= array->elementCount)
		{return false;}

	if(indexLow < indexHigh)
	{
		size_t partitionIndex = daHelperQuickSortPartition(array, indexLow, indexHigh);

		daQuickSort(array, indexLow, (partitionIndex - 1));
		daQuickSort(array, (partitionIndex + 1), indexHigh);
	}

	return true;
}