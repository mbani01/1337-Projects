/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_lst_helper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamoussa <mamoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 13:00:14 by mamoussa          #+#    #+#             */
/*   Updated: 2020/12/11 13:02:44 by mamoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	ft_lstclearnod(t_cmd *back, t_cmd *next)
{
	t_cmd *temp;

	temp = back->next;
	back->next = next;
	free(temp->string);
	temp->string = NULL;
	free(temp);
	temp = NULL;
}
