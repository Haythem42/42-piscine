/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habelhad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 14:01:01 by habelhad          #+#    #+#             */
/*   Updated: 2022/07/28 11:41:17 by habelhad         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	ft_min_max_diff(int min, int max)
{
	int	i;

	if (min >= max)
		return (0);
	i = 0;
	while (min != max)
	{
		min++;
		i++;
	}
	return (i);
}

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;
	int	*array_length;

	if (!ft_min_max_diff(min, max))
	{
		*range = NULL;
		return (0);
	}
	array_length = malloc(sizeof(int) * (ft_min_max_diff(min, max) + 1));
	if (array_length == NULL)
		return (-1);
	i = 0;
	while (min < max)
	{
		array_length[i] = min;
		i++;
		min++;
	}
	*range = array_length;
	return (i);
}
