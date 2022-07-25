/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habelhad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 14:11:27 by habelhad          #+#    #+#             */
/*   Updated: 2022/07/12 19:28:37 by habelhad         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putstr_non_printable(char *str)
{
	unsigned int	i;
	unsigned char	c;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 32 && str[i] <= 126)
		{
			write(1, &str[i], 1);
		}
		else
		{
			c = str[i];
			write(1, "\\", 1);
			write(1, &"0123456789abcdef"[c / 16], 1);
			write(1, &"0123456789abcdef"[c % 16], 1);
		}
		i++;
	}
}
