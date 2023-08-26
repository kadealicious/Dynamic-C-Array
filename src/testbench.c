#include<stdio.h>
#include<stdint.h>
#include"da.h"
#include"daprint.h"



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

	// Push a subset of elements[] to our dynamic array.
	for(uint8_t i = 0; i < 8; i++)
	{
		daPushBack(&testArray, &elements[i]);
		daPrintUint32(&testArray);
		getchar();
	}

	//Insert a test value to array and then print it.
	uint32_t testElement = 100203;
	daInsert(&testArray, &testElement, 2);
	daPrintUint32(&testArray); 
	getchar();

	//Remove fourth element and print it.
	daRemove(&testArray, 3);
	daPrintUint32(&testArray);
	getchar();

	//Print fifth element using daGet().
	printf("daGet(5): %i\n", *(uint32_t*)daGet(&testArray, 5));
	getchar();

	//Replace test element and print.
	daReplace(&testArray, &testElement, 900);
	daPrintUint32(&testArray);
	getchar(); 

	return 0;
}