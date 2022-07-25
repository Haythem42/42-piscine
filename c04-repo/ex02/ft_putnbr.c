/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habelhad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 05:07:55 by habelhad          #+#    #+#             */
/*   Updated: 2022/07/14 18:03:49 by habelhad         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putnbr(int nb)
{
	int	nbr_print;

	if (nb < 0)
	{
		write(1, "-", 1);
		if (nb == -2147483648)
			write(1, "2147483648", 10);
		nb = nb * -1;
	}
	if (nb > 9)
	{
		ft_putnbr(nb / 10);
		nbr_print = (nb % 10) + '0';
		write(1, &nbr_print, 1);
	}
	if (nb >= 0 && nb <= 9)
	{
		nbr_print = nb + '0';
		write(1, &nbr_print, 1);
	}
}
