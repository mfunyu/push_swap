#include "push_swap.h"

int	check_dup(t_stack *sorted_stack)
{
	int		prev;
	int		i;

	prev = sorted_stack[0].elem;
	i = 1;
	while (!sorted_stack[i].nil)
	{
		if (sorted_stack[i].elem == prev)
		{
			ft_putendl_fd("Error", 2);
			free(sorted_stack);
			return (ERROR);
		}
		prev = sorted_stack[i].elem;
		i++;
	}
	return (SUCCESS);
}

t_stack	*find_order(char **av, int ac)
{
	t_stack		*sorted_stack;
	int			i;

	sorted_stack = malloc(sizeof(t_stack) * (ac + 1));
	i = 0;
	while (i < ac - 1)
	{
		sorted_stack[i].elem = ft_atoi(av[i + 1]);
		sorted_stack[i].nil = 0;
		sorted_stack[i].next = NULL;
		sorted_stack[i].prev = NULL;
		i++;
	}
	sorted_stack[i].nil = 1;
	qsort_stack(sorted_stack, 0, i - 1);
	return (sorted_stack);
}

int	match_order(t_stack *sorted_stack, int elem)
{
	int		i;

	i = 0;
	while (!sorted_stack[i].nil)
	{
		if (sorted_stack[i].elem == elem)
			return (i);
		i++;
	}
	return (-1);
}

int	init_stack_a(t_stack **stack_a, char **av, int ac)
{
	t_stack		*new;
	t_stack		*prev;
	t_stack		*sorted_stack;
	int			i;

	sorted_stack = find_order(av, ac);
	if (check_dup(sorted_stack) == ERROR)
		return (ERROR);
	i = 1;
	prev = NULL;
	while (i < ac)
	{
		new = stacklst_new(ft_atoi(av[i]));
		if (!new)
			exit(EXIT_FAILURE);
		new->order = match_order(sorted_stack, new->elem);
		if (!prev)
			*stack_a = new;
		else
		{
			prev->next = new;
			new->prev = prev;
		}
		prev = new;
		i++;
	}
	return (SUCCESS);
}

int	ps_init_info(t_info **info, char **av, int ac)
{
	t_stack		*stack_a;
	t_stack		*stack_b;
	t_stack		*nil;
	t_list		*instructions;

	*info = malloc(sizeof(t_info));
	stack_b = stacklst_nil();
	if (!stack_b)
		exit(EXIT_FAILURE);
	(*info)->b_min = 0;
	(*info)->b_max = 0;
	(*info)->a_min = 0;
	(*info)->a_max = ac - 2;
	stack_a = NULL;
	if (init_stack_a(&stack_a, av, ac) == ERROR)
		return (ERROR);
	nil = stacklst_nil();
	stacklst_add_back(&stack_a, nil);
	stacklst_add_front(&stack_a, nil);
	(*info)->stack_a = stack_a;
	(*info)->stack_b = stack_b;
	instructions = NULL;
	(*info)->instructions = instructions;
	return (SUCCESS);
}
