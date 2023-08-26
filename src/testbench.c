#include<stdio.h>
#include<stdint.h>
#include"dynamicarray.h"



/**
 * @brief Main function.
 *
 * @return Returns 0 to indicate successful execution.
 */
int main()
{
	daArray testArray;
	daInit(&testArray, 4, sizeof(uint32_t), true);

	// Elements that will be stored 
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

	// Push elements from 0 to 7 (not 8) to our array
	for(uint8_t i = 0; i < 8; i++)
	{
		daPushBack(&testArray, &elements[i]); // Main push function
		daPrintUint32(&testArray); // Print elements in array
		getchar(); // Get a keypress from user
	}

	//Insert a test value to array and then print it
	uint32_t testElement = 100203;
	daInsert(&testArray, &testElement, 2);
	daPrintUint32(&testArray); 
	getchar(); // Get a keypress from user

	//Remove fourth (indexing starts from 0) element and print it 
	daRemove(&testArray, 3);
	daPrintUint32(&testArray);
	getchar(); // Get a keypress from user

	//Print fifth element
	printf("daGet(5): %i\n", *(uint32_t*)daGet(&testArray, 5));
	getchar(); // Get a keypress from user

	//Replace test element (100203) to 900 and print the elements
	daReplace(&testArray, &testElement, 900);
	daPrintUint32(&testArray);
	getchar(); // Get a keypress from user

	return 0; // Exit successfully
}