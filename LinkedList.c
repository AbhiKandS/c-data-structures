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
    if (newList == NULL) return NULL;

    newList->first = NULL;
    newList->last = NULL;
    newList->size = 0;

    return newList;
}


//insertion functions
void listPushBack(linkedList* list, int newData) {
    node* newNode = malloc(sizeof(node));
    newNode->data = newData;

    if (list->first == NULL) {
        list->first = newNode;
        list->last = newNode;
        list->last->next = NULL;
    }
    else {
        list->last->next = newNode;
        list->last = newNode;
        list->last->next = NULL;
    }

    ++list->size;
}

void listPushFront(linkedList* list, int newData) {
    node* newNode = malloc(sizeof(node));
    newNode->data = newData;

    if (list->first == NULL) {
        list->first = newNode;
        list->last = newNode;
        list->last->next = NULL;
    }
    else {
        newNode->next = list->first;
        list->first = newNode;
    }

    ++list->size;
}

void listPushAtPosition(linkedList* list, int position, int newData) {
    if (position < 1 || list->size+1 < position){
        printf("invalid position\n");
        return;
    }
    if (position == list->size+1) return listPushBack(list, newData);
    if (position == 1) return listPushFront(list,newData);

    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = newData;
    node* ptr = list->first;
    for (int i = 1; i < position - 1; i++) ptr = ptr->next;
    newNode->next = ptr->next;
    ptr->next = newNode;

    ++list->size;
}

//print and free functions
void listPrint(linkedList* list) {

    node* ptr = list->first;
    while (ptr != NULL) {
        printf("%d\t", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}
void freeLinkedList(linkedList* list) {
    node* ptr = list->first;
    while (ptr != NULL) {
        node* temp = ptr;
        ptr = ptr->next;
        free(temp);
    }
    free(list);
}

//deletion functions
int listPopBack(linkedList* list) {
    if (list->last == NULL) return INT_MIN;

    else if (list->first == list->last) {
        int result = list->last->data;

        free(list->last);
        list->first = NULL;
        list->last = NULL;
        list->size--;

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
        list->size--;

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
        list->size--;


        return result;
    }

    else {
        int result = list->first->data;

        node* ptr = list->first->next;
        free(list->first);
        list->first = ptr;
        list->size--;

        return result;
    }
}

linkedList* initializeNewLinkedList() {
    int size;
    printf("Enter the size of the list: ");
    scanf("%d", &size);

    linkedList* newList = newLinkedList();
    printf("Enter elements of list seperated by space: ");
    for (int i = 0; i < size; i++) {
        int data;
        scanf("%d", &data);
        listPushBack(newList, data);
    }
    
    return newList;
}

int listPopAtPosition(linkedList* list, int position) {
    if (position < 1 || list->size < position) {
        printf("invalid position\n");
        return INT_MIN;
    }
    else if (position == list->size) return listPopBack(list);
    else if (position == 1) return listPopFront(list);
    else {
        node* ptr = list->first;
        for (int i = 1; i < position-1; i++) ptr = ptr->next;
        node* deletionNode = ptr->next;
        int result = deletionNode->data;
        ptr->next = deletionNode->next;

        free(deletionNode);
        list->size--;

        return result;
    }
}

int main() {
    linkedList* list1 = initializeNewLinkedList();

    int n, m, pos;
    printf("Enter the number to insert at begining and end: ");
    scanf("%d %d", &n, &m);
    listPushFront(list1, n);
    listPushBack(list1, m);

    printf("Enter the position and number to be inserted(the size of the list is %d): ", list1->size);
    scanf("%d %d", &pos, &n);
    listPushAtPosition(list1, pos, n);

    printf("\n");
    printf("List after all insertions: \n");
    listPrint(list1);
    printf("\n");

    //deletion operations
    printf("List after deletion of first and last element: \n");
    listPopBack(list1);
    listPopFront(list1);
    listPrint(list1);
    printf("\n");

    printf("Enter the position to delete from list(size of list is %d): ", list1->size);
    scanf("%d", &pos);
    listPopAtPosition(list1, pos);
    listPrint(list1);



    freeLinkedList(list1);
    return 0;
}