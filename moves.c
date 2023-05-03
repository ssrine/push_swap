/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-hark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 09:55:58 by nel-hark          #+#    #+#             */
/*   Updated: 2023/05/03 16:56:19 by nel-hark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_list *list)
{
	int	tmp;

	if (ft_lstsize(list) > 1)
	{
		tmp = list->data;
		list->data = list->link->data;
		list->link->data = tmp;
	}
	ft_putstr_fd(1, "sa\n");
}

void	sb(t_list *list)
{
	int	tmp;

	if (ft_lstsize(list) > 1)
	{
		tmp = list->data;
		list->data = list->link->data;
		list->link->data = tmp;
	}
	ft_putstr_fd(1, "sb\n");
}

void	rra(t_list **list)
{
	t_list	*head;
	t_list	*befor_last_node;
	t_list	*last;

	head = *list;
	if (head == NULL || head->link == NULL)
		return ;
	befor_last_node = head;
	last = ft_lstlast(head);
	while (befor_last_node->link->link)
		befor_last_node = befor_last_node->link;
	befor_last_node->link = NULL;
	last->link = head;
	*list = last;
	ft_putstr_fd (1, "rra\n");
}

void	rrb(t_list **list)
{
	t_list	*head;
	t_list	*befor_last_node;
	t_list	*last;

	head = *list;
	if (head == NULL || head->link == NULL)
		return ;
	befor_last_node = head;
	last = ft_lstlast(head);
	while (befor_last_node->link->link)
		befor_last_node = befor_last_node->link;
	befor_last_node->link = NULL;
	last->link = head;
	*list = last;
	ft_putstr_fd(1, "rrb\n");
}

void	ra(t_list **list)
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
	ft_putstr_fd(1, "ra\n");
}
