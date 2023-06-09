/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-hark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 02:48:17 by nel-hark          #+#    #+#             */
/*   Updated: 2023/05/03 11:05:56 by nel-hark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	sort_stack(t_stack *stack, t_helper *helper)
{
	if (stack->size == 2)
		sa(stack->a);
	else if (stack->size == 3)
		sort_tlata(&stack->a);
	else if (stack->size <= 5)
		sort_five(&stack->a, &stack->b);
	else
	{
		ft_sort_int_tab(stack->init_array, stack->size);
		init_helper(helper, stack->size);
		push_to_b(&stack->a, &stack->b, helper, stack->init_array);
		stack->size--;
		push_to_a(stack);
	}
}

int	main(int ac, char **av)
{
	t_stack		stack;
	t_helper	helper;
	int			size;
	int			*tab;

	(void)ac;
	stack.a = NULL;
	stack.b = NULL;
	size = get_array_size(av, ac);
	stack.size = size;
	tab = fill_array(av, ac);
	check_duplicates(tab, size);
	fill_stack_a(&stack.a, tab, size);
	stack.init_array = tab;
	if (is_sorted(stack.init_array, stack.size) == 1)
		exit(0);
	sort_stack(&stack, &helper);
}
