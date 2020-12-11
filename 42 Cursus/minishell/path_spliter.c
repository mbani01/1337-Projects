/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_spliter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamoussa <mamoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 10:23:08 by mamoussa          #+#    #+#             */
/*   Updated: 2020/12/10 17:51:13 by mamoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

char	**path_spliter(void)
{
	t_env	*current;
	char	**res;

	current = g_env_head;
	while (current)
	{
		if (!ft_strncmp(current->key, "PATH", ft_strlen("PATH")))
		{
			res = ft_split(current->value, ':');
			return (res);
		}
		current = current->next;
	}
	return (NULL);
}
