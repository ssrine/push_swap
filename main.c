/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-hark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 02:48:17 by nel-hark          #+#    #+#             */
/*   Updated: 2023/04/29 17:15:56 by nel-hark         ###   ########.fr       */
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
int is_sorted(int *arr, int size)
{
    int i;

    i = 0;
    while (i < size - 1) 
    {
        if (arr[i] > arr[i + 1]) 
        {
            return (0);
        }
        i++;
    }
    return (1);
}
int *fill_array(char **av, int ac)
{
    int i;
    char **split;
    int j ;
    int *tab;
    int counterargs;

    counterargs = get_array_size(av, ac);
    //printf("---%d\n", counterargs);
    tab = malloc(sizeof(int) *(counterargs));
    i = 1;
    int size = 0;
    while (i < ac)
    {
        split = ft_split(av[i] , ' ');
        j = 0;
        while(split[j])
        {
            tab[size] = ft_atoi(split[j]);// free(split[j])
            size++; // size
            free(split[j]);
            j++;
        }
        free(split);
        i++;
    }
    // system("leaks push_swap");
    return(tab);
}
int get_array_size(char **av, int ac)
{
    int i = 1;
    char ** split;
    int size = 0;
    while(i < ac)
    {
        split = ft_split(av[i], ' ');
        if (split[0] == '\0') //douple ""
			print_error();
        int j = 0;
        while (split[j])
        {
            free(split[j]);
            size++;
            j++;
        }
        free(split);
        i++;
    }
    // system("leaks push_swap");
    return(size);
}
// void sort_numbers_greater_than_five(t_list **a, t_list **b)
// {
//     t_helper helper;

//     if (ft_lstsize(*a) <= 5)
//     {
//         if (ft_lstsize(*a) == 3)
//             sort_tlata(a);
//         else if (ft_lstsize(*a) <= 5)
//             sort_five(a, b);
//         return;
//     }

//     init_helper(&helper, ft_lstsize(*a));
	
//     sort_numbers_greater_than_five(a, b);
// }

void    ft_sort_int_tab(int *tab, int size)
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

int main(int ac, char **av)
{
    (void)ac;

    t_stack stack;
    t_list *p;
    t_list *l;
    t_helper helper;

    stack.a = NULL;
    stack.b = NULL;


    int size = get_array_size(av, ac);
    stack.size = size;
    int *tab = fill_array(av, ac);
    check_duplicates(tab, size);
    fill_stack_a(&stack.a, tab, size);
    
    if(is_sorted(tab, size) == 1)
        exit(0);
    if (size == 2)
        sa(stack.a);
    else if( size == 3)
        sort_tlata(&stack.a);
    else if(size <= 5)
        sort_five(&stack.a,&stack.b);
	else
	{       stack.init_array = tab; 
            ft_sort_int_tab(stack.init_array, stack.size);
			init_helper(&helper, size);
			push_to_b(&stack.a, &stack.b, &helper, stack.init_array);
            stack.size--;
        //    max_in_b(&stack.b, *stack.init_array);
            push_to_a(&stack);
            // printf("-->%d\n",stack.size);
            // sleep(1);
            // if(stack.size %  2 == 0)
            //     rra(&stack.a);
            
	}
    // system("leaks push_swap");
    p = stack.a;
    l = stack.b;
    while (p)
    {
        printf("staaaaackkkk AAA==> %d\n", p->data);
        p = p->link;
    }
    while (l)
    {
        printf("staackkkkk BBB==> %d\n", l->data);
        l = l->link;
    }
}

