/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habelhad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 11:44:02 by habelhad          #+#    #+#             */
/*   Updated: 2022/07/23 15:46:12 by lcrimet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <unistd.h>

char	*ft_atoa(char *str)
{
	char	*clean_array;
	int	i;
	int j;

	clean_array = malloc(500);
	i = 0;
	j = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13) || str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		clean_array[j] = str[i];
		i++;
		j++;
	}
	return (clean_array);
}

int ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_strcmp(char *str, char *limit)
{
	int		i;

	i = 0;
	while (str[i] && limit[i] && str[i] == limit[i])
		i++;
	return (str[i] - limit[i]);
}

int	ft_valid_args(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

void	ft_print_error()
{
	write(1, "Error\n", 6);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

int main(int argc, char **argv)
{
	char	*max_value;

	max_value = "4294967295";
	if (argc != 2)
	{
		ft_print_error();
		return (0);
	}
	if (!ft_valid_args(argv[argc - 1]) || 
			ft_strlen(argv[argc - 1]) > ft_strlen(max_value))
		ft_print_error();
	else
	{
		if (ft_strlen(argv[argc - 1]) == ft_strlen(max_value))
		{
			if (ft_strcmp(argv[argc - 1], max_value) > 0)
				ft_print_error();
			else
				ft_putstr(argv[argc - 1]);
		}
		if (ft_strlen(argv[argc - 1]) <= ft_strlen(max_value))
			ft_putstr(argv[argc - 1]);
	}
	return (0);
}
