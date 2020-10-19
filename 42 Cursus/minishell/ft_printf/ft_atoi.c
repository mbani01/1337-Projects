/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani <mbani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 17:52:01 by mbani             #+#    #+#             */
/*   Updated: 2019/11/16 11:05:45 by mbani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int		ft_atoi(const char *str)
{
	int		i;
	int		sign;
	long	res;

	i = 0;
	res = 0;
	sign = 1;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while ((str[i] != '\0') && (str[i] <= '9' && str[i] >= '0'))
	{
		res = ((res * 10) + (str[i] - 48));
		if (res > 2147483648 && sign == -1)
			return (0);
		else if (res > 2147483647 && sign == 1)
			return (-1);
		i++;
	}
	return (res * sign);
}

int		fprint_u(va_list *ap, const char **a, t_flag **f)
{
	unsigned int	u;
	int				len;
	char			*str;

	len = 0;
	*a += 1;
	u = va_arg(*ap, unsigned);
	str = ft_itoa_u(u);
	len = ft_printx(f, str);
	free(str);
	return (len);
}

char	*ft_strrev(char *str)
{
	char	c;
	int		i;
	int		start;
	int		end;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	start = 0;
	end = i - 1;
	while (start < end)
	{
		c = str[start];
		str[start] = str[end];
		str[end] = c;
		start++;
		end--;
	}
	return (str);
}

int		fprint_x(va_list *ap, const char **a, char x, t_flag **f)
{
	unsigned int	u;
	int				len;
	char			*str;

	len = 0;
	*a += 1;
	u = va_arg(*ap, unsigned);
	str = convert_hex(u);
	if (x == 'x')
	{
		if (x)
		{
			str = ft_strlowcase(str);
			len = ft_printx(f, str);
			free(str);
		}
	}
	else if (x == 'X')
	{
		len = ft_printx(f, str);
		free(str);
	}
	return (len);
}

int		fprint_percent(t_flag **f, const char **a)
{
	int len;

	len = 0;
	*a += 1;
	if ((*f)->zero && (*f)->precision < 0)
		return (len = print_zeroes((*f)->width - 1) + ft_putchar('%'));
	if ((*f)->zero && (*f)->precision >= 0 && (*f)->width)
		return (len = print_spaces((*f)->width - (*f)->precision) +
		print_zeroes((*f)->precision - 1));
		if ((*f)->width)
	{
		if ((*f)->minus)
			return (len = ft_putchar('%') + print_spaces((*f)->width - 1));
		if (!(*f)->minus)
			return (len = print_spaces((*f)->width - 1) + ft_putchar('%'));
	}
	else
	{
		if ((*f)->minus)
			return (len = ft_putchar('%'));
		if (!(*f)->minus)
			return (len = ft_putchar('%'));
	}
	return (0);
}
