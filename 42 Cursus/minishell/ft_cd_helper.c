/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamoussa <mamoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 17:02:57 by mamoussa          #+#    #+#             */
/*   Updated: 2020/12/10 12:18:18 by mamoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

size_t	cd_helper(void)
{
	if (!ft_strncmp(g_cmd_head->string, "cd/", ft_strlen("cd/")))
	{
		chdir(g_cmd_head->string);
		ft_error(strerror(errno));
		write(1, ":", 1);
		write(1, g_cmd_head->string, ft_strlen(g_cmd_head->string));
		write(1, "\n", 1);
		g_status = 127;
		return (1);
	}
	return (0);
}

size_t	ft_cd_helper(void)
{
	char	*str;

	if (cd_helper())
		return (1);
	if (!ft_strncmp("cd", g_cmd_head->string,
	ft_strlen(g_cmd_head->string)))
	{
		g_cmd_head = g_cmd_head->next;
		if (!g_cmd_head)
		{
			str = check_for_home();
			chdir(str);
			return (1);
		}
	}
	else
	{
		ft_error("command not found:");
		write(1, g_cmd_head->string, ft_strlen(g_cmd_head->string));
		write(1, "\n", 1);
		g_status = 127;
		return (1);
	}
	return (0);
}
