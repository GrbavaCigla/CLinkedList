#include <stdio.h>
#include <stdlib.h>

// Define your type
// Default is int
#define listype double
#include "list.h"

// Print function
// print function takes listype as parametar
void myprint(double val) {
    printf("%f\n", val);
}

int main() {
    list_t *list = list_create();
    list_append(list, 5);
    list_append(list, 1.14);
    list_append(list, 7);
    list_append(list, 54);
    list_append(list, 432);
    list_append(list, 15);
    list_append(list, 76);

    printf("Printing list\n");
    list_print(list, myprint);

    printf("Printing element at 2: ");
    printf("%d\n", list_at(list, 2));

    printf("Removing element at 2, list now looks like this:\n");
    list_remove_at(list, 2);
    list_print(list, myprint);

    printf("Finding value 15: ");
    printf("%d\n", list_find(list, 15));

    printf("Poping twice and appending 1500:\n");
    list_pop(list);
    list_pop(list);
    list_append(list, 1500);
    list_print(list, myprint);

    printf("Inserting at location 4:\n");
    list_insert(list, 4, 8293);
    list_print(list, myprint);

    printf("Replace at location 4:\n");
    list_replace_at(list, 4, 9382);
    list_print(list, myprint);

    int *arr = list_to_arr(list);
    printf("Linked list converted to array, location at 4: %d\n", arr[4]);
    free(arr);

    printf("Cleanup function frees memory\n");
    list_cleanup(list);

    return 0;
}
