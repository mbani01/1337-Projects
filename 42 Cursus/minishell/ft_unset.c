/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamoussa <mamoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 12:51:04 by mamoussa          #+#    #+#             */
/*   Updated: 2020/12/11 17:07:33 by mamoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	delete_node(t_env *current)
{
	t_env	*head;
	t_env	*tmp;

	head = g_env_head;
	while (head)
	{
		if (head->next == current)
		{
			tmp = current->next;
			free(current);
			current = NULL;
			head->next = tmp;
			break ;
		}
		head = head->next;
	}
}

void	ft_unset_helper(void)
{
	t_env	*current;

	current = g_env_head;
	while (current)
	{
		if ((ft_strlen(g_cmd_head->string) == ft_strlen(current->key) &&
		!ft_strncmp(g_cmd_head->string, current->key,
		ft_strlen(current->key))))
		{
			delete_node(current);
			break ;
		}
		current = current->next;
	}
}

size_t	unset_error(void)
{
	t_cmd	*cur;

	cur = g_cmd_head;
	while (cur && (cur->type != semicolumn))
	{
		if (cur->type == pipee)
			return (1);
		if (ft_strchr(cur->string, '='))
		{
			write(2, "unset: ", ft_strlen("unset: "));
			write(2, cur->string, ft_strlen(cur->string));
			write(2, "=: invalid parameter name\n",
			ft_strlen("=: invalid parameter name\n"));
			g_status = 1;
			return (1);
		}
		cur = cur->next;
	}
	return (0);
}

void	ft_unset(void)
{
	if (ft_strncmp("unset", g_cmd_head->string,
	ft_strlen(g_cmd_head->string)))
	{
		ft_error(g_cmd_head->string);
		write(1, ": command not found\n", ft_strlen(": command not found\n"));
		g_status = 127;
		return ;
	}
	g_cmd_head = g_cmd_head->next;
	if (!g_cmd_head)
		return ;
	if (unset_error())
		return ;
	while (g_cmd_head && (g_cmd_head->type != semicolumn))
	{
		ft_unset_helper();
		g_cmd_head = g_cmd_head->next;
	}
}
