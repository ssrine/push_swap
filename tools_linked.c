/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_linked.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-hark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 09:56:53 by nel-hark          #+#    #+#             */
/*   Updated: 2023/04/30 17:20:44 by nel-hark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstnew(int content)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->data = content;
	new->link = NULL;
	return (new);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
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

t_list	*ft_lstlast(t_list *lst)
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

int	ft_lstsize(t_list *lst)
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

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (new)
	{
		if (*lst)
			new->link = *lst;
		*lst = new;
	}
}
