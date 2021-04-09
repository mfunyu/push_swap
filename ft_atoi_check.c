/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 13:03:35 by mfunyu            #+#    #+#             */
/*   Updated: 2021/04/09 21:13:42 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi_check(const char *n, int *error)
{
	long long	nb;
	int			sign;

	nb = 0;
	sign = 1;
	*error = ERROR;
	while (*n == ' ' || *n == '\n' || *n == '\t'
		|| *n == '\v' || *n == '\f' || *n == '\r')
		n++;
	if (*n == '-' || *n == '+')
	{
		if (*n == '-')
			sign *= -1;
		n++;
	}
	while (ft_isdigit(*n))
	{
		nb = nb * 10 + (*n++ - '0');
		if (nb * sign < INT_MIN || INT_MAX < nb * sign)
			return (0);
	}
	if (*n == '\0')
		*error = SUCCESS;
	return ((int)(nb * sign));
}
