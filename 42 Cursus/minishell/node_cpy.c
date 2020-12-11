/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_cpy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamoussa <mamoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 12:08:29 by mamoussa          #+#    #+#             */
/*   Updated: 2020/12/10 16:45:16 by mamoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

t_env	*node_cpy(void)
{
	t_env	*head_cpy;
	t_env	*current;
	t_env	*new_node;

	current = g_env_head;
	head_cpy = NULL;
	while (current)
	{
		new_node = ft_lstnewenv(ft_strdup(current->key),
		ft_strdup(current->value));
		ft_lstadd_backenv(&head_cpy, new_node);
		current = current->next;
	}
	return (head_cpy);
}
