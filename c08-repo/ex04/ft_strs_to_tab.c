/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habelhad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 14:55:37 by habelhad          #+#    #+#             */
/*   Updated: 2022/07/22 19:18:25 by habelhad         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "ft_stock_str.h"
#include "ft_show_tab.h"

/*int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}*/

void ft_convert(char *string, t_stock_str *stock_str)
{
	int	i;

	i = 0;
	stock_str->size = ft_strlen(&string[i]);
	stock_str->str = &string[i];
	stock_str->copy = &string[i];
}

struct	s_stock_str *ft_strs_to_tab(int ac, char **av)
{
	//t_stock_str stock_str;
	int	i;
	t_stock_str  *struct_array;

	struct_array = malloc(ft_strlen(*av) + 1);
	if (struct_array == NULL)
	{
		return (struct_array);
	}
	i = 0;
	while (av[i] && i < ac)
	{
		ft_convert(av[i], struct_array);
		i++;
	}
	return (struct_array);
}

int	main(int argc, char **argv)
{
	ft_show_tab(ft_strs_to_tab(argc, argv));
}
