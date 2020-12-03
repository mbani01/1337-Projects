/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamoussa <mamoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 18:50:41 by mamoussa          #+#    #+#             */
/*   Updated: 2019/10/20 17:18:18 by mamoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static	void	ft_print(char c, int fd)
{
	write(fd, &c, 1);
}

void			ft_putstr_fd(char *s, int fd)
{
	if (s)
		while (*s != '\0')
		{
			ft_print(*s, fd);
			s++;
		}
}
