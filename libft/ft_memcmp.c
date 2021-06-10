/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 16:13:04 by mfunyu            #+#    #+#             */
/*   Updated: 2021/04/09 11:30:50 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s1_copy;
	unsigned char	*s2_copy;
	size_t			i;

	i = 0;
	s1_copy = (unsigned char *)s1;
	s2_copy = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (i < n - 1 && s1_copy[i] == s2_copy[i])
		i++;
	return (s1_copy[i] - s2_copy[i]);
}
