/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habelhad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 11:24:45 by habelhad          #+#    #+#             */
/*   Updated: 2022/07/14 10:37:06 by habelhad         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	ft_check_base(char *base)
{
	int	i;
	int	j;

	if ('\0' == base[0] || '\0' == base[1])
		return (0);
	i = 0;
	while (base[i])
	{
		j = i + 1;
		if (43 == base[i] || 45 == base[i])
			return (0);
		if (32 > base[i] || 126 < base[i])
			return (0);
		while (base[j])
		{
			if (base[j] == base[i])
				return (0);
				j++;
		}
		i++;
	}
	return (1);
}

void	ft_putchar(char c)

{
	write(1, &c, 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int			base_length;
	long int	li;

	li = nbr;
	base_length = 0;
	while (base[base_length])
		base_length++;
	if (ft_check_base(base))
	{
		if (0 > li)
		{
			ft_putchar('-');
			li = li * -1;
		}
		if (li < base_length)
			ft_putchar(base[li]);
		if (li >= base_length)
		{
			ft_putnbr_base(li / base_length, base);
			ft_putnbr_base(li % base_length, base);
		}
	}
}
