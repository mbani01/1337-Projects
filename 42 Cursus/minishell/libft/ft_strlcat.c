/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamoussa <mamoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 11:05:43 by mamoussa          #+#    #+#             */
/*   Updated: 2019/10/22 11:49:42 by mamoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	srclen;
	size_t	dstlen;
	size_t	i;

	i = 0;
	srclen = 0;
	dstlen = 0;
	if (dst || !src)
	{
		dstlen = ft_strlen(dst);
		srclen = ft_strlen(src);
		if (size <= dstlen)
			return (srclen + size);
		else
		{
			i = dstlen;
			while (size - 1 > dstlen && *src)
			{
				dst[dstlen++] = *src;
				src++;
			}
			dst[dstlen] = '\0';
		}
	}
	return (i + srclen);
}
