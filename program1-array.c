#include <stdio.h>
#include <stdlib.h>
#define REP(i,init,condition,incriment) for (int i = init; i < condition; i+=incriment)

int maxInt(int a, int b) { return (a > b) ? a : b;}

int main() {
    printf("Solution 1 \n\n");

    //user input for array elements
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    int arr[size];
    REP(i,0,size,1) {
        printf("Enter the element at index %d: ", i);
        scanf("%d", &arr[i]);
    }

    //finding the min and max in the given array to calc max - min
    if (size == 0) printf("The given array has no element, largest and smallest element don't exitst\n");
    else {
        int min = arr[0], max = arr[0];
        REP(i, 1, size, 1) {
            min = (arr[i] < min) ? arr[i] : min;
            max = maxInt(max, arr[i]);
        }
        printf("Differenece between largest and smalleset value: %d\n", max - min);
    }

    printf("\n\nSolution 2\n\n");

    //array with 10 random numbers
    int tenRandom[10];
    REP(i,0,10,1) tenRandom[i] = rand();

    //printing
    printf("1) Every element at even index: ");
    REP(i,0,10,2) printf("%d\t", tenRandom[i]);
    printf("\n");

    printf("2) Every element at odd index: ");
    REP(i,1,10,2) printf("%d\t", tenRandom[i]);
    printf("\n");
    
    printf("3) Every element in reverse order: ");
    REP(i,0,10,1) printf("%d \t", tenRandom[9-i]);
    printf("\n");

    printf("4) First element: %d  and Last element: %d\n", tenRandom[0], tenRandom[9]);


    
    printf("\n\nSolution 3\n\n");

    //uset input 
    int a[5];
    REP(i,0,5,1) {
        printf("Enter the element at index %d", i);
        scanf("%d", &a[i]);
    }

    int sum = 0, sumEven = 0, sumOdd = 0;
    REP(i,0,5,1) sum += a[i];
    REP(i,0,5,2) sumEven += a[i];
    REP(i,1,5,2) sumOdd += a[i];

    printf("Sum of all elements: %d\n", sum);
    printf("Sum of elements at even index: %d\n", sumEven);
    printf("Sum of elements at odd index: %d\n", sumOdd);

    int highest = a[0], secondHighest = a[0];
    REP(i,1,5,1) {
        secondHighest = maxInt(secondHighest, a[i]);

        if (a[i] > highest) {
            secondHighest = highest;
            highest = a[i];
        }
    }
    if (highest == secondHighest) printf("There is no second highest element, highest element: %d\n", highest);
    else printf("The second highest element is: %d\n", secondHighest);
}