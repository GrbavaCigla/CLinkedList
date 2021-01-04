#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main() {
    list_t *list = list_create();
    list_append(list, 10);
    list_append(list, 20);
    list_append(list, 30);

    list_print(list);
    return 0;
}
