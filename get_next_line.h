#ifndef GET_NEXT_LINE
# define GET_NEXT_LINE

# include <unistd.h>
# include <stdlib.h>
// # include <string.h>

int		get_next_line(int fd, char **line);
int		newline_in_str(char **line, char **str, char **save, int END);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *str);
void	*ft_calloc(unsigned int nmemb, unsigned int size);
char	*ft_strldup(const char *s, int len);
char	*ft_strljoin(char *s1, char *s2, int len);

# endif
