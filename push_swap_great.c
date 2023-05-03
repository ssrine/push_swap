/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_great.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-hark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 17:08:33 by nel-hark          #+#    #+#             */
/*   Updated: 2023/04/30 17:13:51 by nel-hark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	temp;
	int	j;
	int	count;

	i = 0;
	j = 0;
	count = 0;
	while (i < size - 1)
	{
		if (tab[i] > tab[i + 1])
		{
			temp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = temp;
			count++;
			i = 0;
		}
		else
			i++;
	}
	if (!count)
		exit(0);
}

void	init_helper(t_helper *helper, int size)
{
	if (size <= 10)
		helper->chunk_size = size / 5;
	else if (size <= 150)
		helper->chunk_size = size / 8;
	else if (size <= 500)
		helper->chunk_size = size / 18;
	helper->middle = size / 2 - 1;
	helper->start = helper->middle - helper->chunk_size;
	helper->end = helper->middle + helper->chunk_size;
	helper->array_size = size;
}
