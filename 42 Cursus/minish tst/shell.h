/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani <mbani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 20:08:51 by mbani             #+#    #+#             */
/*   Updated: 2020/10/24 16:44:31 by mbani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "get_next_line.h"
#include <stdlib.h>
#include <stdio.h>
#ifndef _SHELL_H
# define _SHELL_H

typedef struct		s_env
{
	char			*key;
	char			*value;
	struct s_env	*next;
}					t_env;
typedef	struct		s_cmd
{
	char *			string;
	// enum					;
	struct s_cmd	*next;
}					t_cmd;
// enum	e_type
// {
// 	cmd, string, pipe, greater,
// };
enum	e_quotes
{
	none, opened, closed
};

t_env	*g_env_head;
t_cmd	*g_cmd_head;
t_env	*ft_lstnewenv(char *key, char *value);
void	ft_lstadd_backenv(t_env **alst, t_env *new);
void	ft_lstclearenv(t_env **lst);
t_cmd	*ft_lstnew_cmd(char *string);
void	ft_lstadd_backcmd(t_cmd **alst, t_cmd *new);
void	ft_lstclearcmd(t_cmd **lst);

#endif