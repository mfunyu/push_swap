/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 17:20:53 by mfunyu            #+#    #+#             */
/*   Updated: 2021/05/22 20:26:01 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "utils.h"

typedef enum e_stack_type
{
	A,
	B
}			t_stack_type;

typedef struct s_stack_info
{
	int				pivot;
	t_stack_type	type;
}				t_stack_info;

typedef enum e_operation_name
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
}			t_operation_name;

typedef enum e_operation_type
{
	swap,
	push,
	rotate,
	revrotate
}			t_operation_type;

typedef struct s_instruc
{
	t_operation_name	operation;
	struct s_instruc	*next;
}				t_instruc;

typedef struct s_info
{
	t_stack		*stack_a;
	t_stack		*stack_b;
	t_instruc	*instructions;
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
int		ps_init_info(t_info **info, char **av, int ac, int option);
int		init_stacks(t_stack **stack_a, t_stack **stack_b, char **av, int ac);
void	stacklst_init(t_stack **head, int elem);

t_stack	*get_order(char **av, int a_len);
int		check_av_dup(t_stack *sorted_stack);
void	init_stacklst_a(t_stack **stack_a, t_stack *sorted_stack,
			char **av, int a_len);
void	qsort_stack(t_stack sort_stack[], int first, int last);

/*
** sorts
*/
void	sort_stack(t_info **info, t_stack_type type);
void	sort_two(t_stack **stack, t_info **info, t_stack_type type);
void	sort_three(t_stack **stack, t_info **info, t_stack_type type);
void	sort_five(t_info **info, int len);
void	sort_all(t_info **info);
void	split_stacklst_mv_smaller(t_info **info, int pivot_a);
void	split_stacklst_mv_larger(t_info **info, int pivot_b);
bool	stack_b_push_back(t_info **info, int pivot_a);
bool	is_ordered(t_stack *stack_a);

/*
** stack managements
*/
int		count_stacklst(t_stack *lst);
void	record_swap(t_stack **stack, t_list **instructions,
			t_stack_type type);

/*
** prints
*/
void	exec_add_instructions(t_stack **stacksrc, t_stack **stackdst,
			t_info **info, t_operation_name op_name);
void	print_instructions(t_info *info);
void	ps_print_stack(t_info *info, char *title, int option);
void	print_operation(t_operation_name name);

void	clear_info(t_info **info);
void	clear_exit(t_stack **stack_a, t_stack **stack_b,
			t_info **info, t_instruc **instructions);

#endif
