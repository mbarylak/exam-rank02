/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarylak <mbarylak@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 17:46:46 by mbarylak          #+#    #+#             */
/*   Updated: 2021/11/11 14:59:23 by mbarylak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s, int c)
{
	char	*str;
	int		i;

	i = 0;
	str = (char *) malloc(ft_strlen(s) + 2);
	if (!str)
		return (NULL);
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

int	get_next_line(char **line)
{
	int		ret;
	char	buf;

	if (!line || !(*line = malloc(1)))
		return (-1);
	*line[0] = '\0';
	while ((ret = read(0, &buf, 1)) > 0)
	{
		if (buf == '\n')
			break ;
		*line = ft_strjoin(*line, buf);
	}
	return (ret);
}
