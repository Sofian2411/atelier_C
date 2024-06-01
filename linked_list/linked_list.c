#include "linked_list.h"

#include <stdlib.h>

// Return an empty list
List* ll_new_list() {
    List* ll = calloc(1, sizeof(List));
    if (ll == NULL) 
        return NULL;

    return ll;
}

// Append node to the list
ssize_t ll_append(List* list, size_t data) {
    if (list == NULL)
        return -1;
    Node* n = malloc(sizeof(Node));
    if (n == NULL)
        return -1;

    n->data = data;
    n->next = NULL;
    
    if (list->size == 0)
    {
        list->head = n;
    } else {
        Node* aux = list->head;
        while (aux->next != NULL)
            aux = aux->next;

        aux->next = n;
    }

    list->size++;
    return 1;
}

// Pop first node
ssize_t ll_pop(List* list) {
    if (list == NULL || list->size == 0)
        return -1;

    Node* last;
    ssize_t res;
    if (list->size == 1) {
        last = list->head->next;
        res = last->data;
        list->head->next = NULL;
    } else {
        Node* aux = list->head;
        while (aux->next->next != NULL)
            aux = aux->next;
        last = aux->next;
        res = last->data;
        aux->next = NULL;
    }
    list->size--;
    free(last);
    return res;
}

// Get the data at index
ssize_t ll_get(List* list, size_t index) {
    if (list == NULL || index >= list->size)
        return -1;
    Node* aux = list->head;
    while (index != 0) {
        aux = aux->next;
        index--;
    }
    return aux->data;
}

// Remove the node at index
ssize_t ll_remove(List* list, size_t index) {
    if (list == NULL || index >= list->size)
        return -1;
    if (index == list->size - 1)
        return ll_pop(list);
    Node* aux;
    Node* cur = list->head;
    if (index == 0)
    {
        list->head = cur->next;
    }
    else
    {
        while (index != 0) {
            aux = cur;
            cur = cur->next;
            index--;
        }
        aux->next = cur->next;
    }
    ssize_t res = cur->data;
    free(cur);
    list->size--;
    return res;
}

// Insert data at index
ssize_t ll_insert(List* list, size_t index, size_t data) {
    if (list == NULL || index > list->size)
        return -1;
    if (index > list->size)
        return ll_append(list, data);

    Node* n = malloc(sizeof(Node));
    if (n == NULL)
        return -1;
    n->data = data;
    
    Node* cur = list->head;
    if (index == 0)
    {
        list->head = n;
    } else {
        Node* aux;
        while (index != 0) {
            aux = cur;
            cur = cur->next;
            index--;
        }
        aux->next = n;
    }
    n->next = cur;
    list->size++;
    return 1;
}

// Clear list
void ll_clear(List *list) {
    if (list == NULL)
    {
        return;
    }
    Node* cur = list->head;
    Node* aux;
    
    while (cur != NULL) {
        aux = cur;
        cur = cur->next;
        free(aux);
    }
    list->head = NULL;
    list->size = 0;
}

// Destroy list
void ll_destroy(List* list) {
    if (list == NULL)
    {
        return;
    }
    ll_clear(list);
    free(list);
}
