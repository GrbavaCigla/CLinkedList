#include <malloc.h>
#include <stdio.h>

typedef struct node {
    int val;
    struct node *next;
} node_t;

typedef struct list {
    unsigned short int length;
    node_t *head;
} list_t;

list_t *list_create() {
    list_t *new_list = (list_t *)malloc(sizeof(list_t));
    new_list->length = 0;

    return new_list;
}

void list_append(list_t *list, int val) {
    if (list->length == 0) {
        list->head = (node_t *)malloc(sizeof(node_t));
        list->head->val = val;
    } else {
        node_t *new_node = (node_t *)malloc(sizeof(node_t));
        new_node->val = val;

        node_t *curr = list->head;
        while (curr->next) {
            curr = curr->next;
        }

        curr->next = new_node;
    }

    list->length++;
}

node_t *_list_at(list_t *list, int index) {
    node_t *curr = list->head;

    for (int i = 0; i < index; i++) {
        curr = curr->next;
    }

    return curr;
}

int list_at(list_t *list, int index) { return _list_at(list, index)->val; }

void list_print(list_t *list) {
    node_t *curr = list->head;

    while (curr->next) {
        printf("%d\n", curr->val);
        curr = curr->next;
    }
    printf("%d\n", curr->val);
}

int list_remove_at(list_t *list, int index) {
    node_t *bef_node = _list_at(list, index - 1);

    list->length--;
    node_t *node_to_remove = bef_node->next;

    bef_node->next = bef_node->next->next;
    free(node_to_remove);
}

void list_cleanup(list_t *list) {
    int length = list->length;

    node_t *arr[length];

    node_t *curr = list->head;
    int i = 0;
    while (curr) {
        arr[i] = curr;
        i++;
        curr = curr->next;
    }
    arr[i] = curr;

    for (int i = 0; i < length; i++) {
        free(arr[i]);
    }
    free(list);
}