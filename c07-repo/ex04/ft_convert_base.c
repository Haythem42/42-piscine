/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habelhad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 17:48:25 by habelhad          #+#    #+#             */
/*   Updated: 2022/07/28 17:19:56 by habelhad         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

char	*ft_itoa_base(long n, char *base_to);

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	check_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (base[i])
	{
		if (base[i] == 32 || (base[i] >= 9 && base[i] <= 13))
			return (0);
		else if (base[i] == '+' || base[i] == '-')
			return (0);
		while (j < i)
		{
			if (base[j++] == base[i])
				return (0);
		}
		j = 0;
		i++;
	}
	if (i < 2)
		return (0);
	return (1);
}

int	check_char_in_base(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	get_char(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i] != c)
		i++;
	return (i);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		i;
	long	result;
	int		sign;

	i = 0;
	result = 0;
	sign = 1;
	if (!check_base(base_from) || !check_base(base_to))
		return (0);
	while (nbr[i] == 32 || (nbr[i] >= 9 && nbr[i] <= 13))
		i++;
	while (nbr[i] == '+' || nbr[i] == '-')
	{
		if (nbr[i] == '-')
			sign *= -1;
		i++;
	}
	while (nbr[i] && check_char_in_base(nbr[i], base_from))
	{
		result = (result * ft_strlen(base_from)) + get_char(nbr[i], base_from);
		i++;
	}
	return (ft_itoa_base(result * sign, base_to));
}
