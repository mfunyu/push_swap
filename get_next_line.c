/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 18:32:49 by mfunyu            #+#    #+#             */
/*   Updated: 2020/07/01 18:45:17 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdio.h>

int		get_next_line(int fd, char **line)
{
	char		buf[BUFFER_SIZE + 1];
	static char	*save;
	int		index;
	int		i;
	char	*newline;
	// static int		sum;
	int		bytes;

	i = 0;
	index = 0;

	printf("save: \"%s\"\n", save);
	bytes = read(fd, buf, BUFFER_SIZE);
	if (bytes == -1)
	{
		return (-1);
	}
	printf("yes\n");
	if (bytes == 0)
	{
		printf("yes\n");
		return (0);
		if ((newline = ft_strchr(buf, '\n')))
		{
			index = newline - buf + 1;
			ft_strlcat(*line, buf, index);
			if (index < BUFFER_SIZE)
			{
				save = (char *)malloc((BUFFER_SIZE - index + 1) + sizeof(char));
				ft_strlcpy(save, buf + index, BUFFER_SIZE + 1);
			}
			else
			{
				ft_strlcat(*line, buf, 100);
			}
			return (1);
		}
		ft_strlcat(*line, buf, 100);
		return (0);
	}
	else
	{
		printf("yes\n");
		printf("buf: \"%s\"\n", buf);
		if ((newline = ft_strchr(buf, '\n')))
		{
			printf("yes\n");
			index = newline - buf + 1;
			ft_strlcat(*line, buf, index);
			if (index < BUFFER_SIZE)
			{
				save = (char *)malloc((BUFFER_SIZE - index + 1) + sizeof(char));
				ft_strlcpy(save, buf + index, BUFFER_SIZE + 1);
			}
			else
			{
				ft_strlcat(*line, buf, 100);
			}
			return (1);
		}
		ft_strlcat(*line, buf, 100);
		}
	return (1);
}



	// printf("buf: %s\n", buf);
	// while (buf[i])
	// {
	// 	if (buf[i++] == '\n')
	// 	{
	// 		break ;
	// 	}
	// }