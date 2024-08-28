#include <stdio.h>

int main()
{
    // user input for array elements
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    int arr[size];
    for (int i = 0; i < size; i += 1)
    {
        printf("Enter the element at index %d: ", i);
        scanf("%d", &arr[i]);
    }

    // finding the min and max in the given array to calc max - min
    if (size == 0)
        printf("The given array has no element\n");
    else
    {
        int min = arr[0], max = arr[0];
        for (int i = 1; i < size; i += 1)
        {
            min = (arr[i] < min) ? arr[i] : min;
            max = (arr[i] > max) ? arr[i] : max;
        }
        printf("Differenece between largest(%d) and smalleset(%d) value: %d\n", max, min, max - min);
    }
}