/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habelhad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 19:51:59 by habelhad          #+#    #+#             */
/*   Updated: 2022/07/14 20:56:17 by habelhad         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_rev_params(char **str, int nbr_arg)
{
	int		i;
	char	*temp;

	i = 1;
	while (str[i] && i < (nbr_arg + 1) / 2)
	{
		temp = str[i];
		str[i] = str[nbr_arg - i];
		str[nbr_arg - i] = temp;
		i++;
	}
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
}

int	main(int argc, char **argv)
{
	int	i;

	i = 1;
	ft_rev_params(argv, argc);
	while (argv[i])
	{
		ft_putstr(argv[i]);
		ft_putstr("\n");
		i++;
	}
	return (0);
}
