/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dozella <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 07:40:35 by dozella           #+#    #+#             */
/*   Updated: 2022/03/28 07:40:38 by dozella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	work(int argc, char **argv)
{
	t_stack_elem	*head_a;

	head_a = stack_init(argc, argv);
	stack_sort(&head_a);
	free_stack(&head_a);
	if (argv[0][0] == 'q')
		free_after_split(argv);
}

int	main(int argc, char **argv)
{
	char	*str;
	int		a;

	a = 0;
	if (argc == 1)
		return (0);
	if (argc == 2)
	{
		if (probel(argv) == 1)
			return (0);
		str = ft_strjoin("q ", argv[1]);
		argv = ft_split(str, ' ');
		free(str);
		argc = size(argv);
		a = 1;
	}
	if (error(argc, argv, a) == 1)
		return (0);
	if (argc > 1)
		work(argc, argv);
}
