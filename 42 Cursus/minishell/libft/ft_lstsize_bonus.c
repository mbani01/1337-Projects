/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamoussa <mamoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 16:36:13 by mamoussa          #+#    #+#             */
/*   Updated: 2019/10/21 17:34:17 by mamoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lstsize(t_list *lst)
{
	int compt;

	compt = 1;
	if (lst == NULL)
		return (0);
	while (lst->next)
	{
		lst = lst->next;
		compt++;
	}
	return (compt);
}
