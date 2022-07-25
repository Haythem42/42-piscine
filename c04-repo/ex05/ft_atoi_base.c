/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habelhad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 10:46:54 by habelhad          #+#    #+#             */
/*   Updated: 2022/07/14 15:39:28 by habelhad         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include <stdbool.h>

int	check_base(char *base)
{
	int	i;
	int	j;

	if (base[0] == '\0' || base[1] == '\0')
		return (0);
	i = 0;
	while (base[i])
	{
		j = i + 1;
		if (base[i] == 43 || base[i] == 45)
			return (0);
		if (base[i] < 32 || base[i] > 126)
			return (0);
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	find_base_index(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

int	verif(char *str, char c)
{
	int		i;
	bool	tf;

	i = 0;
	tf = false;
	while (str[i])
	{
		if (c == str[i])
			tf = true;
		i++;
	}
	if (tf)
		return (1);
	else
		return (0);
}

int	ft_atoi(char *str, char *base, int base_length)
{
	int	result;
	int	sign;
	int	i;

	result = 0;
	sign = 1;
	i = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (verif(base, str[i]))
	{
		result = result * base_length + find_base_index(base, str[i]);
		i++;
	}
	return (result * sign);
}

int	ft_atoi_base(char *str, char *base)
{
	int	base_length;

	base_length = 0;
	while (base[base_length])
		base_length++;
	if (!check_base(base))
		return (0);
	return (ft_atoi(str, base, base_length));
}
