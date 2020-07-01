/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 18:32:49 by mfunyu            #+#    #+#             */
/*   Updated: 2020/07/01 14:34:23 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdio.h>

int		get_next_line(int fd, char **line)
{
	char		buf[BUFFER_SIZE + 1];
	static char	save[BUFFER_SIZE + 1];
	int		index;
	int		i;
	char	*newlineptr;
	// static int		sum;
	int		bytes;

	i = 0;
	index = 0;
	// buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	// if (!read(fd, buf, BUFFER_SIZE))
	// 	return (-1);
	
	// read(fd, *line, 1);
	while ((bytes = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		if ((newlineptr = ft_strchr(buf, '\n')))
		{
			index = newlineptr - buf + 1;
			ft_strlcat(*line, buf, index);
			*line[index] = '\0';
			if (index > BUFFER_SIZE)
			{
				ft_strlcpy(save, buf + index, BUFFER_SIZE + 1);
			}
			return (1);
		}
		else
		{
			ft_strlcat(*line, buf, 100);
		}
	}
	if (bytes == 0)
	{
		ft_strlcat(*line, buf, 100);
		return (0);
	}
	else if (bytes == -1)
	{
		return (-1);
	}
	// sum += index;
	// printf("i: %d\n", index);
	// printf("bytes: %d\n", bytes);
	// printf("sum: %d\n", sum);
	// printf("line: %s\n", *line);
	// printf("buf: %s\n", buf);
	// ft_strlcat(*line, buf, 100);
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