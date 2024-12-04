#include <stdio.h>

void selection_sort(int arr[], int len)
{
    for (int i = 0; i < len - 1; i++)
    {
        int min_idx = i;
        for (int j = i + 1; j < len; j++)
        {
            if (arr[j] < arr[min_idx])
            {
                min_idx = j;
            }
        }

        if (min_idx != i)
        {
            int temp = arr[i];
            arr[i] = arr[min_idx];
            arr[min_idx] = temp;
        }
    }
}

void print_array(int a[], int len)
{
    for (int i = 0; i < len; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main()
{
    int size;
    printf("Enter size of array: ");
    scanf("%d", &size);
    printf("Enter %d elements seperated by space: ", size);
    int a[size];
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &a[i]);
    }

    selection_sort(a, size);
    printf("selection Sorted array: ");
    print_array(a, size);
}