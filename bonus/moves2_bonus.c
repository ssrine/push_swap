/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves2_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-hark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 08:21:30 by nel-hark          #+#    #+#             */
/*   Updated: 2023/05/03 17:38:44 by nel-hark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	bonus_rb(t_list **list)
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

void	bonus_pa(t_list **a, t_list **b)
{
	t_list	*head;

	if (ft_lstsize(*b))
	{
		head = *b;
		*b = (*b)->link;
		ft_lstadd_front(a, ft_lstnew(head->data));
		free(head);
	}
}

void	bonus_pb(t_list **a, t_list **b)
{
	t_list	*head;

	if (ft_lstsize(*a))
	{
		head = *a;
		*a = (*a)->link;
		ft_lstadd_front(b, ft_lstnew(head->data));
		free(head);
	}
}

void	do_moves(char *move, t_stack *vars)
{
	if (!ft_strncmp(move, "sa\n", 3))
		bonus_sa(vars->a);
	else if (!ft_strncmp(move, "sb\n", 3))
		bonus_sb(vars->b);
	else if (!ft_strncmp(move, "rra\n", 4))
		bonus_rra(&vars->a);
	else if (!ft_strncmp(move, "rrb\n", 4))
		bonus_rrb(&vars->b);
	else if (!ft_strncmp(move, "rrr\n", 4))
		bonus_rrr(&vars->a, &vars->b);
	else if (!ft_strncmp(move, "ss\n", 3))
		bonus_ss(&vars->a, &vars->b);
	else if (!ft_strncmp(move, "pa\n", 3))
		bonus_pa(&vars->a, &vars->b);
	else if (!ft_strncmp(move, "pb\n", 3))
		bonus_pb(&vars->a, &vars->b);
	else if (!ft_strncmp(move, "ra\n", 3))
		bonus_ra(&vars->a);
	else if (!ft_strncmp(move, "rb\n", 3))
		bonus_rb(&vars->b);
	else if (!ft_strncmp(move, "rr\n", 3))
		bonus_rr(&vars->a, &vars->b);
	else
		print_error();
}
