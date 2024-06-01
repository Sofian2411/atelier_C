#include <criterion/criterion.h>
#include <stdio.h>

#include "linked_list.h"

Test(Basics, newList)
{
    List* linked = ll_new_list();
    cr_expect_neq(linked, NULL, "Expected list to be not null");
    cr_expect_eq(linked->head, NULL, "Expected head to be null");
    cr_expect_eq(linked->size, 0, "Expected sze to be 0 but was %lu",
            linked->size);
}

Test(Basic, append_to_empty_list)
{
    List* linked = ll_new_list();
    cr_expect_neq(linked, NULL, "Expected list to be not null");
    ssize_t i = ll_append(linked, 10);
    cr_expect_eq(i, 1, "Expected return value of append to be 1");
    Node* head = linked->head;
    cr_expect_neq(head, NULL, "Expected head to be not null");
    cr_expect_eq(head->next, NULL, "Expected head->next to be null");
    cr_expect_eq(head->data, 10, "Expected head->data to be 10 but was %lu",
            head->data);
    cr_expect_eq(linked->size, 1, "Expected list->size to be 1 but was %lu",
            linked->size);
}

Test(Basic, append_to_list)
{
    List* linked = ll_new_list();
    cr_expect_neq(linked, NULL, "Expected list to be not null");
    ll_append(linked, 10);
    Node* head = linked->head;
    cr_expect_neq(head, NULL, "Expected list to be not null");
    ssize_t i = ll_append(linked, 15);
    cr_expect_eq(i, 1, "Expected return value of append to be 1");
    head = head->next;
    cr_expect_neq(head, NULL, "Expected head to be not null");
    cr_expect_eq(head->next, NULL, "Expected head->next to be null");
    cr_expect_eq(head->data, 15, "Expected head->data to be 10 but was %lu",
            head->data);
    cr_expect_eq(linked->size, 2, "Expected list->size to be 1 but was %lu",
            linked->size);
}

Test(Basics, pop_list)
{
    List* linked = ll_new_list();
    ll_append(linked, 10);
    ll_append(linked, 11);
    ll_append(linked, 12);
    Node* indice0 = linked->head;
    Node* indice1 = indice0->next;
    ssize_t r = ll_pop(linked);
    cr_expect_eq(r, 12, 
            "Expected return value to be %d", 12);
    cr_expect_eq(linked->head, indice0, 
            "Expected head to be the same");
    cr_expect_eq(linked->head->next, indice1, 
            "Expected indice1 to be the same");
    cr_expect_eq(linked->head->next->next, NULL, 
            "Expected indice2 to be the NULL");
    cr_expect_eq(linked->size, 2, 
            "Expected list->size to be %d but was %lu",
            2, linked->size);
}

Test(Basics, pop_empty_list)
{
    List* linked = ll_new_list();
    ssize_t r = ll_pop(linked);
    cr_expect_eq(r, -1, 
            "Expected return value to be %d", -1);
    cr_expect_eq(linked->head, NULL, 
            "Expected head to stay NULL");
    cr_expect_eq(linked->size, 0, 
            "Expected size to stay %d", 0);
}

Test(Basics, pop_list_multiple_times)
{
    List* linked = ll_new_list();
    ll_append(linked, 10);
    ll_append(linked, 11);
    ll_append(linked, 12);
    Node* indice0 = linked->head;
    Node* indice1 = indice0->next;
    ll_pop(linked);
    ssize_t r = ll_pop(linked);
    cr_expect_eq(r, 11, 
            "Expected return value to be %d", 11);
    cr_expect_eq(linked->head, indice0, 
            "Expected head to be the same");
    cr_expect_eq(linked->head->next, NULL, 
            "Expected indice1 to be NULL");
    cr_expect_eq(linked->size, 1, 
            "Expected list->size to be %d but was %lu",
            1, linked->size);
}

Test(Basics, get_on_a_list)
{
    List* linked = ll_new_list();
    size_t a[5] = {10,11,12,13,14};
    for (size_t i = 0; i < 5 ; i++)
    {
        ll_append(linked, a[i]);
    }
    ssize_t r = 0;
    for (size_t i  = 0; i < 5; i++)
    {
        r = ll_get(linked, i);
        cr_expect_eq(r, a[i], 
                "Expected return value to be %ld but was %ld", a[i], r);
    }
}

