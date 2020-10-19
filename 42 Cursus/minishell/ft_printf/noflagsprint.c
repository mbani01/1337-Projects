/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   noflagsprint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani <mbani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 16:11:58 by mbani             #+#    #+#             */
/*   Updated: 2019/11/15 17:16:43 by mbani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_i(va_list *ap, const char **a)
{
	long int	d;
	int			len;

	d = va_arg(*ap, int);
	*a += 1;
	len = ft_putnbr(d);
	return (len);
}

int	print_str(va_list *ap, const char **a)
{
	char	*s;
	int		len;

	len = 0;
	s = va_arg(*ap, char *);
	*a += 1;
	if (!s)
		s = "(null)";
	len = ft_putstr(s);
	return (len);
}

int	print_c(va_list *ap, const char **a)
{
	char	c;
	int		len;

	len = 1;
	c = (char)va_arg(*ap, int);
	*a += 1;
	if (c == '\0')
		return (len = ft_putchar(c) + 1);
	len = ft_putchar(c);
	return (len);
}

int	print_p(va_list *ap, const char **a)
{
	unsigned long	i;
	int				len;
	char			*str;

	len = 0;
	i = va_arg(*ap, unsigned long);
	*a += 1;
	str = convert_hex(i);
	if (str)
	{
		write(1, "0x", 2);
		str = ft_strlowcase(str);
		len = 2 + (ft_putstr(str));
		free(str);
	}
	return (len);
}

int	print_u(va_list *ap, const char **a)
{
	unsigned int	u;
	int				len;
	char			*str;

	len = 0;
	*a += 1;
	u = va_arg(*ap, unsigned);
	str = ft_itoa_u(u);
	len = ft_putstr(str);
	free(str);
	return (len);
}
