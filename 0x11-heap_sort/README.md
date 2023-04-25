# 0x11. Heap Sort

For this project you are given the following print_array function:

    ```c
    #include <stdlib.h>
    #include <stdio.h>

    /**
    * print_array - Prints an array of integers
    *
    * @array: The array to be printed
    * @size: Number of elements in @array
    */

    void print_array(const int *array, size_t size)
    {
        size_t i;

        i = 0;
        while (array && i < size)
        {
            if (i > 0)
                printf(", ");
            printf("%d", array[i]);
            ++i;
        }
        printf("\n");
    }
    ```

- Our files print_array.c and print_array.h will be compiled with your functions during the correction.
- Please declare the prototype of the function print_array in your sort.h header file

Please, note this format is used for Task questions.

- O(1)
- O(n)
- O(n!)
- n square -> O(n^2)
- log(n) -> O(log(n))
- n \* log(n) -> O(nlog(n))
- …

Please use the “short” notation (don’t use constants). Example: O(nk) or O(wn) should be written O(n). If an answer is required within a file, all your answers files must have an empty line at the end.
