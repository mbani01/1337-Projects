/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_for_red2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamoussa <mamoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 12:43:28 by mamoussa          #+#    #+#             */
/*   Updated: 2020/12/09 20:54:44 by mamoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	check_for_red2(t_cmd *current)
{
	if (g_is_in || g_is_out)
	{
		current = g_cmd_head;
		current = ptr_to_red(current);
		current = remove_red(current);
		if (current)
			add_back_cmd(g_cmd_head, current);
	}
}
