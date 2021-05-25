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

#ifndef CHECKER_H
# define CHECKER_H

# include "utils.h"

/*
** stack_list
*/
void	stacklst_init(t_stack **head, int elem);
int		ch_init_stacks(t_stack **stack_a, t_stack **stack_b,
			char **av, int option);

/*
** reader.c
*/
int		read_instructions(t_list **instructions);

/*
** executer.c
*/
void	execute_instructions(t_stack **stack_a, t_stack **stack_b,
			t_list *instructions, int option);

/*
** stacklst
*/
void	stacklst_add_back(t_stack **lst, t_stack *new);
void	stacklst_add_front(t_stack **lst, t_stack *new);
t_stack	*stacklst_last(t_stack *lst);

/*
** print
*/
void	ch_print_stack(t_stack *lst_a, t_stack *lst_b, char *title, int option);

void	clear_all(t_stack **stack_a, t_stack **stack_b, t_list **instructions);
int		clear_return(t_stack **stack1, t_stack **stack2);
void	clear_exit(t_stack **stack1, t_stack **stack2);

#endif
