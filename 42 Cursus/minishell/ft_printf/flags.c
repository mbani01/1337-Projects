/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani <mbani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 21:29:02 by mbani             #+#    #+#             */
/*   Updated: 2019/11/16 11:04:28 by mbani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_pre_d(int precision, char *s)
{
	int len;

	len = 0;
	if (precision == 0 && s[0] == '0')
		return (0);
	if (precision == 0)
		return (len = ft_putstr(s));
	if (precision >= ft_strlen(s))
	{
		if (s[0] == '-')
		{
			s[0] = '0';
			return (len = ft_putchar('-') +
			print_zeroes(precision - ft_strlen(s)) + ft_putstr(s));
		}
		return (len = print_zeroes(precision - ft_strlen(s)) + ft_putstr(s));
	}
	else
		return (len = ft_putstr(s));
}

int	ft_width_d(int minus, int width, short zero, char *s)
{
	int len;

	len = 0;
	if ((width > ft_strlen(s)) && (zero))
	{
		if (s[0] == '-')
		{
			s[0] = '0';
			return (len = ft_putchar('-') +
			print_zeroes(width - ft_strlen(s) - 1) +
			ft_putstr(s));
		}
		return (len = print_zeroes(width - ft_strlen(s)) + ft_putstr(s));
	}
	if (minus)
		return (len = ft_putstr(s) + print_spaces(width - ft_strlen(s)));
	else
		return (len = print_spaces(width - ft_strlen(s)) + ft_putstr(s));
}

int	fprint_c(va_list *ap, t_flag **f, const char **a)
{
	int		len;
	char	c;

	len = 0;
	*a += 1;
	c = (char)va_arg(*ap, int);
	if ((*f)->width)
		len = ft_widthc((*f)->minus, (*f)->width, 1, c);
	return (len);
}

int	fprint_p(va_list *ap, t_flag **f, const char **a)
{
	unsigned long	i;
	int				len;
	char			*str;
	char			*tmp;

	len = 0;
	i = va_arg(*ap, unsigned long);
	*a += 1;
	str = convert_hex(i);
	str = ft_strlowcase(str);
	tmp = str;
	str = ft_strjoin("0x", str);
	if ((*f)->width)
		len = ft_width((*f)->minus, (*f)->width, ft_strlen(str), str);
	free(tmp);
	free(str);
	return (len);
}

int	fprint_s(va_list *ap, t_flag **f)
{
	int		len;
	int		tmp;
	char	*s;

	len = 0;
	s = va_arg(*ap, char *);
	if (!s)
		s = "(null)";
	tmp = ft_strlen(s);
	if ((((*f)->width) && ((*f)->precision >= 0)))
	{
		if ((*f)->precision < ft_strlen(s))
			tmp = (*f)->precision;
		if ((*f)->minus)
			return (len = ft_puts(s, (*f)->precision) +
					print_spaces((*f)->width - tmp));
		else
			return (len = print_spaces((*f)->width - tmp) +
					ft_puts(s, (*f)->precision));
	}
	else if ((*f)->width)
		return (ft_width((*f)->minus, (*f)->width, tmp, s));
	else if (((*f)->precision))
		len = ft_puts(s, (*f)->precision);
	return (len);
}
