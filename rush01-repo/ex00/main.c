/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habelhad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 12:59:11 by habelhad          #+#    #+#             */
/*   Updated: 2022/07/16 14:42:55 by habelhad         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdio.h>

void	ft_putstr(int nb)
{
	write(1, &nb, 1);
}

void	tab()
{
	int tab[4][4] = {{1, 2, 3, 4}, {1, 2, 3, 4}, {1, 2, 3, 4}, {1, 2, 3, 4}};	
	int	i;
	int j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			ft_putstr(tab[i][j] + '0');
			if (j < 3)
				ft_putstr(32);
			j++;
		}
		i++;
		ft_putstr('\n');
	}
}

int main(void)
{
	tab();
}
