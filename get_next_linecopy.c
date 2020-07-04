/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: u_2 <u_2@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 18:32:49 by mfunyu            #+#    #+#             */
/*   Updated: 2020/07/04 21:10:17 by u_2              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdio.h>

int		newline_in_save(char **line, char **save, int END)
{
	char	*newline;
	int		index;

	index = 0;
	if (!*line)
	{
		*line = ft_strldup("", 0);
	}
	// 改行があったら
	if ((newline = ft_strchr(*save, '\n')))
	{
		index = newline - *save + 1;
			printf("F2: save: \"%s\"\n", *save);
			printf("F2: line0: \"%s\"\n", *line);
			printf("F2: i: %d\n", index);
		*line = ft_strljoin(*line, *save, index - 1);
			printf("F2: line0.5: \"%s\"\n", *line);
			printf("F2: cat\n");
		// あまりがあったら
		if (index != (int)ft_strlen(*save))
		{
			// printf("F2: saved\n");
			*save += index;
			printf("F2: save2: \"%s\"\n", *save);
			printf("F2: ret1\n");
			// *save = NULL;
			return (1);
		}
		printf("F2: ret1NULL\n");
		*save = NULL;
		return (1);
	}
	// 改行がなくてEOFフラグが立っていたら
	else if (END)
	{
		printf("F2: catEND\n");
		*line = ft_strljoin(*line, *save, ft_strlen(*save) + 1);
		*save = NULL;
		return (1);
	}
	// 改行がなかったら
	// lineにstrをつめる、saveはから
	// printf("line←save\n");
	// printf("line1: %s\n", *line);
	*line = ft_strljoin(*line, *save, ft_strlen(*save) + 1);
	printf("F2: line1: %s\n", *line);
	*save = NULL;
	return (0);
}

int		newline_in_buf(char **line, char **buf, char **save, int END)
{
	char	*newline;
	int		index;

	index = 0;
	if (!*line)
	{
		*line = ft_strldup("", 0);
	}
	// 改行があったら
	if ((newline = ft_strchr(*buf, '\n')))
	{
		index = newline - *buf + 1;
			printf("F3: save: \"%s\"\n", *buf);
			// printf("F3: line0: \"%s\"\n", *line);
			printf("F3: i: %d\n", index);
		*line = ft_strljoin(*line, *buf, index - 1);
			printf("F3: line0: \"%s\"\n", *line);
			printf("F3: cat\n");
		// あまりがあったら
		if (index != (int)ft_strlen(*buf))
		{
			printf("F3: saved\n");
			*save = ft_strldup(*buf + index, ft_strlen(*buf + index));
			printf("F3: save2: \"%s\"\n", *save);
			return (1);
		}
		*buf = NULL;
		*save = NULL;
		printf("F3: ret1\n");
		return (1);
	}
	// 改行がなくてEOFフラグが立っていたら
	else if (END)
	{
		printf("F3: catEND\n");
		*line = ft_strljoin(*line, *buf, ft_strlen(*buf) + 1);
		*save = NULL;
		return (1);
	}
	// 改行がなかったら
	// lineにstrをつめる、saveはから
	// printf("line←save\n");
	// printf("line1: %s\n", *line);
	*line = ft_strljoin(*line, *buf, ft_strlen(*buf) + 1);
	printf("F3: line1: %s\n", *line);
	*save = NULL;
	return (0);
}

int		get_next_line(int fd, char **line)
{
	static char	*save;
	char	*buf;
	// char	buf[BUFFER_SIZE + 1];
	static int	END;
	int		bytes;
	int		done;

	done = 0;
	*line = NULL;
	printf("save: \"%s\"\n", save);
	buf = (char *)ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!buf)
		return (-1);
	// saveがあったら
	if (save)
	{
		// 一行読み終わったかどうか = read
		printf("<<<SAVE>>>\n");
		done = newline_in_save(line, &save, END);
		if (done)
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
	// printf("F1: before while\n");
	while (!done && (bytes = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		if (bytes < BUFFER_SIZE)
		{
			END = 1;
		}
		printf("<<<READ>>>\n");
		buf[bytes] = '\0';
		printf("buf: \"%s\"\n", buf);
		printf("byt: %d\n", bytes);
		done = newline_in_buf(line, &buf, &save, END);
		if (done)
			return (1);
		// return (1);

	}
	if (done == -1 || bytes == -1)
	{
		return (-1);
	}
	if (bytes == 0 && !*line)
	{
		printf("endbytes0\n");
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