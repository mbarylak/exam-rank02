/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarylak <mbarylak@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 18:05:10 by mbarylak          #+#    #+#             */
/*   Updated: 2021/11/11 15:00:17 by mbarylak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	free(s);
	return (i);
}

int	ft_putstr2(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (write(1, "(null)", 6));
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

int	digit_counter(int n)
{
	unsigned int	nbr;
	int				count;

	count = 1;
	if (n < 0)
	{
		nbr = n * -1;
		count++;
	}
	else
		nbr = n;
	while (nbr >= 10)
	{
		nbr = nbr / 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	unsigned int	nbr;
	char			*num;
	int				dig_count;

	dig_count = digit_counter(n);
	num = (char *) malloc(dig_count + 1);
	if (!num)
		return (NULL);
	if (n < 0)
	{
		num[0] = '-';
		nbr = n * -1;
	}
	else
		nbr = n;
	if (nbr == 0)
		num[0] = '0';
	num[dig_count] = '\0';
	while (nbr > 0)
	{
		dig_count--;
		num[dig_count] = (nbr % 10) + '0';
		nbr = nbr / 10;
	}
	return (num);
}

char	*ft_itohex(unsigned long int n, char *base)
{
	unsigned long int	nbr;
	char				*num;
	int					dig_count;

	dig_count = 1;
	nbr = n;
	while (nbr >= 16)
	{
		nbr = nbr / 16;
		dig_count++;
	}
	num = (char *) malloc(dig_count + 1);
	if (!num)
		return (NULL);
	if (n == 0)
		num[0] = '0';
	num[dig_count] = '\0';
	while (n > 0)
	{
		dig_count--;
		num[dig_count] = base[n % 16];
		n = n / 16;
	}
	return (num);
}

int	do_ur_thing(char c, va_list args)
{
	if (c == 's')
		return (ft_putstr2(va_arg(args, char *)));
	else if (c == 'd')
		return (ft_putstr(ft_itoa(va_arg(args, int))));
	else if (c == 'x')
		return (ft_putstr(ft_itohex(va_arg(args, unsigned int), "0123456789abcdef")));
	else if (c == '%')
		return (write(1, "%", 1));
	return (write(1, &c, 1));
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		count;
	int		i;

	i = 0;
	count = 0;
	va_start(args, s);
	while (s[i])
	{
		if (s[i] == '%')
		{
			count += do_ur_thing(s[i + 1], args);
			i = i + 2;
		}
		else
		{
			write(1, &s[i], 1);
			i++;
			count++;
		}
	}
	va_end(args);
	return (count);
}
