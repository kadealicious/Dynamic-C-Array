#include<stdio.h>
#include<stdint.h>
#include<memory.h>
#include"dynamicarray.h"


bool daInit(daArray* array, size_t size, size_t elementByteSize, bool zeroInitialize);
size_t daInsert(daArray* array, void* element, size_t index);	// Returns size of array after insertion.
size_t daPushBack(daArray* array, void* element);				// Returns index of newly added element.
void* daGet(daArray* array, size_t index);						// Returns the element as a void*.
bool daReplace(daArray* array, void* element, size_t index);	// Returns if the element was replaced.
size_t daRemove(daArray* array, size_t index);					// Returns size of array after deletion.
bool daResize(daArray* array, size_t newSize);
bool daFree(daArray* array);

void daPrintUint32(daArray* array);
size_t daGetFinalElementIndex(daArray* array);
bool daReallocate(daArray* array, size_t allocationFactor);


int main(int argc, char* argv[])
{
	daArray testArray;
	daInit(&testArray, 4, sizeof(uint32_t), true);

	uint32_t elements[10] = 
	{
		17, 
		45, 
		12, 
		2, 
		1, 
		2, 
		5, 
		10, 
		9, 
		16
	};
	for(uint8_t i = 0; i < 8; i++)
	{
		daPushBack(&testArray, &elements[i]);
		daPrintUint32(&testArray);
		getchar();
	}

	uint32_t testElement = 100203;
	daInsert(&testArray, &testElement, 2);
	daPrintUint32(&testArray);
	getchar();

	daRemove(&testArray, 3);
	daPrintUint32(&testArray);
	getchar();

	printf("daGet(5): %i\n", *(uint32_t*)daGet(&testArray, 5));
	getchar();

	daReplace(&testArray, &testElement, 900);
	daPrintUint32(&testArray);
	getchar();

	return 0;
}

bool daInit(daArray* array, size_t size, size_t elementByteSize, bool zeroInitialize)
{
	array->elementByteSize	= elementByteSize;
	array->elementCount		= 0;
	array->zeroInitialize	= zeroInitialize;

	if(size < 1)			{size = 10;}
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

	return true;
}

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

void* daGet(daArray* array, size_t index)
{
	return &array->data[index * array->elementByteSize];
}

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

size_t daGetFinalElementIndex(daArray* array)
{
	size_t finalElementIndex	= 0;
	if(array->elementCount > 0)	{finalElementIndex = (array->elementCount - 1);}
	
	return finalElementIndex;
}

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