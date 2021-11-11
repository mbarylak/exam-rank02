/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarylak <mbarylak@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 14:29:51 by mbarylak          #+#    #+#             */
/*   Updated: 2021/11/10 19:37:56 by mbarylak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	dup_checker(char *s, char c, int ind)
{
	int	i;

	i = 0;
	while (i < ind)
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

void	ft_union(char *s1, char *s2)
{
	int	i;
	int	j;
	int	flag;

	i = 0;
	while(s1[i])
	{
		if (!dup_checker(s1, s1[i], i))
			write(1, &s1[i], 1);
		i++;
	}
	j = 0;
	while (s2[j])
	{
		if (!dup_checker(s2, s2[j], j))
		{
			i = 0;
			flag = 0;
			while (s1[i])
			{
				if (s2[j] == s1[i])
				{	
					flag = 1;
					break ;
				}
				i++;
			}
			if (!flag)
				write(1, &s2[j], 1);
		}
		j++;
	}
}

int	main(int argc, char ** argv)
{
	if (argc == 3)
		ft_union(argv[1], argv[2]);
	write(1, "\n", 1);
	return (0);
}
