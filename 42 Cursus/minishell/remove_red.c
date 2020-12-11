/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_red.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamoussa <mamoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 11:33:43 by mamoussa          #+#    #+#             */
/*   Updated: 2020/12/10 18:01:30 by mamoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

t_cmd	*remove_red(t_cmd *ptr)
{
	t_cmd	*tmp;

	if (ptr)
	{
		tmp = ptr->next;
		ptr->next = NULL;
		ptr = tmp;
	}
	while (ptr && (ptr->type != semicolumn) && (ptr->type != pipee))
	{
		tmp = ptr->next;
		simple_pointer_free(ptr->string);
		free(ptr);
		ptr = NULL;
		ptr = tmp;
	}
	return (ptr);
}

void	add_back_cmd(t_cmd *head, t_cmd *new_node)
{
	while (head)
	{
		if (!(head->next))
		{
			head->next = new_node;
			break ;
		}
		head = head->next;
	}
}
