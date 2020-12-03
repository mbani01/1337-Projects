/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamoussa <mamoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 12:45:49 by mamoussa          #+#    #+#             */
/*   Updated: 2020/11/23 17:34:03 by mamoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

size_t  erro_cheker(void)
{
    if(ft_strncmp("pwd", g_cmd_head->string, ft_strlen(g_cmd_head->string)))
    {
        ft_error("command not found\n");
        return (1);
    }
    g_cmd_head = g_cmd_head->next;
    if(g_cmd_head)
    {
        write(1, "pwd: too many arguments\n",
        ft_strlen("pwd: too many arguments\n"));
        return (1);
    }
    return (0);
}

void	ft_pwd(void)
{
    char    *buf;

    buf = NULL;
    if(erro_cheker())
        return ;
    buf = getcwd(buf, 0);
    if (!buf)
    {
        write(1, "Error:", ft_strlen("Error:"));
        write(1, strerror(errno), ft_strlen(strerror(errno)));
        write(1, "\n", 1);
        return ;
    }
    write(1, buf, ft_strlen(buf));
    write(1, "\n", 1);
    simple_pointer_free(buf);
}
