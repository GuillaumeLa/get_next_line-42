#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 100
#endif

void	ft_bzero(void *s, unsigned int n);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *s, int c);
void	*ft_calloc( size_t elementCount, size_t elementSize);
size_t	ft_strlen(const char *str);

#endif
