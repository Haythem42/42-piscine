/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_zero.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcrimet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 19:45:49 by lcrimet           #+#    #+#             */
/*   Updated: 2022/07/24 21:42:02 by lcrimet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include <unistd.h>
#include <fcntl.h>

int	ft_print_zero(char *dict, char *num)
{
	int		i;
	int		check;
	int		fd;
	char	buffer[1];

	i = 0;
	check = 0;
	while (num[i] != '\0')
	{
		if (num[i] != '0')
			check++;
		i++;
	}
	if (check == 0)
	{
		fd = open(dict, O_RDONLY);
		ft_print_units('0', fd, buffer);
		close(fd);
		write(1, "\n", 1);
		return (1);
	}
	return (0);
}
