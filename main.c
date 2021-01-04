#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main() {
    list_t *list = list_create();
    list_append(list, 10);
    list_append(list, 20);
    list_append(list, 30);
    list_append(list, 40);

    printf("Printing list\n");
    list_print(list);

    printf("Printing element at 2: ");
    printf("%d\n", list_at(list, 2));

    printf("Removing element at 2, list now looks like this:\n");
    list_remove_at(list, 2);
    list_print(list);

    return 0;
}
