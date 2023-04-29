/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_linked.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-hark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 09:56:53 by nel-hark          #+#    #+#             */
/*   Updated: 2023/04/26 08:54:29 by nel-hark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstnew(int content) // creates a new node for a linked list data structure
{
	t_list	*new;

	new = (t_list *) malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->data = content;
	new->link = NULL;
	return (new);
}
void	ft_lstadd_back(t_list **lst, t_list *new) //which adds a new node to the end of a linked list
{
	t_list	*node;

	if (new)
	{
		if (*lst)
		{
			node = ft_lstlast(*lst);
			node->link = new;
		}
		else
			*lst = new;
	}
}
t_list	*ft_lstlast(t_list *lst)//which finds the last node in a linked list
{
	if (!lst)
		return (NULL);
	while (lst->link)
	{
		if (!lst->link)
			break ;
		lst = lst->link;
	}
	return (lst);
}

int	ft_lstsize(t_list *lst)//which calculates the number of nodes in a linked list.
{
	int	size;

	size = 0;
	if (!lst)
		return (0);
	while (lst)
	{
		size++;
		lst = lst->link;
	}
	return (size);
}
void	ft_lstadd_front(t_list **lst, t_list *new)//which adds a new node to the front of a linked list
{
	if (new)
	{
		if (*lst)
			new->link = *lst;
		*lst = new;
	}
}