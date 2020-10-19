/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani <mbani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 21:42:00 by mbani             #+#    #+#             */
/*   Updated: 2019/10/21 13:07:50 by mbani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_calloc(size_t count, size_t size)
{
	register void	*ptr;
	register size_t	i;
	register int	j;

	j = 0;
	i = (count * size);
	ptr = malloc(count * size);
	if (ptr)
		while (i-- > 0)
		{
			*(unsigned char *)ptr = 0;
			if (i != 0)
			{
				ptr++;
				j++;
			}
		}
	return (ptr - j);
}
