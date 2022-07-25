/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habelhad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 12:59:58 by habelhad          #+#    #+#             */
/*   Updated: 2022/07/10 13:40:03 by habelhad         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

struct	s_comb
{
	int	a;
	int	a1;
	int	a2;
	int	b;
	int	b1;
	int	b2;
};

void	ft_print_comb2(void)
{
	struct s_comb	numb;

	numb.a = 0;
	while (numb.a <= 98)
	{
		numb.b = numb.a + 1;
		while (numb.b <= 99)
		{
			numb.a1 = numb.a / 10 + '0';
			numb.a2 = numb.a % 10 + '0';
			numb.b1 = numb.b / 10 + '0';
			numb.b2 = numb.b % 10 + '0';
			write(1, &numb.a1, 1);
			write(1, &numb.a2, 1);
			write(1, " ", 1);
			write(1, &numb.b1, 1);
			write(1, &numb.b2, 1);
			if (numb.a != 98)
				write(1, ", ", 2);
			numb.b++;
		}
		numb.a++;
	}
}
