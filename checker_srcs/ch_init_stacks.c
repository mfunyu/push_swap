#include "checker.h"

int	check_dup_add_back(t_stack **stack_a, t_stack *new)
{
	t_stack		*node;

	if (*stack_a == NULL)
		*stack_a = new;
	else
	{
		node = *stack_a;
		while (1)
		{
			if (node->elem == new->elem)
			{
				stacklst_clear(&new);
				return (ERROR);
			}
			if (!node->next)
				break ;
			node = node->next;
		}
		node->next = new;
		new->prev = node;
	}
	return (SUCCESS);
}

int	ch_init_stacks(t_stack **stack_a, t_stack **stack_b, char **av, int option)
{
	t_stack		*new;
	t_stack		*nil;
	int			i;

	*stack_b = stacklst_nil();
	if (!(*stack_b))
		exit(EXIT_FAILURE);
	*stack_a = NULL;
	i = option;
	while (av[++i])
	{
		new = stacklst_new(ft_atoi(av[i]));
		if (!new)
			clear_exit(stack_b, stack_a);
		if (check_dup_add_back(stack_a, new) == ERROR)
			return (ERROR);
	}
	nil = stacklst_nil();
	stacklst_add_back(stack_a, nil);
	stacklst_add_front(stack_a, nil);
	return (SUCCESS);
}
