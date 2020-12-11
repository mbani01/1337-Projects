/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_in_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamoussa <mamoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 16:15:07 by mamoussa          #+#    #+#             */
/*   Updated: 2020/12/10 17:59:41 by mamoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	node_swap(t_env *head, t_env *current)
{
	char	*tmp;

	tmp = ft_strdup(head->key);
	g_tmp = head->key;
	head->key = ft_strdup(current->key);
	simple_pointer_free(g_tmp);
	g_tmp = current->key;
	current->key = ft_strdup(tmp);
	simple_pointer_free(g_tmp);
	simple_pointer_free(tmp);
	tmp = ft_strdup(head->value);
	g_tmp = head->value;
	head->value = ft_strdup(current->value);
	simple_pointer_free(g_tmp);
	g_tmp = current->value;
	current->value = ft_strdup(tmp);
	simple_pointer_free(g_tmp);
	simple_pointer_free(tmp);
}

int		key_compariason(char *head_key, char *cur_key)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (head_key[i] && cur_key[i])
	{
		if (head_key[i] == cur_key[j])
		{
			i++;
			j++;
			continue ;
		}
		else
			return (head_key[i] - cur_key[j]);
	}
	return (0);
}

void	node_sort(t_env *head_cpy)
{
	t_env	*head;
	t_env	*current;

	head = head_cpy;
	while (head->next)
	{
		current = head->next;
		while (current)
		{
			if (key_compariason(head->key, current->key) > 0)
				node_swap(head, current);
			current = current->next;
		}
		head = head->next;
	}
}

void	print_in_sort_helper(t_env *current)
{
	if (g_is_out)
	{
		dup2(g_fd_out, 1);
		close(g_fd_out);
	}
	imp_pipes();
	while (current)
	{
		write(1, "declare -x ", ft_strlen("declare -x "));
		write(1, current->key, ft_strlen(current->key));
		write(1, "=", 1);
		write(1, current->value, ft_strlen(current->value));
		write(1, "\n", 1);
		current = current->next;
	}
	exit(0);
}

void	print_in_sort(void)
{
	t_env	*current;
	t_env	*head_cpy;
	pid_t	pid;

	head_cpy = node_cpy();
	current = head_cpy;
	node_sort(head_cpy);
	if ((pid = fork()) < 0)
		return ;
	if (pid == 0)
		print_in_sort_helper(current);
	else
		ft_lstclearenv(&head_cpy);
}
