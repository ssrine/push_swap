
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
    else if(head->data > head->link->data && head->data < head->link->link->data)
        sa(head);
    else if(head->data > head->link->data && head->data > head->link->link->data && head->link->data > head->link->link->data)
    {
        sa(head);
        rra(list);
    }
    else if(head->data < head->link->data && head->data > head->link->link->data)
        rra(list);
    else if(head->data < head->link->data && head->data < head->link->link->data) 
    {
        rra(list);
        sa(*list);
    }
    else if(head->data > head->link->data && head->data > head->link->link->data && head->link->data < head->link->link->data)
        ra(list);
   
}
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
//     helper->middle = size / 2 - 1;
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

	if (size <= 10)
		helper->chunk_size = size / 5; 
	else if (size <= 150)
		helper->chunk_size = size / 8;          
	else if (size <= 500)
		helper->chunk_size = size / 18;
    
	helper->middle = size / 2 - 1; 
   
	helper->start = helper->middle - helper->chunk_size;
    
	helper->end = helper->middle + helper->chunk_size; 
  
	helper->array_size = size;
}
void	push_to_b(t_list **a, t_list **b, t_helper *helper, int *array)
{
	while (*a)
	{
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
void ra_rra(t_list **a, t_list **b, int *array, t_helper *helper)
{
    t_list *head;

    head = *a; 
    (void)b;   
    while (head && !(head->data >= array[helper->start] && head->data <= array[helper->end]))
        head = head->link; 
    if (!head)
        update_params(helper);  
    else  
    {
   
        if (search_content(a, head->data) <= helper->array_size / 2)  
        {  
          
            ra(a);  
        }
        else  
            rra(a); 
    }
}
void update_params(t_helper *helper)
{
    helper->start -= helper->chunk_size; 
    helper->end += helper->chunk_size;     


    if (helper->start < 0)    
        helper->start = 0;     

    if (helper->end > helper->array_size - 1)  
        helper->end = helper->array_size - 1;

}

int search_content(t_list **a, int find)
{
    t_list *head;  
    int i;          

    head = *a;     
    i = 0;          
    while (head)    
    {
        if (head->data == find) 
            return (i);       

        i++;                   
        head = head->link;     
    }
    return (-1);   
}