Test(Basics, get_greater_index_than_size)
{
    List* linked = ll_new_list();
    size_t a[5] = {10,11,12,13,14};
    for (size_t i = 0; i < 5 ; i++)
    {
        ll_append(linked, a[i]);
    }
    ssize_t r = ll_get(linked, 6);
    cr_expect_eq(r, -1, 
            "Expected return value to be %d but was %ld", -1, r);
}

Test(Basics, clear_array)
{
    List* linked = ll_new_list();
    size_t a[5] = {10,11,12,13,14};
    for (size_t i = 0; i < 5 ; i++)
    {
        ll_append(linked, a[i]);
    }
    ll_clear(linked);
    cr_expect_eq(linked->head, NULL, "Expected head to be null");
    cr_expect_eq(linked->size, 0, "Expected sze to be 0 but was %lu",
            linked->size);
}

Test(Basics, clear_array_empty)
{
    List* linked = ll_new_list();
    ll_clear(linked);
    cr_expect_eq(linked->head, NULL, "Expected head to be null");
    cr_expect_eq(linked->size, 0, "Expected sze to be 0 but was %lu",
            linked->size);
}

Test(Basics, insert_at_back)
{
    List* linked = ll_new_list();
    size_t a[5] = {10,11,12,13,14};
    for (size_t i = 0; i < 5 ; i++)
    {
        ll_append(linked, a[i]);
    }
    ssize_t r = ll_insert(linked,5, 15);
    cr_expect_eq(r, 1, "Expected return value to be 1");
    cr_expect_eq(linked->size, 6, "Expected size to be 6 but was %lu",
            linked->size);
    Node* indice5 = linked->head->next->next->next->next->next;
    cr_expect_neq(indice5, NULL, "Expected indice5 to be not NULL");
    cr_expect_eq(indice5->next, NULL, "Expected indice6 to be NULL");
    cr_expect_eq(indice5->data, 15, "Expected indice5->data to be 15 but was %lu"
            , indice5->data);
}

Test(Basics, insert_at_front)
{
    List* linked = ll_new_list();
    size_t a[5] = {10,11,12,13,14};
    for (size_t i = 0; i < 5 ; i++)
    {
        ll_append(linked, a[i]);
    }
    ssize_t r = ll_insert(linked,0, 9);
    cr_expect_eq(r, 1, "Expected return value to be 1");
    cr_expect_eq(linked->size, 6, "Expected size to be 6 but was %lu",
            linked->size);
    Node* indice0 = linked->head;
    cr_assert_neq(indice0, NULL, "Expected indice0 to be not NULL");
    cr_assert_neq(indice0->next, NULL, "Expected indice1 to be not NULL");
    cr_expect_eq(indice0->next->data, 10, "Expected indice1-> to be 10 but was %lu"
            , indice0->next->data);
    cr_expect_eq(indice0->data, 9, "Expected indice0->data to be 9 but was %lu"
            , indice0->data);
}

Test(Basics, insert_at_middle)
{
    List* linked = ll_new_list();
    size_t a[5] = {10,11,12,13,14};
    for (size_t i = 0; i < 5 ; i++)
    {
        ll_append(linked, a[i]);
    }
    ssize_t r = ll_insert(linked,1, 9);
    cr_expect_eq(r, 1, "Expected return value to be 1");
    cr_expect_eq(linked->size, 6, "Expected size to be 6 but was %lu",
            linked->size);
    cr_assert_neq(linked->head, NULL, "Expected indice0 to be not NULL");
    Node* indice1= linked->head->next;
    cr_expect_eq(linked->head->data, 10, "Expected indice0->data to be 10 but was %lu"
            , linked->head->data);
    cr_assert_neq(indice1, NULL, "Expected indice1 to be not NULL");
    cr_expect_eq(indice1->data, 9, "Expected indice1->data to be 9 but was %lu"
            , indice1->data);
    cr_assert_neq(indice1->next, NULL, "Expected indice2 to be not NULL");
    cr_expect_eq(indice1->next->data, 11, "Expected indice2-> to be 11 but was %lu"
            , indice1->next->data);
}

Test(Basics, insert_at_index_to_big)
{
    List* linked = ll_new_list();
    size_t a[5] = {10,11,12,13,14};
    for (size_t i = 0; i < 5 ; i++)
    {
        ll_append(linked, a[i]);
    }
    ssize_t r = ll_insert(linked,10, 1);
    cr_expect_eq(r, -1, "Expected return value to be 0");
    cr_expect_eq(linked->size, 5, "Expected size to be 5 but was %lu",
            linked->size);
}

