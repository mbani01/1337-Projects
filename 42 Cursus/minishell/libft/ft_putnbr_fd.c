/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani <mbani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 19:04:43 by mbani             #+#    #+#             */
/*   Updated: 2019/10/16 19:24:34 by mbani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static	void	ft_print(char c, int fd)
{
	write(fd, &c, 1);
}

void			ft_putnbr_fd(int n, int fd)
{
	unsigned int new_nb;

	new_nb = n;
	if (n < 0)
	{
		ft_print('-', fd);
		new_nb = n * -1;
	}
	if (new_nb > 9)
	{
		ft_putnbr_fd(new_nb / 10, fd);
		ft_print((new_nb % 10) + '0', fd);
	}
	if (new_nb <= 9)
	{
		ft_print((new_nb) + '0', fd);
	}
}
