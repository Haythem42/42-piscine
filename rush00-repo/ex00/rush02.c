/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habelhad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 17:12:35 by habelhad          #+#    #+#             */
/*   Updated: 2022/07/10 10:16:20 by habelhad         ###   ########lyon.fr   */
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
		ft_putchar('A');
	if (x == 1 && y > 1)
		column('A', 'B', 'C', y);
	if (x > 1 && y == 1)
		line('A', 'B', 'A', x);
	if (x > 1 && y > 1)
	{
		line('A', 'B', 'A', x);
		while (i < y - 2)
		{
			line('B', ' ', 'B', x);
			i++;
		}
		line('C', 'B', 'C', x);
	}
}
