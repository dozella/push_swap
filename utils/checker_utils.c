/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dozella <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 07:38:35 by dozella           #+#    #+#             */
/*   Updated: 2022/03/28 07:38:39 by dozella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_not_finally_sorted(t_stack_elem *head)
{
	t_stack_elem	*p;
	int				flag;

	flag = 0;
	p = head;
	while (head && head->next)
	{
		if (head->value > head->next->value)
			return (1);
		head = head->next;
	}
	return (0);
}

static int	do_action(t_stack_elem **head_a, t_stack_elem **head_b,
	char *act)
{
	if (ft_strcmp(act, "sa") == 0)
		act_sa(head_a, 0);
	else if (ft_strcmp(act, "sb") == 0)
		act_sb(head_b, 0);
	else if (ft_strcmp(act, "ss") == 0)
		act_ss(head_a, head_b, 0);
	else if (ft_strcmp(act, "pa") == 0)
		act_pa(head_a, head_b, 0);
	else if (ft_strcmp(act, "pb") == 0)
		act_pb(head_a, head_b, 0);
	else if (ft_strcmp(act, "ra") == 0)
		act_ra(head_a, 0);
	else if (ft_strcmp(act, "rb") == 0)
		act_rb(head_b, 0);
	else if (ft_strcmp(act, "rr") == 0)
		act_rr(head_a, head_b, 0);
	else if (ft_strcmp(act, "rra") == 0)
		act_rra(head_a, 0);
	else if (ft_strcmp(act, "rrb") == 0)
		act_rrb(head_b, 0);
	else if (ft_strcmp(act, "rrr") == 0)
		act_rrr(head_a, head_b, 0);
	else
		return (1);
	return (0);
}

static int	vvod(char (*buf)[5])
{
	int		size;
	char	symbol[2];

	*buf[0] = '\0';
	size = read(0, symbol, 1);
	symbol[1] = '\0';
	while (symbol[0] != '\n' && ft_strlen(*buf) < 5 && size != 0)
	{
		ft_strlcat(*buf, symbol, 5);
		size = read(0, symbol, 1);
	}
	return (size);
}

void	read_instructions(t_stack_elem **head_a)
{
	t_stack_elem	*head_b;
	char			buf[5];
	int				size;

	head_b = NULL;
	size = vvod(&buf);
	while (size != 0)
	{
		if (do_action(head_a, &head_b, buf) != 0)
		{
			free_stack(&head_b);
			ft_putstr_fd("Error\n", 2);
			return ;
		}
		size = vvod(&buf);
	}
	if (is_not_finally_sorted(*head_a) || stack_size(head_b) > 0)
	{
		ft_putstr_fd("KO\n", 1);
		free_stack(&head_b);
	}
	else
		ft_putstr_fd("OK\n", 1);
}
