/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dozella <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 11:02:18 by dozella           #+#    #+#             */
/*   Updated: 2022/03/28 11:02:20 by dozella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack_elem
{
	struct s_stack_elem	*next;
	int					value;
	int					a_score;
	int					a_rscore;
	int					b_score;
	int					b_rscore;
	int					rank;
}	t_stack_elem;

int				error_arguments(int argc, char **argv);
t_stack_elem	*make_des_5(t_stack_elem *head, int *transfer_type);
int				error(int argc, char **argv, int a);
void			ft_putstr_fd(char *s, int fd);
size_t			ft_strlen(const char *s);
char			*ft_strjoin(char const *s1, char const *s2);
void			free_after_split(char **argv);
int				probel(char **argv);
t_stack_elem	*stack_init(int argc, char **argv);
int				stack_size(t_stack_elem *stack);
void			stack_add_front(t_stack_elem **stack, t_stack_elem *new);
void			stack_add_back(t_stack_elem **stack, t_stack_elem *new);
t_stack_elem	*last_stack_elem(t_stack_elem *stack);
t_stack_elem	*before_last_stack_elem(t_stack_elem *stack);
void			free_stack(t_stack_elem **head);
long long int	ft_atoi(const char *str);
int				ft_isdigit(int c);
int				ft_isspace(int c);
t_stack_elem	*stack_sort(t_stack_elem **head);
void			act_sa(t_stack_elem **head, int output);
void			act_pb(t_stack_elem **head, t_stack_elem **head_b, int output);
void			act_pa(t_stack_elem **head_a, t_stack_elem **head_b,
					int output);
void			act_ra(t_stack_elem **head, int output);
void			act_rb(t_stack_elem **head, int output);
void			act_rr(t_stack_elem **head_a, t_stack_elem **head_b,
					int output);
void			act_rra(t_stack_elem **head, int output);
void			act_rrb(t_stack_elem **head, int output);
void			act_rrr(t_stack_elem **head_a, t_stack_elem **head_b,
					int output);
void			act_sb(t_stack_elem **head, int output);
void			act_ss(t_stack_elem **head_a, t_stack_elem **head_b,
					int output);
int				is_not_presorted(t_stack_elem *head);
void			final_sort_stack(t_stack_elem **head);
int				find_minmaxmed(t_stack_elem **head,
					int *min, int *max, int *med);
int				*sort_array(int *array, int size, t_stack_elem *head);
void			start_rotating(t_stack_elem **head, int index);
void			transfer_to_a(t_stack_elem **head_a, t_stack_elem **head_b);
int				total_score_elem2(int result, t_stack_elem *head, int *ttype);
int				total_score_elem(t_stack_elem *head, int *ttype);
t_stack_elem	*make_decision(t_stack_elem *head, int *transfer_type);
void			process_decision2(t_stack_elem **head_a, t_stack_elem **head_b,
					t_stack_elem *elem, int *ttype);
void			process_decision(t_stack_elem **head_a, t_stack_elem **head_b,
					t_stack_elem *elem, int *ttype);
char			**ft_split(char const *s, char c);
int				size(char **words);
void			read_instructions(t_stack_elem **head_a);
int				ft_strcmp(char *s1, char *s2);
size_t			ft_strlcat(char *dst, const char *src, size_t dstsize);

#endif
