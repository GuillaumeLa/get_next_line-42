#include "get_next_line.h"
#include <stdlib.h>

int ft_find_newline(char *str)
{
    int i;
    i = 0;
    while(str[i])
    {
        if(str[i] == '\n')
            return(i);
        i++;
    }
    return 0;
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
char	*ft_strjoin(char const *s1, char const *s2)
{
	int		size_new;
	int		i;
	int		j;
	char	*result;

	if (!s1 || !s2)
		return (0);
	i = 0;
	j = 0;
	size_new = ft_strlen((char *)s1) + ft_strlen((char *)s2);
	result = (char *) malloc((size_new +1) * sizeof(char));
	if (result == NULL)
		return (0);
	while (s1[i])
	{
		result[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		result[i + j] = s2[j];
		j++;
	}
	result[i + j] = 0;
	return (result);
}

char *get_next_line(int fd)
{
    static char *buffer;
    char *line;
    char *content;
    char *temp;

    if(buffer && ft_find_newline(buffer))
    {
        line = ft_strjoin(buffer,line);
        buffer = malloc(1 * sizeof(char));
        //printf("%s",line);
        return(line);
    }
    else if(buffer)
    {
        line = ft_strjoin(buffer,line);
        //printf("%s",line);
    }
    else
        line = malloc(1 * sizeof(char));
    buffer = malloc(1 * sizeof(char));

    content = malloc(BUFFER_SIZE * sizeof(char));
    //line = malloc(BUFFER_SIZE * sizeof(char));
    if(!read(fd,content,BUFFER_SIZE))
        return(NULL);
    while(!ft_find_newline(content) && read(fd,content,BUFFER_SIZE))
    {
        line = ft_strjoin(line,content);
    }
    int nline_inde = ft_find_newline(content);
    temp = malloc((nline_inde + 1) * sizeof(char));
    int i = 0;
    while(i != nline_inde + 1)
    {
        temp[i] = content[i];
        i++;
    }
    //printf("%s",temp);
    buffer = ft_strjoin(buffer,content+nline_inde);
    line = ft_strjoin(line,temp);
    

    free(temp);
    free(content);
    return(line);
}

int main()
{
    int fd = open("test.txt",O_RDONLY);
    char *test;
    int i = 0;

    test = get_next_line(fd);
    while(test)
    {
        printf("%s",test);
        test = get_next_line(fd);

    }
    return(0);
}