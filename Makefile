NAME				:= push_swap

SRCS_DIR			:= srcs
SRCS_FILES			:= $(wildcard ./srcs/*.c)
# SRCS				:= $(addprefix $(SRCS_DIR)/, $(SRCS_FILES))
# OBJS				:= $(SRCS:.c=.o)
OBJS				:= $(SRCS_FILES:.c=.o)

PS_SRCS_DIR			:= push_swap_srcs
# PS_SRCS_FILES		:= push_swap.c
PS_SRCS_FILES		:= $(wildcard ./push_swap_srcs/*.c)
# PS_SRCS				:= $(addprefix $(PS_SRCS_DIR)/, $(PS_SRCS_FILES))
# PS_OBJS				:= $(PS_SRCS:.c=.o)
PS_OBJS				:= $(PS_SRCS_FILES:.c=.o)
# PS_OBJS				+= $(SRCS:.c=.o)
PS_OBJS				+= $(SRCS_FILES:.c=.o)

CHECKER				:= checker
CHECKER_SRCS_DIR	:= checker_srcs
CHECKER_SRCS_FILES	:= $(wildcard ./checker_srcs/*.c)
# CHECKER_SRCS		:= $(addprefix $(CHECKER_SRCS_DIR)/, $(CHECKER_SRCS_FILES))
CHECKER_SRCS_FILES	+= get_next_line/get_next_line.c \
 					get_next_line/get_next_line_utils.c
# CHECKER_OBJS		:= $(CHECKER_SRCS:.c=.o)
CHECKER_OBJS		:= $(CHECKER_SRCS_FILES:.c=.o)
# CHECKER_OBJS		+= $(SRCS:.c=.o)
CHECKER_OBJS		+= $(SRCS_FILES:.c=.o)

INCLUDES	:= -Iincludes -Ilibft -Iget_next_line
LIBFT		:= libft
LIBS		:= -L$(LIBFT) -lft
CC			:= gcc
CFLAGS		:= -Wall -Wextra -Werror $(INCLUDES)
CFLAGS		+= -fsanitize=address

all		: $(NAME)

$(NAME)	: $(LIBFT) $(PS_OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(PS_OBJS) $(LIBS)

$(CHECKER)	: $(LIBFT) $(CHECKER_OBJS)
	$(CC) $(CFLAGS) -o $(CHECKER) $(CHECKER_OBJS) $(LIBS)

$(LIBFT): FORCE
	make -C $(LIBFT)

FORCE:

clean	:
	# make clean -C $(LIBFT)
	$(RM) $(PS_OBJS) $(CHECKER_OBJS)

fclean	: clean
	# make fclean -C $(LIBFT)
	$(RM) $(NAME) $(CHECKER)

re		: fclean all

.PHONY	: all clean fclean re