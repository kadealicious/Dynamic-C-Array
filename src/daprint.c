#include<stdio.h>
#include<stdint.h>
#include"daprint.h"


/**
 * @brief Print the elements of the dynamic array.
 *
 * @param array The dynamic array.
 */
void daPrintArrayMetadata(daArray* array)
{
	printf("Allocated: %llu elements/%llub, Element Size: %llub, Element Count: %llu\n", 
			array->allocatedSize, (array->allocatedSize * array->elementByteSize), 
			array->elementByteSize, array->elementCount);
}
void daPrintUint64(daArray* array)
{
	daPrintArrayMetadata(array);
	
	for(size_t i = 0; i < array->allocatedSize; i++)
	{
		uint64_t* data = (uint64_t*)array->data;
		if(i < array->elementCount)
			{printf(" <o> ");}
		else {printf(" < > ");}
		printf("%llu\n", (uint64_t)(data[i]));
	}
}
void daPrintUint32(daArray* array)
{
	daPrintArrayMetadata(array);
	
	for(size_t i = 0; i < array->allocatedSize; i++)
	{
		uint32_t* data = (uint32_t*)array->data;
		if(i < array->elementCount)
			{printf(" <o> ");}
		else {printf(" < > ");}
		printf("%i\n", (uint32_t)(data[i]));
	}
}
void daPrintUint16(daArray* array)
{
	daPrintArrayMetadata(array);
	
	for(size_t i = 0; i < array->allocatedSize; i++)
	{
		uint16_t* data = (uint16_t*)array->data;
		if(i < array->elementCount)
			{printf(" <o> ");}
		else {printf(" < > ");}
		printf("%i\n", (uint16_t)(data[i]));
	}
}
void daPrintUint8(daArray* array)
{
	daPrintArrayMetadata(array);
	
	for(size_t i = 0; i < array->allocatedSize; i++)
	{
		uint8_t* data = (uint8_t*)array->data;
		if(i < array->elementCount)
			{printf(" <o> ");}
		else {printf(" < > ");}
		printf("%i\n", (uint8_t)(data[i]));
	}
}

void daPrintInt64(daArray* array)
{
	daPrintArrayMetadata(array);
	
	for(size_t i = 0; i < array->allocatedSize; i++)
	{
		int64_t* data = (int64_t*)array->data;
		if(i < array->elementCount)
			{printf(" <o> ");}
		else {printf(" < > ");}
		printf("%lli\n", (int64_t)(data[i]));
	}
}
void daPrintInt32(daArray* array)
{
	daPrintArrayMetadata(array);
	
	for(size_t i = 0; i < array->allocatedSize; i++)
	{
		int32_t* data = (int32_t*)array->data;
		if(i < array->elementCount)
			{printf(" <o> ");}
		else {printf(" < > ");}
		printf("%i\n", (int32_t)(data[i]));
	}
}
void daPrintInt16(daArray* array)
{
	daPrintArrayMetadata(array);
	
	for(size_t i = 0; i < array->allocatedSize; i++)
	{
		int16_t* data = (int16_t*)array->data;
		if(i < array->elementCount)
			{printf(" <o> ");}
		else {printf(" < > ");}
		printf("%i\n", (int16_t)(data[i]));
	}
}
void daPrintInt8(daArray* array)
{
	daPrintArrayMetadata(array);
	
	for(size_t i = 0; i < array->allocatedSize; i++)
	{
		int8_t* data = (int8_t*)array->data;
		if(i < array->elementCount)
			{printf(" <o> ");}
		else {printf(" < > ");}
		printf("%i\n", (int8_t)(data[i]));
	}
}

void daPrintFloat(daArray* array)
{
	daPrintArrayMetadata(array);
	
	for(size_t i = 0; i < array->allocatedSize; i++)
	{
		float* data = (float*)array->data;
		if(i < array->elementCount)
			{printf(" <o> ");}
		else {printf(" < > ");}
		printf("%f\n", (float)(data[i]));
	}
}
void daPrintDouble(daArray* array)
{
	daPrintArrayMetadata(array);
	
	for(size_t i = 0; i < array->allocatedSize; i++)
	{
		double* data = (double*)array->data;
		if(i < array->elementCount)
			{printf(" <o> ");}
		else {printf(" < > ");}
		printf("%f\n", (double)(data[i]));
	}
}
void daPrintChar(daArray* array)
{
	daPrintArrayMetadata(array);
	
	for(size_t i = 0; i < array->allocatedSize; i++)
	{
		char* data = (char*)array->data;
		if(i < array->elementCount)
			{printf(" <o> ");}
		else {printf(" < > ");}
		printf("%c\n", (char)(data[i]));
	}
}