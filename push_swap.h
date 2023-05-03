/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-hark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 18:24:00 by nel-hark          #+#    #+#             */
/*   Updated: 2023/05/03 14:44:16 by nel-hark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>

typedef struct node
{
	int			data;
	struct node	*link;
}	t_list;

typedef struct s_stack
{
	t_list	*a;
	t_list	*b;
	int		*init_array;
	int		size;
}	t_stack;

typedef struct fill
{
	int		size;
	int		i;
	char	**split;
	int		j;
	int		*tab;
	int		counterargs;
}	t_fill;

typedef struct s_helper
{
	int	size;
	int	median;
	int	start;
	int	end;
	int	middle;
	int	array_size;
	int	chunk_size;
}	t_helper;

char	*ft_strdup(char *s1);
size_t	ft_strlen(char *str);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	**ft_split(char *s, char c);
int		ft_atoi(char *str);
void	ft_putstr_fd(int fd, char *s);
void	ft_putchar_fd(char c, int fd);
void	ft_putnbr_fd(int n, int fd);
int		*fill_array(char **av, int ac);
int		get_array_size(char **av, int ac);
void	check_duplicates(int *tab, int size);
void	print_error(void);
void	sa(t_list *list);
int		is_sorted(int *arr, int size);
void	rra(t_list **list);
t_list	*ft_lstnew(int content);
void	ft_lstadd_back(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ra(t_list **list);
void	sort_tlata(t_list **list);
void	sort_tlata_help(t_list **list);
void	sort_five(t_list **a, t_list **b);
void	sort_stack(t_stack *stack, t_helper *helper);
void	sb(t_list *list);
void	ss(t_list **a, t_list **b);
void	rrb(t_list **list);
void	rrr(t_list **a, t_list **b);
void	rb(t_list **list);
void	rr(t_list **a, t_list **b);
void	pa(t_list **a, t_list **b);
void	pb(t_list **a, t_list **b);
int		get_min(t_list **a);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	init_helper(t_helper *helper, int size);
void	push_to_b(t_list **a, t_list **b, t_helper *helper, int *array);
void	push_to_a(t_stack *vars);
void	find_head_to_move(t_list **a, int *array, t_helper *helper);
void	move_head_to_top(t_list **a, t_list *head, int array_size);
void	push_to_a_2(t_stack *vars, int *down);
void	update_params(t_helper *helper);
int		search_content(t_list **a, int find);
int		max_in_b(t_list **b, int max);
void	ft_sort_int_tab(int *tab, int size);
void	move_b(t_stack *vars);
void	push_a_top(t_stack *vars, int *down);
void	init_main(t_stack *vars, int ac, char **av);
void	do_moves(char *move, t_stack *vars);
void	bonus_sa(t_list *list);
void	bonus_sb(t_list *list);
void	bonus_rra(t_list **list);
void	bonus_rrb(t_list **list);
void	bonus_ra(t_list **list);
void	bonus_rb(t_list **list);
void	bonus_pa(t_list **a, t_list **b);
void	bonus_pb(t_list **a, t_list **b);
void	bonus_ss(t_list **a, t_list **b);
void	bonus_rrr(t_list **a, t_list **b);
void	bonus_rr(t_list **a, t_list **b);
void	fill_stack_a(t_list **a, int *array, int size);
int		*fill_array(char **av, int ac);
int	ft_strncmp(const char *s1, const char *s2, size_t n);
int	is_sorted2(int *arr, int size);
#endif