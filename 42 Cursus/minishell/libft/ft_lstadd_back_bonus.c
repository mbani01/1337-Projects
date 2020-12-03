/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamoussa <mamoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 18:44:08 by mamoussa          #+#    #+#             */
/*   Updated: 2019/10/19 16:03:01 by mamoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list *ptr;

	ptr = *alst;
	if (*alst == NULL)
		*alst = new;
	else
	{
		while (ptr->next)
		{
			ptr = ptr->next;
		}
		ptr->next = new;
	}
	new->next = NULL;
}
