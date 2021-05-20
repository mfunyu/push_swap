/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 17:20:53 by mfunyu            #+#    #+#             */
/*   Updated: 2021/05/20 22:04:18 by mfunyu           ###   ########.fr       */
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

typedef enum e_size
{
	min,
	middle,
	max
}			t_size;

typedef struct s_info
{
	t_stack		**stack_a;
	t_stack		**stack_b;
	t_list		**instructions;
	int			a_max;
	int			a_min;
	int			b_max;
	int			b_min;
}				t_info;
int		print_stack2(t_info *info, char *title);

void	clear_info(t_info *info);
int		ps_init_info(t_info *info, char **av, int ac);

int		count_stacklst(t_stack *lst);
void	qsort_stack(t_stack sort_stack[], int first, int last);
/*
** stack_list
*/
int		init_stacks(t_stack **stack_a, t_stack **stack_b, char **av, int ac);
void	stacklst_init(t_stack **head, int elem);
bool	stack_b_push_back(t_stack **stack_b, t_stack **stack_a,
									t_info *info, t_stack_info *st_info);

/*
** operations
*/
void	sort_stack(t_info *info, t_stack_type type);
void	sort_two(t_stack **stack, t_info *info, t_stack_type type);
void	record_swap(t_stack **stack, t_list **instructions,
			t_stack_type type);
void	sort_three(t_stack **stack, t_info *info, t_stack_type type);
void	sort_five(t_info *info, int len);
void	sort_all(t_stack **stack_a, t_stack **stack_b,
			t_list **instructions, int len_a);
void	split_stacklst(t_stack **src, t_stack **dst,
			t_info *info, t_stack_info *st_info);
void	split_stacklst_b(t_stack **src, t_stack **dst, t_info *info,
			t_stack_info *st_info);
/*
** print
*/
void	exec_add_instructions(t_stack **stacksrc, t_stack **stackdst,
			t_info *info, t_operation_name op_name);
void	print_instructions(t_info *info);

/*
** checkers
*/
void	operation_swap_one(t_stack **stack);
void	operation_swap_both(t_stack **stack_a, t_stack **stack_b);
void	operation_push_one(t_stack **src, t_stack **dest);
void	operation_rotate_one(t_stack **stack);
void	operation_rotate_both(t_stack **stack_a, t_stack **stack_b);
void	operation_revrotate_one(t_stack **stack);
void	operation_revrotate_both(t_stack **stack_a, t_stack **stack_b);

#endif
