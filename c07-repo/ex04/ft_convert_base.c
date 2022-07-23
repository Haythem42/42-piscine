/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habelhad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 17:48:25 by habelhad          #+#    #+#             */
/*   Updated: 2022/07/21 21:00:26 by habelhad         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int		ft_find_base_index(char *nbr, char c);
int		ft_check_exist(char *nbr, char c);
int		ft_strlen(char *base);
char	*ft_rev_str(char *str, int size);
int		ft_check_base(char *base);

char	ft_atoi(char *nbr, char *base, int base_length)
{
	int	result;
	int	sign;
	int	i;

	result = 0;
	sign = 1;
	i = 0;
	while (nbr[i] == 32 || (nbr[i] >= 9 && nbr[i] <= 13))
		i++;
	while (nbr[i] == '-' || nbr[i] == '+')
	{
		if (nbr[i] == '-')
			sign *= -1;
		i++;
	}
	while (ft_check_exist(base, nbr[i]))
	{
		result = result * base_length + ft_find_base_index(base, nbr[i]);
		i++;
	}
	return (result * sign);
}

char	*ft_insert_in_str(long int li, int base_length, char *base, int sign)
{
	int		index;
	char	*convert_nbr;

	index = 0;
	convert_nbr = malloc(500);
	while (li > base_length - 1)
	{
		convert_nbr[index] = base[li % base_length];
		li = li / base_length;
		index++;
	}
	convert_nbr[index] = base[li];
	index++;
	if (sign)
	{
		convert_nbr[index] = '-';
		index++;
	}
	convert_nbr[index] = '\0';
	return (convert_nbr);
}

char	*ft_putnbr_base(int nbr, char *base)
{
	int			base_length;
	long int	li;
	int			sign;
	char		*convert_nbr;

	convert_nbr = malloc(500);
	li = nbr;
	sign = 0;
	base_length = ft_strlen(base);
	if (ft_check_base(base))
	{
		if (0 > li)
		{
			sign = 1;
			li = li * -1;
		}
		convert_nbr = ft_insert_in_str(li, base_length, base, sign);
	}
	ft_rev_str(convert_nbr, ft_strlen(convert_nbr));
	return (convert_nbr);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int	temp;

	if (!ft_check_base(base_from) || !ft_check_base(base_to))
		return (NULL);
	temp = ft_atoi(nbr, base_from, ft_strlen(base_from));
	return (ft_putnbr_base(temp, base_to));
}
