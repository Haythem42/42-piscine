/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habelhad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 18:31:58 by habelhad          #+#    #+#             */
/*   Updated: 2022/07/18 19:02:08 by habelhad         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	ft_min_max_diff(int min, int max)
{
	int	i;

	i = 0;
	if (min > max)
		return (0);
	while (min != max)
	{
		i++;
		min++;
	}
	return (i);
}

int	*ft_range(int min, int max)
{
	int	*int_array;
	int	nbr;
	int	i;

	int_array = malloc(ft_min_max_diff(min, max) + 1);
	if (int_array == NULL)
		return (NULL);
	nbr = min;
	i = 0;
	while (nbr < max)
	{
		int_array[i] = nbr;
		nbr++;
		i++;
	}
	return (int_array);
}
