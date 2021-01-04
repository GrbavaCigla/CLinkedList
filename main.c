#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main() {
    list_t *list = list_create();
    for(int i=0;i<10;i++) {
        list_append(list, i*1);
    }

    printf("Printing list\n");
    list_print(list);

    printf("Printing element at 2: ");
    printf("%d\n", list_at(list, 2));

    printf("Removing element at 2, list now looks like this:\n");
    list_remove_at(list, 2);
    list_print(list);

    printf("Cleanup function frees memory");
    list_cleanup(list);

    return 0;
}
