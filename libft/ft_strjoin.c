/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 19:30:09 by mfunyu            #+#    #+#             */
/*   Updated: 2020/07/01 11:06:41 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*joined;
	unsigned int	size;
	unsigned int	i;

	i = 0;
	if (!s1)
		return (NULL);
	if (!s2)
		return (ft_strdup(s1));
	size = ft_strlen(s1) + ft_strlen(s2);
	joined = (char *)malloc((size + 1) * sizeof(char));
	if (!joined)
		return (NULL);
	while (*s1)
	{
		joined[i++] = *s1++;
	}
	while (*s2)
	{
		joined[i++] = *s2++;
	}
	joined[i] = '\0';
	return (joined);
}
