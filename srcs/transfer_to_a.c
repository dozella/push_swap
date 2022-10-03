/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transfer_to_a.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dozella <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 07:42:41 by dozella           #+#    #+#             */
/*   Updated: 2022/03/28 07:42:43 by dozella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_elem	*make_des_5(t_stack_elem *head, int *transfer_type)
{
	int	best_total_score;
	int	best_transfer_type;

	best_total_score = total_score_elem(head, transfer_type);
	best_transfer_type = *transfer_type;
	if (best_total_score == total_score_elem(head->next, transfer_type)
		&& head->rank < head->next->rank)
		return (head->next);
	*transfer_type = best_transfer_type;
	return (head);
}

void	scoring_in_b(t_stack_elem *head_b)
{
	int	size;
	int	i;

	size = stack_size(head_b);
	i = 0;
	while (head_b)
	{
		head_b->b_score = i;
		head_b->b_rscore = size - i;
		i++;
		head_b = head_b->next;
	}
}

void	scoring_in_a(t_stack_elem *head_a, t_stack_elem *head_b)
{
	t_stack_elem	*save_point;
	int				size;
	int				i;
	int				prev;

	size = stack_size(head_a);
	save_point = head_a;
	while (head_b)
	{
		head_a = save_point;
		i = 0;
		prev = last_stack_elem(head_a)->value;
		while (head_a)
		{
			if (prev < head_b->value && head_a->value > head_b->value)
			{
				head_b->a_score = i;
				head_b->a_rscore = size - i;
			}
			i++;
			prev = head_a->value;
			head_a = head_a->next;
		}
		head_b = head_b->next;
	}
}

void	transfer_to_a(t_stack_elem **head_a, t_stack_elem **head_b)
{
	t_stack_elem	*best_rank_elem;
	int				transfer_type;

	scoring_in_b(*head_b);
	scoring_in_a(*head_a, *head_b);
	best_rank_elem = make_decision(*head_b, &transfer_type);
	process_decision(head_a, head_b, best_rank_elem, &transfer_type);
}