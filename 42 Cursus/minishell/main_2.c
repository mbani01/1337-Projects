/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamoussa <mamoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 11:56:34 by mamoussa          #+#    #+#             */
/*   Updated: 2020/12/11 12:23:48 by mamoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	main_2(char *line)
{
	free(line);
	line = NULL;
	ft_lstclearenv(&g_env_head);
	if (g_tmp_cmd)
		ft_lstclearcmd(&g_tmp_cmd);
	if (g_tmp_env)
		double_pointer_free(g_tmp_env);
}

void	main_3(char *line)
{
	g_tmp_cmd = g_cmd_head;
	if (g_tmp_cmd && (syntax_error(g_tmp_cmd)) && (swap_lst(&g_tmp_cmd))
	&& (add_echo(&g_tmp_cmd)))
	{
		g_cmd_head = g_tmp_cmd;
		ft_execution(line, g_tmp_cmd);
	}
	if (g_tmp_cmd)
		ft_lstclearcmd(&g_tmp_cmd);
	free(g_buff);
	g_buff = NULL;
}
