/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 18:32:49 by mfunyu            #+#    #+#             */
/*   Updated: 2020/07/04 23:31:02 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		newline_in_str(char **line, char **str, char **save, int END)
{
	char	*newline;
	int		index;

	index = 0;
	if (!*line)
	{
		*line = ft_strldup("", 0);
	}
	// 改行があったら
	if ((newline = ft_strchr(*str, '\n')))
	{
		index = newline - *str + 1;
		*line = ft_strljoin(*line, *str, index - 1);
		// あまりがあったら
		if (index != (int)ft_strlen(*str))
		{
			if (str == save)
			{
				*save += index;
			}
			else
			{
				*save = ft_strldup(*str + index, ft_strlen(*str + index));
			}
			return (1);
		}
		free(*save);
		*save = NULL;
		return (1);
	}
	// 改行がなくてEOFフラグが立っていたら
	else if (END)
	{
		*line = ft_strljoin(*line, *str, ft_strlen(*str) + 1);
		*save = NULL;
		return (1);
	}
	// 改行がなかったら
	// lineにstrをつめる、saveはから
	// printf("line←save\n");
	// printf("line1: %s\n", *line);
	*line = ft_strljoin(*line, *str, ft_strlen(*str) + 1);
	*save = NULL;
	return (0);
}

int		get_next_line(int fd, char **line)
{
	static char	*save;
	char		*buf;
	static int	END;
	int			bytes;
	int			done;

	done = 0;
	*line = NULL;
	// saveがあったら
	if (save)
	{
		// 一行読み終わったかどうか = read
		done = newline_in_str(line, &save, &save, END);
		if (done)
			return (1);
	}
	else
	{
		if (END)
		{
			return (0);
		}
	}
	buf = (char *)ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!buf)
		return (-1);
	while (!done && (bytes = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		if (bytes < BUFFER_SIZE)
		{
			END = 1;
		}
		buf[bytes] = '\0';
		done = newline_in_str(line, &buf, &save, END);
		if (done)
		{
			free(buf);
			return (1);
		}
	}
	if (done == -1 || bytes == -1)
	{
		return (-1);
	}
	if (bytes == 0 && !*line)
	{
		return (0);
	}
	return (1);
}
