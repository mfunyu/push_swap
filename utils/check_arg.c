#include "utils.h"

bool	is_valid_arg(char **av, t_options *option)
{
	int		error;
	int		i;

	i = 0;
	if (option)
	{
		i++;
		if (ft_strncmp(av[1], "-v", 3) == 0)
			*option = DISPLAYALL;
		else if (ft_strncmp(av[1], "-a", 3) == 0)
			*option = AUTOPLAY;
		else if (ft_strncmp(av[1], "-c", 3) == 0)
			*option = CONTROL;
		else
			i = 0;
	}
	error = 0;
	while (av[++i] && !error)
		ft_atoi_check(av[i], &error);
	if (error)
	{
		ft_putendl_fd("Error", STDERR_FILENO);
		return (false);
	}
	return (true);
}
