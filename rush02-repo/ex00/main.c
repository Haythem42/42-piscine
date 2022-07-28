/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcrimet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 11:01:35 by lcrimet           #+#    #+#             */
/*   Updated: 2022/07/24 23:31:05 by nmilan           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>

char	*ft_allocate(char *num)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (num[i] == '0')
		i++;
	while (num[i] >= '0' && num[i] <= '9')
	{
		i++;
		j++;
	}
	str = malloc((ft_strlen(num) + 1) * sizeof(char));
	if (!str)
		return (0);
	return (str);
}

char	*ft_atoa(char *str)
{
	char	*clean_array;
	int		i;
	int		j;

	i = 0;
	j = 0;
	clean_array = ft_allocate(str);
	while (str[i] == '0')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		clean_array[j] = str[i];
		i++;
		j++;
	}
	clean_array[j] = '\0';
	return (clean_array);
}

int	main(int argc, char **argv)
{
	int		fd;
	char	buffer[1];
	int		j;
	char	*num;
	int		size;
	char	*dict;

	dict = "numbers.dict";
	if (argc == 1)
		ft_print_error();
	else if (argc == 2)
	{
		if (ft_check_dict(buffer, dict))
			return (0);
		if (ft_print_zero(dict, argv[1]))
			return (0);
		if (ft_valid_args(argv[1]))
		{
			ft_print_error();
			return (0);
		}
		num = ft_atoa(argv[1]);
		j = ft_strlen(num) % 3;
		if (!j)
			j = 3;
		fd = 0;
		size = ft_strlen(num) - j + 1;
		while (size > 37)
		{
			if (ft_check(size, buffer, dict))
			{
				write(1, "Dict Error\n", 11);
				return (0);
			}
			size -= 3;
		}
		bloc_select(num, buffer, dict);
		free(num);
	}
	else if (argc == 3)
	{
		if (ft_valid_args(argv[2]))
		{
			ft_print_error();
			return (0);
		}
		num = ft_atoa(argv[2]);
		j = ft_strlen(num) % 3;
		if (!j)
			j = 3;
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
		{
			free(num);
			return (0);
		}
		if (read(fd, buffer, 1) == -1)
		{
			free(num);
			close(fd);
			return (0);
		}
		close(fd);
		if (ft_print_zero(argv[1], argv[2]))
		{
			free(num);
			return (0);
		}
		size = ft_strlen(num) - j + 1;
		while (size > 37)
		{
			if (ft_check(size, buffer, argv[1]))
			{
				write(1, "Dict Error\n", 11);
				return (0);
			}
			size -= 3;
		}
		bloc_select(num, buffer, argv[1]);
		free(num);
	}
	return (0);
}
