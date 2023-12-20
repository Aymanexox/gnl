#include <stdio.h>
#include "get_next_line.h"
char	*get_next_line(int fd)
{
	static char *save;
	char *readed;
	char *line;
	char *before;
	int i;
	int j;

	readed = NULL;
	line = NULL;
	i =j = 0;
	(void)save;
	while (ft_strchr(readed, '\n') != 1)
	{
		readed = malloc(BUFFER_SIZE + 1);
		if (!readed)
			return (NULL);
		i = read(fd, readed, BUFFER_SIZE);
		readed[i] = '\0';
		while (readed)
			{
				if(readed[j] == '\n')
				{
					before = malloc(i - j);
					if (!before)
						return (NULL);
					before = ft_substr(readed,j,i - j);
				}
				j++;
				*(save)++ = *(before)++;

			}
		line = ft_strjoin(line, before);
		free(readed);
	}
	return (line);
}

int main()
{
	int fd = open("foo.txt", O_RDONLY);
	printf("[[%s]]", get_next_line(fd));
}