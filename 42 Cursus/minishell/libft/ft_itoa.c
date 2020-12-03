/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamoussa <mamoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 12:00:31 by mamoussa          #+#    #+#             */
/*   Updated: 2019/10/21 13:09:04 by mamoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int			ft_count(unsigned int s)
{
	short i;

	i = 1;
	while (s >= 10)
	{
		s /= 10;
		i++;
	}
	return (i);
}

static	char		*ft_conv(char *ptr, unsigned int c, short i, short k)
{
	short mod;
	short j;

	j = 0;
	mod = 0;
	while (c >= 10)
	{
		mod = c % 10;
		ptr[--i + k] = mod + '0';
		c /= 10;
		j++;
	}
	if (c < 10)
		ptr[--i + k] = c + '0';
	ptr[j + 1 + k] = '\0';
	return (ptr);
}

char				*ft_itoa(int n)
{
	unsigned int	save;
	short			k;
	char			*ptr;
	short			compt;

	k = 0;
	save = 0;
	if (n < 0)
	{
		save = n * -1;
		k = 1;
	}
	else
		save = n;
	compt = ft_count(save);
	ptr = malloc(sizeof(char) * compt + 1 + k);
	if (!ptr)
		return (NULL);
	if (k)
		ptr[0] = '-';
	return (ft_conv(ptr, save, compt, k));
}
