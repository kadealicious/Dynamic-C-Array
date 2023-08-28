#include<stdlib.h>
#include<string.h>
#include"dasort.h"


#include<stdio.h>


/**
 * @brief Swap two elements in the array.
 *
 * @param array The dynamic array.
 * @param index0 Index of the first element to be swapped.
 * @param index1 Index of the second element to be swapped.
 * @return True if successful, false otherwise.
 */
bool daSwap(daArray* array, size_t index0, size_t index1)
{
	void* element0 = daGet(array, index0);
	void* element1 = daGet(array, index1);

	if(element0 == NULL || element1 == NULL)
		{return false;}

	memcpy(array->tempElement, element0, array->elementByteSize);
	memcpy(element0, element1, array->elementByteSize);
	memcpy(element1, array->tempElement, array->elementByteSize);

	return true;
}

/**
 * @brief Scramble the dynamic array's elements between indexLow and indexHigh.
 *
 * @param array The dynamic array.
 * @param index0 Index of the low scramble bound.
 * @param index1 Index of the upper scramble bound.
 * 
 * @return True if successful, false otherwise.
 */
bool daScramble(daArray* array, size_t indexLow, size_t indexHigh)
{
	if(indexHigh >= array->elementCount)
		{return false;}
	
	srand((uintptr_t)array->data);

	for(size_t i = 0; i < array->elementCount; i++)
	{
		size_t index0 = rand() % (array->elementCount - 1);
		size_t index1 = rand() % (array->elementCount - 1);

		daSwap(array, index0, index1);
	}

	return true;
}

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
 * 
 * @note Time best: O(n log(n)), time average: O(n log(n)), time worst: O(n^2), space worst: O(log(n)).
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

/**
 * @brief Perform an insertion sort on the dynamic array using byte comparisions.
 * 
 * @param array The dynamic array to sort.
 * @param indexLow the low index for sorting.
 * @param indexHigh the high index for sorting.
 * 
 * @return True if the array was able to be sorted, false otherwise.
 * 
 * @note Time best: O(n), time average: O(n^2), time worst: O(n^2), space worst: O(1).
 */
bool daInsertionSort(daArray* array, size_t indexLow, size_t indexHigh)
{
	if(indexHigh >= array->elementCount)
		{return false;}
	
	for(size_t i = (indexLow + 1); i < indexHigh; i++)
	{
		size_t subsearchIndex = (i - 1);
		memcpy(array->tempElement, daGet(array, i), array->elementByteSize);
		
		while(subsearchIndex >= 0 && subsearchIndex != SIZE_MAX && memcmp(daGet(array, subsearchIndex), array->tempElement, array->elementByteSize) > 0)
		{
			daReplace(array, daGet(array, subsearchIndex), (subsearchIndex + 1));
			subsearchIndex--;
		}

		daReplace(array, array->tempElement, (subsearchIndex + 1));
	}

	return true;
}

/**
 * @brief Perform a binary search on the dynamic array.  Array must be sorted first.
 *
 * @param array The dynamic array to sort.
 * @param targetElement The element to search for.
 * @param indexLow The lower bound for searching.
 * @param indexHigh The upper bound for searching.
 * 
 * @return Index of the first occurrence of targetElement.  Returns SIZE_MAX if element is not found.
 * 
 * @note Time best: O(1), time average: O(log(n)), time worst: O(log(n)), space worst: O(1).
 */
size_t daBinarySearch(daArray* array, void* targetElement, size_t indexLow, size_t indexHigh)
{
	if(indexHigh >= array->elementCount)
		{return SIZE_MAX;}

	while(indexLow <= indexHigh)
	{
		size_t indexMiddle	= ((indexHigh + indexLow) / 2);
		void* middleElement	= daGet(array, indexMiddle);
		int elementComparison = memcmp(middleElement, targetElement, array->elementByteSize);

		if(elementComparison == 0)
			{return indexMiddle;}
		else if(elementComparison < 0)
			{indexLow = (indexMiddle + 1);}
		else if(elementComparison > 0)
			{indexHigh = indexMiddle;}
	}

	return SIZE_MAX;
}