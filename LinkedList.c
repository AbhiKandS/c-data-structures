#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct node {
    int data;
    struct node* next;
} node;

typedef struct linkedList {
    node* first;
    node* last;
    int size;
} linkedList;

linkedList* newLinkedList() {
    linkedList* newList = malloc(sizeof(linkedList));
    if (newList == NULL) //to-do free()

    newList->first = NULL;
    newList->last = NULL;
    newList->size = 0;

    return newList;
}

void listPushBack(linkedList* list, int newData) {
    node* newNode = malloc(sizeof(node));
    newNode->data = newData;

    if (list->first == NULL) {
        list->first = newNode;
        list->last = newNode;
    }
    else {
        list->last->next = newNode;
        list->last = newNode;
    }

    list->size++;
}

void listPushFront(linkedList* list, int newData) {
    node* newNode = malloc(sizeof(node));
    newNode->data = newData;

    if (list->first == NULL) {
        list->first = newNode;
        list->last = newNode;
    }
    else {
        newNode->next = list->first;
        list->first = newNode;
    }

    list->size++;
}

void listPrint(linkedList* list) {
    node* ptr = list->first;
    while (ptr != NULL) {
        printf("%d\t", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

int listPopBack(linkedList* list) {
    if (list->last == NULL) return INT_MIN;

    else if (list->first == list->last) {
        int result = list->last->data;

        free(list->last);
        list->first = NULL;
        list->last = NULL;

        return result;
    }
    else {
        int result = list->last->data;

        node* ptr = list->first;
        while (ptr->next != list->last) {
            ptr = ptr->next;
        }
        free(list->last);
        list->last = ptr;
        list->last->next = NULL;

        return result;
    }

}

int listPopFront(linkedList* list) {
    if (list->first == NULL) return INT_MIN;

    else if (list->first == list->last) {
        int result = list->first->data;

        free(list->first);
        list->first = NULL;
        list->last = NULL;

        return result;
    }

    else {
        int result = list->first->data;

        node* ptr = list->first->next;
        free(list->first);
        list->first = ptr;

        return result;
    }
}

int main() {
    linkedList* list1 = newLinkedList();

    for (int i = 0; i < 5; i++) {
        listPushFront(list1, i);
    }

    listPrint(list1);
    printf("%d\n", listPopFront(list1));
    listPrint(list1);

    free(list1);
    return 0;
}