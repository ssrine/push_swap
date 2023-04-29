
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-hark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 10:30:16 by nel-hark          #+#    #+#             */
/*   Updated: 2023/04/13 10:36:21 by nel-hark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void  sort_tlata(t_list **list)
{
    t_list *head = *list;
    if(head->data < head->link->data && head->link->data < head->link->link->data && head->data < head->link->link->data)
            return ;
    else if(head->data > head->link->data && head->data < head->link->link->data)// 2 1 3
        sa(head);
    else if(head->data > head->link->data && head->data > head->link->link->data && head->link->data > head->link->link->data)// 3 2 1
    {
        sa(head);
        rra(list);
    }
    else if(head->data < head->link->data && head->data > head->link->link->data)// 2 3 1
        rra(list);
    else if(head->data < head->link->data && head->data < head->link->link->data) //1 3 2
    {
        rra(list);
        sa(*list);
    }
    else if(head->data > head->link->data && head->data > head->link->link->data && head->link->data < head->link->link->data)// 3 1 2
        ra(list);
   
}

// int get_second_min(t_list **a)
// {
//     int min_value, second_min_value;
//     t_list *temp = *a;

//     // Set the first two values as the minimum and second minimum
//     if (temp->data < temp->link->data) {
//         min_value = temp->data;
//         second_min_value = temp->link->data;
//     } else {
//         min_value = temp->link->data;
//         second_min_value = temp->data;
//     }

//     // Iterate over the rest of the list to find the second minimum value
//     while (temp) {
//         if (temp->data < min_value) {
//             second_min_value = min_value;
//             min_value = temp->data;
//         } else if (temp->data < second_min_value && temp->data != min_value) {
//             second_min_value = temp->data;
//         }
//         temp = temp->link;
//     }

//     return second_min_value;
// }
int get_min(t_list **a)
{
    t_list *temp = *a;


    int min_value = temp->data;
    while (temp)
        {
            if (temp->data < min_value )
            {
                min_value = temp->data;
            }
            temp = temp->link;

        }
    // printf("3aa%d\n",min_value);
    return min_value;
}


void sort_five(t_list **a, t_list **b)
{
    while((*a)->data != get_min(a))
        ra(a);
    if((*a)->data == get_min(a))
        pb(a, b);
     while((*a)->data != get_min(a))
        ra(a);
    if((*a)->data == get_min(a))
        pb(a, b);
    if(ft_lstsize(*a) == 3)
	    sort_tlata(a);
    else if((*a)->data > (*a)->link->data)
        sa(*a);
	pa(a, b);
	pa(a, b);
}
// void set_chunk_size(t_helper *helper, int size) {
//     if (size <= 10) {
//         helper->chunk_size = size / 5;
//     } else if (size <= 150) {
//         helper->chunk_size = size / 8;
//     } else {
//         helper->chunk_size = size / 18;
//     }
// }

// void set_stack_range(t_helper *helper, int size) {
//     helper->middle = size / 2;
//     helper->start = helper->middle - helper->chunk_size;
//     helper->end = helper->middle + helper->chunk_size;
//     helper->array_size = size;
// }

// void init_helper(t_helper *helper, int size) {
//     set_chunk_size(helper, size);
//     set_stack_range(helper, size);
// }

void	init_helper(t_helper *helper, int size)
{
    // printf("size : ----%d\n", size);
	if (size <= 10)
		helper->chunk_size = size / 5; // hajm dyal stack = size(liykonsghar mn 10 ) / 5
	else if (size <= 150)
		helper->chunk_size = size / 8;           // mn lakher kan9albo 3la 9assem li y3dena asgher 9d3a 
	else if (size <= 500)
		helper->chunk_size = size / 18;
    // printf("chunk: ----%d\n", helper->chunk_size);
	helper->middle = size / 2; //kan9albo 3la middle dyal stack a
    // printf("middle : ----%d\n", helper->middle);
	helper->start = helper->middle - helper->chunk_size; // kanchof mnin nbda dak range
    // printf("start: ----%d\n", helper->start);
	helper->end = helper->middle + helper->chunk_size; // mnach ysali dak range
    // printf("end: ----%d\n", helper->end);
	helper->array_size = size;
}
void	push_to_b(t_list **a, t_list **b, t_helper *helper, int *array)
{
	while (*a)
	{
        // printf("tab[start] : %d    tab[end] :  %d\n", array[helper->start], array[helper->end]);
        // printf("data a : %d\n", (*a)->data);
		if ((*a)->data >= array[helper->start]
			&& (*a)->data <= array[helper->end])
		{
			pb(a, b);
			if ((*b)->data < array[helper->middle])
				rb(b);
		}
		else
			ra_rra(a, b, array, helper);
	}
}
// void push_to_b(t_list **a, t_list **b, t_helper *helper, int *array)
// {
//     int i = 0;
//     while ((*a) != NULL)  // while there are elements in a
//     {
//         i = 0;
//         while (i < helper->chunk_size)
//         {
//             if ((*a)->data >= array[helper->start] && (*a)->data <= array[helper->end])  // if the element is in the unsorted portion of the array
//             {
//                 pb(a, b);   // push the element from a to b
//                 if ((*b)->data < array[helper->middle])   // if the top element of b is in the lower half of the unsorted portion of the array
//                     rb(b);  // rotate b to the down
//                 i++;
//             }
//             else
//                 ra_rra(a, b, array, helper);  // if the element is not in the unsorted portion of the array, rotate a either to the up or down
//         }
//         helper->start -= helper->chunk_size;// ==<
//         if (helper->start < 0)
//             helper->start = 0;
//         helper->end += helper->chunk_size;// ==<
//         if (helper->end > helper->array_size - 1 )
//             helper->end = helper->array_size - 1;
//     }
// }

void ra_rra(t_list **a, t_list **b, int *array, t_helper *helper)
{
    t_list *head;

    head = *a;  // set a pointer to the top of stack a
    (void)b;    // suppress unused variable warning
    while (head && !(head->data >= array[helper->start] && head->data <= array[helper->end]))  // while the top element of a is not in the unsorted portion of the array
        head = head->link; // move the pointer to the next element in the stack
    if (!head)  // if the pointer is null (i.e., the entire stack a is sorted)
        update_params(helper);  // update the sorting parameters (i.e., the range of the unsorted portion of the array)
    else  // if the pointer is not null
    {
        // printf("position: %d\n", search_content(a, head->data));  
        if (search_content(a, head->data) <= helper->array_size / 2)  // if the top element is closer to the top of the stack
        {  
            // printf("headdata : %d     find : %d\n", (*a)->data, head->data);
          

            ra(a);  // rotate a to the right
        }
        else  // if the top element is closer to the bottom of the stack
            rra(a); // rotate a to the left
    }
}
void update_params(t_helper *helper)
{
    helper->start -= helper->chunk_size;   // subtract chunk_size from start
    helper->end += helper->chunk_size;     // add chunk_size to end


    if (helper->start < 0)      // if start is less than 0
        helper->start = 0;      // set it to 0

    if (helper->end > helper->array_size - 1)  // if end is greater than the size of the array minus 1
        helper->end = helper->array_size - 1;  // set it to the size of the array minus 1
//  printf("----------------------------------------------\n");
//     printf("chunk apaah : ----%d\n", helper->chunk_size);
//      printf("middle apaaah : ----%d\n", helper->middle);
//       printf("start appah : ----%d\n", helper->start);
//       printf("end appah : ----%d\n", helper->end);
//  printf("----------------------------------------------\n\n");
}

int search_content(t_list **a, int find)
{
    t_list *head;   // declare a pointer variable head to t_list structure
    int i;          // declare an integer variable i

    head = *a;      // set head to the value of the pointer to linked list a
    i = 0;          // initialize i to 0
    while (head)    // while head is not null
    {
        if (head->data == find) // check if the value of data in the current node is equal to find
            return (i);        // if yes, return the index i

        i++;                    // increment i
        head = head->link;      // set head to the next node in the linked list
    }
    return (-1);    // if find is not found in any node, return -1 
}