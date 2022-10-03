/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dozella <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 07:40:08 by dozella           #+#    #+#             */
/*   Updated: 2022/03/28 07:40:11 by dozella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (s == NULL)
		return (0);
	while (*s)
	{
		s++;
		i++;
	}
	return (i);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (s != NULL)
		write(fd, s, ft_strlen(s));
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*p;
	char	*res;
	int		len;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	p = (char *)malloc(sizeof(char) * (len + 1));
	res = p;
	if (p == NULL)
		return (NULL);
	while (*s1)
		*p++ = *s1++;
	while (*s2)
		*p++ = *s2++;
	*p = '\0';
	return (res);
}

void	free_after_split(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		free(argv[i]);
		argv[i] = NULL;
		i++;
	}
	free(argv);
}

int	probel(char **argv)
{
	int	b;
	int	i;

	b = 0;
	i = 0;
	while (argv[1][i])
	{
		if (argv[1][i] != ' ')
			b = 1;
		i++;
	}
	if (b == 0)
		return (1);
	return (0);
}
