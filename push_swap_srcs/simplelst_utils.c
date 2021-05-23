#include "push_swap.h"

int	simplelst_add_front(t_instruc **simplelst, t_operation_name value)
{
	t_instruc	*new;

	new = malloc(sizeof(t_instruc));
	if (!new)
		return (ERROR);
	new->operation = value;
	new->next = *simplelst;
	*simplelst = new;
	return (SUCCESS);
}

int	simplelst_add_back(t_instruc **simplelst, t_operation_name value)
{
	t_instruc	*last;
	t_instruc	*new;

	new = malloc(sizeof(t_instruc));
	new->operation = value;
	new->next = NULL;
	if (!new)
		return (ERROR);
	if (*simplelst == NULL)
		*simplelst = new;
	else
	{
		last = *simplelst;
		while (last->next)
			last = last->next;
		last->next = new;
	}
	return (SUCCESS);
}

int	simplelst_pop(t_instruc **simplelst)
{
	t_instruc	*last;
	int			value;

	if (!simplelst || !*simplelst)
		return (-1);
	last = *simplelst;
	if (last->next)
	{
		while (last->next->next)
			last = last->next;
		value = last->next->operation;
		free(last->next);
		last->next = NULL;
	}
	else
	{
		value = last->operation;
		free(last);
		*simplelst = NULL;
	}
	return (value);
}
