/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-hark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 08:09:33 by nel-hark          #+#    #+#             */
/*   Updated: 2023/05/03 14:25:23 by nel-hark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../push_swap.h"
# include "gnl/get_next_line.h"

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

void	init_main(t_stack *stack, int ac, char **av)
{
	stack->size = get_array_size(av, ac);
	stack->init_array = fill_array(av, ac);
	check_duplicates(stack->init_array, stack->size);
	fill_stack_a(&stack->a, stack->init_array, stack->size);
}
int	is_sorted2(t_list **a)
{
	while ((*a) && (*a)->link != NULL)
	{
		if ((*a)->data < (*a)->link->data)
		{
			*a = (*a)->link;
			return (1);
		}
		else
			return (0);
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_stack stack;
	char	*move;

	stack.a = NULL;
	stack.b = NULL;
	if (ac > 1)
	{
		init_main(&stack, ac, av);
		move = get_next_line(0);
		while (move)
		{
			
			if (!ft_strncmp(move, "\n", ft_strlen("\n")))
				break ;
			do_moves(move, &stack);
			free(move);
			move = get_next_line(0);
		}
		if (is_sorted2(&stack.a) == 0 && !ft_lstsize(stack.b)
			&& ft_lstsize(stack.a) == stack.size)
			ft_putstr_fd(1, "OK\n");
		else
			ft_putstr_fd(1, "KO\n");
	}
}