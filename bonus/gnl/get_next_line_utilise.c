/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utilise.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-hark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 08:14:06 by nel-hark          #+#    #+#             */
/*   Updated: 2023/05/03 09:15:20 by nel-hark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*c;
	size_t	i;

	i = 0;
	if (count != 0 && size > SIZE_MAX / count)
		return (NULL);
	c = malloc(count * size);
	if (!c)
		return (NULL);
	while (i < count * size)
	{
		*((unsigned char *)(c + i)) = 0;
		i++;
	}
	return (c);
}

int	ft_strlenl(char *s)
{
	int	a;

	a = 0;
	while (s && s[a] != '\0')
	{
		a++;
	}
	return (a);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*p;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	p = malloc(sizeof(char) * (ft_strlenl(s1) + ft_strlenl(s2) + 1));
	if (!p)
		return (NULL);
	while (s1[i])
		p[i++] = s1[j++];
	i = 0;
	while (s2[i])
		p[j++] = s2[i++];
	p[j] = '\0';
	if (s1)
		free(s1);
	return (p);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (0);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	i = 0;
	str1 = (unsigned char *) s1;
	str2 = (unsigned char *) s2;
	while (i < n && (str1[i] || str2[i]))
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (0);
}
