#include <unistd.h>
#include <stdlib.h>


typedef struct s_list {
    void *content;
    struct s_list *next;
} t_list;

t_list *ft_lstnew(void *content)
{
    t_list *new_node = malloc(sizeof(t_list)); // allocate memory for the new node
    if (new_node == NULL) {
        return NULL; // return NULL if malloc fails
    }

    new_node->content = content; // set the content of the new node
    new_node->next = NULL; // initialize the next pointer to NULL

    return new_node; // return the new node
}
