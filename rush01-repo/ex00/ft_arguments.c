/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arguments.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habelhad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 13:04:15 by habelhad          #+#    #+#             */
/*   Updated: 2022/07/16 13:25:33 by habelhad         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	verif_argc(int argc)
{
	if (argc != 2)
		return (0);
	return (1);
}

int	verif_argv_length(char *argv)
{
	int	argv_length;

	argv_length = 0;
	while (argv[i])
		argv_length++;
	if (argv_length != 31)
		return (0);
	return (1);
}

int	verif_argv_param(char *argv)
{
	int	i;

	i = 0;
	if ((i % 2 == 0) && !(argv[i] >= 1 && argv[i] <= 4))
		return (0);
	if ((i % 2 == 1) && !(argv[i] == 32))
		return (0);
	return (1);
}
