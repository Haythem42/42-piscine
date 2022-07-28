/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habelhad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 14:39:54 by habelhad          #+#    #+#             */
/*   Updated: 2022/07/28 16:33:51 by habelhad         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strcat(int size, char **strs, char *sep, char *dest)
{
	int	i;
	int	j;
	int	k;

	i = -1;
	j = 0;
	while (++i < size)
	{
		k = 0;
		while (strs[i][k])
			dest[j++] = strs[i][k++];
		if (i != size - 1)
		{
			k = 0;
			while (sep[k])
				dest[j++] = sep[k++];
		}
	}
	dest[j] = '\0';
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	char	*array_temp;
	int		temp;

	i = 0;
	temp = 0;
	if (size == 0)
	{
		array_temp = (char *) malloc(sizeof(char));
		array_temp[0] = '\0';
		return (array_temp);
	}
	while (i < size)
	{
		temp += ft_strlen(strs[i]);
		i++;
	}
	array_temp = (char *) malloc(sizeof(char)
			* (temp + ft_strlen(sep) * (size - 1) + 1));
	array_temp = ft_strcat(size, strs, sep, array_temp);
	return (array_temp);
}
