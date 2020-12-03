/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamoussa <mamoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 12:08:35 by mamoussa          #+#    #+#             */
/*   Updated: 2019/10/15 10:43:19 by mamoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static	void	ft_print(char n, int fd)
{
	write(fd, &n, 1);
}

void			ft_putnbr_fd(int n, int fd)
{
	unsigned int div;

	div = n;
	if (n < 0)
	{
		ft_print('-', fd);
		div = div * -1;
	}
	if (div > 9)
	{
		ft_putnbr_fd(div / 10, fd);
		ft_print((div % 10) + '0', fd);
	}
	if (div <= 9)
		ft_print(div + '0', fd);
}
