/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_dict.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habelhad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 19:15:07 by habelhad          #+#    #+#             */
/*   Updated: 2022/07/24 22:37:18 by lcrimet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>

int	ft_check_syntax(char *buffer, int fd, int i)
{
	while (buffer[0] == '\n')
		i = read(fd, buffer, 1);
	if (buffer[0] < '0' || buffer[0] > '9')
		return (2);
	while (buffer[0] >= '0' && buffer[0] <= '9')
		i = read(fd, buffer, 1);
	while (buffer[0] == ' ')
		i = read(fd, buffer, 1);
	if (buffer[0] == ':')
		i = read(fd, buffer, 1);
	else
		return (2);
	while (buffer[0] == ' ')
		i = read(fd, buffer, 1);
	if (buffer[0] < 33 || buffer[0] > 127)
		return (2);
	while (buffer[0] >= 32 && buffer[0] <= 127)
		i = read(fd, buffer, 1);
	if (buffer[0] == '\n')
		i = read(fd, buffer, 1);
	else
		return (2);
	return (i);
}

int	ft_check_dict(char *buffer, char *dict)
{
	int	i;
	int	fd;

	fd = open(dict, O_RDONLY);
	i = read(fd, buffer, 1);
	while (i)
	{
		i = ft_check_syntax(buffer, fd, i);
		if (i == 2)
		{
			close(fd);
			return (1);
		}
	}
	close(fd);
	return (0);
}

int	ft_check(int size, char *buffer, char *dict)
{
	int	i;
	int	check;
	int	count;
	int	fd;

	fd = open(dict, O_RDONLY);
	i = 1;
	check = 0;
	count = -1;
	while (i && !check)
	{
		i = read(fd, buffer, 1);
		if (buffer[0] == '1')
		{
			i = read(fd, buffer, 1);
			while (++count < size && buffer[0] == '0')
				i = read(fd, buffer, 1);
			if (count == size - 1)
			{
				while (buffer[0] == ' ' || buffer[0] == '	'
					|| buffer[0] == ':' || buffer[0] == '1')
					i = read(fd, buffer, 1);
				while (buffer[0] != '\n')
				{
					i = read(fd, buffer, 1);
					if (buffer[0] != '\n')
						check = 1;
				}
			}
			else
				count = -1;
		}
	}
	close(fd);
	if (!i)
		return (1);
	return (0);
}
