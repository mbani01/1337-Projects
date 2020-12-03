/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamoussa <mamoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 12:51:04 by mamoussa          #+#    #+#             */
/*   Updated: 2020/11/23 17:34:48 by mamoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void    delete_node(t_env *current)
{
    t_env   *head;
    t_env   *tmp;

    head = g_env_head;
    while (head)
    {
        if (head->next == current)
        {
            tmp = current->next;
            free(current);
            current = NULL;
            head->next = tmp;
            break;
        }
        head = head->next;
    }
}

void    ft_unset_helper(void)
{
    t_env   *current;

    current = g_env_head;
    while (current)
    {
        if (!ft_strncmp(g_cmd_head->string, current->key,
        ft_strlen(g_cmd_head->string)))
        {
            delete_node(current);
           break;
        }
        current = current->next;
    }
}

void	ft_unset(void)
{
    t_cmd   *current;

    current = g_cmd_head;
    current = current->next;
    if (ft_strchr(current->string, '='))
    {
        write(1, "unset: ", ft_strlen("unset: "));
        write(1, current->string, ft_strlen(current->string));
        write(1, ": invalid parameter name\n", 
        ft_strlen(": invalid parameter name\n"));
        return ;
    }
    if (ft_strncmp("unset", g_cmd_head->string, ft_strlen(g_cmd_head->string)))
    {
        ft_error(g_cmd_head->string);
        write(1, ": command not found\n", ft_strlen(": command not found\n"));
        return ;
    }
    g_cmd_head = g_cmd_head->next;
    if (!g_cmd_head)
        return ;
    ft_unset_helper();
}
