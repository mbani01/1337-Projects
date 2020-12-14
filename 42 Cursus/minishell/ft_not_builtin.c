/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_not_builtin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamoussa <mamoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 16:28:57 by mamoussa          #+#    #+#             */
/*   Updated: 2020/12/12 16:45:33 by mamoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

size_t	args_count(void)
{
	size_t	counter;
	t_cmd	*current;

	counter = 0;
	current = g_cmd_head;
	while (current && (current->type != semicolumn) &&
	(current->type != pipee))
	{
		counter++;
		current = current->next;
	}
	return (counter);
}

char	**set_args(size_t counter)
{
	size_t	i;
	char	**args;
	t_cmd	*current;

	i = 0;
	current = g_cmd_head;
	args = (char**)malloc(sizeof(char*) * (counter + 1));
	while (current && (current->type != semicolumn) &&
	(current->type != pipee))
	{
		args[i] = ft_strdup(current->string);
		i++;
		current = current->next;
	}
	args[i] = NULL;
	return (args);
}

void	ft_not_builtin(void)
{
	size_t	counter;
	char	**args;

	counter = args_count();
	if (!not_built_error())
	{
		printf("%s\n", g_cmd_head->string);
		ft_error("command not found\n");
		exit(127);
	}
	imp_red();
	imp_pipes();
	args = set_args(counter);
	execve(args[0], args, g_tmp_env);
}
