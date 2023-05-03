/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves3_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-hark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 08:22:22 by nel-hark          #+#    #+#             */
/*   Updated: 2023/05/03 10:42:48 by nel-hark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../push_swap.h"

void	bonus_ss(t_list **a, t_list **b)
{
	sa(*a);
	sb(*b);
}

void	bonus_rrr(t_list **a, t_list **b)
{
	rra(a);
	rrb(b);
}

void	bonus_rr(t_list **a, t_list **b)
{
	ra(a);
	rb(b);
}