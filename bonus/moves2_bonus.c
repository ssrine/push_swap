/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves2_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-hark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 08:21:30 by nel-hark          #+#    #+#             */
/*   Updated: 2023/05/03 12:12:31 by nel-hark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../push_swap.h"

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
	if (!ft_strncmp(move, "sa", ft_strlen("sa")))
		bonus_sa(vars->a);
	else if (!ft_strncmp(move, "sb", ft_strlen("sb")))
		bonus_sb(vars->b);
	else if (!ft_strncmp(move, "ss", ft_strlen("ss")))
		bonus_ss(&vars->a, &vars->b);
	else if (!ft_strncmp(move, "pa", ft_strlen("pa")))
		bonus_pa(&vars->a, &vars->b);
	else if (!ft_strncmp(move, "pb", ft_strlen("pb")))
		bonus_pb(&vars->a, &vars->b);
	else if (!ft_strncmp(move, "ra", ft_strlen("ra")))
		bonus_ra(&vars->a);
	else if (!ft_strncmp(move, "rb", ft_strlen("rb")))
		bonus_rb(&vars->b);
	else if (!ft_strncmp(move, "rr", ft_strlen("rr")))
		bonus_rr(&vars->a, &vars->b);
	else if (!ft_strncmp(move, "rra", ft_strlen("rra")))
		bonus_rra(&vars->a);
	else if (!ft_strncmp(move, "rrb", ft_strlen("rrb")))
		bonus_rrb(&vars->b);
	else if (!ft_strncmp(move, "rrr", ft_strlen("rrr")))
		bonus_rrr(&vars->a, &vars->b);
	else
		print_error();
}