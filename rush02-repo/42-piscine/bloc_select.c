/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block_select.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmilan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 22:00:26 by nmilan            #+#    #+#             */
/*   Updated: 2022/07/24 20:29:40 by lcrimet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>

void	search_in_bloc_ten(char caract, char *buffer, t_var *var, char *dict)
{
	int	fd;

	if (var->is_first != 1)
		write(1, " ", 1);
	fd = open(dict, O_RDONLY);
	ft_print_tens(caract, fd, buffer);
	if (var->bloc == 1)
		write(1, "\n", 1);
	close(fd);
	var->i += 2;
	var->head -= 2;
	var->is_first = 0;
}

void	ft_search_in_bloc(char caract, char *buffer, t_var *var, char *dict)
{
	if (caract != '0' && var->is_first != 1)
		write(1, " ", 1);
	ft_print(caract, var->head, buffer, dict);
	if (var->bloc == 1 && var->head == 1)
		write(1, "\n", 1);
	var->i++;
	var->head--;
	var->is_first = 0;
}

void	ft_search_end_bloc(t_var var, char *buffer, char *dict)
{
	int	fd;

	write (1, " ", 1);
	fd = open(dict, O_RDONLY);
	ft_print_bloc((var.bloc - 1) * 3 + 1, fd, buffer);
	close(fd);
}

void	ft_init_var(t_var *var, char *str)
{
	var->i = 0;
	var->size = ft_strlen(str);
	var->head = var->size % 3;
	var->bloc = (var->size / 3) + 1;
	var->is_first = 1;
	if (var->head == 0)
		var->control_first_empty = 1;
	else
		var->control_first_empty = 0;
}

void	bloc_select(char *str, char *buffer, char *dict)
{
	t_var	var;

	ft_init_var (&var, str);
	while (var.bloc > 0)
	{
		while (var.head > 0)
		{
			if (str[var.i] == '1' && var.head == 2)
				search_in_bloc_ten(str[var.i + 1], buffer, &var, dict);
			else
				ft_search_in_bloc(str[var.i], buffer, &var, dict);
		}
		var.head = 3;
		if (var.control_first_empty == 0 && var.bloc > 1
			&& (str[var.i - 1] != '0'
				|| str[var.i - 2] != '0' || str[var.i - 3] != '0'))
			ft_search_end_bloc(var, buffer, dict);
		var.control_first_empty = 0;
		var.bloc--;
	}
}
