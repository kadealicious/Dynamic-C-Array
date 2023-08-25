#ifndef DYNAMICARRAY_H_
#define DYNAMICARRAY_H_

#include<stdlib.h>
#include<stdbool.h>

typedef struct daArray
{
	void* data;					// TODO: Add a bucketing system for faster insertion and removal.
	size_t allocatedSize;
	size_t elementCount;
	size_t elementByteSize;
	bool zeroInitialize;
}
daArray;

bool daInit(daArray* array, size_t size, size_t elementByteSize, bool zeroInitialize);
size_t daInsert(daArray* array, void* element, size_t index);	// Returns size of array after insertion.
size_t daPushBack(daArray* array, void* element);				// Returns index of newly added element.
void* daGet(daArray* array, size_t index);						// Returns the element as a void*.
bool daReplace(daArray* array, void* element, size_t index);	// Returns if the element was replaced.
size_t daRemove(daArray* array, size_t index);					// Returns size of array after deletion.
bool daResize(daArray* array, size_t newSize);
bool daFree(daArray* array);


#endif