/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-hark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 10:30:16 by nel-hark          #+#    #+#             */
/*   Updated: 2023/04/30 17:55:21 by nel-hark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_tlata(t_list **list)
{
	t_list	*head;

	head = *list;
	if (head->data > head->link->data
		&& head->data < head->link->link->data)
		sa(head);
	else if (head->data > head->link->data
		&& head->data > head->link->link->data
		&& head->link->data > head->link->link->data)
	{
		sa(head);
		rra(list);
	}
	else
		sort_tlata_help(list);
}

void	sort_tlata_help(t_list **list)
{
	t_list	*head;

	head = *list;
	if (head->data < head->link->data
		&& head->data > head->link->link->data)
		rra(list);
	else if (head->data < head->link->data
		&& head->data < head->link->link->data
		&& head->link->data > head->link->link->data)
	{
		rra(list);
		sa(*list);
	}
	else if (head->data > head->link->data
		&& head->data > head->link->link->data
		&& head->link->data < head->link->link->data)
		ra(list);
}

int	get_min(t_list **a)
{
	int		min_value;
	t_list	*temp;

	temp = *a;
	min_value = temp->data;
	while (temp)
	{
		if (temp->data < min_value)
		{
			min_value = temp->data;
		}
		temp = temp->link;
	}
	return (min_value);
}

void	sort_five(t_list **a, t_list **b)
{
	while ((*a)->data != get_min(a))
		ra(a);
	if ((*a)->data == get_min(a))
		pb(a, b);
	while ((*a)->data != get_min(a))
		ra(a);
	if ((*a)->data == get_min(a))
		pb(a, b);
	if (ft_lstsize(*a) == 3)
		sort_tlata(a);
	else if ((*a)->data > (*a)->link->data)
		sa(*a);
	pa(a, b);
	pa(a, b);
}
