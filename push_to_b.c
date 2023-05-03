/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-hark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 09:28:00 by nel-hark          #+#    #+#             */
/*   Updated: 2023/04/30 17:18:26 by nel-hark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
			find_head_to_move(a, array, helper);
	}
}

void	find_head_to_move(t_list **a, int *array, t_helper *helper)
{
	t_list	*head;

	head = *a;
	while (head && !(head->data >= array[helper->start]
			&& head->data <= array[helper->end]))
		head = head->link;
	if (!head)
		update_params(helper);
	else
	{
		move_head_to_top(a, head, helper->array_size);
	}
}

void	move_head_to_top(t_list **a, t_list *head, int array_size)
{
	if (search_content(a, head->data) <= array_size / 2)
		ra(a);
	else
		rra(a);
}

void	update_params(t_helper *helper)
{
	helper->start -= helper->chunk_size;
	helper->end += helper->chunk_size;
	if (helper->start < 0)
		helper->start = 0;
	if (helper->end > helper->array_size - 1)
		helper->end = helper->array_size - 1;
}

int	search_content(t_list **a, int find)
{
	t_list	*head;
	int		i;

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
