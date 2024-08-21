#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Solution 1 \n\n");

    //user input for array elements
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    int arr[size];
    for (int i = 0; i < size; i+=1) {
        printf("Enter the element at index %d: ", i);
        scanf("%d", &arr[i]);
    }

    //finding the min and max in the given array to calc max - min
    if (size == 0) printf("The given array has no element\n");
    else {
      int min = arr[0], max = arr[0];
      for (int i = 1; i < size; i += 1)
      {
        min = (arr[i] < min) ? arr[i] : min;
        max = (arr[i] > max) ? arr[i] : max;
      }
      printf("Differenece between largest and smalleset value: %d\n", max - min);
    }

    //array with 10 random numbers
    printf("\n\nSolution 2\n\n");

    int tenRandom[10];
    for (int i = 0; i < 10; i+=1) tenRandom[i] = rand();

    //printing
    printf("1) Every element at even index: ");
    for (int i = 0; i < 10; i+=2) printf("%d\t", tenRandom[i]);
    printf("\n");

    printf("2) Every element at odd index: ");
    for (int i = 1; i < 10; i+=2) printf("%d\t", tenRandom[i]);
    printf("\n");

    printf("3) Every element in reverse order: ");
    for (int i = 0; i < 10; i+=1) printf("%d \t", tenRandom[9-i]);
    printf("\n");

    printf("4) First element: %d  and Last element: %d\n", tenRandom[0], tenRandom[9]);



    printf("\n\nSolution 3\n\n");

    //user input
    int a[5];
    for (int i = 0; i < 5; i++) {
      printf("Enter element at index %d: ", i);
      scanf("%d", &a[i]);
    }

    int sum = 0, sumEven = 0, sumOdd = 0;
    for (int i = 0; i < 5; i+=1) sum += a[i];
    for (int i = 0; i < 5; i+=2) sumEven += a[i];
    for (int i = 1; i < 5; i+=2) sumOdd += a[i];

    printf("Sum of all elements: %d\n", sum);
    printf("Sum of elements at even index: %d\n", sumEven);
    printf("Sum of elements at odd index: %d\n", sumOdd);

    int highest = a[0], secondHighest = a[0];
    for (int i = 1; i < 5; i+=1) {
      secondHighest = (a[i] > secondHighest) ? a[i] : secondHighest;

      if (a[i] > highest)
      {
        secondHighest = highest;
        highest = a[i];
      }
    }
    if (highest == secondHighest) printf("There is no second highest element, highest element: %d\n", highest);
    else printf("The second highest element is: %d\n", secondHighest);
}
