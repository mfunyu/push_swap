/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 17:20:53 by mfunyu            #+#    #+#             */
/*   Updated: 2021/05/17 14:37:44by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

// delete later
# include <stdio.h>

# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include "libft.h"
# include "get_next_line.h"

# define SUCCESS 0
# define ERROR -1

typedef struct s_stack
{
	int				elem;
	int				nil;
	int				order;
	int				sorted;
	struct s_stack	*prev;
	struct s_stack	*next;
}				t_stack;

/*
** checkarg.c
*/
bool	is_valid_arg(int ac, char **av, int *option);

bool	is_sorted(t_stack *stack_a, t_stack *stack_b);

/*
** stack_list
*/
t_stack	*stacklst_last(t_stack *lst);
t_stack	*stacklst_new(int elem);
void	stacklst_add_back(t_stack **lst, t_stack *new);
void	stacklst_add_front(t_stack **lst, t_stack *new);
void	stacklst_clear(t_stack **lst);
t_stack	*stacklst_nil(void);
void	stacklst_insert(t_stack *a, t_stack *b, t_stack *new);
t_stack	*stacklst_pop(t_stack **lst, bool head);

/*
** operations
*/
void	operation_swap_one(t_stack **stack);
void	operation_swap_both(t_stack **stack_a, t_stack **stack_b);
void	operation_push_one(t_stack **src, t_stack **dest);
void	operation_rotate_one(t_stack **stack);
void	operation_rotate_both(t_stack **stack_a, t_stack **stack_b);
void	operation_revrotate_one(t_stack **stack);
void	operation_revrotate_both(t_stack **stack_a, t_stack **stack_b);

/*
** utils
*/
void	null_free(char **elem);

#endif
