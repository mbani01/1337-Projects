/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamoussa <mamoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 12:49:37 by mamoussa          #+#    #+#             */
/*   Updated: 2020/11/24 16:58:57 by mamoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void    ft_export_helper(void)
{

    
}

void	ft_export(void)
{
    if (ft_strncmp("export", g_cmd_head->string, ft_strlen(g_cmd_head->string)))
    {
        ft_error(g_cmd_head->string);
        write(1, ": command not found\n", ft_strlen(": command not found\n"));
        return ;
    }
    g_cmd_head = g_cmd_head->next;
    if (!g_cmd_head)
    {
        print_in_sort();
        return ;
    }
    if (ft_strchr(g_cmd_head->string, '='))
        ft_export_helper();
}
