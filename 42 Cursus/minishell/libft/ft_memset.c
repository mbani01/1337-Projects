/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamoussa <mamoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 12:59:57 by mamoussa          #+#    #+#             */
/*   Updated: 2019/10/21 13:09:56 by mamoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char *s1;

	s1 = (unsigned char *)b;
	while (len > 0)
	{
		*s1 = (unsigned char)c;
		s1++;
		len--;
	}
	return ((unsigned char *)b);
}
