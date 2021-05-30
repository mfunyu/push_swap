NAME				:= push_swap

SRCS_DIR			:= utils
SRCS_FILES			:= check_arg.c \
						check_is_sorted.c \
						null_free.c \
						operation_push.c \
						operation_revrotate.c \
						operation_rotate.c \
						operation_swap.c \
						stacklst_clear.c \
						stacklst_insert.c \
						stacklst_new.c \
						stacklst_pop.c
SRCS				:= $(addprefix $(SRCS_DIR)/, $(SRCS_FILES))
OBJS				:= $(SRCS:.c=.o)

PS_SRCS_DIR			:= push_swap_srcs
PS_SRCS_FILES		:= push_swap.c \
						exec_add_instructions.c \
						info_clear.c \
						ps_print_instructions.c \
						ps_print_stack.c \
						qsort.c \
						simplelst_utils.c \
						sort_all.c \
						sort_five.c \
						sort_stack.c \
						sort_three.c \
						sort_two.c \
						stack_a_init_utils.c \
						stack_count.c \
						stack_split.c \
						stacks_init.c
PS_SRCS				:= $(addprefix $(PS_SRCS_DIR)/, $(PS_SRCS_FILES))
PS_OBJS				:= $(PS_SRCS:.c=.o)
PS_OBJS				+= $(OBJS)

CHECKER				:= checker
CHECKER_SRCS_DIR	:= checker_srcs
CHECKER_SRCS_FILES	:= checker.c \
						ch_print_stack.c \
						ch_init_stacks.c \
						executer.c \
						reader.c \
						stacklst_init.c \
						stacklst_add_back.c \
						stacklst_add_front.c \
						stacklst_last.c \
						stacks_clear.c
CHECKER_SRCS		:= $(addprefix $(CHECKER_SRCS_DIR)/, $(CHECKER_SRCS_FILES))
CHECKER_SRCS		+= get_next_line/get_next_line.c \
 						get_next_line/get_next_line_utils.c
CHECKER_OBJS		:= $(CHECKER_SRCS:.c=.o)
CHECKER_OBJS		+= $(OBJS)

INCLUDES	:= -Iincludes -Ilibft -Iget_next_line
LIBFT		:= libft
LIBS		:= -L$(LIBFT) -lft
CC			:= gcc
CFLAGS		:= -Wall -Wextra -Werror $(INCLUDES)

all		: $(NAME) $(CHECKER)

$(NAME)	: $(LIBFT) $(PS_OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(PS_OBJS) $(LIBS)

$(CHECKER)	: $(LIBFT) $(CHECKER_OBJS)
	$(CC) $(CFLAGS) -o $(CHECKER) $(CHECKER_OBJS) $(LIBS)

$(LIBFT)	: FORCE
	make -C $(LIBFT)

FORCE	:

clean	:
	make clean -C $(LIBFT)
	$(RM) $(PS_OBJS) $(CHECKER_OBJS)

fclean	: clean
	make fclean -C $(LIBFT)
	$(RM) $(NAME) $(CHECKER)

re		: fclean all

.PHONY	: all clean fclean re