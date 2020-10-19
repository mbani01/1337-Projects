/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani <mbani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 11:24:43 by mbani             #+#    #+#             */
/*   Updated: 2019/11/15 18:39:12 by mbani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

int		ft_width(int minus, int width, int tmp, char *s)
{
	int len;

	len = 0;
	if (minus)
		return (len = ft_putstr(s) + print_spaces(width - tmp));
	else
		return (len = print_spaces(width - tmp) + ft_putstr(s));
}

void	flag_saver(char **ptr, char **flags, char **tmp, const char ***a)
{
	**ptr = **a[0];
	*tmp = *flags;
	*flags = ft_strjoin(*flags, *ptr);
	free(*tmp);
	*tmp = NULL;
}
