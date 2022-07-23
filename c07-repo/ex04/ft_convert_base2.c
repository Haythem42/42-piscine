/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habelhad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 19:59:27 by habelhad          #+#    #+#             */
/*   Updated: 2022/07/21 20:59:55 by habelhad         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	ft_find_base_index(char *nbr, char c)
{
	int	i;

	i = 0;
	while (nbr[i] && nbr[i] != c)
		i++;
	return (i);
}

int	ft_check_exist(char *nbr, char c)
{
	int	i;
	int	check_c;

	i = 0;
	check_c = 0;
	while (nbr[i])
	{
		if (c == nbr[i])
			check_c = 1;
		i++;
	}
	return (check_c);
}

int	ft_strlen(char *base)
{
	int	base_length;

	base_length = 0;
	while (base[base_length])
		base_length++;
	return (base_length);
}

char	*ft_rev_str(char *str, int size)
{
	int		i;
	char	temp;

	i = 0;
	while (i < size / 2)
	{
		temp = str[i];
		str[i] = str[size - i - 1];
		str[size - i - 1] = temp;
		i++;
	}
	return (str);
}

int	ft_check_base(char *base)
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
