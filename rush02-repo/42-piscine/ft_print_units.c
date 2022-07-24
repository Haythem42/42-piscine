/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_units.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmilan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 22:04:32 by nmilan            #+#    #+#             */
/*   Updated: 2022/07/24 16:31:37 by nmilan           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>

void	ft_print_units_ok(int *check, char *buffer, int fd, char c)
{
	while (buffer[0] == ' ' || buffer[0] == '	'
		|| buffer[0] == ':' || buffer[0] == c)
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

void	ft_print_units(char c, int fd, char *buffer)
{
	int	check;

	check = 0;
	while (!check)
	{
		read(fd, buffer, 1);
		if (buffer[0] == c)
		{
			read(fd, buffer, 1);
			if (buffer[0] == ' ' || buffer[0] == ':')
			{
				ft_print_units_ok(&check, buffer, fd, c);
			}
		}
	}
}

void	ft_print_tens_ok(int *check, char *buffer, int fd, char c)
{
	while (buffer[0] == ' ' || buffer[0] == '	'
		|| buffer[0] == ':' || buffer[0] == c)
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

void	ft_print_tens(int c, int fd, char *buffer)
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
			while (count < 2 && buffer[0] == c)
			{
				read(fd, buffer, 1);
				count++;
			}
			if (count == 1)
			{
				ft_print_tens_ok(&check, buffer, fd, c);
			}
			else
				count = 0;
		}
	}
}
