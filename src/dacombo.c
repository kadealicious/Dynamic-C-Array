#include<memory.h>
#include"dacombo.h"


size_t daSplit(daArray* destArray, daArray* srcArray, size_t indexLow, size_t indexHigh)
{
	if(indexLow > indexHigh || indexLow < 0 || indexHigh >= srcArray->elementCount)
		{return DA_INVALID_INDICES;}

	size_t newSize				= (indexHigh - indexLow) + 1;
	size_t memoryCopyLowBound	= (indexLow * srcArray->elementByteSize);
	size_t memoryCopySize		= (newSize * srcArray->elementByteSize);

	if(destArray != srcArray)
	{
		daFree(destArray);	// BUG: This may cause a double-free if destArray has garbage memory in place of its allocatedSize attribute.  Be careful!
		daInit(destArray, newSize, srcArray->elementByteSize, srcArray->zeroInitialize);

		memcpy(destArray->data, &srcArray->data[memoryCopyLowBound], memoryCopySize);
	}
	else
	{
		// We wouldn't want a memory leak, now would we?
		void* oldMemory = srcArray->data;

		srcArray->data = malloc(srcArray->elementByteSize * memoryCopySize);
		memcpy(destArray->data, &srcArray->data[memoryCopyLowBound], memoryCopySize);

		free(oldMemory);
	}

	destArray->allocatedSize	= newSize;
	destArray->elementCount		= newSize;

	return newSize;
}

size_t daAppend(daArray* destArray, daArray* array0, daArray* array1)
{
	if(array0->allocatedSize == 0 || array1->allocatedSize == 0 || array0->elementByteSize != array1->elementByteSize)
		{return DA_INVALID_ARRAY;}
	
	size_t newSize			= (array0->elementCount + array1->elementCount);
	size_t elementByteSize	= array0->elementByteSize;
	bool zeroInitialize		= (array0->zeroInitialize | array1->zeroInitialize);

	destArray->zeroInitialize = zeroInitialize;

	if(destArray == array0)
	{
		size_t memoryCopySize	= (array1->elementCount * elementByteSize);

		daResize(destArray, newSize);
		memcpy(&destArray->data[destArray->elementCount * elementByteSize], array1->data, memoryCopySize);
	}
	else if(destArray == array1)
	{
		size_t memoryCopySize	= (array0->elementCount * elementByteSize);

		daResize(destArray, newSize);
		memcpy(&destArray->data[destArray->elementCount * elementByteSize], array0->data, memoryCopySize);
	}
	else
	{
		size_t destMemoryCo`yStart	= 0;
		size_t array0MemoryCopySize	= (array0->elementCount * elementByteSize);
		size_t array1MemoryCopySize	= (array1->elementCount * elementByteSize);

		if(destArray->allocatedSize > 0)
			{destMemoryCopyStart = (destArray->elementCount * elementByteSize);}

		memcpy(&destArray->data[destMemoryCopyStart], array0->data, array0MemoryCopySize);
		memcpy(&destArray->data[destMemoryCopyStart + array0MemoryCopySize], array1->data, array1MemoryCopySize);
	}

	destArray->allocatedSize	= (newSize * elementByteSize); 
	destArray->elementCount		= (destArray->allocatedSize);

	return destArray->elementCount;
}