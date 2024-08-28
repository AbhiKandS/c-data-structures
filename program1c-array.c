#include <stdio.h>

int main() {
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