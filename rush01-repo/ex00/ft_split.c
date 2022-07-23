/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habelhad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 15:14:49 by habelhad          #+#    #+#             */
/*   Updated: 2022/07/17 16:36:11 by habelhad         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while(str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

void	ft_split(char *str)
{
	char	array1[4];
	char	array2[4];
	char	array3[4];
	char	array4[4];
	int		i;
	int		j;
	int		k;
	int		l;
	int		m;

	i = 0;
	j = 0;
	k = 0;
	l = 0;
	m = 0;
	while (str[i])
	{
		if (i % 2 == 0)
		{
			if (i < 7)
			{
				array1[j] = str[i];
				j++;
			}
			if (i > 7 && i < 15)
			{
				array2[k] = str[i];
				k++;
			}
			/*if (i > 15 && i < 23)
			{
				array3[l] = str[i];
				l++;
			}
			if (i > 23 && i < 31)
			{
				array4[m] = str[i];
				m++;
			}*/
			i++;
		}
		else
			i++;
	}
	array1[j] = '\0';
	array2[k] = '\0';
	array3[l] = '\0';
	array4[m] = '\0';
	ft_putstr(array1);
	ft_putstr(array2);
	ft_putstr(array3);
	ft_putstr(array4);
	/*j = 0;
	k = 0;
	l = 0;
	m = 0;
	while (array1[j])
	{
		write(1, &array1[j], 1);
		j++;
	}
	write(1, "\n", 1);
	while (array2[k])
	{
		write(1, &array2[k], 1);
		k++;
	}
	write(1, "\n", 1);
	while (array3[l])
	{
		write(1, &array3[l], 1);\
		l++;
	}
	write(1, "\n", 1);
	while (array4[m])
	{	
		write(1, &array4[m], 1);
		m++;
	}
	write(1, "\n", 1);*/
}

int main(int argc, char **argv)
{
	(void)argc;
	ft_split(argv[1]);
}
