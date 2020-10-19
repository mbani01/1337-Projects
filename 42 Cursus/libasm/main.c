/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani <mbani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 16:22:20 by mbani             #+#    #+#             */
/*   Updated: 2020/02/28 11:57:54 by mbani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int		ft_strlen(char *str);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_write(int fildes, const void *buf, int nbyte);
int		ft_read(int fd, char *buffer, int count);
char	*ft_strcpy(char *dest, char *src);
char	*ft_strdup(const char *s1);

int		main(void)
{
	int		i;
	char	*buff;

	buff = ft_strdup("hello");
	ft_read(0, buff, 5);
	i = ft_strlen(buff);
	ft_strcpy(buff, buff);
	ft_strcmp(buff, buff);
	ft_write(1, "hello", 5);
	return (0);
}
