#ifndef CHECKER_H
# define CHECKER_H

# include "utils.h"

/*
** init
*/
int		ch_init_stacks(t_stack **stack_a, t_stack **stack_b, char **av);

/*
** reader.c
*/
int		read_instructions(t_list **instructions);

/*
** executer.c
*/
void	execute_instructions(t_stack **stack_a, t_stack **stack_b,
			t_list *instructions);

/*
** stacklst
*/
void	stacklst_add_back(t_stack **lst, t_stack *new);
void	stacklst_add_front(t_stack **lst, t_stack *new);
t_stack	*stacklst_last(t_stack *lst);

/*
** clear
*/
void	clear_all(t_stack **stack_a, t_stack **stack_b, t_list **instructions);
int		clear_return(t_stack **stack1, t_stack **stack2);
void	clear_exit(t_stack **stack1, t_stack **stack2);

#endif
