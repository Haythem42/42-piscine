/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_bloc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmilan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 22:06:45 by nmilan            #+#    #+#             */
/*   Updated: 2022/07/24 21:04:52 by lcrimet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>

void	ft_print_bloc_ok(int *check, char *buffer, int fd)
{
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
}

void	ft_print_bloc(int size, int fd, char *buffer)
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
			while (count < size && buffer[0] == '0')
			{
				read(fd, buffer, 1);
				count++;
			}
			if (count == size - 1)
			{
				ft_print_bloc_ok(&check, buffer, fd);
			}
			else
				count = 0;
		}
	}
}
