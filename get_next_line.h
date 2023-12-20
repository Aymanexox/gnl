# ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <fcntl.h>
#include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif


typedef struct list
{
    int fd;
    char *str;
    struct list *next;
}            t_list;

typedef struct global
{
    char *readed; // readed is the string readed from the file descriptor 1337=BUFFER_SIZE 
    char *new_line;
    int ret;
    char buf[BUFFER_SIZE + 1];/* data */
}       t_global;



char* get_next_line(int fd);
int ft_strlen(char *str);
char *ft_strjoin(char *s1, char *s2);
char *ft_strdup(char *str);
char *ft_substr(char *str, int start, int len);
int ft_strchr(char *str, char c);
void	ft_strclr(char *s);
t_list *ft_lstnew(char *content, int fd);
t_list *ft_lstadd(t_list **lst, t_list *node);
void	ft_strdel(char **as);
t_list	*is_valid(int fd, t_list **origin);

# endif
