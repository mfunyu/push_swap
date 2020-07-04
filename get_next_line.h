#ifndef GET_NEXT_LINE
# define GET_NEXT_LINE

# include <unistd.h>
# include <stdlib.h>
// # include <string.h>

int		get_next_line(int fd, char **line);
void	ft_strlcpy(char *dst, const char *src, size_t size);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
size_t	ft_strlen(const char *str);
void	*ft_calloc(unsigned int nmemb, unsigned int size);
void	*ft_memset(void *s, int c, unsigned int n);
char	*ft_strdup(const char *s);

# endif