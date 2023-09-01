#include<stdio.h>
#include<stdint.h>
#include"da.h"
#include"daprint.h"
#include"dasort.h"


/**
 * @brief Main function.
 *
 * @return Returns 0 to indicate successful execution.
 */
int main()
{
	daArray testArray;
	daInit(&testArray, 4, sizeof(uint32_t), true);

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
	daPrintUint32(&testArray);
	getchar();

	// Push a subset of elements[] to our dynamic array.
	printf("daPushBack(): \n");
	for(uint8_t i = 0; i < 9; i++)
	{
		daPushBack(&testArray, &elements[i]);
	}
	daPrintUint32(&testArray);
	getchar();

	//Insert a test value to array and then print it.
	printf("daInsert(100203, 2): \n");
	uint32_t testElement = 100203;
	daInsert(&testArray, &testElement, 2);

	// Test element swapping.
	printf("daSwap(3, 6): \n");
	daSwap(&testArray, 3, 6);

	//Remove fourth element and print it.
	printf("daRemove(3): \n");
	daRemove(&testArray, 3);

	//Print fifth element using daGet().
	printf("daGet(5): %i\n", *(uint32_t*)daGet(&testArray, 5));

	//Replace test element and print.
	printf("daReplace(100203, 900): \n");
	daReplace(&testArray, &testElement, 900);
	daPrintUint32(&testArray);
	getchar();

	//Test scramble!
	printf("daScramble(): \n");
	daScramble(&testArray, 0, daGetFinalElementIndex(&testArray));
	daPrintUint32(&testArray);
	getchar();

	//Test quick sort!
	printf("daQuickSort(): \n");
	daQuickSort(&testArray, 0, daGetFinalElementIndex(&testArray));
	daPrintUint32(&testArray);
	getchar();

	// Test binary search!
	uint32_t one = 1, two = 2, seventeen = 17, fourtyFive = 45;
	printf("daBinarySearch(1): %llu\n", daBinarySearch(&testArray, &one, 0, daGetFinalElementIndex(&testArray)));
	printf("daBinarySearch(2): %llu\n", daBinarySearch(&testArray, &two, 0, daGetFinalElementIndex(&testArray)));
	printf("daBinarySearch(17): %llu\n", daBinarySearch(&testArray, &seventeen, 0, daGetFinalElementIndex(&testArray)));
	printf("daBinarySearch(45): %llu\n", daBinarySearch(&testArray, &fourtyFive, 0, daGetFinalElementIndex(&testArray)));
	printf("daBinarySearch(100203): %llu\n", daBinarySearch(&testArray, &testElement, 0, daGetFinalElementIndex(&testArray)));
	getchar();

	//Test insertion sort!
	printf("daScramble() + daInsertionSort(2, finalElementIndex - 2): \n");
	daScramble(&testArray, 0, daGetFinalElementIndex(&testArray));
	daInsertionSort(&testArray, 2, daGetFinalElementIndex(&testArray) - 2);
	daPrintUint32(&testArray);
	getchar();

	//Test heap sort!
	printf("daScramble() + daHeapSort(1, finalElementIndex - 1)\n");
	daScramble(&testArray, 0, daGetFinalElementIndex(&testArray));
	daPrintUint32(&testArray);
	daHeapSort(&testArray, 1, daGetFinalElementIndex(&testArray) - 1);
	daPrintUint32(&testArray);
	getchar();

	return 0;
}