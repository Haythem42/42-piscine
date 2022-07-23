/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habelhad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 14:30:17 by habelhad          #+#    #+#             */
/*   Updated: 2022/07/18 16:32:32 by habelhad         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	ft_power(int nb, int power)
{
	int	temp;

	temp = nb;
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	while (1 < power)
	{
		nb *= temp;
		power--;
	}
	return (nb);
}

int	ft_sqrt(int nb)
{
	int	i;

	i = 0;
	while (ft_power(i, 2) != nb && i < (nb / 2))
		i++;
	if (nb % i == 1)
		return (0);
	return (i);
}
