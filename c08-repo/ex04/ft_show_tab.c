/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habelhad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 16:53:49 by habelhad          #+#    #+#             */
/*   Updated: 2022/07/22 17:50:41 by habelhad         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include "ft_stock_str.h"

struct s_stock_str	*ft_strs_to_tab(int ac, char **av);

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putstr(char *str)
{
	write(1, &str, ft_strlen(str));
}

void	ft_putnbr(int nbr)
{
	int	nbr_temp;

	if (nbr < 0)
	{
		ft_putstr("-");
		if (nbr == -2147483648)
		{
			ft_putstr("2147483648");
			return ;
		}
		nbr *= -1;
	}
	if (nbr > 9)
	{
		ft_putnbr(nbr / 10);
		nbr_temp = (nbr % 10) + '0';
		write(1, &nbr_temp, 1);
	}
	if (nbr >= 0 && nbr <= 9)
	{
		nbr_temp = nbr + '0';
		write(1, &nbr_temp, 1);
	}
}

void	ft_show_tab(struct s_stock_str *par)
{
	int	i;

	i = 0;
	while (par[i].str)
	{
		ft_putstr(par[i].str);
		ft_putstr("\n");
		ft_putnbr(par[i].size);
		ft_putstr("\n");
		ft_putstr(par[i].copy);
		ft_putstr("\n");
		i++;
	}
}
