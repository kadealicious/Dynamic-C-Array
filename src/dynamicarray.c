// Include needed libraries

#include<stdio.h>
#include<stdint.h>
#include<memory.h>
#include"dynamicarray.h"



/**
 * @brief Initialize a dynamic array.
 *
 * @param array The dynamic array to initialize.
 * @param size Initial size of the array.
 * @param elementByteSize Size of each element in bytes.
 * @param zeroInitialize Whether to zero-initialize memory.
 * @return Returns true if initialization is successful, false otherwise.
 */
bool daInit(daArray* array, size_t size, size_t elementByteSize, bool zeroInitialize)
{
	
	array->elementByteSize	= elementByteSize; 
	array->elementCount		= 0;
	array->zeroInitialize	= zeroInitialize; 

	// If size is not positive, make it 10
	if(size < 1)			{size = 10;}

	// Double the size
	size					*= 2;
	array->allocatedSize	= size;


	if(zeroInitialize)
	{
		array->data = calloc(size, elementByteSize);
	}
	else
	{
		array->data = malloc(size * elementByteSize);
	}

	return true;	// Always returning true?
}

/**
 * @brief Insert an element at a specific index.
 *
 * @param array The dynamic array.
 * @param element Pointer to the element to insert.
 * @param index Index at which to insert the element.
 * @return New size of the array after insertion.
 */
size_t daInsert(daArray* array, void* element, size_t index)
{
	// Determine if array must be resized before insertion.
	size_t finalElementIndex			= daGetFinalElementIndex(array);
	if(index >= finalElementIndex)		{return (daPushBack(array, element) + 1);}
	daReallocate(array, 2);
	
	// Shift memory on right side of index to the right by one element.
	size_t memoryCopySize	= (array->elementCount - index) * array->elementByteSize;
	size_t elementIndex		= (index * array->elementByteSize);
	void* srcMemory			= &array->data[elementIndex];
	void* dstMemory			= &array->data[elementIndex + array->elementByteSize];
	memcpy(dstMemory, srcMemory, memoryCopySize);			// BUG: This is likely undefined behavior.

	// Insert element at index.
	memcpy(&array->data[elementIndex], element, array->elementByteSize);	// TODO: Don't use memcpy()!  It's slow.
	array->elementCount++;

	return array->elementCount;
}

/**
 * @brief Add an element to the end of the array.
 *
 * @param array The dynamic array.
 * @param element Pointer to the element to add.
 * @return Index of the newly added element.
 */
size_t daPushBack(daArray* array, void* element)
{
	// Determine if array must be resized before pushing back.
	size_t finalElementIndex = daGetFinalElementIndex(array);
	daReallocate(array, 2);

	size_t newElementIndex = finalElementIndex * array->elementByteSize;
	if(array->elementCount != 0)
		{newElementIndex += array->elementByteSize;}
	memcpy(&array->data[newElementIndex], element, array->elementByteSize);
	array->elementCount++;

	return finalElementIndex;
}

/**
 * @brief Remove an element from the array at a specific index.
 *
 * @param array The dynamic array.
 * @param index Index of the element to remove.
 * @return New size of the array after removal.
 */
size_t daRemove(daArray* array, size_t index)
{
	if(index >= array->elementCount)
		{return false;}

	size_t memoryCopySize	= (array->elementCount - index) * array->elementByteSize;
	size_t elementIndex		= (index * array->elementByteSize);
	void* srcMemory			= &array->data[elementIndex];
	void* dstMemory			= &array->data[elementIndex - array->elementByteSize];
	memcpy(dstMemory, srcMemory, memoryCopySize);			// BUG: This is likely undefined behavior.

	array->elementCount--;

	return array->elementCount;
}

/**
 * @brief Resize the dynamic array.
 *
 * @param array The dynamic array.
 * @param newSize New size for the array.
 * @return Returns true if resizing is successful, false otherwise.
 */
bool daResize(daArray* array, size_t newSize)
{
	// Ensure element count stays correct.
	array->allocatedSize = newSize;
	if(array->elementCount > newSize)
	{
		array->elementCount -= (array->elementCount - newSize);
	}

	// Resize and reassign data pointer within array.
	void* tempData;
	if(array->zeroInitialize)
	{
		tempData = calloc(newSize, array->elementByteSize);
	}
	else
	{
		tempData = malloc(newSize * array->elementByteSize);
	}
	size_t copySize = (array->elementCount * array->elementByteSize);
	memcpy(tempData, array->data, copySize);
	free(array->data);
	array->data = tempData;

	return true;
}

/**
 * @brief Free the memory used by the dynamic array.
 *
 * @param array The dynamic array to free.
 * @return Returns true if memory is successfully freed, false otherwise.
 */
bool daFree(daArray* array)
{
	if(array->allocatedSize > 0)
	{
		array->allocatedSize	= 0;
		array->elementByteSize	= 0;
		array->elementCount		= 0;
		free(array->data);

		return true;
	}

	return false;
}

/**
 * @brief Get an element from the array at a specific index.
 *
 * @param array The dynamic array.
 * @param index Index of the element to retrieve.
 * @return Pointer to the element at the given index.
 */
void* daGet(daArray* array, size_t index)
{
	return &array->data[index * array->elementByteSize];
}

/**
 * @brief Replace an element at a specific index.
 *
 * @param array The dynamic array.
 * @param element Pointer to the new element.
 * @param index Index of the element to replace.
 * @return Returns true if the element was replaced successfully, false otherwise.
 */
bool daReplace(daArray* array, void* element, size_t index)
{
	if(index >= array->elementCount)
		{return false;}
	
	size_t elementIndex		= (index * array->elementByteSize);
	void* srcMemory			= element;
	void* dstMemory			= &array->data[elementIndex];
	memcpy(dstMemory, srcMemory, array->elementByteSize);

	return true;
}

/**
 * @brief Print the elements of the dynamic array.
 *
 * @param array The dynamic array.
 */
void daPrintUint32(daArray* array)
{
	printf("Allocated: %llu elements/%llub, Element Size: %llub, Element Count: %llu\n", 
			array->allocatedSize, (array->allocatedSize * array->elementByteSize), 
			array->elementByteSize, array->elementCount);
	
	for(size_t i = 0; i < array->allocatedSize; i++)
	{
		uint32_t* data = (uint32_t*)array->data;
		if(i < array->elementCount)
			{printf(" <o> ");}
		else {printf(" < > ");}
		printf("%i\n", (uint32_t)(data[i]));
	}
}

/**
 * @brief Get the index of the last element in the array.
 *
 * @param array The dynamic array.
 * @return Index of the last element.
 */
size_t daGetFinalElementIndex(daArray* array)
{
	size_t finalElementIndex	= 0;
	if(array->elementCount > 0)	{finalElementIndex = (array->elementCount - 1);}
	
	return finalElementIndex;
}

/**
 * @brief Reallocate the dynamic array with increased size.
 *
 * @param array The dynamic array.
 * @param allocationFactor Factor by which to increase the allocation size.
 * @return Returns true if reallocation is successful, false otherwise.
 */
bool daReallocate(daArray* array, size_t allocationFactor)
{
	if((array->allocatedSize - daGetFinalElementIndex(array)) <= 1)
	{
		daResize(array, array->allocatedSize * allocationFactor);	// BUG: This could get very big.
		return true;
	}
	else
	{
		return false;
	}
}