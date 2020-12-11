/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamoussa <mamoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 12:49:37 by mamoussa          #+#    #+#             */
/*   Updated: 2020/12/11 16:42:44 by mamoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

size_t	search_for_key(char *key, char *value)
{
	t_env	*current;

	current = g_env_head;
	while (current)
	{
		if (!ft_strncmp(current->key, key, ft_strlen(current->key)))
		{
			g_tmp = current->value;
			current->value = ft_strdup(value);
			simple_pointer_free(g_tmp);
			return (1);
		}
		current = current->next;
	}
	return (0);
}

void	ft_export_helper(char *ptr)
{
	char	*key;
	char	*value;
	char	*tmp;
	t_env	*new_node;
	t_env	*current;

	tmp = ptr + 1;
	current = g_env_head;
	*ptr = '\0';
	key = ft_strdup(g_cmd_head->string);
	value = ft_strdup(tmp);
	if (search_for_key(key, value))
	{
		simple_pointer_free(key);
		simple_pointer_free(value);
		*ptr = '=';
		return ;
	}
	new_node = ft_lstnewenv(key, value);
	ft_lstadd_backenv(&current, new_node);
	*ptr = '=';
}

size_t	export_pipe_checker(void)
{
	t_cmd	*current;
	char	*ptr_equ;

	ptr_equ = NULL;
	current = g_cmd_head;
	current = current->next;
	while (current)
	{
		if (current->type == pipee)
			return (1);
		current = current->next;
	}
	return (0);
}

void	ft_export(void)
{
	char	*ptr_to_equ;

	ptr_to_equ = NULL;
	if (ft_strncmp("export", g_cmd_head->string,
	ft_strlen(g_cmd_head->string)))
	{
		ft_error(g_cmd_head->string);
		write(2, ": command not found\n", ft_strlen(": command not found\n"));
		g_status = 127;
		return ;
	}
	g_cmd_head = g_cmd_head->next;
	if (!g_cmd_head || (g_cmd_head->type == semicolumn) ||
	(g_cmd_head->type == pipee))
	{
		print_in_sort();
		return ;
	}
	ft_export_2();
}
