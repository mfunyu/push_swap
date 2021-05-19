/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 17:20:53 by mfunyu            #+#    #+#             */
/*   Updated: 2021/05/19 17:29:54 by mfunyu           ###   ########.fr       */
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

int		count_stacklst(t_stack *lst);

/*
** stack_list
*/
void	stacklst_init(t_stack **head, int elem);

/*
** operations
*/
void	sort_stack(t_stack **stack_a, t_stack **stack_b, t_list **instructions);
void	sort_two(t_stack **stack, t_list **instructions, t_stack_type type);
void	record_swap(t_stack **stack, t_list **instructions,
			t_stack_type type);
void	sort_three(t_stack **stack_a, t_list **instructions);
void	sort_five(t_stack **stack_a, t_stack **stack_b, t_list **instructions, int len);

/*
** print
*/
void	exec_add_instructions(t_stack **stacksrc, t_stack **stackdst,
			t_list **instructions, t_operation_name op_name);
void	print_instructions(t_list *instructions);

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
