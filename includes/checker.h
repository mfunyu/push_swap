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
int		read_instructions(t_stack **stack_a, t_list **instructions);

/*
** executer.c
*/
int		execute_instructions(t_stack **stack_a, t_stack **stack_b,
			t_list *instructions, int option);

/*
** print
*/
void	ch_print_stack(t_stack *lst_a, t_stack *lst_b, char *title, int option);

#endif
