/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habelhad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 16:53:49 by habelhad          #+#    #+#             */
/*   Updated: 2022/07/22 17:31:01 by habelhad         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

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
	write(1, &str, ft_strlen(str[i]));
}

void	ft_putnbr(int nbr)
{
	int	nbr_temp;

	if (nbr > 9)
	{
		ft_putnbr(nbr / 10);
		nbr_temp = (nbr % 10) + '0';
		write(1, &nbr_temp, 1);
	}
	if (nb >= 0 && nbr <= 9)
	{
		nbr_temp = nbr + '0';
		write(1, &nbr_temp, 1);
	}
}

void	ft_show_tab(struct s_stock_str *par)
{
	int	i;

	i = 0;
	while (par[i])
	{
		ft_putstr(par[i].str);
		ft_putstr("\n");
		ft_putnbr(par[i].size);
		ft_putstr("\n");
		ft_putstr(par[i].copy);
		ft_putstr("\n");
	}
}
