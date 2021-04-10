NAME	:= checker
SRCS	:= checker.c
OBJS	:= $(SRCS:.c=.o)
LIBFT	:= libft
CC		:= gcc
CFLAGS	:= -Wall -Wextra -Werror


all		: $(NAME)

$(NAME)	: $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L$(LIBFT) -lft

$(LIBFT): FORCE
	make -C $(LIBFT)

FORCE:

clean	:
	$(MAKE) clean -C $(LIBFT)
	$(RM) $(OBJS)

fclean	: clean
	$(MAKE) fclean -C $(LIBFT)
	$(RM) $(NAME)

re		: fclean all

.PHONY	: all clean fclean re