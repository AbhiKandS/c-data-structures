#include <stdio.h>

int binary_search(int arr[], int left, int right, int num)
{

    if (left > right)
        return -1;
    int mid = left + (right - left) / 2;

    if (arr[mid] == num)
        return mid;

    if (arr[mid] > num)
        return binary_search(arr, left, mid - 1, num);

    return binary_search(arr, mid + 1, right, num);
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
    int search_Idx = binary_search(a, 0, size - 1, num);
    if (search_Idx == -1)
        printf("number not found!\n");
    else
        printf("number found at index %d\n", search_Idx);
}