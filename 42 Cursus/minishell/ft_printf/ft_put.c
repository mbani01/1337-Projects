/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani <mbani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 20:32:33 by mbani             #+#    #+#             */
/*   Updated: 2019/11/15 18:12:17 by mbani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	if (c && c != '\0')
		return (1);
	return (0);
}

int	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (*str != '\0')
	{
		i = i + ft_putchar(*str);
		str++;
	}
	return (i);
}

int	ft_putnbr(int nb)
{
	static int		i;
	unsigned int	new_nb;

	new_nb = nb;
	if (nb < 0)
	{
		i = i + ft_putchar('-');
		new_nb = nb * -1;
	}
	if (new_nb > 9)
	{
		ft_putnbr(new_nb / 10);
		i = i + ft_putchar((new_nb % 10) + '0');
	}
	if (new_nb <= 9)
	{
		i = i + ft_putchar((new_nb) + '0');
	}
	return (i);
}

int	print_x(va_list *ap, const char **a, char x)
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
			len = ft_putstr(str);
			free(str);
		}
	}
	else if (x == 'X')
	{
		len = ft_putstr(str);
		free(str);
	}
	return (len);
}

int	ft_puts(char *str, int n)
{
	int i;

	i = 0;
	while (*str != '\0' && n)
	{
		i = i + ft_putchar(*str);
		str++;
		n--;
	}
	return (i);
}
