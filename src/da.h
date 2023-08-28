#ifndef DYNAMICARRAY_H_
#define DYNAMICARRAY_H_

#include <stdlib.h>
#include <stdbool.h>

/**
 * @brief A dynamic array data structure.
 */
typedef struct daArray
{

    void* data;               /**< Pointer to the array data */ // TODO: Add a bucketing system for faster insertion and removal.
	void* tempElement;        /**< Pointer to temporary element for use in swapping & sorting. */
    size_t allocatedSize;     /**< Allocated size of the array */
    size_t elementCount;      /**< Number of elements in the array */
    size_t elementByteSize;   /**< Size of each array element in bytes */
    bool zeroInitialize;      /**< Whether to zero-initialize memory */
} daArray;

/**
 * @brief Initialize a dynamic array.
 *
 * @param array The dynamic array to initialize.
 * @param size Initial size of the array.
 * @param elementByteSize Size of each element in bytes.
 * @param zeroInitialize Whether to zero-initialize memory.
 * @return Returns true if initialization is successful, false otherwise.
 */
bool daInit(daArray* array, size_t size, size_t elementByteSize, bool zeroInitialize);

/**
 * @brief Insert an element at a specific index.
 *
 * @param array The dynamic array.
 * @param element Pointer to the element to insert.
 * @param index Index at which to insert the element.
 * @return New size of the array after insertion.
 */
size_t daInsert(daArray* array, void* element, size_t index);

/**
 * @brief Add an element to the end of the array.
 *
 * @param array The dynamic array.
 * @param element Pointer to the element to add.
 * @return Index of the newly added element.
 */
size_t daPushBack(daArray* array, void* element);

/**
 * @brief Get an element from the array at a specific index.
 *
 * @param array The dynamic array.
 * @param index Index of the element to retrieve.
 * @return Pointer to the element at the given index.
 */
void* daGet(daArray* array, size_t index);

/**
 * @brief Replace an element at a specific index.
 *
 * @param array The dynamic array.
 * @param element Pointer to the new element.
 * @param index Index of the element to replace.
 * @return Returns true if the element was replaced successfully, false otherwise.
 */
bool daReplace(daArray* array, void* element, size_t index);

/**
 * @brief Remove an element from the array at a specific index.
 *
 * @param array The dynamic array.
 * @param index Index of the element to remove.
 * @return New size of the array after removal.
 */
size_t daRemove(daArray* array, size_t index);

/**
 * @brief Resize the dynamic array.
 *
 * @param array The dynamic array.
 * @param newSize New size for the array.
 * @return Returns true if resizing is successful, false otherwise.
 */
bool daResize(daArray* array, size_t newSize);

/**
 * @brief Free the memory used by the dynamic array.
 *
 * @param array The dynamic array to free.
 * @return Returns true if memory is successfully freed, false otherwise.
 */
bool daFree(daArray* array);

/**
 * @brief Get the index of the last element in the array.
 *
 * @param array The dynamic array.
 * 
 * @return Index of the last element (0 is returned if the array is empty).
 */
size_t daGetFinalElementIndex(daArray* array);


#endif