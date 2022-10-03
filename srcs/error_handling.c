/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dozella <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 07:38:57 by dozella           #+#    #+#             */
/*   Updated: 2022/03/28 07:39:00 by dozella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	numbers(char *s)
{
	while (*s && ft_isspace(*s))
		s++;
	if (*s && (*s == '-' || *s == '+'))
		s++;
	while (*s)
	{
		if (ft_isdigit(*s) != 1)
			return (1);
		s++;
	}
	return (0);
}

static int	maxmin(char *s)
{
	long long int	i;

	if (ft_strlen(s) > 11)
		return (1);
	i = ft_atoi(s);
	if (i > 2147483647 || i < -2147483648)
		return (1);
	return (0);
}

int	povtor(int argc, char **argv)
{
	int	*array;
	int	i;
	int	j;
	int	flag;

	flag = 0;
	array = (int *)malloc(sizeof(int) * (argc - 1));
	if (array == NULL)
		return (1);
	i = -1;
	while (++i < argc - 1)
		array[i] = ft_atoi(argv[i + 1]);
	i = -1;
	while (++i < argc - 2)
	{
		j = i;
		while (++j < argc - 1)
			if (array[i] == array[j])
				flag = 1;
	}
	free(array);
	array = NULL;
	return (flag);
}

int	error_arguments(int argc, char **argv)
{
	int	i;
	int	err;

	i = 1;
	err = 0;
	while (i < argc)
	{
		err = numbers(argv[i]);
		if (err > 0)
			return (err);
		err = maxmin(argv[i]);
		if (err > 0)
			return (err);
		i++;
	}
	err = povtor(argc, argv);
	if (err > 0)
		return (err);
	return (0);
}	

int	error(int argc, char **argv, int a)
{
	if (error_arguments(argc, argv) > 0)
	{
		ft_putstr_fd("Error\n", 2);
		if (a == 1)
			free_after_split(argv);
		return (1);
	}
	return (0);
}
