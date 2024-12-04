#include <stdio.h>

void insertion_sort(int arr[], int len)
{
    int curr;
    for (int i = 1; i < len; i++)
    {
        curr = arr[i];
        int pos = i;
        while (pos > 0 && arr[pos - 1] > curr)
            pos--;

        for (int k = i; k > pos; k--)
            arr[k] = arr[k - 1];

        arr[pos] = curr;
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

    insertion_sort(a, size);
    printf("Insertion Sorted array: ");
    print_array(a, size);
}