/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmilan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 14:15:32 by nmilan            #+#    #+#             */
/*   Updated: 2022/07/24 20:32:18 by lcrimet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>

void	ft_print(char c, int head, char *buffer, char *dict)
{
	int	fd;

	if (head == 3 && c != '0')
	{
		fd = open(dict, O_RDONLY);
		ft_print_units(c, fd, buffer);
		write(1, " ", 1);
		close(fd);
		fd = open(dict, O_RDONLY);
		ft_print_hundred(fd, buffer);
		close(fd);
	}
	else if (head == 2 && c != '0')
	{
		fd = open(dict, O_RDONLY);
		ft_print_decade(c, fd, buffer);
		close(fd);
	}
	else if (head == 1 && c != '0')
	{
		fd = open(dict, O_RDONLY);
		ft_print_units(c, fd, buffer);
		close(fd);
	}
}
