/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_in_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamoussa <mamoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 16:15:07 by mamoussa          #+#    #+#             */
/*   Updated: 2020/11/24 16:49:01 by mamoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void    node_swap(t_env *head, t_env *current)
{
    char *tmp;

    tmp = ft_strdup(head->key);
    g_tmp = head->key;
    head->key = ft_strdup(current->key);
    simple_pointer_free(g_tmp);
    g_tmp = current->key;
    current->key = ft_strdup(tmp);
    simple_pointer_free(g_tmp);
    simple_pointer_free(tmp);
    tmp = ft_strdup(head->value);
    g_tmp = head->value;
    head->value = ft_strdup(current->value);
    simple_pointer_free(g_tmp);
    g_tmp = current->value;
    current->value = ft_strdup(tmp);
    simple_pointer_free(g_tmp);
    simple_pointer_free(tmp);
}

int     key_compariason(char *head_key, char *cur_key)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (head_key[i] && cur_key[i])
    {
        if (head_key[i] == cur_key[j])
        {
            i++;
            j++;
            continue;
        }
        else
            return (head_key[i] - cur_key[j]);
    }
    return (0);
}

void    node_sort(void)
{
    t_env   *head;
    t_env   *current;

    head = g_env_head;
    while (head->next)
    {
        current = head->next;
        while (current)
        {
            if (key_compariason(head->key, current->key) > 0)
                node_swap(head, current);
            current = current->next; 
        }
        head = head->next;
    }
}

void print_in_sort(void)
{
    t_env *current;

    current = g_env_head;
    node_sort();
    while (current)
    {
        write(1, current->key, ft_strlen(current->key));
        write(1, "=", 1);
        write(1, current->value, ft_strlen(current->value));
        write(1, "\n", 1);
        current = current->next;
    }
}