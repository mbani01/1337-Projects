/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani <mbani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 19:55:21 by mbani             #+#    #+#             */
/*   Updated: 2019/10/21 22:17:39 by mbani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static	void	*ftt_memcpy(void *dst, const void *src, size_t n)
{
	size_t i;

	i = n;
	if (*(char *)dst == '\0' && *(char *)src == '\0')
		return (dst);
	while (n > 0)
	{
		*(char *)dst = *(char *)src;
		dst++;
		src++;
		n--;
	}
	return (dst - i);
}

void			*ft_memmove(void *dst, const void *src, size_t len)
{
	if (dst == src)
		return (dst);
	if (len == 0 || (dst == NULL && src == NULL))
		return (dst);
	if (dst < src)
		return (ftt_memcpy((char *)dst, (char *)src, len));
	else
	{
		src += len;
		dst += len;
		while (len-- > 0)
		{
			*(char *)--dst = *(char *)--src;
		}
		return (dst);
	}
	return (0);
}
