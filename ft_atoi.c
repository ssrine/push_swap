
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-hark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 06:28:48 by nel-hark          #+#    #+#             */
/*   Updated: 2023/04/14 14:42:37 by nel-hark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int is_whitespace(char c) {
    return (c == 32 || (c >= 9 && c <= 13));
}

int char_to_digit(char c) 
{
    if (c >= '0' && c <= '9') 
        return c - '0';
	else
        print_error();
        return 0;
}

int ft_atoi(char *str) {
    int m ;
    size_t r;
    int i ;
    
	m = 1;
	r = 0;
	i = 0;
    while (is_whitespace(str[i]))
        i++;
    if (str[i] == '-' || str[i] == '+') {
        if (str[i] == '-') {
            m = m * -1;
        }
        i++;
    }
    if (str[i] == '\0')
        print_error();
    while (str[i]) {
        r = (r * 10) + char_to_digit(str[i]);
        if ((r > 2147483647 && m == 1) || (r > 2147483648 && m == -1))
            print_error();
        i++;
    }
    return (r * m);
}