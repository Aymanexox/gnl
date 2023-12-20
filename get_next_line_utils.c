#include "get_next_line.h"


char *ft_strdup(char *str)
{
    char *ret;
    int i;

    if (!str)
        return (NULL);
    if (!(ret = malloc(sizeof(char) * (ft_strlen(str) + 1))))
        return (NULL);
    i = -1;
    while (str[++i])
        ret[i] = str[i];
    ret[i] = '\0';
    return (ret);
}

t_list* ft_lstnew(char *content, int fd)
{
    t_list *ret;

    if (!(ret = malloc(sizeof(t_list))))
        return (NULL);
    ret->fd = fd;
    ret->str = ft_strdup(content);
    ret->next = NULL;
    return (ret);
}

int ft_strlen(char *str)
{
    int i;

    if (!str)
        return (0);
    i = -1;
    while (str[++i]);
    return (i);
}

char *ft_strjoin(char *s1, char *s2)
{
    char *ret;
    int i;
    int j;

    if (!s1 || !s2)
        return (NULL);
    if (!(ret = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1))))
        return (NULL);
    i = -1;
    while (s1[++i])
        ret[i] = s1[i];
    j = -1;
    while (s2[++j])
        ret[i + j] = s2[j];
    ret[i + j] = '\0';
    free(s1);
    return (ret);
}

char *ft_substr(char *str, int start, int len)
{
    char *ret;
    int i;

    if (!str)
        return (NULL);
    if (!(ret = malloc(sizeof(char) * (len + 1))))
        return (NULL);
    i = -1;
    while (++i < len)
        ret[i] = str[start + i];
    ret[i] = '\0';
    return (ret);
}



// void	ft_strdel(char **as)
// {
// 	if (as != NULL)
// 	{
// 		free(*as);
// 		*as = NULL;
// 	}
// }