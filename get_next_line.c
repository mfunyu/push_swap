/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 18:32:49 by mfunyu            #+#    #+#             */
/*   Updated: 2020/07/02 10:54:46 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdio.h>

char	*find_newline(char **line, char *str, int END)
{
	char	*newline;
	int		index;
	char *save;

	index = 0;
	// 改行があったら
	if ((newline = ft_strchr(str, '\n')))
	{
		index = newline - str + 1;
		ft_strlcat(*line, str, index);
		printf("cat\n");
		// あまりがなかったら
		if (index >= (int)ft_strlen(str) - 1)
		{
			// saveをnullにする
			printf("cat2\n");
			ft_strlcat(*line, str, index);
			return (NULL);
		}
		// あまりがあったら
		else
		{
			// saveにあまりつめる
			save = (char *)ft_calloc(sizeof(char), (int)ft_strlen(str) - index + 1);
			ft_strlcpy(save, str + index, (int)ft_strlen(str) + 1);
			printf("saved\n");
			return (save);
		}
		
	}
	if (END)
	{
		printf("cat3\n");
		ft_strlcat(*line, str, ft_strlen(str) + 1);
		return (NULL);
	}
	// 改行がなかったら
	// lineにstrをつめる、saveはから
	printf("line←save\n");
	// save = (char *)ft_calloc(sizeof(char), BUFFER_SIZE - index + 1);
	// ft_strlcpy(*line, save, ft_strlen(save) + 1);
	ft_strlcpy(*line, str, ft_strlen(str) + 1);
	*line += ft_strlen(str);
	return (NULL);
}

int		get_next_line(int fd, char **line)
{
	static char	*save;
	char	buf[BUFFER_SIZE + 1];
	static int	END;
	int		bytes;

	printf("save: \"%s\"\n", save);
	if (save)
	{
		save = find_newline(line, save, END);
		if (save || END)
			return (1);
	}
	else
	{
		if (END)
		{
			printf("end2\n");
			return (0);
		}
	}
	bytes = read(fd, buf, BUFFER_SIZE);
	if (bytes == -1)
	{
		return (-1);
	}
	if (bytes == 0)
	{
		printf("end2\n");
		// ft_strlcpy(*line, "", 2);
		return (0);
	}
	if (bytes < BUFFER_SIZE)
	{
		END = 1;
	}
	save = find_newline(line, buf, END);
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