#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node * next;
} node_t;

node_t *create_list(int val) {
    node_t *head;
    head = (node_t *) malloc(sizeof(node_t));
    head->val = val;
    head->next = NULL;

    return head;
}

void delete_list() {
    
}

void append(node_t *list, int val) {
    node_t *new_node = create_list(val);
    
    node_t *curr = list;
    while(curr->next) {
        curr = curr->next;
    }

    curr->next = new_node;
}

void print_list(node_t *node) {
    node_t *curr = node;

    while(curr->next){
        printf("%d\n", curr->val);
        curr = curr->next;
    }
    printf("%d\n", curr->val);
}

int main() {
    node_t *mylist = create_list(0);
    append(mylist, 1);
    append(mylist, 2);
    append(mylist, 3);

    print_list(mylist);

    return 0;
}
