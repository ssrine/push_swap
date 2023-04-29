#include "apaah.h"

void ft_lstadd_back(t_list **lst, t_list *new)
{
    // If the linked list is empty, set the new element as the head of the list
    if (*lst == NULL) {
        *lst = new;
        return;
    }

    // Find the last element of the list
    t_list *last = *lst;
    while (last->next != NULL) {
        last = last->next;
    }

    // Set the next pointer of the last element to the new element
    last->next = new;
}
//In this example, the ft_lstadd_back function takes a pointer to a pointer to the head of the list and a pointer to the new element to be added. If the linked list is empty, the function sets the new element as the head of the list. If the linked list is not empty, the function finds the last element of the list by traversing the list using a while loop, and then sets the next pointer of the last element to the new element.