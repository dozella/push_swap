/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_actions2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dozella <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 07:41:10 by dozella           #+#    #+#             */
/*   Updated: 2022/03/28 07:41:12 by dozella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	act_rr(t_stack_elem **head_a, t_stack_elem **head_b, int output)
{
	t_stack_elem	*tmp;
	int				flag;

	flag = 0;
	if (*head_a && (*head_a)->next)
	{
		tmp = *head_a;
		*head_a = (*head_a)->next;
		tmp->next = NULL;
		stack_add_back(head_a, tmp);
	}
	if (*head_b && (*head_b)->next)
	{
		tmp = *head_b;
		*head_b = (*head_b)->next;
		tmp->next = NULL;
		stack_add_back(head_b, tmp);
	}
	if (output)
		ft_putstr_fd("rr\n", 1);
}

void	act_rra(t_stack_elem **head, int output)
{
	t_stack_elem	*before_last;

	if (*head && (*head)->next)
	{
		before_last = before_last_stack_elem(*head);
		stack_add_front(head, before_last->next);
		before_last->next = NULL;
		if (output)
			ft_putstr_fd("rra\n", 1);
	}
}

void	act_rrb(t_stack_elem **head, int output)
{
	t_stack_elem	*before_last;

	if (*head && (*head)->next)
	{
		before_last = before_last_stack_elem(*head);
		stack_add_front(head, before_last->next);
		before_last->next = NULL;
		if (output)
			ft_putstr_fd("rrb\n", 1);
	}
}

void	act_rrr(t_stack_elem **head_a, t_stack_elem **head_b, int output)
{
	t_stack_elem	*before_last;
	int				flag;

	flag = 0;
	if (*head_a && (*head_a)->next)
	{
		before_last = before_last_stack_elem(*head_a);
		stack_add_front(head_a, before_last->next);
		before_last->next = NULL;
		flag = 1;
	}
	if (*head_b && (*head_b)->next)
	{
		before_last = before_last_stack_elem(*head_b);
		stack_add_front(head_b, before_last->next);
		before_last->next = NULL;
		flag += 1;
	}
	if (flag == 1 && output)
		ft_putstr_fd("rra\n", 1);
	if (flag == 2 && output)
		ft_putstr_fd("rrr\n", 1);
}
