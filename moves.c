/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-hark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 09:55:58 by nel-hark          #+#    #+#             */
/*   Updated: 2023/04/29 09:26:52 by nel-hark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    sa(t_list *list)
{
    int tmp;

    if (ft_lstsize(list) > 1)
	{
        tmp = list->data;
        list->data = list->link->data;
        list->link->data = tmp;
    }

    ft_putstr_fd(1, "sa\n");
}

void    sb(t_list *list)
{
    int tmp;

    if (ft_lstsize(list) > 1)
	{
        tmp = list->data;
        list->data = list->link->data;
        list->link->data = tmp;
    }

    ft_putstr_fd(1, "sb\n");
}
void ss(t_list **a, t_list **b)
{
    sa(*a);
    sb(*b);
    ft_putstr_fd(1, "ss\n");
}
void rra(t_list **list)
{   
    t_list *head = *list;
    if (head == NULL || head->link == NULL)
        return; // the list is empty or has only one element

    t_list *befor_last_node = head;
    t_list *last;

    last = ft_lstlast(head);
    while(befor_last_node->link->link)
        befor_last_node = befor_last_node->link;
        
    befor_last_node->link = NULL;
    last->link = head;
    *list = last;
    ft_putstr_fd(1, "rra\n");
}
void rrb(t_list **list)
{   

    t_list *head = *list;
    if (head == NULL || head->link == NULL)
        return; // the list is empty or has only one element

    t_list *befor_last_node = head;
    t_list *last;

    last = ft_lstlast(head);
    while(befor_last_node->link->link)
        befor_last_node = befor_last_node->link;
        
    befor_last_node->link = NULL;
    last->link = head;
    *list = last;
    ft_putstr_fd(1, "rrb\n");
}
void rrr(t_list **a, t_list **b)
{
    rra(a);
    rrb(b);
    ft_putstr_fd(1, "rrr\n");
}
void ra(t_list **list)
{   
    t_list *head = *list;
    if (head == NULL || head->link == NULL) {
        return; // the list is empty or has only one element
    }

    t_list *new_head = head->link;
    t_list *last = ft_lstlast(head);

    last->link = head;
    head->link = NULL;
    *list = new_head;

    ft_putstr_fd(1, "ra\n");
}
void rb(t_list **list)
{   
    t_list *head = *list;
    if (head == NULL || head->link == NULL) {
        return; // the list is empty or has only one element
    }

    t_list *new_head = head->link;
    t_list *last = ft_lstlast(head);

    last->link = head;
    head->link = NULL;
    *list = new_head;

    ft_putstr_fd(1, "rb\n");
}
void rr(t_list **a, t_list **b)
{
    ra(a);
    rb(b);

    ft_putstr_fd(1, "rr\n");
}

void pa(t_list **a, t_list **b)
{
    t_list	*head;

	if (ft_lstsize(*b))
	{
		head = *b;
		*b = (*b)->link;
		ft_lstadd_front(a, ft_lstnew(head->data));
		free(head);
    }
    ft_putstr_fd(1,"pa\n" );
}
void pb(t_list **a, t_list **b)
{
   t_list	*head;

	if (ft_lstsize(*a))
	{
		head = *a;
		*a = (*a)->link;
		ft_lstadd_front(b, ft_lstnew(head->data));
		free(head);
    }
    
    ft_putstr_fd(1,"pb\n" );
}