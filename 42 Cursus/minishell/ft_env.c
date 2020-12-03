/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamoussa <mamoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 12:52:12 by mamoussa          #+#    #+#             */
/*   Updated: 2020/11/23 13:44:58 by mamoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

size_t    ft_env_helper(void)
{
    if (ft_strncmp("env", g_cmd_head->string, ft_strlen(g_cmd_head->string)))
    {
        ft_error(g_cmd_head->string);
        write(1, ": command not found\n", ft_strlen(": command not found\n"));
        return (1);
    }
    return (0);
}
void	ft_env(void)
{
    t_env   *current;

    if (ft_env_helper())
        return ;
    g_cmd_head = g_cmd_head->next;
    if (g_cmd_head)
    {
        write(1, "env: ", ft_strlen("env: "));
        write(1, g_cmd_head->string, ft_strlen(g_cmd_head->string));
        write(1, ": No such file or directory\n",
        ft_strlen(": No such file or directory\n"));
        return ;
    }
    current = g_env_head;
    while (current)
    {
        write(1, current->key, ft_strlen(current->key));
        write(1, "=", 1);
        write(1, current->value, ft_strlen(current->value));
        write(1, "\n", 1);
        current = current->next;
    }
}
