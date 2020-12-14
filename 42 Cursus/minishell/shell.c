/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani <mbani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 17:54:10 by mbani             #+#    #+#             */
/*   Updated: 2020/12/12 20:30:15 by mbani            ###   ########.fr       */
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
}

void	sig_handler(int seg)
{
	g_is_sigint = 0;
	if (seg == SIGINT && !g_is_cmd)
	{
		g_len = ft_strlen(g_line);
		write(1, "\nminishell-2.0$\t", 18);
	}
	else
		g_is_sigint = 1;
	if (seg == SIGQUIT && !g_is_cmd)
		write(1, "\b\b", 2);
	else if (!g_is_sort && seg == SIGQUIT)
		write(1, "Quit: 3", 7);
}

void	main_1(char **envp)
{
	cpy_env(envp);
	env_var(envp);
	signal(SIGINT, sig_handler);
	signal(SIGQUIT, sig_handler);
}

int		main(int argc, char **argv, char **envp)
{
	int		ret;

	(void)argc;
	(void)argv;
	main_1(envp);
	g_line = NULL;
	while (1)
	{
		if (!g_line)
			write(1, "minishell-2.0$ ", 15);
		g_tmp = NULL;
		g_len = 0;
		ret = get_next_line(0, &g_line);
		if (!ret)
			ft_exit(g_line, g_tmp_cmd);
		line_parser(g_line);
		main_3(g_line);
		if (g_line)
		{
			free(g_line);
			g_line = NULL;
		}
	}
	main_2(g_line);
	return (0);
}
