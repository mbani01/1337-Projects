/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani <mbani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 17:10:21 by mbani             #+#    #+#             */
/*   Updated: 2019/12/25 23:02:06 by mbani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_noflags(va_list *ap, const char **a, char **flags)
{
	int len;

	free(*flags);
	if (*a[0] == 's')
		return (len = print_str(ap, a));
	if (*a[0] == 'c')
		return (len = print_c(ap, a));
	if (*a[0] == 'd' || *a[0] == 'i')
		return (len = print_i(ap, a));
	if (*a[0] == 'p')
		return (len = print_p(ap, a));
	if (*a[0] == 'u')
		return (len = print_u(ap, a));
	if (*a[0] == 'x' || *a[0] == 'X')
		return (len = print_x(ap, a, *a[0]));
	return (0);
}

int		type_check(const char **a, t_flag **f, va_list *ap)
{
	int len;

	len = 0;
	if (*a[0] == 's')
	{
		*a += 1;
		return (len = fprint_s(ap, f));
	}
	if (*a[0] == 'c')
		return (len = fprint_c(ap, f, a));
	if (*a[0] == 'd' || *a[0] == 'i')
		return (len = fprint_i(ap, f, a));
	if (*a[0] == 'p')
		return (len = fprint_p(ap, f, a));
	if (*a[0] == 'u')
		return (len = fprint_u(ap, a, f));
	if (*a[0] == 'x' || *a[0] == 'X')
		return (len = fprint_x(ap, a, *a[0], f));
	if (*a[0] == '%')
		return (len = fprint_percent(f, a));
	return (0);
}

int		ft_flagschecker(va_list *ap, char **flags, const char **a)
{
	t_flag	*f;
	int		len;
	char	*tmp;

	len = 0;
	tmp = *flags;
	f = malloc(sizeof(t_flag));
	struct_in(&f);
	width_check(flags, &f, ap);
	len = type_check(a, &f, ap);
	free(tmp);
	free(f);
	return (len);
}

int		check(va_list *ap, const char **a)
{
	int		len;
	t_help	*p;

	p = malloc(sizeof(t_help));
	(*p).i = 0;
	p->flags = malloc(1);
	*p->flags = '\0';
	p->ptr = malloc(1);
	p->tmp1 = p->ptr;
	while (*a[0] != 'c' && *a[0] != 's' && *a[0] != 'p' && *a[0] != 'd' &&
			*a[0] != 'i' && *a[0] != 'u' && *a[0] != 'x' && *a[0] != 'X')
	{
		flag_saver(&(p->ptr), &(p->flags), &(p->tmp), &a);
		*a += 1;
		(*p).i++;
		if (*a[0] == '%')
			break ;
	}
	flag_saver(&(p->ptr), &(p->flags), &(p->tmp), &a);
	free(p->tmp1);
	free(p);
	if (((*p).i) == 1 && *a[0] != '%')
		return (len = ft_noflags(ap, a, &(p->flags)));
	return (len = ft_flagschecker(ap, &(p->flags), a));
}

void	width_check(char **flags, t_flag **f, va_list *ap)
{
	int j;
	int fla;

	j = 1;
	fla = 1;
	while (flags[0][j] != '.' && ft_isalpha(flags[0][j]) == 0)
	{
		if (flags[0][1] == '-')
			(*f)->minus = 1;
		if (flags[0][1] == '0')
			(*f)->zero = 1;
		if (ft_isdigit(flags[0][j]) && fla == 1 && flags[0][j] != '0')
		{
			(*f)->width = ft_atoi(&flags[0][j]);
			fla = 0;
		}
		if (flags[0][j] == '*')
			width_arg(ap, f);
		j++;
	}
	if (flags[0][j] == '.')
	{
		flags[0] = &flags[0][j + 1];
		precision_check(flags, ap, f);
	}
}
