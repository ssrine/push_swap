/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves1_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-hark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 08:20:47 by nel-hark          #+#    #+#             */
/*   Updated: 2023/05/03 15:35:46 by nel-hark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	bonus_sa(t_list *list)
{
	int	tmp;

	if (ft_lstsize(list) > 1)
	{
		tmp = list->data;
		list->data = list->link->data;
		list->link->data = tmp;
	}
}

void	bonus_sb(t_list *list)
{
	int	tmp;

	if (ft_lstsize(list) > 1)
	{
		tmp = list->data;
		list->data = list->link->data;
		list->link->data = tmp;
	}
}

void	bonus_rra(t_list **list)
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
}

void	bonus_rrb(t_list **list)
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
}

void	bonus_ra(t_list **list)
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
}
