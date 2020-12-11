/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamoussa <mamoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 11:32:17 by mbani             #+#    #+#             */
/*   Updated: 2020/12/11 12:39:01 by mamoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	add_to_str(char **tmp, char c)
{
	char *temp;

	temp = ft_strdup(*tmp);
	free(*tmp);
	tmp[0] = ft_calloc(ft_strlen(temp) + 1, ft_strlen(temp) + 1);
	ft_strlcpy(tmp[0], temp, ft_strlen(temp));
	ft_strlcat(tmp[0], &c, 1);
}

void	rm_backslash(char **temp, char **str, char **tmp, int *i)
{
	char *tmp1;

	temp[0][0] = str[0][*i + 1];
	tmp1 = tmp[0];
	tmp[0] = ft_strjoin(tmp[0], temp[0]);
	free(tmp1);
	*i += 1;
}

void	join(char **temp, char **tmp)
{
	char *tmp1;

	tmp1 = tmp[0];
	tmp[0] = ft_strjoin(tmp[0], temp[0]);
	free(tmp1);
}

int		not_escaped(char *line, int i)
{
	int res;

	res = 0;
	if (i)
		while (line[i] && line[i - 1] && line[--i] == '\\')
		{
			res++;
		}
	if (res % 2 == 0 || res == 0)
		return (1);
	else
		return (0);
}

void	add_to_list(char **tmp, enum e_type t)
{
	t_cmd	*new;

	new = ft_lstnew_cmd(*tmp, t);
	ft_lstadd_backcmd(&g_cmd_head, new);
	free(*tmp);
	*tmp = NULL;
}
