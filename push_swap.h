/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-hark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 18:24:00 by nel-hark          #+#    #+#             */
/*   Updated: 2023/04/28 12:53:34 by nel-hark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H


#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

typedef struct node 
{
    int data;
    struct node *link;
}	t_list;

typedef struct s_stack
{
    t_list *a;
    t_list *b;
	int		*init_array;
	int		size;
}   t_stack;

typedef struct s_helper
{
	int size;
	int median;
	int rotated;
	int pushed;
	int		start;
	int		end;
	int		middle;
	int		array_size;
	int		chunk_size;
}			t_helper;

char	*ft_strdup(char *s1);
size_t	ft_strlen(char *str);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	**ft_split(char  *s, char c);
int	ft_atoi( char *str);
void	ft_putstr_fd(int fd, char *s);
void	ft_putchar_fd(char c, int fd);
void	ft_putnbr_fd(int n, int fd);
int *fill_array(char **av, int ac);
int get_array_size(char **av, int ac);
void	check_duplicates(int *tab, int size);
void print_error();
void    sa(t_list *list);
int is_sorted(int *arr, int size);
void rra(t_list **list);
t_list	*ft_lstnew(int content);
void	ft_lstadd_back(t_list **lst, t_list *new);
int	ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void ra(t_list **list);
void  sort_tlata(t_list **list);
void sort_five(t_list **a, t_list **b);
void    sb(t_list *list);
void ss(t_list **a, t_list **b);
void rrb(t_list **list);
void rrr(t_list **a, t_list **b);
void rb(t_list **list);
void rr(t_list **a, t_list **b);
void pa(t_list **a, t_list **b);
void pb(t_list **a, t_list **b);
int get_min(t_list **a);
void	ft_lstadd_front(t_list **lst, t_list *new);
void init_helper(t_helper *helper, int size);
void	push_to_b(t_list **a, t_list **b, t_helper *helper, int *array);
void	push_to_a(t_stack *vars);
void	ra_rra(t_list **a, t_list **b, int *array, t_helper *helper);
void	push_to_a_helper(t_stack *vars, int *down);
void	update_params(t_helper *helper);
int	search_content(t_list **a, int find);
int	max_in_b(t_list **b, int max);
void    ft_sort_int_tab(int *tab, int size);
#endif