Test(Basics, remove_end)
{
    List* linked = ll_new_list();
    size_t a[5] = {10,11,12,13,14};
    for (size_t i = 0; i < 5 ; i++)
    {
        ll_append(linked, a[i]);
    }
    ssize_t r = ll_remove(linked, 4);
    cr_expect_eq(r, 14, "Expected return value to be 14");
    cr_expect_eq(linked->size, 4, "Expected size to be 4 but was %lu",
            linked->size);
    Node* tmp = linked->head;
    for (size_t i = 0; i < 4; i++)
    {
        cr_assert_neq(tmp, NULL, "index%lu shouldn't be NULL",i);
        cr_expect_eq(tmp->data, a[i], "index%lu->data should be %lu be was %lu",
            i,a[i], tmp->data);
        tmp = tmp->next;

    }
    cr_expect_eq(tmp, NULL, "index4 should be NULL");
}

Test(Basics, remove_start)
{
    List* linked = ll_new_list();
    size_t a[5] = {10,11,12,13,14};
    for (size_t i = 0; i < 5 ; i++)
    {
        ll_append(linked, a[i]);
    }
    ssize_t r = ll_remove(linked, 0);
    cr_expect_eq(r, 10, "Expected return value to be 10, but was %lu", r);
    cr_expect_eq(linked->size, 4, "Expected size to be 4 but was %lu",
            linked->size);
    size_t retour[4] = {11,12,13,14};
    Node* tmp = linked->head;
    for (size_t i = 0; i < 4; i++)
    {
        cr_assert_neq(tmp, NULL, "index%lu shouldn't be NULL",i);
        cr_expect_eq(tmp->data, retour[i], "index%lu->data should be %lu be was %lu",
            i, retour[i], tmp->data);
        tmp = tmp->next;

    }
    cr_expect_eq(tmp, NULL, "index4 should be NULL");
}

Test(Basics, remove_middle)
{
    List* linked = ll_new_list();
    size_t a[5] = {10,11,12,13,14};
    for (size_t i = 0; i < 5 ; i++)
    {
        ll_append(linked, a[i]);
    }
    ssize_t r = ll_remove(linked, 2);
    cr_expect_eq(r, 12, "Expected return value to be 12, but was %lu", r);
    cr_expect_eq(linked->size, 4, "Expected size to be 4 but was %lu",
            linked->size);
    size_t retour[4] = {10,11,13,14};
    Node* tmp = linked->head;
    for (size_t i = 0; i < 4; i++)
    {
        cr_assert_neq(tmp, NULL, "index%lu shouldn't be NULL",i);
        cr_expect_eq(tmp->data, retour[i], "index%lu->data should be %lu be was %lu",
            i, retour[i], tmp->data);
        tmp = tmp->next;

    }
    cr_expect_eq(tmp, NULL, "index4 should be NULL");
}

Test(Basics, remove_index_to_big)
{
    List* linked = ll_new_list();
    size_t a[5] = {10,11,12,13,14};
    for (size_t i = 0; i < 5 ; i++)
    {
        ll_append(linked, a[i]);
    }
    ssize_t r = ll_remove(linked, 5);
    cr_expect_eq(r, -1, "Expected return value to be -1, but was %lu", r);
    cr_expect_eq(linked->size, 5, "Expected size to be 5 but was %lu",
            linked->size);
}

Test(list_NULL, append)
{
    ssize_t r = ll_append(NULL, 0);
    cr_expect_eq(r, -1, "expected return value to be 0 but was %lu", r);
}

Test(list_NULL, get)
{
    ssize_t r = ll_get(NULL, 0);
    cr_expect_eq(r, -1, "expected return value to be -1 but was %lu", r);
}

Test(list_NULL, pop)
{
    ssize_t r = ll_pop(NULL);
    cr_expect_eq(r, -1, "expected return value to be -1 but was %lu", r);
}

Test(list_NULL, remove)
{
    ssize_t r = ll_remove(NULL, 0);
    cr_expect_eq(r, -1, "expected return value to be -1 but was %lu", r);
}

Test(list_NULL, clear)
{
    ll_clear(NULL);
}

Test(list_NULL, destroy)
{
    ll_destroy(NULL);
}

