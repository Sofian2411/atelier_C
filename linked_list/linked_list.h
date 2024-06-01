#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stddef.h>
#include <sys/types.h>

// Struc representing a single node of the list.
// The data is an unsigned long integer (size_t)
// If at the end of the list, the next pointer must be NULL
typedef struct node {
    size_t data;
    struct node* next;
} Node ;

// Struct representing the list.
// An empty list must have a size of 0 and a NULL head pointer
typedef struct List {
    size_t size;
    Node* head;
} List;

// Return an empty list
List* ll_new_list();

// Append node at the end of the list
// Return value:
//      0 if list is NULL or malloc fails
//      1 otherwise
// Don't forget to update the list's size
ssize_t ll_append(List* list, size_t data);

// Pop first node
// Return value:
//      -1 if the operation is not possible
//      Value of the popped node's data otherwise
// Don't forget to free the popped node's memory
ssize_t ll_pop(List* list);

// Get the data at index
// Return value:
//      -1 if the index is invalid
//      Value of the node at index otherwise
ssize_t ll_get(List* list, size_t index);

// Remove the node at index
// Return value:
//      -1 if the index is invalid
//      Value of the node at index otherwise
// Don't forget to free up memory and update list size
ssize_t ll_remove(List* list, size_t index);

// Insert data at index
// Return value:
//      -1 if the index is invalid or malloc fails
//      1 otherwise
ssize_t ll_insert(List* list, size_t index, size_t data);

// Clear list
// Free memory used by each node
// Do not free the list
void ll_clear(List* list);

// Destroy list
// Clear the list and free up all used memory
void ll_destroy(List* list);

// Add your own functions !
// For example:
// - list reverse
// - list merge
// - list sort (try merge sort)
// - list zip (merge two lists into one by alternating elements)
// etc...
// (Embetez moi sur discord si vous voulez une ref pour ces fonctions)

#endif
