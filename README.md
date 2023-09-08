# Dynamic Array Library

The Dynamic Array Library is a C library that provides a dynamic array data structure, allowing you to work with resizable arrays in your C projects. It offers simple and intuitive functions to manage dynamic arrays efficiently.

## Features

- Dynamically resizable array data structure.
- Efficient insertion, removal, and replacement of elements.
- Ability to access elements by index.
- Automatic memory management for dynamic resizing.
- Simple initialization and freeing of dynamic arrays.

## Getting Started

To use the Dynamic Array Library in your project, follow these steps:

1. **Clone the Repository:** Clone this repository to your local machine.

2. **Include the Library:** Copy the `dynamicarray.h` and `dynamicarray.c` files from the `src` directory into your project directory.

3. **Compile:** Compile with `make` command to get output on build directory.

4. **Use the Library:** Include the `dynamicarray.h` header in your source files where you want to use the library's functionality. See the library's functions and documentation to understand how to work with dynamic arrays.

## Usage Example

Here's a simple example of using the Dynamic Array Library to create a resizable array of integers:

```c
#include "dynamicarray.h"

int main() {
    daArray intArray = {};    // Make sure to zero-initialize all daArray objects for consistent behavior.
    daInit(&intArray, 10, sizeof(int), true); // Initialize with 10 elements, each sizeof(int) bytes.

    int value = 42;
    daPushBack(&intArray, &value);

    int retrievedValue = *(int*)daGet(&intArray, 0);
    printf("Retrieved value: %d\n", retrievedValue);

    daFree(&intArray); // Free the dynamic array's memory.

    return 0;
}
```

## Documentation

For detailed information about the library's functions, parameters, and usage, refer to the [header file](./src/dynamicarray.h).

## Contributing

Contributions are welcome! If you find any issues or have suggestions for improvements, please create a GitHub issue or submit a pull request.


---

Happy coding with the Dynamic Array Library! If you have any questions or feedback, don't hesitate to get in touch.
