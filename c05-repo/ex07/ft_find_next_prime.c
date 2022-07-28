/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habelhad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 16:02:10 by habelhad          #+#    #+#             */
/*   Updated: 2022/07/28 10:59:10 by habelhad         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int	i;

	if (nb <= 1)
		return (0);
	if (nb == 2)
		return (1);
	i = 2;
	while ((i * i) <= nb + 1)
	{
		if ((nb % i) == 0)
			return (0);
		i++;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	int	is_next_prime_found;
	int	next_prime;

	is_next_prime_found = 0;
	next_prime = 0;
	while (!is_next_prime_found)
	{
		if (2 > nb)
			nb = 2;
		if (ft_is_prime(nb))
		{
			is_next_prime_found = 1;
			next_prime = nb;
		}
		nb++;
	}
	return (next_prime);
}
