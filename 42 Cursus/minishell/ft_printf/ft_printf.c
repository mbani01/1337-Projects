/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani <mbani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 20:31:24 by mbani             #+#    #+#             */
/*   Updated: 2019/11/15 21:55:21 by mbani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_spaces(int n)
{
	int i;

	i = 0;
	while (n > 0)
	{
		i = i + ft_putchar(' ');
		n--;
	}
	return (i);
}

int	ft_widthc(int minus, int width, int tmp, char s)
{
	int len;

	len = 0;
	if (minus)
		return (len = ft_putchar(s) + print_spaces(width - tmp));
	else
		return (len = print_spaces(width - tmp) + ft_putchar(s));
}

int	print_zeroes(int n)
{
	int len;

	len = 0;
	while (n > 0)
	{
		len += ft_putchar('0');
		n--;
	}
	return (len);
}

int	ft_printf(const char *a, ...)
{
	va_list	ap;
	int		len;

	len = 0;
	va_start(ap, a);
	while (*a)
	{
		while (*a == '%')
		{
			if (*a == '%' && *(a + 1) == '%')
			{
				a += 2;
				len = len + ft_putchar('%');
				continue;
			}
			len = len + check(&ap, &a);
		}
		if (*a)
			len = len + ft_putchar(*(a++));
		else
			break ;
	}
	va_end(ap);
	return (len);
}
