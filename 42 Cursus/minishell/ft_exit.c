/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamoussa <mamoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 11:11:48 by mamoussa          #+#    #+#             */
/*   Updated: 2020/12/11 13:29:40 by mamoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

size_t	erro_exit(void)
{
	t_cmd	*cur;

	cur = g_cmd_head;
	cur = cur->next;
	if (cur && (cur->type == pipee || cur->type == semicolumn))
		return (0);
	else if (cur && cur->next && (cur->next->type != pipee))
		return (1);
	return (0);
}

size_t	is_all_num(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (1);
		i++;
	}
	return (0);
}

size_t	ft_exit1(void)
{
	if (erro_exit())
	{
		if (!g_is_pipe)
			write(1, "exit\n", 5);
		ft_error("too many arguments\n");
		return (1);
	}
	return (0);
}

size_t	ft_exit_helper(void)
{
	if (g_cmd_head && ft_strncmp("exit", g_cmd_head->string,
	ft_strlen(g_cmd_head->string)))
	{
		ft_error("command not found:");
		write(1, g_cmd_head->string, ft_strlen(g_cmd_head->string));
		write(1, "\n", 1);
		return (1);
	}
	if (g_cmd_head->next && g_cmd_head->next->type != pipee
	&& g_cmd_head->next->type != semicolumn &&
	is_all_num(g_cmd_head->next->string))
	{
		ft_error("exit: ");
		write(1, g_cmd_head->next->string, ft_strlen(g_cmd_head->next->string));
		write(1, ": numeric argument required\n",
		ft_strlen(": numeric argument required\n"));
		return (0);
	}
	if (ft_exit1())
		return (1);
	return (0);
}

void	ft_exit(char *line, t_cmd *tmp)
{
	char	*str;

	str = NULL;
	if (g_cmd_head && g_cmd_head->next)
		str = g_cmd_head->next->string;
	if (g_cmd_head && ft_exit_helper())
		return ;
	if (!g_is_pipe)
	{
		write(1, "exit\n", 5);
		if (line)
			simple_pointer_free(line);
		if (tmp)
			ft_lstclearcmd(&tmp);
		ft_lstclearenv(&g_env_head);
		if (g_tmp_env)
			double_pointer_free(g_tmp_env);
		if (g_pipe_head)
			free_pipe();
		if (str)
			exit(ft_atoi(str));
		else
			exit(0);
	}
}
