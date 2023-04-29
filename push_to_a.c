/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-hark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 10:39:08 by nel-hark          #+#    #+#             */
/*   Updated: 2023/04/29 17:33:24 by nel-hark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_to_a_helper(t_stack *vars, int *down)
{
	if ((vars->b->data) == vars->init_array[vars->size])
	{
		pa(&vars->a, &vars->b);
		vars->size--;
	}
	else
	{
		if (!*down || (vars->b->data) > ft_lstlast(vars->a)->data)
		{
			pa(&vars->a, &vars->b);
			ra(&vars->a);
			++*down;
		}
		else
		{
			if (search_content(&vars->b,
					vars->init_array[vars->size]) <= ft_lstsize(vars->b) / 2)
				rb(&vars->b);
			else
				rrb(&vars->b);
		}
	}
}

void	push_to_a(t_stack *vars)
{
	int	down;
        printf("-----------------------size : %d----------------\n", vars->size);
	down = 0;
	while (vars->b)
	{
		if (max_in_b(&vars->b, vars->init_array[vars->size]))
			push_to_a_helper(vars, &down);
		else
		{
			rra(&vars->a);
			down--;
			vars->size--;
		}
	}
	while (down--)
		rra(&vars->a);
}

// void push_to_a(t_stack *vars)
// {
//     int down = 0;
//     while (vars->b)
//     {
//         if ((vars->b->data) == vars->init_array[vars->size])
//         {
//             pa(&vars->a, &vars->b);    
//             vars->size--;             
//         }
//         else if (!max_in_b(&vars->b, vars->init_array[vars->size]))
//         {
//             rra(&vars->a);
//             down--;
//             vars->size--;
//         }
//         else if (!down || (vars->b->data) > ft_lstlast(vars->a)->data) 
//         {
//             pa(&vars->a, &vars->b);    
//             ra(&vars->a);             
//             ++down;                  
//         }
//         else
//         {
//             if (search_content(&vars->b, vars->init_array[vars->size]) <= ft_lstsize(vars->b) / 2)
//                 rb(&vars->b);
//             else
//                 rrb(&vars->b);
//         }
//     }
//     while (down < 0)
//     { 
//         ra(&vars->a);
//         ++down;
//     }
// }
 
int max_in_b(t_list **b, int max)
{
    int i;        
    t_list *head;  

    i = 0;          
    head = *b;      

    while (head)    
    {
        if (head->data == max)  
            return (1);         

        head = head->link;    
    }

    return (0);     
}  
