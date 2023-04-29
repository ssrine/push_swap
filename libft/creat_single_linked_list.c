


#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

struct node 
{
    int data;
    struct node *link;
};

int main()
{
    struct node *head = malloc (sizeof(struct node));

    head->data = 45;
    head->link = NULL;

    struct node *current = malloc(sizeof(struct node));
    current->link = NULL;
    head->link = current;

}