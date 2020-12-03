/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani <mbani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 11:11:48 by mamoussa          #+#    #+#             */
/*   Updated: 2020/11/24 17:24:04 by mbani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void    ft_exit(char *line, t_cmd *tmp)
{
    if (ft_strncmp("exit", g_cmd_head->string, ft_strlen(g_cmd_head->string)))
    {
        ft_error("command not found:");
        write(1, g_cmd_head->string, ft_strlen(g_cmd_head->string));
        write(1, "\n", 1);
        return ;
    }
    simple_pointer_free(line);
    if (tmp)
        ft_lstclearcmd(&tmp);
	ft_lstclearenv(&g_env_head);/* free env var  */
	if (g_tmp_env)
		double_pointer_free(g_tmp_env);
    exit(0);
}