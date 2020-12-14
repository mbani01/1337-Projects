/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani <mbani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 10:33:43 by mamoussa          #+#    #+#             */
/*   Updated: 2020/12/12 11:40:19 by mbani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	exec1(void)
{
	if (check_for_red())
	{
		while (g_cmd_head && (g_cmd_head->type != semicolumn) &&
		(g_cmd_head->type != pipee))
			g_cmd_head = g_cmd_head->next;
	}
}

size_t	ft_exec1(char *line, t_cmd *tmp)
{
	while (g_cmd_head && g_cmd_head->type != semicolumn)
	{
		glob_var_init();
		exec1();
		if (g_cmd_head && g_cmd_head->type == cmd)
		{
			g_is_cmd = 1;
			ft_pipes(g_cmd_head);
			if (ft_strlen(g_cmd_head->string) == ft_strlen("sort") &&
			!ft_strncmp(g_cmd_head->string, "sort", ft_strlen("sort")))
				g_is_sort = 1;
			else
				g_is_sort = 0;
			ft_exec2(line, tmp);
			g_cur = g_cur->next;
		}
		g_cmd_head = (g_cmd_head && g_cmd_head->type != semicolumn) ?
		g_cmd_head->next : g_cmd_head;
	}
	ft_exec3();
	g_is_pipe = 0;
	return (0);
}

void	ft_copy(char *val, char *str, char **tmp, int k)
{
	int x;
	int j;

	x = 0;
	j = k + 2;
	while (val[x])
	{
		tmp[0][k] = val[x];
		k++;
		x++;
	}
	while (str[j])
	{
		tmp[0][k] = str[j];
		k++;
		j++;
	}
}

void	replace_1(char **str, char *val)
{
	int		len;
	int		k;
	char	*tmp;

	k = 0;
	len = ft_strlen(str[0]) + ft_strlen(val);
	tmp = ft_calloc(len, len);
	tmp[len] = '\0';
	while (str[0][k] != 127)
	{
		tmp[k] = str[0][k];
		k++;
	}
	ft_copy(val, str[0], &tmp, k);
	free(str[0]);
	str[0] = NULL;
	str[0] = tmp;
}

void	replace_return_value(t_cmd **str, size_t value)
{
	t_cmd	*tmp;
	int		i;
	char	*val;

	tmp = str[0];
	val = ft_itoa((int)value);
	while (tmp && (tmp->type != semicolumn))
	{
		i = 0;
		while (tmp->string[i])
		{
			if (tmp->string[i] == 127)
				replace_1(&tmp->string, val);
			i++;
		}
		tmp = tmp->next;
	}
	free(val);
	val = NULL;
}
