/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-hark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 08:09:33 by nel-hark          #+#    #+#             */
/*   Updated: 2023/05/03 15:34:55 by nel-hark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "gnl/get_next_line.h"

void	fill_stack_a(t_list **a, int *array, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		ft_lstadd_back(a, ft_lstnew(array[i]));
		i++;
	}
}

int	*fill_array(char **av, int ac)
{
	t_fill	array;

	array.counterargs = get_array_size(av, ac);
	array.tab = malloc(sizeof(int) * (array.counterargs));
	array.i = 1;
	array.size = 0;
	while (array.i < ac)
	{
		array.split = ft_split(av[array.i], ' ');
		array.j = 0;
		while (array.split[array.j])
		{
			array.tab[array.size] = ft_atoi(array.split[array.j]);
			array.size++;
			free(array.split[array.j]);
			array.j++;
		}
		free(array.split);
		array.i++;
	}
	return (array.tab);
}

void	init_main(t_stack *stack, int ac, char **av)
{
	stack->size = get_array_size(av, ac);
	stack->init_array = fill_array(av, ac);
	check_duplicates(stack->init_array, stack->size);
	fill_stack_a(&stack->a, stack->init_array, stack->size);
}

int	main(int ac, char **av)
{
	t_stack	vars;
	char	*move;

	vars.a = NULL;
	vars.b = NULL;
	if (ac > 1)
	{
		init_main(&vars, ac, av);
		move = get_next_line(0);
		while (move)
		{
			if (!ft_strncmp(move, "\n", ft_strlen("\n")))
				break ;
			do_moves(move, &vars);
			free(move);
			move = get_next_line(0);
		}
		if (check_stack_sorted(&vars.a) == 1 && !ft_lstsize(vars.b)
			&& ft_lstsize(vars.a) == vars.size)
			ft_putstr_fd(1, "OK\n");
		else
			ft_putstr_fd(1, "KO\n");
	}
	return (0);
}
