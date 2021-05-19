#include "utils.h"

bool	is_valid_arg(int ac, char **av)
{
	int		error;
	int		i;

	if (ac <= 1)
		return (false);
	i = 0;
	error = 0;
	while (av[++i] && !error)
		ft_atoi_check(av[i], &error);
	if (error)
	{
		ft_putendl_fd("Error", 2);
		return (false);
	}
	return (true);
}
