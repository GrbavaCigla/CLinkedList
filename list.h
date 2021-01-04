#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct node {
    int val;
    struct node * next;
} node_t;

typedef struct list {
    unsigned short int length;
    node_t *head;
} list_t;

list_t *list_create() {
    list_t *new_list = (list_t*)malloc(sizeof(list_t));
    new_list->length = 0;

    return new_list;
}

void list_append(list_t *list, int val) {
    if (list->length == 0) {
        list->head = (node_t*)malloc(sizeof(node_t));
        list->head->val = val;
    } else {
        node_t *new_node = (node_t*)malloc(sizeof(node_t));
        new_node->val = val;

        node_t *curr = list->head;
        while (curr->next) {
            curr = curr->next;
        }

        curr->next = new_node;
    }

    list->length++;
}

void list_print(list_t *list) {
    node_t *curr = list->head;

    while(curr->next){
        printf("%d\n", curr->val);
        curr = curr->next;
    }
    printf("%d\n", curr->val);
}