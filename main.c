#include "list.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    list_t *list = list_create();
    list_append(list, 5);
    list_append(list, 1);
    list_append(list, 7);
    list_append(list, 54);
    list_append(list, 432);
    list_append(list, 15);
    list_append(list, 76);

    printf("Printing list\n");
    list_print(list);

    printf("Printing element at 2: ");
    printf("%d\n", list_at(list, 2));

    printf("Removing element at 2, list now looks like this:\n");
    list_remove_at(list, 2);
    list_print(list);

    printf("Finding value 15: ");
    printf("%d\n", list_find(list, 15));

    printf("Poping twice and appending 1500:\n");
    list_pop(list);
    list_pop(list);
    list_append(list, 1500);
    list_print(list);

    printf("Inserting at location 4:\n");
    list_insert(list, 4, 8293);
    list_print(list);

    printf("Replace at location 4:\n");
    list_replace_at(list, 4, 9382);
    list_print(list);

    printf("Linked list converted to array, location at 4: %d\n", *(list_to_arr(list) + 4));

    printf("Cleanup function frees memory\n");
    list_cleanup(list);

    return 0;
}
