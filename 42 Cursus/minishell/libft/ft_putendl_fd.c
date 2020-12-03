/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamoussa <mamoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 12:01:11 by mamoussa          #+#    #+#             */
/*   Updated: 2019/10/20 16:57:32 by mamoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static	void	ft_print(char c, int fd)
{
	write(fd, &c, 1);
}

void			ft_putendl_fd(char *s, int fd)
{
	if (s)
	{
		while (*s != '\0')
		{
			ft_print(*s, fd);
			s++;
		}
		write(fd, "\n", 1);
	}
}
