/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcrimet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 11:01:35 by lcrimet           #+#    #+#             */
/*   Updated: 2022/07/23 18:31:22 by lcrimet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>

void	ft_print_error()
{
	write(1, "Error\n", 6);
}

int	ft_valid_args(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (1);
		i++;
	}
	return (0);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_print_block(int size, int fd, char *buffer)
{
	int	i;
	int	check;
	int	count;

	i = 1;
	check = 0;
	count = 0;
	while (i && !check)
	{
		i = read(fd, buffer, 1);
		if (buffer[0] == '1')
		{
			i = read(fd, buffer, 1);
			while (count < size && buffer[0] == '0')
			{
				i = read(fd, buffer, 1);
				count++;
			}
			if (count == size - 1)
			{
				while (buffer[0] == ' ' || buffer[0] == '	'
					|| buffer[0] == ':' || buffer[0] == '1')
					i = read(fd, buffer, 1);
				write(1, &buffer[0], 1);
				while (buffer[0] != '\n')
				{
					i = read(fd, buffer, 1);
					if (buffer[0] != '\n')
						write(1, &buffer[0], 1);
					check = 1;
				}
			}
			else
				count = 0;
		}
	}
	if (!i)
		return (1);
	return (0);
}

int	ft_print_hundred(int fd, char *buffer)
{
	int	i;
	int	check;
	int	count;

	i = 1;
	check = 0;
	count = 0;
	while (i && !check)
	{
		i = read(fd, buffer, 1);
		if (buffer[0] == '1')
		{
			i = read(fd, buffer, 1);
			while (count < 3 && buffer[0] == '0')
			{
				i = read(fd, buffer, 1);
				count++;
			}
			if (count == 2)
			{
				while (buffer[0] == ' ' || buffer[0] == '	'
					|| buffer[0] == ':' || buffer[0] == '1')
					i = read(fd, buffer, 1);
				write(1, &buffer[0], 1);
				while (buffer[0] != '\n')
				{
					i = read(fd, buffer, 1);
					if (buffer[0] != '\n')
						write(1, &buffer[0], 1);
					check = 1;
				}
			}
			else
				count = 0;
		}
	}
	if (!i)
		return (1);
	return (0);
}

int	ft_print_decade(char c, int fd, char *buffer)
{
	int	i;
	int	check;
	int	count;

	i = 1;
	check = 0;
	count = 0;
	while (i && !check)
	{
		i = read(fd, buffer, 1);
		if (buffer[0] == c)
		{
			i = read(fd, buffer, 1);
			while (count < 2 && buffer[0] == '0')
			{
				i = read(fd, buffer, 1);
				count++;
			}
			if (count == 1)
			{
				while (buffer[0] == ' ' || buffer[0] == '	'
					|| buffer[0] == ':' || buffer[0] == '1')
					i = read(fd, buffer, 1);
				write(1, &buffer[0], 1);
				while (buffer[0] != '\n')
				{
					i = read(fd, buffer, 1);
					if (buffer[0] != '\n')
						write(1, &buffer[0], 1);
					check = 1;
				}
			}
			else
				count = 0;
		}
	}
	if (!i)
		return (1);
	return (0);
}

int	ft_print_tens(int c, int fd, char *buffer)
{
	int	i;
	int	check;

	i = 1;
	check = 0;
	while (i && !check)
	{
		i = read(fd, buffer, 1);
		if (buffer[0] == '1')
		{
			i = read(fd, buffer, 1);
			if (buffer[0] == c)
			{
				while (buffer[0] == ' ' || buffer[0] == '	'
					|| buffer[0] == ':' || buffer[0] == c)
					i = read(fd, buffer, 1);
				write(1, &buffer[0], 1);
				while (buffer[0] != '\n')
				{
					i = read(fd, buffer, 1);
					if (buffer[0] != '\n')
						write(1, &buffer[0], 1);
					check = 1;
				}
			}
		}
	}
	if (!i)
		return (1);
	return (0);
}

int	ft_print_units(char c, int fd, char *buffer)
{
	int	i;
	int	check;

	i = 1;
	check = 0;
	while (i && !check)
	{
		i = read(fd, buffer, 1);
		if (buffer[0] == c)
		{
			while (buffer[0] == ' ' || buffer[0] == '	'
				|| buffer[0] == ':' || buffer[0] == c)
				i = read(fd, buffer, 1);
			write(1, &buffer[0], 1);
			while (buffer[0] != '\n')
			{
				i = read(fd, buffer, 1);
				if (buffer[0] != '\n')
					write(1, &buffer[0], 1);
				check = 1;
			}
		}
	}
	if (!i)
		return (1);
	return (0);
}

int	ft_print(char c, int head, int fd, char *buffer)
{
	if (head == 3 && c != '0')
	{
		if (ft_print_units(c, fd, buffer))
			return (1);
		write(1, " ", 1);
		close(fd);
		fd = open("numbers.dict", O_RDONLY);
		if (ft_print_hundred (fd, buffer))
			return (1);
	}
	else if (head == 2 && c != '0')
	{
		if (ft_print_decade (c, fd, buffer))
			return (1);
	}
	else if (head == 1 && c != '0')
	{
		if (ft_print_units (c, fd, buffer))
			return (1);
	}
	return (0);
}

int	block_select(char *str, int fd, char *buffer)
{
	int	head;
	int	block;
	int	size;
	int	control_first_empty;
	int	i;

	i = 0;
	size = ft_strlen(str);
	head = size % 3;
	block = (size / 3) + 1;
	control_first_empty = 0;
	if (head == 0)
		control_first_empty = 1;
	while (block > 0)
	{
		while (head > 0)
		{ 
			if (str[i] == '1' && head == 2)
			{
				fd = open("numbers.dict", O_RDONLY);
				if (ft_print_tens(str[i + 1], fd, buffer))
					return (1);
				if (block != 1)
					write(1, " ", 1);
				else
					write(1, "\n", 1);
				close(fd);
				head -= 2;
				i += 2;
			}
			else
			{
				fd = open("numbers.dict", O_RDONLY);
				if (ft_print(str[i], head, fd, buffer))
					return (1);
				if (block == 1 && head == 1)
					write(1, "\n", 1);
				else if (str[i] != '0')
					write(1, " ", 1);
				close(fd);
				i++;
				head--;
			}
		}
		head = 3;
		if (control_first_empty == 0 && block > 1 && (str[i - 1] != '0' || str[i - 2] != '0' || str[i - 3] != '0'))
		{
			fd = open("numbers.dict", O_RDONLY);
			if (ft_print_block((block - 1) * 3 + 1, fd, buffer))
				return (1);
			write(1, " ", 1);
			close(fd);
		}
		block--;
		control_first_empty = 0;
	}
	return (0);
}


int	ft_check(int size, char *buffer)
{
	int	i;
	int	check;
	int	count;
	int	fd;

	fd = open("numbers.dict", O_RDONLY);
	i = 1;
	check = 0;
	count = 0;
	while (i && !check)
	{
		i = read(fd, buffer, 1);
		if (buffer[0] == '1')
		{
			i = read(fd, buffer, 1);
			while (count < size && buffer[0] == '0')
			{
				i = read(fd, buffer, 1);
				count++;
			}
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
				count = 0;
		}
	}
	close(fd);
	if (!i)
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	int		fd;
	char	buffer[1];
	int		j;

	j = ft_strlen(argv[1]) % 3;
	if (!j)
		j = 3;
	if (argc == 1)
		ft_print_error();
	else if (ft_valid_args(argv[1]))
		ft_print_error();
	else if (argc == 2)
	{
		fd = 0;
		if (ft_check(ft_strlen(argv[1]) - j + 1, buffer))
		{
			write(1, "Dict Error\n", 11);
			return (0);
		}
		else
			block_select(argv[1], fd, buffer);
	}
	return (0);
}
