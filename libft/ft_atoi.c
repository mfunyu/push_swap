/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 13:03:35 by mfunyu            #+#    #+#             */
/*   Updated: 2021/04/09 11:34:45 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static const char	*ft_skip_space(const char *str)
{
	while (*str == ' ' || *str == '\n' || *str == '\t'
		|| *str == '\v' || *str == '\f' || *str == '\r')
		str++;
	return (str);
}

int	ft_atoi(const char *n)
{
	long long	nb;
	int			sign;

	nb = 0;
	sign = 1;
	n = ft_skip_space(n);
	if (*n == '-' || *n == '+')
	{
		if (*n == '-')
			sign *= -1;
		n++;
	}
	while (ft_isdigit(*n))
	{
		if ((LONG_MAX - (*n - '0')) / 10 < nb)
		{
			nb = LONG_MAX;
			if (sign == -1)
				nb = LONG_MIN;
			return ((int)nb);
		}
		nb = nb * 10 + (*n++ - '0');
	}
	nb *= sign;
	return ((int)nb);
}
