/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamoussa <mamoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 18:15:50 by mamoussa          #+#    #+#             */
/*   Updated: 2019/10/21 13:08:07 by mamoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(const char *str)
{
	int				i;
	long			result;
	short			s;

	i = 0;
	result = 0;
	s = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if ((str[i] == '-') || (str[i] == '+'))
	{
		if (str[i] == '-')
			s = s * -1;
		i++;
	}
	while ((str[i] != '\0') && (str[i] >= '0') && (str[i] <= '9'))
	{
		result = result * 10 + (str[i] - 48);
		if (result > 2147483648 && s == -1)
			return (0);
		if (result > 2147483647 && s == 1)
			return (-1);
		i++;
	}
	return (result * s);
}
