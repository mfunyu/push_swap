/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 09:27:12 by mfunyu            #+#    #+#             */
/*   Updated: 2021/04/09 11:35:17 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	set_nb(char *nb, int n, int len)
{
	nb[len--] = '\0';
	while (n > 9)
	{
		nb[len] = n % 10 + '0';
		len--;
		n /= 10;
	}
	nb[len] = n + '0';
}

static int	cnt_len(int n)
{
	int		len;

	len = 1;
	if (n == INT_MIN)
		n++;
	if (n < 0)
	{
		n *= -1;
		len++;
	}
	while (n > 9)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char		*nb;
	int			len;

	len = cnt_len(n);
	nb = (char *)malloc((len + 1) * sizeof(char));
	if (!nb)
		return (NULL);
	if (n == INT_MIN)
		ft_strlcpy(nb, "-2147483648", 12);
	else
	{
		if (n < 0)
		{
			n *= -1;
			*nb = '-';
		}
		set_nb(nb, n, len);
	}
	return (nb);
}
