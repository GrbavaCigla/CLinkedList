#include "list.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    list_t *list = list_create();
    list_append(list, 0);
    list_append(list, 1);
    list_append(list, 2);
    list_append(list, 3);
    list_append(list, 4);
    list_append(list, 5);
    list_append(list, 6);

    printf("Printing list\n");
    list_print(list);

    printf("Printing element at 2: ");
    printf("%d\n", list_at(list, 2));

    printf("Removing element at 2, list now looks like this:\n");
    list_remove_at(list, 2);
    list_print(list);

    printf("Cleanup function frees memory\n");
    list_cleanup(list);

    return 0;
}
