/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-hark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 11:26:48 by nel-hark          #+#    #+#             */
/*   Updated: 2023/04/30 11:43:24 by nel-hark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rb(t_list **list)
{
	t_list	*head;
	t_list	*new_head;
	t_list	*last;

	head = *list;
	if (head == NULL || head->link == NULL)
		return ;
	new_head = head->link;
	last = ft_lstlast(head);
	last->link = head;
	head->link = NULL;
	*list = new_head;
	ft_putstr_fd(1, "rb\n");
}

void	pa(t_list **a, t_list **b)
{
	t_list	*head;

	if (ft_lstsize(*b))
	{
		head = *b;
		*b = (*b)->link;
		ft_lstadd_front(a, ft_lstnew(head->data));
		free(head);
	}
	ft_putstr_fd(1, "pa\n");
}

void	pb(t_list **a, t_list **b)
{
	t_list	*head;

	if (ft_lstsize(*a))
	{
		head = *a;
		*a = (*a)->link;
		ft_lstadd_front(b, ft_lstnew(head->data));
		free(head);
	}
	ft_putstr_fd(1, "pb\n");
}
