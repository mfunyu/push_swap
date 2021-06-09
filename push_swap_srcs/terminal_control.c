#include "push_swap.h"

void	sleep_and_clear(void)
{
	int			i;
	long long	sleep_seconds;

	sleep_seconds = SLEEP_LENGTH;
	i = 0;
	while (i < sleep_seconds)
	{
		ft_putstr_fd("", STDERR_FILENO);
		i++;
	}
	ft_putstr_fd(CLEAR_SCREEN, STDOUT_FILENO);
}

int	get_terminal_height(void)
{
	int		height;
	char	c;

	ft_putstr_fd(SHIFT_CURSOR, STDOUT_FILENO);
	ft_putendl_fd("Terminal Height Setup: press the Enter", STDOUT_FILENO);
	ft_putstr_fd(CURSOR_POSITION, STDOUT_FILENO);
	height = 0;
	while (1)
	{
		read(STDIN_FILENO, &c, 1);
		if (ft_isdigit(c))
			height = height * 10 + (c - '0');
		if (c == ';')
		{
			read(STDIN_FILENO, &c, 1);
			read(STDIN_FILENO, &c, 1);
			read(STDIN_FILENO, &c, 1);
			break ;
		}
	}
	ft_putstr_fd(CLEAR_SCREEN, STDOUT_FILENO);
	return (height);
}
