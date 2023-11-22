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
char *get_next_line(int fd)
{
    char content[BUFFER_SIZE];

    read(fd,content,BUFFER_SIZE);
    printf("%s",content);
    return(content);
}

int main()
{
    int fd = open("test.txt",O_RDONLY);
    get_next_line(fd);
    return(0);
}