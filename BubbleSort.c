#include <stdio.h>

void bubble_sort(int *a, int size)
{
    int n = size;
    for (int i = 0; i < n-1; i++)
    {
        for (int j = 0; j < n-1-i; j++)
        {
            if (a[j] > a[j+1]) {
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
        
    }
}

int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    int a[size];
    
    printf("Enter %d elements seperated by spaces:\n", size);
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &a[i]);
    }

    bubble_sort(a, 5);

    printf("Sorted array: ")
    for (int i = 0; i < size; i++)
    {
        printf("%d ", a[i]);
    }
}