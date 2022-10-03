/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dozella <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 07:40:58 by dozella           #+#    #+#             */
/*   Updated: 2022/03/28 07:41:00 by dozella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	act_sa(t_stack_elem **head, int output)
{
	t_stack_elem	*p;

	if (*head && (*head)->next)
	{
		p = (*head)->next;
		(*head)->next = p->next;
		p->next = (*head);
		(*head) = p;
		if (output)
			ft_putstr_fd("sa\n", 1);
	}
}

void	act_pb(t_stack_elem **head_a, t_stack_elem **head_b, int output)
{
	t_stack_elem	*p;
	t_stack_elem	*p2;

	if (*head_a)
	{
		p = *head_b;
		p2 = *head_a;
		(*head_a) = (*head_a)->next;
		(*head_b) = p2;
		(*head_b)->next = p;
		if (output)
			ft_putstr_fd("pb\n", 1);
	}	
}

void	act_pa(t_stack_elem **head_a, t_stack_elem **head_b, int output)
{
	t_stack_elem	*p;
	t_stack_elem	*p2;

	if (*head_b)
	{
		p = *head_a;
		p2 = *head_b;
		(*head_b) = (*head_b)->next;
		(*head_a) = p2;
		(*head_a)->next = p;
		if (output)
			ft_putstr_fd("pa\n", 1);
	}	
}

void	act_ra(t_stack_elem **head, int output)
{
	t_stack_elem	*tmp;

	if (*head && (*head)->next)
	{
		tmp = *head;
		*head = (*head)->next;
		tmp->next = NULL;
		stack_add_back(head, tmp);
		if (output)
			ft_putstr_fd("ra\n", 1);
	}
}

void	act_rb(t_stack_elem **head, int output)
{
	t_stack_elem	*tmp;

	if (*head && (*head)->next)
	{
		tmp = *head;
		*head = (*head)->next;
		tmp->next = NULL;
		stack_add_back(head, tmp);
		if (output)
			ft_putstr_fd("rb\n", 1);
	}
}
