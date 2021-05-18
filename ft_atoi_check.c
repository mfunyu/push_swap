/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 13:03:35 by mfunyu            #+#    #+#             */
/*   Updated: 2021/05/18 18:52:32 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_skip_spaces(const char **str)
{
	while (**str == ' ' || **str == '\n' || **str == '\t'
		|| **str == '\v' || **str == '\f' || **str == '\r')
		(*str)++;
}

int	ft_atoi_check(const char *n, int *error)
{
	long long	nb;
	int			sign;

	nb = 0;
	sign = 1;
	*error = ERROR;
	ft_skip_spaces(&n);
	if (*n == '-' || *n == '+')
		sign *= 44 - *n++;
	while (ft_isdigit(*n))
	{
		*error = 1;
		nb = nb * 10 + (*n++ - '0');
		if (nb * sign < INT_MIN || INT_MAX < nb * sign)
		{
			*error = ERROR;
			return (0);
		}
	}
	if (*error == 1 && *n == '\0')
		*error = SUCCESS;
	return ((int)(nb * sign));
}
