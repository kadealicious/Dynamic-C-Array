#ifndef DYNAMICARRAY_COMBO_H_
#define DYNAMICARRAY_COMBO_H_

#include"da.h"


/**
 * @brief Split srcArray by the specified bounds and store in destArray.
 *
 * @param destArray The destination array.
 * @param arcArray The source array.
 * @param indexLow The lower bound (inclusive) to include in the new array.
 * @param indexHigh The upper bound (inclusive) to include in the new array.
 * 
 * @return New size of resulting array if successful, DA_INVALID_ARRAY or DA_ERROR (both equal to SIZE_MAX) if unsuccessful.
 * 
 * @warning destArray must be uninitialized if it is not the same array as srcArray.  Otherwise, you might crash.  Better than the alternative of leaking memory!
 */
size_t daSplit(daArray* destArray, daArray* srcArray, size_t indexLow, size_t indexHigh);

/**
 * @brief Append array1 to the end of array0.
 *
 * @param destArray The destination array.
 * @param array0 The array to be appended to.
 * @param array1 The array to append.
 * 
 * @return New size of resulting array if successful, DA_INVALID_ARRAY (equal to SIZE_MAX) if unsuccessful.
 * 
 * @note If &destArray != &array0 and destArray is not empty, then the final result will be destArray + array0 + array1.
 */
size_t daAppend(daArray* destArray, daArray* array0, daArray* array1);


/**
 * @brief Duplicate the contents of srcArray into destArray, erasing any data previously held in destArray.
 *
 * @param destArray The destination array.
 * @param srcArray The source array.
 * 
 * @return True if the duplication was a success, DA_INVALID_ARRAY (equal to SIZE_MAX) if unsuccessful.
 * 
 * @warning destArray must be uninitialized if it is not the same array as srcArray.
 */
bool daDuplicate(daArray* destArray, daArray* srcArray);


#endif