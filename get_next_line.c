
#include "get_next_line.h"


char	*ft_free(char *buffer, char *buf)
{
	char	*temp;

	temp = ft_strjoin(buffer, buf);
	free(buffer);
	return (temp);
}
char	*ft_read_filed(int fd, char *res)
{
	char	*readed;
	int		len_read;

	if (!res)
		res = ft_calloc(1, 1);
	readed = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	len_read = 1;
	while (len_read > 0)
	{
		len_read = read(fd, readed, BUFFER_SIZE);
		if (len_read == -1)
		{
			free(readed);
			return (NULL);
		}
		readed[len_read] = 0;
		res = ft_free(res, readed);
		if (ft_strchr(readed, '\n'))
			break ;
	}
	free(readed);
	return (res);
}

char	*ft_find_newline(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = ft_calloc(i + 2, sizeof(char));
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] && buffer[i] == '\n')
		line[i++] = '\n';
	return (line);
}
char	*ft_store(char *buffer)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	line = ft_calloc((ft_strlen(buffer) - i + 1), sizeof(char));
	i++;
	j = 0;
	while (buffer[i])
		line[j++] = buffer[i++];
	free(buffer);
	return (line);
}

char *get_next_line(int fd)
{
    static char *buffer;
    char *line;

    if(fd == -1)
        return (NULL);
    buffer = ft_read_filed(fd,buffer);
    if(!buffer)
        return (NULL);
    line = ft_find_newline(buffer);
    buffer = ft_store(buffer);
    return (line);
}

int main()
{
    int fd = open("test.txt",O_RDONLY);
    char *test;

    test = get_next_line(fd);
    while(test)
    {
        printf("%s",test);
        test = get_next_line(fd);

    }
    return(0);
}