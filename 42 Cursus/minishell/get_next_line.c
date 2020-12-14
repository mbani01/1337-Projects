/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani <mbani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 21:52:51 by mbani             #+#    #+#             */
/*   Updated: 2020/12/12 20:49:11 by mbani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "get_next_line.h"
#include "shell.h"

#define BUFFER_SIZE 100

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	unsigned int	len;
	char			*s3;
	unsigned int	len1;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len1 = ft_strlen(s1);
	len = len1 + ft_strlen(s2);
	s3 = (char *)malloc(sizeof(char) * len + 1);
	if (!s3)
		return (NULL);
	ft_strcpy(s3, (char *)s1);
	s3 += len1;
	ft_strcpy(s3, (char *)s2);
	return (s3 - len1);
}

char	*save_check(char *save, char **line)
{
	char *c;

	c = NULL;
	if (save)
	{
		if ((c = ft_strchr(save, '\n')))
		{
			*line = ft_strdup(save);
			ft_strcpy(save, ++c);
		}
		else
			*line = ft_strdup(save);
	}
	else
		*line = ft_calloc(1, 1);
	return (c);
}

int		body_check(char **save, char **buff)
{
	free(*save);
	*save = NULL;
	free(*buff);
	return (0);
}

void	ft_save(char **save, char **ch)
{
	char	*tmp;

	tmp = *save;
	*ch = *ch + 1;
	*save = ft_strdup(*ch);
	free(tmp);
}

int		get_next_line(int fd, char **line)
{
	int			ret;
	static char	*save;
	char		*ch;
	char		*tmp;

	if (read(fd, NULL, 0) != 0 || fd < 0 ||
	!(g_buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1))) || !line)
		return (-1);
	ch = save_check(save, line);
	while (!(ch))
	{
		if ((ret = read(fd, g_buffer, BUFFER_SIZE)) == 0 && !g_buff)
			return (body_check(&save, &g_buffer));
		g_buffer[ret] = '\0';
		if (g_len > 0)
			delete_pre();
		get_next_line_helper(g_buffer);
		if ((ch = ft_strchr(g_buffer, '\n')))
			ft_save(&save, &ch);
		tmp = *line;
		*line = ft_strjoin_gnl(*line, g_buffer);
		free(tmp);
	}
	free_g_buff();
	return (1);
}
