#include <stdio.h>

int linear_search(int arr[], int len, int num)
{
    for (int i = 0; i < len; i++)
    {
        if (num == arr[i])
            return i;
    }
    return -1;
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

    int num;
    printf("Enter the number to search: ");
    scanf("%d", &num);

    int search_Idx = linear_search(a, size, num);
    if (search_Idx == -1)
        printf("number not found!\n");
    else
        printf("number found at index %d\n", search_Idx);
}