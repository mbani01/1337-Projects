/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamoussa <mamoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 18:47:18 by mamoussa          #+#    #+#             */
/*   Updated: 2020/11/10 17:47:37 by mamoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	while (src[i])
		i++;
	if (size == 0)
		return (i);
	while (j < i && j < (size - 1))
	{
		*dst = *src;
		dst++;
		src++;
		j++;
	}
	*dst = '\0';
	return (i);
}
