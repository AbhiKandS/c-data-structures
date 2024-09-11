#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define HEAD (clist->head)
#define LAST (clist->last)
#define COUNT (clist->count)

typedef struct cnode
{
    int data;
    struct cnode* next;
} cnode;

typedef struct clist
{
    int count;
    cnode* head;
    cnode* last;
} clist;

int get_int(char prompt[]) {
    int result;
    printf("%s", prompt);
    scanf("%d", &result);
    return result;
}

cnode* new_cnode(int data) {
    cnode* new = (cnode*)malloc(sizeof(cnode));
    new->data = data;
    new->next = NULL;
    return new;
}

clist* new_clist() {
    clist* clist = (struct clist*)malloc(sizeof(clist));
    HEAD = NULL;
    LAST = NULL;
    COUNT = 0;
    return clist;
}

void insert_at_beg_end(clist* clist, int data, bool atBegin) {
    cnode *new = new_cnode(data);
    if (!HEAD) {
        HEAD = new;
        LAST = new;
        new->next = new;
    }
    else  {
        new->next = HEAD;
        (LAST)->next = new;
        if (atBegin) HEAD = new;
        else LAST = new;
    }
    COUNT++;
}

void insert_at_position(clist* clist, int data, int pos) {
    if (pos < 1 || COUNT+1 < pos) {
        printf("invalid position\n");
        return;
    }
    if (pos == 1) return insert_at_beg_end(clist, data, 1);
    if (pos == COUNT+1) return insert_at_beg_end(clist, data, 0);

    cnode* new = new_cnode(data);
    cnode* temp = HEAD;
    for (int i = 1; i < pos-1; i++) {
        temp = temp->next;
    }
    new->next = temp->next;
    temp->next = new;

    COUNT++;
}

void print_clist(clist* clist) {
    if (!HEAD) {
        printf("Empty List\n");
        return;
    }

    cnode* i = HEAD;
    do {
        printf("%d ", i->data);
        i = i->next;
    }while (i != HEAD);
    printf("\n");
}

void del_at_beg_end(clist* clist, bool atBegin) {
    if (!HEAD) {
        printf("Empty list\n");
        return;
    }
    else if (HEAD == LAST) {
        free(HEAD);
        HEAD = LAST = NULL;
    }
    else if (atBegin) {
        HEAD = HEAD->next;
        free(LAST->next);
        LAST->next = HEAD;
    }
    else {
        cnode* temp = HEAD;
        while (temp->next != LAST) {
            temp = temp->next;
        }
        free(LAST);
        temp->next = HEAD;
        LAST = temp;
    }
    COUNT--;
}

void del_at_position(clist* clist, int pos) {
    if (pos < 1 || COUNT+1 < pos) {
        printf("Invalid position\n");
        return;
    }
    if (pos == 1) return del_at_beg_end(clist, 1);
    if (pos == COUNT+1) return del_at_beg_end(clist, 0);

    cnode* deletionNode;
    cnode* temp = HEAD;
    for (int i = 1; i < pos-1; i++) {
        temp = temp->next;
    }
    deletionNode = temp->next;
    temp->next = deletionNode->next;
    free(deletionNode);

    COUNT--;
}

clist* initialize_clist() {
    clist* clist = new_clist();
    int size = get_int("Size of list: ");
    printf("Enter %d numbers seperated by spaces: \n", size);
    int x;
    for (int i = 0; i < size; i++) {
        scanf("%d", &x);
        insert_at_beg_end(clist, x, 0);
    }
    return clist;
}

int main() {
    clist* clist1 = initialize_clist();
    printf("List: ");
    print_clist(clist1);

    int a = get_int("Insert at begining: ");
    int b = get_int("Insert at end: ");
    insert_at_beg_end(clist1, a, 1);
    insert_at_beg_end(clist1, b, 0);
    a = get_int("position to insert: ");
    b = get_int("element to insert: ");
    insert_at_position(clist1, b, a);
    printf("List: ");
    print_clist(clist1);


    del_at_beg_end(clist1, 1);
    printf("List after deletion at begining: ");
    print_clist(clist1);
    del_at_beg_end(clist1, 0);
    printf("List after deletion at end: ");
    print_clist(clist1);

    int x = get_int("Enter position to delete: ");
    del_at_position(clist1, x);
    print_clist(clist1);

    return 0;
}