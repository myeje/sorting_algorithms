#include "sort.h"

/**
 * insertion_sort_list - function that sorts a list using
 * insertion sort
 * @list: pointer to doubly linked list to be sorted
 * Return: nothing
 */
void insertion_sort_list(listint_t **list)
{
    listint_t *i, *temp, *prev;

    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;

    for (i = (*list)->next; i != NULL; i = temp)
    {
        temp = i->next;
        prev = i->prev;
        while (prev != NULL && i->n < prev->n)
        {
            i->prev = prev->prev;
            if (prev->prev != NULL)
                prev->prev->next = i;
            prev->next = i->next;
            if (i->next != NULL)
                i->next->prev = prev;
            i->next = prev;
            prev->prev = i;

            if (i->prev == NULL)
                *list = i;

            print_list((const listint_t *)*list);
            prev = i->prev;
        }
    } 
}
