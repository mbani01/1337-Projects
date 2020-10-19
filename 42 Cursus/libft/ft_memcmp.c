/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 22:48:41 by mbani             #+#    #+#             */
/*   Updated: 2019/10/09 23:20:31 by mbani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int i;

	while (n-- > 0)
	{
		i = *(unsigned char *)s1 - *(unsigned char *)s2;
		if (i == 0)
		{
			s1++;
			s2++;
		}
		else
			return (i);
	}
	return (0);
}
