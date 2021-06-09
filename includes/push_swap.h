#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "utils.h"

# define CLEAR_SCREEN "\033[1J"
# define SHIFT_CURSOR "\x1b[999B"
# define CURSOR_POSITION "\x1b[6n"

# define SLEEP_LENGTH 1500000
# define STACK_WIDTH 11

# define C_CYAN "\e[36m"
# define C_DEFAULT "\e[00m"
# define STR_STACK_B " ============_b_==========="
# define STR_EMPTY_A "                             "

typedef enum e_stack_type
{
	A,
	B
}			t_stack_type;

typedef enum e_op_name
{
	sa,
	sb,
	ss,
	pa,
	pb,
	ra,
	rb,
	rr,
	rra,
	rrb,
	rrr
}			t_op_name;

typedef enum e_op_type
{
	swap,
	push,
	rotate,
	revrotate
}			t_op_type;

typedef struct s_simple
{
	int				value;
	struct s_simple	*next;
}				t_simple;

typedef struct s_info
{
	t_stack		*stack_a;
	t_stack		*stack_b;
	t_simple	*instructions;
	t_simple	*pivot;
	int			sorted_id;
	int			a_len;
	int			a_max;
	int			a_min;
	int			b_max;
	int			b_min;
}				t_info;

/*
** inits
*/
int		init_info(t_info **info, char **av, int ac, int option);
int		init_stack_a(t_stack **stack_a, char **av, int a_len);

/*
** stack managements
*/
t_stack	*calc_order(char **av, int a_len);
void	qsort_stack(t_stack sort_stack[], int first, int last);
int		stack_count(t_stack *lst);

/*
** sorts
*/
void	sort_stack(t_info **info, t_stack_type type);
void	sort_two(t_stack **stack, t_info **info, t_stack_type type);
void	sort_three(t_stack **stack, t_info **info, t_stack_type type);
void	sort_five(t_info **info, int len);
void	sort_all(t_info **info);
void	split_stack_a(t_info **info, int pivot_a);
void	split_stack_b(t_info **info, int pivot_b);
void	push_or_sort_stack_a(t_info **info, t_stack **src, t_stack **dst);
void	skip_or_sort_stack_b(t_info **info, t_stack **src, t_stack **dst);

void	exec_add_instructions(t_stack **stacksrc, t_stack **stackdst,
			t_info **info, t_op_name op_name);

/*
** simplelst_utils.c
*/
int		simplelst_add_front(t_simple **simplelst, t_op_name value);
int		simplelst_add_back(t_simple **simplelst, t_op_name value);
int		simplelst_pop(t_simple **simplelst);

/*
** prints
*/
void	print_instructions(t_info *info);
void	print_operation(t_op_name name, bool newline);
void	print_stack(t_info *info, char *title, t_op_name name,
			t_options option);
void	print_lines(t_stack *lst_a, t_stack *lst_b, t_options flag);
/*
** terminal_control.c
*/
void	sleep_and_clear(void);
int		get_terminal_height(void);

/*
** clear.c
*/
void	clear_info(t_info **info);
void	clear_exit(t_stack **stack1, t_stack **stack2, t_info **info, bool set);

#endif
