#include <stdlib.h>
#include <unistd.h>

int	ft_strlen(char *s)
{
	int i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char *ft_strdup(char *s)
{
	char *str;
	int		i;

	if (!s)
		return (NULL);
	str = (char *) malloc(ft_strlen(s) + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (s[i])
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strjoin(char *s, char c)
{
	char	*str;
	int		i;

	if (!s)
		return (NULL);
	str = malloc(ft_strlen(s) + 2);
	if (!str)
		return (NULL);
	i = 0;
	while (s[i])
	{
		str[i] = s[i];
		i++;
	}
	str[i] = c;
	str[i + 1] = '\0';
	free(s);
	return (str);
}

char	*get_next_line(int fd)
{
	int		ret;
	char	buf;
	char	*line;

	if (fd < 0)
		return (NULL);
	line = ft_strdup("");
	while ((ret = read(fd, &buf, 1)) > 0)
	{
		line = ft_strjoin(line, buf);
		if (buf == '\n')
			break ;
	}
	if (ret == -1)
	{
		free(line);
		line = NULL;
	}
	if (ft_strlen(line) == 0)
	{
		free(line);
		line = NULL;
	}
	return (line);
}
