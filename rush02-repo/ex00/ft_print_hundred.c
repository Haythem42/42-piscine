/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hundred.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmilan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 22:18:02 by nmilan            #+#    #+#             */
/*   Updated: 2022/07/24 18:44:41 by lcrimet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>

void	ft_print_hundred_ok(int *check, char *buffer, int fd)
{
	while (buffer[0] == ' ' || buffer[0] == ':' || buffer[0] == '1')
		read(fd, buffer, 1);
	write(1, &buffer[0], 1);
	while (buffer[0] != '\n')
	{
		read(fd, buffer, 1);
		if (buffer[0] == ' ')
		{
			while (buffer[0] == ' ')
				read(fd, buffer, 1);
			if (buffer[0] != '\n')
				write(1, " ", 1);
		}
		if (buffer[0] != '\n')
			write(1, &buffer[0], 1);
		*check = 1;
	}
}

void	ft_print_hundred(int fd, char *buffer)
{
	int	check;
	int	count;

	check = 0;
	count = 0;
	while (!check)
	{
		read(fd, buffer, 1);
		if (buffer[0] == '1')
		{
			read(fd, buffer, 1);
			while (count < 3 && buffer[0] == '0')
			{
				read(fd, buffer, 1);
				count++;
			}
			if (count == 2)
			{
				ft_print_hundred_ok(&check, buffer, fd);
			}
			else
				count = 0;
		}
	}
}

void	ft_print_decade_ok(int *check, char *buffer, int fd)
{
	while (buffer[0] == ' ' || buffer[0] == '	'
		|| buffer[0] == ':' || buffer[0] == '1')
		read(fd, buffer, 1);
	write(1, &buffer[0], 1);
	while (buffer[0] != '\n')
	{
		read(fd, buffer, 1);
		if (buffer[0] == ' ')
		{
			while (buffer[0] == ' ')
				read(fd, buffer, 1);
			if (buffer[0] != '\n')
				write(1, " ", 1);
		}
		if (buffer[0] != '\n')
			write(1, &buffer[0], 1);
		*check = 1;
	}
}

void	ft_print_decade(char c, int fd, char *buffer)
{
	int	check;
	int	count;

	check = 0;
	count = 0;
	while (!check)
	{
		read(fd, buffer, 1);
		if (buffer[0] == c)
		{
			read(fd, buffer, 1);
			while (count < 2 && buffer[0] == '0')
			{
				read(fd, buffer, 1);
				count++;
			}
			if (count == 1)
			{
				ft_print_decade_ok(&check, buffer, fd);
			}
			else
				count = 0;
		}
	}
}
