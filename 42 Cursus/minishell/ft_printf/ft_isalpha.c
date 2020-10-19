/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani <mbani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 11:04:34 by mbani             #+#    #+#             */
/*   Updated: 2019/11/16 11:05:54 by mbani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

char	*convert_hex(unsigned long i)
{
	char			str[50];
	unsigned long	temp;
	unsigned long	rem;
	int				j;

	j = 0;
	temp = i;
	while (temp != 0)
	{
		rem = temp % 16;
		if (rem < 10)
			rem += 48;
		else
			rem += 55;
		str[j++] = rem;
		temp = temp / 16;
	}
	if (i == 0)
	{
		str[j] = '0';
		str[j + 1] = '\0';
	}
	else
		str[j] = '\0';
	return (ft_strdup(ft_strrev(str)));
}

void	struct_in(t_flag **f)
{
	(*f)->minus = 0;
	(*f)->zero = 0;
	(*f)->width = 0;
	(*f)->precision = -1;
}

void	width_arg(va_list *ap, t_flag **f)
{
	(*f)->width = va_arg(*ap, int);
	if ((*f)->width < 0)
	{
		(*f)->width *= -1;
		(*f)->minus = 1;
	}
}

void	precision_check(char **flags, va_list *ap, t_flag **f)
{
	(*f)->precision = ft_atoi(&*flags[0]);
	if (**flags == '*')
		(*f)->precision = va_arg(*ap, int);
}
