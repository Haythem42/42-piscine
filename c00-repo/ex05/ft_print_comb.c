/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habelhad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 13:19:51 by habelhad          #+#    #+#             */
/*   Updated: 2022/07/07 15:03:52 by habelhad         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_print_comb(void)
{
	int	first_digit;
	int	second_digit;
	int	third_digit;

	first_digit = '0';
	second_digit = '1';
	third_digit = '2';
	while (first_digit <= '9')
	{
		while (second_digit <= '9')
		{
			while (third_digit <= '9')
			{
				write(1, &first_digit, 1);
				write(1, &second_digit, 1);
				third_digit += write(1, &third_digit, 1);
				if (first_digit != '7')
					write(1, ", ", 2);
			}
			second_digit++;
			third_digit = second_digit + 1;
		}
		first_digit++;
		second_digit = first_digit;
	}
}
