/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dozella <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 07:42:26 by dozella           #+#    #+#             */
/*   Updated: 2022/03/28 07:42:29 by dozella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_elem	*last_stack_elem(t_stack_elem *stack)
{
	if (stack == NULL)
		return (NULL);
	if (stack->next == NULL)
		return (stack);
	else
		return (last_stack_elem(stack->next));
}

t_stack_elem	*before_last_stack_elem(t_stack_elem *stack)
{
	if (stack == NULL)
		return (NULL);
	if (stack->next == NULL)
		return (NULL);
	if (stack->next->next == NULL)
		return (stack);
	else
		return (before_last_stack_elem(stack->next));
}

void	stack_add_front(t_stack_elem **stack, t_stack_elem *new)
{
	new->next = *stack;
	*stack = new;
}

void	stack_add_back(t_stack_elem **stack, t_stack_elem *new)
{
	t_stack_elem	*p;

	if (*stack == NULL)
		*stack = new;
	else
	{
		p = last_stack_elem(*stack);
		p->next = new;
	}
}

void	free_stack(t_stack_elem **head)
{
	t_stack_elem	*tmp;

	while (*head)
	{
		tmp = *head;
		*head = (*head)->next;
		free(tmp);
		tmp = NULL;
	}
}
