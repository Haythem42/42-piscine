/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habelhad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 18:37:32 by habelhad          #+#    #+#             */
/*   Updated: 2022/07/22 18:59:40 by habelhad         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include "ft.h"

int	main(void)
{
	int a;
	int	b;
	char	c;
	char *str;

	a = 15;
	b = 7;
	c = 's';
	str = "salut";
	ft_putchar(c);
	ft_putchar('\n');
	ft_swap(&a, &b);
	printf("%d, %d\n", a, b);	
	ft_putstr(str);
	ft_putchar('\n');
	printf("%d\n", ft_strlen(str));
	printf("%d\n", ft_strcmp("sales", "salet"));
	return (0);
}
