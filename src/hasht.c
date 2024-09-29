#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdarg.h>

#define I(obj, method, ...) (obj.method((&obj), __VA_ARGS__))

static struct hnode
{
    char* key;
    char* obj;
    struct hnode* next;
} hnode;

typedef struct hasht
{
    int size;
    struct hnode **list;
    struct hasht (*new)(int size);
    bool (*insert)(struct hasht*, char*, char*);
    char* (*lookup)(struct hasht*, char*);
} hasht;

    // hash should be at top
    int hash(char* key) {
        int hash = 7;
        for (int i = 0; key[i]; i++)
        {
            hash += key[i] + 31;
        }
        return hash;
    }
    static struct hnode* new_hnode(char* key, char* obj)
    {
        struct hnode *new = (struct hnode *)malloc(sizeof(struct hnode));
        new->key = key;
        new->obj = obj;
        new->next = NULL;
        return new;
    }
    // todo: add for updating inside this only
    static bool hasht_insert(hasht* ht, char* key, char* obj) {
        if (!key) return false;
        int index = hash(key) % ht->size;

        // updating
        struct hnode* temp = ht->list[index];
        while(temp) {
            if (!strcmp(temp->obj, obj))
            {
                free(temp->obj);
                temp->obj = obj;
                return true;
            }
            temp = temp->next;
        } 

        //inserting
        struct hnode* new = (struct hnode*)malloc(sizeof(struct hnode));
        if (!new) return false;
        new->key = key;
        new->obj = obj;
        new->next = ht->list[index];
        ht->list[index] = new;
        return true;
    }
    static char* hasht_lookup(hasht* ht, char* key){
        int index = hash(key) % ht->size;
        struct hnode* temp = ht->list[index];
        while(temp) {
            if (strcmp(temp->key, key) == 0) return temp->obj;
            temp = temp->next;
        }
        return NULL;
    }

    //new should be after all functions
    static hasht hasht_new(int size) {
        hasht ht = {
            .list = (struct hnode **)malloc(size * sizeof(struct hnode*)),
            .size = size,
            .insert = hasht_insert,
            .lookup = hasht_lookup,
        };
        return ht;
    }
hasht HashTable = {
    .new = hasht_new,
};