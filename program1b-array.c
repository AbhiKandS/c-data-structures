#include <stdio.h>
#include <stdlib.h>

int main() {
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
}