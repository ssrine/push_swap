/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-hark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 14:59:36 by nel-hark          #+#    #+#             */
/*   Updated: 2023/04/15 06:59:43 by nel-hark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putstr_fd(int fd, char *s)
{
	int	i;

	i = 0;
	if (!s || fd < 0)
		return ;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}
char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*p;
	size_t	k;

	k = 0;
	if (!s)
		return (0);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len >= ft_strlen(s) - start)
		len = (ft_strlen(s) - start);
	p = (char *)malloc(sizeof(char) * (len + 1));
	if (!p)
		return (NULL);
	while (k < len)
	{
		p[k] = s[start + k];
		k++;
	}
	p[k] = '\0';
	return (p);
}

char	*ft_strdup(char *s1)
{
	char	*str;
	size_t	i;

	i = 0;
	str = (char *)malloc(sizeof(char) * ft_strlen(s1) + 1);
	if (!str)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

size_t	ft_strlen(char *str)
{
	size_t	a;

	a = 0;
	while (str[a] != '\0')
	{
		a++;
	}
	return (a);
}
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	long	c;

	c = (long)n;
	if (c == -2147483648)
	{
		write(fd, "-2147483648", 11);
	}
	else if (c < 0)
	{
		ft_putchar_fd('-', fd);
		ft_putnbr_fd(c * -1, fd);
	}
	else
	{
		if (c < 10)
			ft_putchar_fd(c + '0', fd);
		else
		{
			ft_putnbr_fd(c / 10, fd);
			ft_putchar_fd(c % 10 + '0', fd);
		}
	}
}
