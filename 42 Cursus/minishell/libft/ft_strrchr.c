/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamoussa <mamoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 16:21:25 by mamoussa          #+#    #+#             */
/*   Updated: 2019/10/22 13:22:39 by mamoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ptr;
	char	j;
	int		i;

	ptr = (char *)s;
	j = c;
	i = 0;
	if (*ptr == '\0' && j != '\0')
		return (NULL);
	while (*ptr)
	{
		ptr++;
		i++;
	}
	if (j == '\0')
		return (ptr);
	while (i + 1 > 0)
	{
		if (*ptr == j)
			return (ptr);
		ptr--;
		i--;
	}
	return (NULL);
}
