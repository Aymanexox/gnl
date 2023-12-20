# ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
#include <fcntl.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif


size_t			ft_strlen(const char *s);
char	        *ft_strdup(char *s1);
int			    ft_strchr(char *s, int c);
char			*ft_strjoin(char *s1, char *s2);
char	        *ft_substr(char const *s, unsigned int start, size_t len);
char	*get_next_line(int fd);
char *ft_read(char *s,int fd);


#endif