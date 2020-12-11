/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_var.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamoussa <mamoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 11:28:42 by mbani             #+#    #+#             */
/*   Updated: 2020/12/11 12:27:41 by mamoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	env_var(char **envp)
{
	int		i;
	t_env	*new;
	char	*key;
	char	*value;

	i = 0;
	while (envp[i])
	{
		if (envp[i])
			env_spliter(envp[i], &key, &value);
		i++;
		new = ft_lstnewenv(key, value);
		ft_lstadd_backenv(&g_env_head, new);
	}
}

int		env_spliter(char *env, char **key, char **value)
{
	int i;

	i = 0;
	if (env)
		while (env[i])
		{
			if (env[i] == '=')
			{
				env[i] = '\0';
				*key = ft_strdup(env);
				*value = ft_strdup(&env[i + 1]);
			}
			i++;
		}
	return (0);
}

void	ft_lstadd_backenv(t_env **alst, t_env *new)
{
	t_env *p;

	p = *alst;
	if (*alst == NULL)
	{
		*alst = new;
		new->next = NULL;
	}
	else
	{
		while (p->next)
			p = p->next;
		p->next = new;
		new->next = NULL;
	}
}

void	ft_lstclearenv(t_env **lst)
{
	t_env *tmp;

	while (*lst)
	{
		tmp = (*lst)->next;
		free((*lst)->key);
		(*lst)->key = NULL;
		free((*lst)->value);
		(*lst)->value = NULL;
		free(*lst);
		*lst = NULL;
		*lst = tmp;
	}
}

int		ft_strncmp_env(const char *s1, const char *s2, size_t n)
{
	const unsigned char	*c1;
	const unsigned char	*c2;
	size_t				i;

	if (n == 0)
		return (0);
	c1 = (unsigned char*)s1;
	c2 = (unsigned char *)s2;
	i = 0;
	while (c1[i] && c2[i] && c1[i] == c2[i] && n - 1 > i)
		i++;
	if (ft_strlen(s2) == n)
		return (c1[i] - c2[i]);
	return (-1);
}
