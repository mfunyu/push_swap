/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 17:14:30 by mfunyu            #+#    #+#             */
/*   Updated: 2021/04/10 13:52:36 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# define BUFFER_SIZE 32

int		get_next_line(int fd, char **line);
size_t	ft_strlen(const char *str);
char	*ft_strldup(char *s, int len);
char	*ft_strldup_check(char *s, int len, int *error);
char	*ft_strljoin(char *s1, char *s2, int len);
int		newline_index(char *s);

#endif
