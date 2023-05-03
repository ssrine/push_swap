/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves3_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-hark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 08:22:22 by nel-hark          #+#    #+#             */
/*   Updated: 2023/05/03 15:33:54 by nel-hark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	bonus_ss(t_list **a, t_list **b)
{
	sa(*a);
	sb(*b);
}

void	bonus_rrr(t_list **a, t_list **b)
{
	bonus_rra(a);
	bonus_rrb(b);
}

void	bonus_rr(t_list **a, t_list **b)
{
	bonus_ra(a);
	bonus_rb(b);
}

int	get_array_size(char **av, int ac)
{
	int		i;
	char	**split;
	int		size;
	int		j;

	i = 1;
	size = 0;
	while (i < ac)
	{
		split = ft_split(av[i], ' ');
		if (split[0] == '\0')
			print_error();
		j = 0;
		while (split[j])
		{
			free(split[j]);
			size++;
			j++;
		}
		free(split);
		i++;
	}
	return (size);
}

int	check_stack_sorted(t_list **a)
{
	t_list	*head;

	head = *a;
	while (head->link && head->data < head->link->data)
		head = head->link;
	if (!head->link)
		return (1);
	return (0);
}
