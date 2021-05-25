#include "push_swap.h"

int	simplelst_add_front(t_simple **simplelst, t_op_name value)
{
	t_simple	*new;

	new = malloc(sizeof(t_simple));
	if (!new)
		return (ERROR);
	new->value = value;
	new->next = *simplelst;
	*simplelst = new;
	return (SUCCESS);
}

int	simplelst_add_back(t_simple **simplelst, t_op_name value)
{
	t_simple	*last;
	t_simple	*new;

	new = malloc(sizeof(t_simple));
	new->value = value;
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

int	simplelst_pop(t_simple **simplelst)
{
	t_simple	*last;
	int			value;

	if (!simplelst || !*simplelst)
		return (-1);
	last = *simplelst;
	if (last->next)
	{
		while (last->next->next)
			last = last->next;
		value = last->next->value;
		free(last->next);
		last->next = NULL;
	}
	else
	{
		value = last->value;
		free(last);
		*simplelst = NULL;
	}
	return (value);
}
