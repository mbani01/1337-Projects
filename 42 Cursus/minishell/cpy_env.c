/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cpy_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamoussa <mamoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 19:14:44 by mamoussa          #+#    #+#             */
/*   Updated: 2020/12/09 20:58:00 by mamoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

size_t	envp_count(char **envp)
{
	size_t	counter;
	size_t	i;

	counter = 0;
	i = 0;
	while (envp[i])
	{
		counter++;
		i++;
	}
	return (counter);
}

void	cpy_env(char **envp)
{
	size_t	i;
	size_t	counter;

	i = 0;
	counter = envp_count(envp);
	g_tmp_env = (char**)malloc(sizeof(char*) * (counter + 1));
	while (envp[i])
	{
		g_tmp_env[i] = ft_strdup(envp[i]);
		i++;
	}
	g_tmp_env[i] = NULL;
}
