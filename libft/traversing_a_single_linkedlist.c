


#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

 program to count the number of nodes

struct node
{
    int data;
    struct node *link;
};

void count_of_nodes(struct node *head)
{
    int count = 0;
    if(head == NULL)
        //printf("linked list is empty");
    struct node *ptr = NULL;
    ptr = head;
    while(ptr != NULL)
    {
        count++;
        ptr = ptr->link;  // next addres 
    }
    //printf("%d", count);
}
void add_to_end(struct node *head, int data)
{
    struct node *ptr = NULL;
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));

    temp->data = data;
    temp->link = NULL;
    ptr = head;
    while(ptr != NULL)
    {
        ptr = ptr->link;
    }
    ptr->link = temp;
}
void print_data(struct node *head)
{
    struct node *ptr = NULL;

    if(head == NULL)
        //printf("linked list is empty");
    ptr = head;
    while(ptr != NULL)
    {
        //printf("%d", ptr->data);
        ptr = ptr->link;
    }
}

int main()
{

    struct node *head = malloc(sizeof(struct node));
    // head = NULL;
    head->data= 45;
    head->link = NULL;

    struct node *current = malloc(sizeof(struct node));
    current->data = 98;
    current->link  = NULL;

    head->link = current;

    struct node *current2 = malloc(sizeof(struct node));
    current2->data = 3;
    current2->link = NULL;

   current->link = current2;

   
   count_of_nodes(head);
   print_data(head);
}
