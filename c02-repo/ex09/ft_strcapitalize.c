/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habelhad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 10:11:46 by habelhad          #+#    #+#             */
/*   Updated: 2022/07/12 12:24:26 by habelhad         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strlowcase(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 65 && str[i] <= 90)
			str[i] += 32;
		i++;
	}
	return (str);
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	ft_strlowcase(str);
	if (str[i] >= 97 && str[i] <= 122)
		str[i] -= 32;
	i++;
	while (str[i])
	{
		if ((str[i] >= 97 && str[i] <= 122)
			&& !((str[i - 1] >= 48 && str[i - 1] <= 57)
				|| (str[i - 1] >= 65 && str[i - 1] <= 90)
				|| (str[i - 1] >= 97 && str[i - 1] <= 122)))
			str[i] -= 32;
		i++;
	}
	return (str);
}
