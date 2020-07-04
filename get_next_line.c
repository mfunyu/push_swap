/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: u_2 <u_2@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 18:32:49 by mfunyu            #+#    #+#             */
/*   Updated: 2020/07/04 11:43:29 by u_2              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdio.h>

char	*find_newline(char **line, char *str, int END)
{
	char	*newline;
	int		index;
	// char *save;

	index = 0;
	// 改行があったら
	if ((newline = ft_strchr(str, '\n')))
	{
		index = newline - str + 1;
		printf("line0: %s\n", *line);
		printf("i: %d\n", index);
		ft_strlcat(*line, str, index);
		printf("line0.5: %s\n", *line);
		printf("cat\n");
		// あまりがなかったら
		if (index > (int)ft_strlen(str) - 1)
		{
			// saveをnullにする
			printf("cat2\n");
			// ft_strlcat(*line, str, index);
			return (ft_strdup(""));
		}
		// あまりがあったら
		else
		{
			// saveにあまりつめる
			// save = (char *)ft_calloc(sizeof(char), (int)ft_strlen(str) - index + 1);
			// ft_strlcpy(save, str + index, (int)ft_strlen(str) + 1);
			printf("saved\n");
			// return (save);
			return (ft_strdup(str + index));
		}
		
	}
	// 改行がなくてEOFフラグが立っていたら
	else if (END)
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
	printf("line1: %s\n", *line);
	ft_strlcat(*line, str, 1000);
	printf("line2: %s\n", *line);
	// *line += ft_strlen(str);
	return (NULL);
}

int		get_next_line(int fd, char **line)
{
	static char	*save;
	char *new_save;
	char	buf[BUFFER_SIZE + 1];
	static int	END;
	int		bytes;

	printf("save: \"%s\"\n", save);
	if (save)
	{
		new_save = find_newline(line, save, END);
		free(save);
		save = new_save;
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
	while ((bytes = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		if (bytes < BUFFER_SIZE)
		{
			END = 1;
		}
		printf("buf: \"%s\"\n", buf);
		save = find_newline(line, buf, END);
		if (save || END)
			return (1);
		// return (1);
	}
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