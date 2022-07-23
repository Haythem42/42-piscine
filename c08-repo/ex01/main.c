/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habelhad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 22:35:00 by habelhad          #+#    #+#             */
/*   Updated: 2022/07/21 22:59:00 by habelhad         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_boolean.h"

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

t_bool	ft_is_even(int nbr)
{
	return ((EVEN(nbr)) ? TRUE : FALSE);
}

int	main(int argc, char **argv)
{
	(void)argv;
	if (ft_is_even(argc - 1) == TRUE)
		ft_putstr(EVEN_MSG);
	else
		ft_putstr(ODD_MSG);
	return (SUCCESS);
}
