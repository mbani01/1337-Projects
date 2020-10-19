/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani <mbani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 11:12:40 by mbani             #+#    #+#             */
/*   Updated: 2019/10/22 22:19:12 by mbani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t lend;
	size_t lens;
	size_t j;

	j = 0;
	lens = 0;
	if (dst || !src)
	{
		lend = ft_strlen(dst);
		lens = ft_strlen(src);
		j = lend;
		if (size <= lend)
			return (lens + size);
		else
		{
			while (size - 1 > lend && *src)
				dst[lend++] = *src++;
			dst[lend] = '\0';
		}
	}
	return (j + lens);
}
