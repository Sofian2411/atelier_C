#include <stdio.h>
#include "linked_list.h"

// Helper function to print list
void ll_print(List* list) {
    if (list == NULL) {
        printf("List in NULL.\n");
    }

    if (list->size == 0) {
        printf("Empty list\n");
    }

    for (Node* node = list->head; node != NULL; node = node->next) {
        printf("[%ld]", node->data);
        if (node->next)
            printf(" -> ");
    }

    printf("\n");
}

int main() {
    // Initialise empty list;
    List* list = ll_new_list();

    // Add data to list
    for (size_t i = 1; i <= 5; i++) {
        ll_append(list, i);
    }

    ll_print(list);

    // Add your own tests
}
