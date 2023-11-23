/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glabaden <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 06:28:10 by glabaden          #+#    #+#             */
/*   Updated: 2023/11/22 06:28:15 by glabaden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

char *get_next_line(int fd)
{
    char *content;
    char *line;
    static *buffer;
    if(!buffer)
        buffer = malloc(BUFFER_SIZE * sizeof(char));
    
    content = malloc(BUFFER_SIZE * sizeof(char));
    if(!read(fd,content,BUFFER_SIZE))
        return(NULL); 
    //printf("%s",buffer);
    //printf("%s",content);
    int newlineplac = ft_find_newline(content);
    line = malloc((newlineplac +1 ) * sizeof(char));
    int i = 0;
    while(i != newlineplac + 1)
    {
        line[i] = content[i];
        i++;
    }
    i--;
    j = 0;
    while(i != newlineplac + 1)
    {
        buffer[j] = content[i];
        i++;
    }
    free(content);
    return(line);
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