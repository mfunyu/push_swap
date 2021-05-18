/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 17:20:53 by mfunyu            #+#    #+#             */
/*   Updated: 2021/05/17 09:13:20 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

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
	struct s_stack	*prev;
	struct s_stack	*next;
}			t_stack;

/*
** dbg
*/
int		print_stack(t_stack *head);

/*
** stack_list
*/
t_stack	*stacklst_last(t_stack *lst);
t_stack	*stacklst_new(int elem);
void	stacklst_add_back(t_stack **lst, t_stack *new);
void	stacklst_clear(t_stack **lst);
void	stacklst_init(t_stack **head, int elem);

/*
** utils
*/
void	null_free(char **elem);

#endif
