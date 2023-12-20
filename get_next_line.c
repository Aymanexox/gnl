/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrani <asebrani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 00:49:06 by asebrani          #+#    #+#             */
/*   Updated: 2023/12/20 01:06:25 by asebrani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	ft_strchr(char *str, char c)
{	
	int i;
	
	if (!str)
        return (0);
    i = -1;
    while (str[++i])
        if (str[i] == c)
            return (1);
    return (0);
}

int     read_line(int fd, char **line)
{
    char buf[BUFFER_SIZE + 1];
    int ret = 0;
    while ((ret = read(fd, &buf, BUFFER_SIZE)) > 0)
    {
        buf[ret] = '\0';
        if (!(*line = ft_strjoin(*line, buf)))
            return (-1);
        if (ft_strchr(buf, '\n'))
            break ;
    }
    return (ret);
}

int     line_copy(char *line, char **new_line)
{
    int i = 0;

    while (line[i] != '\0' && line[i] != '\n')
        i++; // i = len of the line
    if (line[i] == '\n')
        i++;
    *new_line = ft_substr(line, 0, i);
    return (i);
}

t_list	*is_valid(int fd, t_list **origin)
{
	t_list *ret;

	if (!origin)
	return (NULL);
	ret = *origin;
	while (ret != NULL)
	{
        if ((int)(ret->fd) == fd)
	    return (ret);
	ret = ret->next;
	}
	ret = ft_lstnew("", fd);
    if (!ret)
        return (free(origin),NULL);
    ret->next = *origin;
    *origin = ret;
	return (ret);
}

char* get_next_line(int fd)
{
    static t_list *head_list; // static linked list  | content: fd, str, next
    t_list *valid; // valid points to node of the file descriptor in the linked list
    t_global v;

    if (fd < 0 || read(fd, v.buf, 0) < 0 || BUFFER_SIZE < 1
		|| !(valid=is_valid(fd, &head_list)))
        return (NULL);
    v.readed = valid->str;
    if ((v.ret = read_line(fd, &v.readed)) < 0) // All buffer 1337
        return (NULL);
    valid->str = v.readed;
    if (v.ret == 0 && !v.readed[0])
        return (NULL);
    v.ret = line_copy(v.readed, &v.new_line); // only the line with one \n.
    if (v.readed[v.ret] != '\0')
	{
		valid->str = ft_strdup(v.readed + v.ret + 1); // the address of the next charactere after \n is static!!!
        if (v.readed)
        	free(v.readed);
	}
    else if (v.readed[v.ret] == '\0')
        while (v.readed && *v.readed)
			*v.readed++ = '\0';
    return (v.new_line);
}

// int main(void)
// {
//     int i = 0;
    
//     int fd = open("test", O_RDWR, 0777);

//     char *str = get_next_line(fd);
//     while (i < 20)
//     {
//       printf("%s", str);
//       free(str);
//       str = get_next_line(fd);
//         i++;
//     }

//     return (0);
// }
