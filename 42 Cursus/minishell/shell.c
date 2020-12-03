/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani <mbani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 17:54:10 by mbani             #+#    #+#             */
/*   Updated: 2020/12/03 12:22:46 by mbani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "shell.h"

int		add_to_list_bulk(char **tmp, char **op, int *i, int *j)
{
	enum e_type t;

	if (g_x == 0)
		t = cmd;
	else
		t = arg;
	if (*tmp[0])
		add_to_list(tmp, t);
	if (*j == 1 && *op[0])
	{
		t = operators_check(op[0]);
		add_to_list(op, t);
		free(*tmp);
		*tmp = NULL;
	}
	if (t == pipee || t == semicolumn)
		g_x = 0;
	else
		g_x -= 10;
	*j = 0;
	return (*i);
}

void	line_parser(char *line)
{
	g_cmd_head = NULL;
	g_x = 0;
	line = rm_spaces(line);
	line_split(line);
	if (line[0])
		param_expansion(g_cmd_head);
}

int		main(int argc, char  **argv, char **envp)
{
	int ret;

	(void) argc;
	(void) argv;
	cpy_env(envp);
	env_var(envp);
	while (1)
	{
		write(1, "Minishell-2.0$ ", 15);
		ret = get_next_line(0, &g_line);
		if (!ret)
			break ;
		line_parser(g_line);
		g_tmp_cmd = g_cmd_head;
		if (g_tmp_cmd && (syntax_error(g_tmp_cmd)) && (swap_lst(&g_tmp_cmd)))
			ft_execution(g_line, g_tmp_cmd);
		if (g_tmp_cmd)
			ft_lstclearcmd(&g_tmp_cmd);
		free(g_line);
	}
	free(g_line);
	ft_lstclearenv(&g_env_head);
	if (g_tmp_cmd)
		ft_lstclearcmd(&g_tmp_cmd);
	if (g_tmp_env)
		double_pointer_free(g_tmp_env);
	return (0);
}
