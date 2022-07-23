/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmilan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 11:34:55 by nmilan            #+#    #+#             */
/*   Updated: 2022/07/23 14:51:05 by nmilan           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

void	block_select(char *str, int fd, char *buffer)
{
	int	head;
	int	block;
	int	size;
	int	control_first_empty;

	size = ft_strlen(str);
	head = size % 3;
	block = (size / 3) + 1;
	control_first_empty = 0;
	if (head == 0)
		control_frist_empty = 1;
	while (block > 0)
	{
		while (head > 0)
		{
			if (str[i] == 1 && head == 2)
				ft_print_tens(str[i + 1], fd, buffer);
			else
			{
				ft_print(str[i], head, fd, buffer);
				i++;
				head--;
			}
		}
		head = 3;
		if (control_first_empty == 0)
			ft_print_block(str[i], block);
		block--;
		control_first_empty = 0;
	}
}

void	ft_print(char caract, int head, int fd, char *buffer)
{
	if (head == 3)
		ft_print_hundred (str[i], fd, buffer);
	else if (head == 2)
		ft_print_decade (str [i], fd, buffer);
	else if (head == 1)
		ft_print_units (str[i], fd, buffer);
}			
