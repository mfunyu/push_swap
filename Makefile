NAME				:= push_swap
SRCS_DIR			:= push_swap_srcs
SRCS_FILES			:= push_swap.c
SRCS				:= $(addprefix $(SRCS_DIR)/, $(SRCS_FILES))
OBJS				:= $(SRCS:.c=.o)

CHECKER				:= checker
CHECKER_SRCS_DIR	:= checker_srcs
CHECKER_SRCS_FILES	:= checker.c \
					free.c \
					reader.c \
					executer.c \
					stacklst_add_back.c \
					stacklst_add_front.c \
					stacklst_clear.c \
					stacklst_last.c \
					stacklst_new.c \
					stacklst_init.c \
					stacklst_pop.c \
					stacklst_insert.c \
					operation_push.c \
					operation_swap.c \
					operation_rotate.c \
					operation_revrotate.c \
					\
					dbg/print_stack.c
CHECKER_SRCS		:= $(addprefix $(CHECKER_SRCS_DIR)/, $(CHECKER_SRCS_FILES)) \
					get_next_line/get_next_line.c \
					get_next_line/get_next_line_utils.c
CHECKER_OBJS		:= $(CHECKER_SRCS:.c=.o)

INCLUDES	:= -Iincludes -Ilibft -Iget_next_line
LIBFT		:= libft
LIBS		:= -L$(LIBFT) -lft
CC			:= gcc
CFLAGS		:= -g -Wall -Wextra -Werror $(INCLUDES)


all		: $(NAME) $(CHECKER)

$(NAME)	: $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBS)

$(CHECKER)	: $(LIBFT) $(CHECKER_OBJS)
	$(CC) $(CFLAGS) -o $(CHECKER) $(CHECKER_OBJS) $(LIBS)

$(LIBFT): FORCE
	make -C $(LIBFT)

FORCE:

clean	:
	make clean -C $(LIBFT)
	$(RM) $(OBJS) $(CHECKER_OBJS)

fclean	: clean
	make fclean -C $(LIBFT)
	$(RM) $(NAME) $(CHECKER)

re		: fclean all

.PHONY	: all clean fclean re