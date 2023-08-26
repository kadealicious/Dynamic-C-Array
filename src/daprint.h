#ifndef DYNAMICARRAY_PRINT_H_
#define DYNAMICARRAY_PRINT_H_

#include"da.h"


/**
 * @brief Print the elements of the dynamic array.
 *
 * @param array The dynamic array.
 */
void daPrintArrayMetadata(daArray* array);

void daPrintUint64(daArray* array);
void daPrintUint32(daArray* array);
void daPrintUint16(daArray* array);
void daPrintUint8(daArray* array);

void daPrintInt64(daArray* array);
void daPrintInt32(daArray* array);
void daPrintInt16(daArray* array);
void daPrintInt8(daArray* array);

void daPrintFloat(daArray* array);
void daPrintDouble(daArray* array);
void daPrintChar(daArray* array);


#endif