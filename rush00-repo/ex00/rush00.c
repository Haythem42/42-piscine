/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                             :+:      :+:    :+: */
/*                                                    +:+ +:+         +:+     */
/*   By: ivella <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 15:47:21 by ivella            #+#    #+#             */
/*   Updated: 2022/07/10 10:03:44 by habelhad         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putchar(char c);

void	line(char c1, char c2, char c3, int size)
{
	int	i;

	i = 0;
	ft_putchar(c1);
	while (i < size - 2)
	{
		ft_putchar(c2);
		i++;
	}
	ft_putchar(c3);
	ft_putchar('\n');
}

void	column(char c1, char c2, char c3, int size)
{
	int	i;

	i = 0;
	ft_putchar(c1);
	ft_putchar('\n');
	while (i < size - 2)
	{
		ft_putchar(c2);
		ft_putchar('\n');
		i++;
	}
	ft_putchar(c3);
	ft_putchar('\n');
}

void	rush(int x, int y)
{
	int	i;

	i = 0;
	if (x < 1 || y < 1)
		write(1, "Error", 5);
	if (x == 1 && y == 1)
		ft_putchar('o');
	if (x > 1 && y == 1)
		line('o', '-', 'o', x);
	if (y > 1 && x == 1)
		column('o', '|', 'o', y);
	if (x > 1 && y > 1)
	{
		line('o', '-', 'o', x);
		while (i < y - 2)
		{
			line('|', ' ', '|', x);
			i++;
		}
		line('o', '-', 'o', x);
	}
}
