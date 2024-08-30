#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define LAST (list->last)
#define FIRST (list->first)
#define SIZE (list->size)


typedef struct dnode {
    int data;
    struct dnode* next;
    struct dnode* prev;
} dnode;

typedef struct dlist
{
    dnode* first;
    dnode* last;
    int size;
} dlist;


dnode* new_dnode(int data) {
    dnode* new = (dnode*)malloc(sizeof(dnode));
    new->prev = NULL; 
    new->next = NULL;
    new->data = data;
    return new;
}

dlist* new_dlist() {
    dlist* new = (dlist*)malloc(sizeof(dlist));
    new->first = NULL;
    new->last = NULL;
    new->size = 0;
    return new;
}

void push_back_dlist(dlist* list, int data) {
    dnode* new = new_dnode(data);

    if (!FIRST) {
        FIRST = new;
        LAST = new;
    }
    else {
        new->prev = LAST;
        LAST->next = new;
        LAST = new;
    }
    SIZE++;
}

void push_front_dlist(dlist* list, int data) {
    dnode* new = new_dnode(data);
    if (!FIRST) {
        FIRST = NULL;
        LAST = NULL;
    }
    else {
        FIRST->prev = new;
        new->next = FIRST;
        FIRST = new;
    }
    SIZE++;
}

void push_at_position(dlist* list, int data, int pos) {
    if (pos < 0 || SIZE+1 < pos) {
        printf("Invalid position");
    }
    else if (pos == 1) push_front_dlist(list, data);
    else if (pos == SIZE+1) push_back_dlist(list, data);
    else {
        dnode* new = new_dnode(data);
        dnode* prev = FIRST;
        for (int i = 1; i < pos-1; i++) {
            prev = prev->next;
        }
        new->next = prev->next;
        new->prev = prev;
        prev->next = new;
        new->next->prev = new;
        SIZE++;
    }
}

dlist* initialize_dlist() {
    dlist* list = new_dlist();
    int s, data;
    printf("Enter size: ");
    scanf("%d", &s);

    printf("Enter data: ");
    for (int i = 0; i < s; i++) {
        scanf("%d", &data);
        push_back_dlist(list, data);
    }
    return list;
}

void print_dlist(dlist* list){
    dnode* current = FIRST;
    while(current) {
        printf("%d\t", current->data);
        current = current->next;
    }
    printf("\n");
}

void del_back_front(dlist* list, bool back) {
    if (!FIRST) {
        printf("List is emtpy");
        return;
    }
    else if (back) {
        LAST = LAST->prev;
        free((void*)LAST->next);
        LAST->next = NULL;
    }
    else {
        FIRST = FIRST->next;
        free((void*)FIRST->prev);
        FIRST->prev = NULL;
    }
    SIZE--;
}

void del_at_pos(dlist* list, int pos) {
    if (pos < 0 || SIZE+1 < pos) {
        printf("Invalid position");
        return;
    }
    else if (pos == 1) del_back_front(list, 0);
    else if (pos == SIZE) del_back_front(list, 1);
    else {
        dnode *next, *prev = FIRST;
        for (int i = 1; i < pos-1; i++) {
            prev = prev->next;
        }
        next = prev->next->next;
        free((void*)prev->next);
        prev->next = next;
        next->prev = prev;
        SIZE--;
    }
}

int main() {
    dlist* list1 = initialize_dlist();

    int a, b, pos;
    printf("Enter the numbers to push at beg and end: ");
    scanf("%d %d: ", &a, &b);
    push_back_dlist(list1, b);
    push_front_dlist(list1, a);

    printf("Enter the position and number to be inserted (the size of the list is %d): ", list1->size);
    scanf("%d %d", &pos, &a);
    push_at_position(list1, a, pos);

    printf("\nList after all the insertions: ");
    print_dlist(list1);
    printf("\n");

    printf("Enter the position to be deleted(size of the list is %d): ", list1->size);
    scanf("%d", &pos);
    del_at_pos(list1, pos);
    del_back_front(list1, 0);
    del_back_front(list1, 1);

    printf("\nList after all deletions (position, back and front): ");
    print_dlist(list1);

    return 0;
}