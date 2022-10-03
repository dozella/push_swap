/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dozella <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 07:39:08 by dozella           #+#    #+#             */
/*   Updated: 2022/03/28 07:39:11 by dozella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	ft_isspace(int c)
{
	if (c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r' || c == ' ')
		return (1);
	return (0);
}

long long int	ft_atoi(const char *str)
{
	long				i;
	unsigned long long	nbr;
	int					isneg;

	i = 0;
	nbr = 0;
	isneg = 1;
	while (str[i] != '\0' && ft_isspace(str[i]))
		i++;
	if (str[i] != '\0' && str[i] == '-')
	{
		isneg = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	if (!str[i])
		return (11111111111111);
	while (str[i] != '\0' && ft_isdigit(str[i]))
		nbr = (nbr * 10) + (str[i++] - '0');
	if ((nbr >= 9223372036854775807) && isneg == 1)
		return (-1);
	if ((nbr >= 9223372036854775807) && isneg == -1)
		return (0);
	return (nbr * isneg);
}
