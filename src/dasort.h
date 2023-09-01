#ifndef DYNAMICARRAY_SORT_H_
#define DYNAMICARRAY_SORT_H_

#include<stdint.h>
#include"da.h"


/**
 * @brief Scramble the dynamic array's elements between indexLow and indexHigh.
 *
 * @param array The dynamic array.
 * @param index0 Index of the low scramble bound.
 * @param index1 Index of the upper scramble bound.
 * 
 * @return True if successful, false otherwise.
 */
bool daScramble(daArray* array, size_t indexLow, size_t indexHigh);

/**
 * @brief Swap two elements in the array.
 *
 * @param array The dynamic array.
 * @param index0 Index of the first element to be swapped.
 * @param index1 Index of the second element to be swapped.
 * @return True if successful, false otherwise.
 */
bool daSwap(daArray* array, size_t index0, size_t index1);

/**
 * @brief Perform an insertion sort on the dynamic array using byte comparisions.
 * 
 * @param array The dynamic array to sort.
 * @param indexLow the low index for sorting.
 * @param indexHigh the high index for sorting.
 * 
 * @return True if the array was able to be sorted, false otherwise.
 * 
 * @note Time best: O(n log(n)), time average: O(n log(n)), time worst: O(n^2), space worst: O(log(n)).
 */
bool daQuickSort(daArray* array, size_t indexLow, size_t indexHigh);

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
bool daInsertionSort(daArray* array, size_t indexLow, size_t indexHigh);

/**
 * @brief Perform a heap sort sort on the dynamic array using byte comparisions.
 * 
 * @param array The dynamic array to sort.
 * @param indexLow the low index for sorting.
 * @param indexHigh the high index for sorting.
 * 
 * @return True if the array was able to be sorted, false otherwise.
 * 
 * @note Time best: O(n log(n)), time average: O(n log(n)), time worst: O(n log(n)), space worst: O(1).
 */
bool daHeapSort(daArray* array, size_t indexLow, size_t indexHigh);

/**
 * @brief Perform a binary search on the dynamic array.  Array must be sorted first.
 *
 * @param array The dynamic array to sort.
 * @param targetElement The element to search for.
 * @param indexLow The lower bound for searching.
 * @param indexHigh The upper bound for searching.
 * 
 * @return Index of the first occurrence of targetElement.  Returns DA_NOT_FOUND (equal to SIZE_MAX) if element is not found.
 * 
 * @note Time best: O(1), time average: O(log(n)), time worst: O(log(n)), space worst: O(1).
 */
size_t daBinarySearch(daArray* array, void* targetElement, size_t indexLow, size_t indexHigh);


#endif