/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamoussa <mamoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 18:32:13 by mamoussa          #+#    #+#             */
/*   Updated: 2019/10/22 12:24:18 by mamoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*str;
	unsigned char	*ptr;
	size_t			j;

	if (n == 0)
		return (0);
	str = (unsigned char *)s1;
	ptr = (unsigned char *)s2;
	j = 0;
	while (str[j] && ptr[j] && (str[j] == ptr[j]) && n - 1 > j)
		j++;
	return (str[j] - ptr[j]);
}
