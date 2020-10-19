/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprint.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani <mbani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 21:08:17 by mbani             #+#    #+#             */
/*   Updated: 2019/11/16 11:05:32 by mbani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	flagd_helper(char *s, int width, int precision, int tmp)
{
	s[0] = '0';
	return (print_spaces(width - (tmp + 1)) + ft_putchar('-') +
			print_zeroes(precision - (ft_strlen(s) - 1) - 1) + ft_putstr(s));
}

int	ft_flagd(int precision, int width, short minus, char *s)
{
	int tmp;

	tmp = ft_strlen(s);
	if (precision > ft_strlen(s))
		tmp = precision;
	if (s[0] == '0' && (precision == 0 || precision == -1))
		return (print_spaces(width - tmp) + ft_putchar(' '));
	if (!minus)
	{
		if (s[0] == '-' && precision > (ft_strlen(s) - 1))
			return (flagd_helper(s, width, precision, tmp));
		return (print_spaces(width - tmp) +
				print_zeroes(precision - ft_strlen(s)) + ft_putstr(s));
	}
	else if (minus)
		if (s[0] == '-' && precision > (ft_strlen(s) - 1))
		{
			s[0] = '0';
			return (ft_putchar('-') +
			print_zeroes(precision - (ft_strlen(s) - 1) - 1)
			+ ft_putstr(s) + print_spaces(width - (tmp + 1)));
		}
	return (print_zeroes(precision - ft_strlen(s))
			+ ft_putstr(s) + print_spaces(width - tmp));
}

int	fprint_i(va_list *ap, t_flag **f, const char **a)
{
	int		len;
	char	*s;
	int		n;

	len = 0;
	*a += 1;
	n = va_arg(*ap, int);
	s = ft_itoa(n);
	if ((((*f)->zero && !(*f)->width) ||
	(!(*f)->zero && (*f)->width == 0)) && ((*f)->precision < 0))
		len = ft_putstr(s);
	if ((*f)->width && (*f)->precision >= 0)
		len = ft_flag_i((*f)->width, (*f)->precision, (*f)->minus, s);
	else if ((*f)->precision >= 0 && !(*f)->width)
		len = ft_pre_d((*f)->precision, s);
	else if ((*f)->width)
		len = ft_width_d((*f)->minus, (*f)->width, (*f)->zero, s);
	free(s);
	return (len);
}

int	ft_flag_i(int width, int precision, int minus, char *s)
{
	int len;
	int tmp;

	len = 0;
	tmp = ft_strlen(s);
	if (precision > ft_strlen(s))
		tmp = precision;
	return (ft_flagd(precision, width, minus, s));
}

int	ft_printx(t_flag **f, char *str)
{
	int len;

	len = 0;
	if ((*f)->precision == 0 && str[0] == '0')
	{
		if ((*f)->width)
			return (ft_flagd((*f)->precision, (*f)->width, (*f)->minus, str));
		else
			return (0);
	}
	if (!(*f)->width && (*f)->precision >= 0)
		return (len = print_zeroes((*f)->precision - ft_strlen(str)) +
				ft_putstr(str));
		if ((*f)->zero && (*f)->precision < 0)
		return (len = print_zeroes((*f)->width - ft_strlen(str)) +
					ft_putstr(str));
		if ((*f)->width && (*f)->precision >= 0)
		return (ft_flagd((*f)->precision, (*f)->width, (*f)->minus, str));
	if ((*f)->width && (*f)->precision < 0)
		return (len = ft_width_d((*f)->minus, (*f)->width, (*f)->zero, str));
	return (len);
}
