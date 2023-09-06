#include<stdio.h>
#include<stdint.h>
#include"da.h"
#include"daprint.h"
#include"dasort.h"
#include"dacombo.h"


void TestBasicFunctionality(daArray* array);
void TestSortsAndSearches(daArray* array);
void TestCombos(daArray* array0, daArray* array1, daArray* array2);


/**
 * @brief Main function.
 *
 * @return Returns 0 to indicate successful execution.
 */
int main()
{
	daArray testArray	= {};
	daArray a0 			= {};
	daArray a1			= {};
	daInit(&testArray, 4, sizeof(uint32_t), true);
	daInit(&a0, 17, sizeof(uint32_t), false);
	daInit(&a1, 6, sizeof(uint32_t), true);

	TestBasicFunctionality(&testArray);
	// TestSortsAndSearches(&testArray);
	TestCombos(&testArray, &a0, &a1);

	return 0;
}

void TestBasicFunctionality(daArray* array)
{
	// Test element list.
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

	printf("Initial array: \n");
	daPrintUint32(array);
	getchar();

	// Push a subset of elements[] to our dynamic array.
	printf("daPushBack(): \n");
	for(uint8_t i = 0; i < 9; i++)
	{
		daPushBack(array, &elements[i]);
	}
	daPrintUint32(array);
	getchar();

	//Insert a test value to array and then print it.
	printf("daInsert(100203, 2): \n");
	uint32_t testElement = 100203;
	daInsert(array, &testElement, 2);

	// Test element swapping.
	printf("daSwap(3, 6): \n");
	daSwap(array, 3, 6);

	//Remove fourth element and print it.
	printf("daRemove(3): \n");
	daRemove(array, 3);

	//Print fifth element using daGet().
	printf("daGet(5): %i\n", *(uint32_t*)daGet(array, 5));

	//Replace test element and print.
	printf("daReplace(100203, 900): \n");
	daReplace(array, &testElement, 900);
	daPrintUint32(array);
	getchar();
}

void TestSortsAndSearches(daArray* array)
{
	//Test scramble!
	printf("daScramble(): \n");
	daScramble(array, 0, daGetFinalElementIndex(array));
	daPrintUint32(array);
	getchar();

	//Test quick sort!
	printf("daQuickSort(): \n");
	daQuickSort(array, 0, daGetFinalElementIndex(array));
	daPrintUint32(array);
	getchar();

	// Test binary search!
	uint32_t one = 1, two = 2, seventeen = 17, fourtyFive = 45, oneHundredOne = 101, testElement = 100203;
	printf("daBinarySearch(1): %llu\n", daBinarySearch(array, &one, 0, daGetFinalElementIndex(array)));
	printf("daBinarySearch(2): %llu\n", daBinarySearch(array, &two, 0, daGetFinalElementIndex(array)));
	printf("daBinarySearch(17): %llu\n", daBinarySearch(array, &seventeen, 0, daGetFinalElementIndex(array)));
	printf("daBinarySearch(45): %llu\n", daBinarySearch(array, &fourtyFive, 0, daGetFinalElementIndex(array)));
	printf("daBinarySearch(100203): %llu\n", daBinarySearch(array, &testElement, 0, daGetFinalElementIndex(array)));
	getchar();

	//Test insertion sort!
	printf("daScramble() + daInsertionSort(2, finalElementIndex - 2): \n");
	daScramble(array, 0, daGetFinalElementIndex(array));
	daInsertionSort(array, 2, daGetFinalElementIndex(array) - 2);
	daPrintUint32(array);
	getchar();

	//Test heap sort!
	printf("daScramble() + daHeapSort(1, finalElementIndex - 1)\n");
	daScramble(array, 0, daGetFinalElementIndex(array));
	daPrintUint32(array);
	daHeapSort(array, 1, daGetFinalElementIndex(array) - 3);
	daPrintUint32(array);
	getchar();

	// Test potentially invalid binary searches.
	printf("daBinarySearch(1, 1, finalElementIndex - 3): %llu\n", daBinarySearch(array, &one, 1, daGetFinalElementIndex(array) - 3));
	printf("daBinarySearch(2, 1, finalElementIndex - 3): %llu\n", daBinarySearch(array, &two, 1, daGetFinalElementIndex(array) - 3));
	printf("daBinarySearch(17, 1, finalElementIndex - 3): %llu\n", daBinarySearch(array, &seventeen, 1, daGetFinalElementIndex(array) - 3));
	printf("daBinarySearch(45, 1, finalElementIndex - 3): %llu\n", daBinarySearch(array, &fourtyFive, 1, daGetFinalElementIndex(array) - 3));
	printf("daBinarySearch(100203, 1, finalElementIndex - 3): %llu\n", daBinarySearch(array, &testElement, 1, daGetFinalElementIndex(array) - 3));
	printf("daBinarySearch(101, 1, finalElementIndex - 3): %llu\n", daBinarySearch(array, &oneHundredOne, 1, daGetFinalElementIndex(array) - 3));
}

void TestCombos(daArray* array0, daArray* array1, daArray* array2)
{
	// Test array splitting.
	printf("daSplit(2, 5): \n");
	daArray splitArray = {};
	daSplit(&splitArray, array0, 2, 5);
	daPrintUint32(&splitArray);
	getchar();

	uint32_t moreElements[] = 
	{
		10, 
		15, 
		3, 
		6, 
		8
	};
	for(size_t i = 0; i < 3; i++)
		{daPushBack(array1, &moreElements[i]);}
	for(size_t i = 1; i < 4; i++)
		{daPushBack(array2, &moreElements[i]);}

	// Test array appendation!
	printf("daAppend(): \n");
	daAppend(array0, array1, array2);
	daPrintUint32(array0);
	getchar();
}