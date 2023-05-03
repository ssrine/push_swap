/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-hark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 11:31:16 by nel-hark          #+#    #+#             */
/*   Updated: 2023/04/30 11:43:37 by nel-hark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(t_list **a, t_list **b)
{
	sa(*a);
	sb(*b);
	ft_putstr_fd(1, "ss\n");
}

void	rrr(t_list **a, t_list **b)
{
	rra(a);
	rrb(b);
	ft_putstr_fd(1, "rrr\n");
}

void	rr(t_list **a, t_list **b)
{
	ra(a);
	rb(b);
	ft_putstr_fd(1, "rr\n");
}
