/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_dict.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habelhad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 19:15:07 by habelhad          #+#    #+#             */
/*   Updated: 2022/07/23 20:35:14 by habelhad         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	ft_check_dict(char *str)
{
	int	i;

	i = 0;
	if (str[i] < '0' || str[i] > '9')
		return (1);
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	if (str[i] == ' ')
	{
		while (str[i] == ' ')
		i++;
	}
	if (str[i] == ':')
		i++;
	else
		return (1);
	if (str[i] == ' ')
	{
		while (str[i] == ' ')
			i++;
	}
	if (str[i] >= 32 && str[i] <= 127)
	{
		while (str[i] >= 32 && str[i] <= 127)
			i++;
	}
	else
		return (1);
	if (str[i] && (str[i] <= 9 || (str[i] >= 11 && str[i] <= 32) || str[i] >= 127))
		return (1);
	return (0);
}

#include <unistd.h>
#include <stdio.h>

int	main(int argc, char **argv)
{

	(void) argc;
	if (ft_check_dict(argv[1]) == 1)
		write(1, "ERROR\n", 6);
	else
		printf("%d\n", ft_check_dict(argv[1]));
	return (0);
}
