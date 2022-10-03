SRCS =	error_handling.c ft_atoi.c libft.c\
		stack_actions.c stack_actions2.c stack_sort.c\
		stack_sort_utils.c\
		stack_utils.c stack_utils2.c\
		transfer_to_a.c transfer_to_a2.c\
		ft_split.c main.c

SRCS_B = ft_split.c libft.c stack_utils.c\
		stack_utils2.c ft_atoi.c error_handling.c\
		stack_actions.c stack_actions2.c\
		checker.c checker_utils.c libft_checker.c\
		stack_actions3.c
OBJS = 	$(SRCS:.c=.o)
OBJS_B = $(SRCS_B:.c=.o)

NAME = 	push_swap
NAME_B = checker

HDRS =	push_swap.h

CC = 	cc
CFLAGS = -Wall -Wextra -Werror
RM = 	rm -f

all: $(NAME)

%.o: %.c
	$(CC) -c $(CFLAGS) $?

$(NAME):$(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

bonus: $(NAME_B)

$(NAME_B): $(OBJS_B)
	$(CC) $(CFLAGS) $(OBJS_B) -o $(NAME_B)

clean:
	$(RM) $(OBJS)
	$(RM) $(OBJS_B)

fclean: clean
	$(RM) $(NAME)
	$(RM) $(NAME_B)

re: fclean all

norm:
	norminette -R CheckForbiddenSourceHeader $(SRCS) $(SRCS_B)
	norminette -R CheckDefine $(HDRS)

.PHONY: all clean fclean re bonus norm