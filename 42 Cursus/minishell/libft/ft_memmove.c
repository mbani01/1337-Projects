/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamoussa <mamoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 20:04:07 by mamoussa          #+#    #+#             */
/*   Updated: 2019/10/21 13:09:49 by mamoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_mmcpy(void *dst, const void *src, size_t n)
{
	size_t save;

	save = n;
	if (*(char *)dst == '\0' && *(char *)src == '\0')
		return (dst);
	while (n > 0)
	{
		*(char *)dst = *(char *)src;
		dst++;
		src++;
		n--;
	}
	return (dst - save);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	if (dst == src)
		return (dst);
	if (len == 0 || ((char *)dst == NULL && (char *)src == NULL))
		return (dst);
	if (dst < src)
		return (ft_mmcpy((char *)dst, (char *)src, len));
	else
	{
		dst += len;
		src += len;
		while (len > 0)
		{
			*(char *)--dst = *(char *)--src;
			len--;
		}
		return (dst);
	}
	return (0);
}
