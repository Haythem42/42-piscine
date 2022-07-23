/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habelhad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 14:39:54 by habelhad          #+#    #+#             */
/*   Updated: 2022/07/20 16:42:12 by habelhad         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	ft_strlen(char *src)
{
	int	i;

	i = 0;
	while (src[i])
		i++;
	return (i);
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	temp;

	i = 0;
	temp = ft_strlen(dest);
	while (src[i])
	{
		dest[temp] = src[i];
		temp++;
		i++;
	}
	dest[temp] = '\0';
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	char	*array_temp;
	int		j;
	int		temp;

	temp = 0;
	j = 0;
	while (strs[j])
	{
		temp += ft_strlen(strs[j]);
		j++;
	}
	array_temp = malloc(temp + (size - 1) * ft_strlen(sep) + 1);
	i = 0;
	while (i < size)
	{
		if (i != 0)
			ft_strcat(array_temp, sep);
		ft_strcat(array_temp, strs[i]);
		i++;
	}
	*strs = array_temp;
	return (*strs);
}
