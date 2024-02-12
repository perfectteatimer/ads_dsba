#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, number;
    scanf("%d", &n);

    // Since we can't use vector, we'll have to allocate an array dynamically.
    // Assuming the worst case where all numbers are even, we allocate space for n integers.
    int *arr = (int *) malloc(n * sizeof(int));
    if (arr == NULL)
    {
        // Handle memory allocation failure
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    int count = 0; // To keep track of how many even numbers are inserted

    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &number);
        if (number % 2 == 0)
        {
            arr[count] = number;
            count++;
        }
    }

    // Print the even numbers in reverse order
    for (int i = count - 1; i >= 0; --i)
    {
        printf("%d\n", arr[i]);
    }

    // Free the allocated memory
    free(arr);

    return 0;
}
