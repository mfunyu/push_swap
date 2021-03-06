#include "push_swap.h"

t_stack	*calc_order(char **av, int a_len)
{
	t_stack		*sorted_stack;
	int			i;

	sorted_stack = malloc(sizeof(t_stack) * (a_len + 1));
	if (!sorted_stack)
		return (NULL);
	i = 0;
	while (i < a_len)
	{
		sorted_stack[i].elem = ft_atoi(av[i]);
		sorted_stack[i].nil = 0;
		sorted_stack[i].next = NULL;
		sorted_stack[i].prev = NULL;
		i++;
	}
	sorted_stack[i].nil = 1;
	qsort_stack(sorted_stack, 0, a_len - 1);
	return (sorted_stack);
}

int	check_av_dup(t_stack *sorted_stack)
{
	int		prev;
	int		i;

	prev = sorted_stack[0].elem;
	i = 1;
	while (!sorted_stack[i].nil)
	{
		if (sorted_stack[i].elem == prev)
		{
			ft_putendl_fd("Error", STDERR_FILENO);
			null_free((void **)&sorted_stack);
			return (ERROR);
		}
		prev = sorted_stack[i].elem;
		i++;
	}
	return (SUCCESS);
}

int	search_order(t_stack *sorted_stack, int elem)
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

void	init_stacklst_a(t_stack **stack_a, t_stack *sorted_stack,
													char **av, int a_len)
{
	t_stack		*new;
	int			i;

	i = 0;
	while (i < a_len)
	{
		new = stacklst_new(ft_atoi(av[i]));
		if (!new)
		{
			null_free((void **)&sorted_stack);
			clear_exit(stack_a, NULL, NULL, false);
		}
		new->order = search_order(sorted_stack, new->elem);
		stacklst_insert((*stack_a)->prev->prev, (*stack_a)->prev, new);
		if ((*stack_a)->nil)
			*stack_a = new;
		i++;
	}
	null_free((void **)&sorted_stack);
}

int	init_stack_a(t_stack **stack_a, char **av, int a_len)
{
	t_stack		*sorted_stack;

	sorted_stack = calc_order(av, a_len);
	if (!sorted_stack)
		exit(EXIT_FAILURE);
	if (check_av_dup(sorted_stack) == ERROR)
		return (ERROR);
	*stack_a = stacklst_nil();
	if (!*stack_a)
	{
		null_free((void **)&sorted_stack);
		exit(EXIT_FAILURE);
	}
	init_stacklst_a(stack_a, sorted_stack, av, a_len);
	return (SUCCESS);
}
